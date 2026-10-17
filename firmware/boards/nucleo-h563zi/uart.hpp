// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    uart.hpp
 * @author  Thomas Legrand
 * @brief   USART3 VCP driver for NUCLEO-H563ZI — 115200 8N1, GPDMA1
 *
 *          TX: GPDMA1 Ch0 (request 26) — TC fires GPDMA1_CH0_IRQn (27).
 *          RX: GPDMA1 Ch1 (request 25) — IDLE fires USART3_IRQn (60).
 *              Ping-pong double buffer: the next buffer is armed before
 *              @c receive() returns, so DMA stays active during @c send().
 *
 * @par Pins
 *   | Pin | Signal | AF  |
 *   |-----|--------|-----|
 *   | PD8 | TX     | AF7 |
 *   | PD9 | RX     | AF7 |
 *
 * @par Missed-wakeup protection
 *   Between enabling a DMA channel and calling @c wait(), the ISR can fire
 *   and call @c notify_one() before the task is registered as a waiter.
 *   This would cause @c wait() to block indefinitely.
 *
 *   Fix: hold @c tx_mutex_ / @c rx_mutex_ (both at @c isr_priority{0x80}) while
 *   enabling the channel, then call @c wait(mutex) which atomically releases
 *   the mutex and registers the task as waiter.  The ISR can only fire after
 *   the task is already in the wait list.
 *
 * @par ISR registration in startup.cpp
 *   @code
 *   constexpr auto g_vectors = InterruptVector<IrqCount>(...)
 *       .Register<GPDMA1_CH0_IRQn, uart::tx_isr>()
 *       .Register<USART3_IRQn,     uart::rx_isr>();
 *   @endcode
 ******************************************************************************
 */

#pragma once

#include <atomic>
#include <cstdint>
#include <mutex>  // std::lock_guard
#include <span>

#include <cortex_m.hpp>
#include <isr_lock.hpp>
#include <condition_variable.hpp>
#include <scheduler.hpp> // condition_variable::notify_one() is defined inline there

#include <STM32H563/gpio.hpp>
#include <STM32H563/gpdma.hpp>
#include <STM32H563/interrupts.hpp>
#include <STM32H563/rcc.hpp>
#include <STM32H563/usart.hpp>

namespace STM32H563
{

// The `atomic` postfix tag used in `| atomic` / `|| atomic` lives in
// opsy::utility — pull it into namespace scope so the BSP register
// helper expressions read naturally.
using opsy::utility::atomic;

/**
 * @brief USART3 VCP driver — 115200 8N1, GPDMA TX/RX, IDLE line detection.
 *
 *        All methods are static. Call @c init() once after @c clock::init()
 *        and before @c scheduler::start().
 *
 *        Half-duplex usage model:
 *          - @c send() blocks until the TX DMA transfer completes.
 *          - @c receive() arms the RX DMA and blocks until an IDLE event
 *            or the caller's timeout expires.
 *
 *        Both functions must be called from a task context only.
 */
class uart
{
public:

	/** @brief Size of each ping-pong RX buffer (bytes). Frames larger than this are truncated. */
	static constexpr std::size_t rx_buffer_size = 256;

	/**
	 * @brief ISR priority for both DMA and USART3 interrupts.
	 *
	 *        Must be strictly lower preemption than the OpSy scheduler
	 *        (numerically higher value), and must match the priority passed
	 *        to the @c mutex and @c condition_variable constructors so that
	 *        the lock correctly masks these ISRs during critical sections.
	 */
	static constexpr opsy::isr_priority isr_priority{0x80};

	/**
	 * @brief Enables clocks, configures PD8/PD9 AF7, sets up USART3 115200 8N1.
	 *
	 *        GPDMA channels are not armed here — they are configured per-transfer.
	 */
	static void init()
	{
		// ── 1. Peripheral clocks ───────────────────────────────────────────
		rcc.rcc_ahb1enr  |= rcc_p::rcc_ahb1enr_r::gpdma1en_f()  | atomic;
		rcc.rcc_ahb2enr  |= rcc_p::rcc_ahb2enr_r::gpioden_f()   | atomic;
		rcc.rcc_apb1lenr |= rcc_p::rcc_apb1lenr_r::usart3en_f() | atomic;

		// ── 2. PD8 = TX (AF7), PD9 = RX (AF7) — alternate, high-speed ────
		gpiod.gpio_moder   <<= gpioc_p::gpio_moder_r::mode8_f(0b10)     || atomic;
		gpiod.gpio_moder   <<= gpioc_p::gpio_moder_r::mode9_f(0b10)     || atomic;
		gpiod.gpio_ospeedr <<= gpioc_p::gpio_ospeedr_r::ospeed8_f(0b11) || atomic;
		gpiod.gpio_ospeedr <<= gpioc_p::gpio_ospeedr_r::ospeed9_f(0b11) || atomic;
		gpiod.gpio_afrh    <<= gpioc_p::gpio_afrh_r::afsel8_f(7)        || atomic;
		gpiod.gpio_afrh    <<= gpioc_p::gpio_afrh_r::afsel9_f(7)        || atomic;

		// ── 3. USART3 — 115200 8N1, DMA on TX and RX, IDLE interrupt ──────
		// BRR = PCLK1 / baud = 250 000 000 / 115 200 = 2170 (oversampling ×16)
		usart3.usart_brr = usart_p::usart_brr_r::brr_f(2170);
		// OVRDIS: disable overrun — bytes that arrive when RDR is full are silently
		// discarded instead of generating ORE. The RDR flush in receive() handles cleanup.
		usart3.usart_cr3 = usart_p::usart_cr3_r::dmat_f()
		                 | usart_p::usart_cr3_r::dmar_f()
		                 | usart_p::usart_cr3_r::ovrdis_f();
		usart3.usart_cr1_enabled = usart_p::usart_cr1_enabled_r::ue_f()
		                         | usart_p::usart_cr1_enabled_r::te_f()
		                         | usart_p::usart_cr1_enabled_r::re_f();
		// IDLEIE is enabled by arm_rx_dma() just before wait(), while rx_mutex_ is
		// held (BASEPRI = isr_priority). Enabling it here would fire a spurious
		// IDLE immediately (line is idle at startup) before DMA is armed.

		// ── 4. NVIC — set priority before enabling ─────────────────────────
		opsy::cortex_m::set_priority(GPDMA1_CH0_IRQn, isr_priority);
		opsy::cortex_m::set_priority(GPDMA1_CH1_IRQn, isr_priority);
		opsy::cortex_m::set_priority(USART3_IRQn,     isr_priority);
		opsy::cortex_m::enable_interrupt(GPDMA1_CH0_IRQn);
		opsy::cortex_m::enable_interrupt(GPDMA1_CH1_IRQn);
		opsy::cortex_m::enable_interrupt(USART3_IRQn);
	}

	/**
	 * @brief Transmits @p data via GPDMA1 Ch0 and blocks until the transfer completes.
	 *
	 *        The caller must keep the buffer alive for the duration of the call.
	 *        Not thread-safe: use from a single task only.
	 *
	 * @param data Bytes to transmit.
	 */
	static void send(std::span<const uint8_t> data)
	{
		// BNDT is 16-bit (max 65535 bytes per DMA transfer): loop in 64K chunks.
		// In practice a single chunk covers every realistic VCP frame.

		// Dest, TR1, TR2 are constant across chunks — configure once.
		// Source: caller buffer (byte, increment) → Dest: USART3 TDR (byte, fixed)
		// DREQ = 1: destination peripheral paces the transfer.
		gpdma1.gpdma_c0dar = gpdma_p::gpdma_cxdar_r::da_f(reinterpret_cast<uint32_t>(&usart3.usart_tdr));
		gpdma1.gpdma_c0tr1 = gpdma_p::gpdma_cxtr1_r::sinc_f(); // src increment, dest fixed (default)
		gpdma1.gpdma_c0tr2 = gpdma_p::gpdma_cxtr2_r::reqsel_f(26)  // USART3_TX
		                   | gpdma_p::gpdma_cxtr2_r::dreq_f();       // dest (peripheral) paces

		while (!data.empty())
		{
			// Clamp to the 16-bit BNDT maximum
			auto const chunk_size = std::min(data.size(), std::size_t{0xFFFFu});

			gpdma1.gpdma_c0sar = gpdma_p::gpdma_cxsar_r::sa_f(reinterpret_cast<uint32_t>(data.data()));
			gpdma1.gpdma_c0br1 = gpdma_p::gpdma_cxbr1_r::bndt_f(static_cast<uint16_t>(chunk_size));

			// Lock masks the TX ISR (priority 0x80) while we enable the channel.
			// wait(mutex) atomically releases the lock and registers this task as waiter,
			// eliminating the missed-wakeup race between enable and wait.
			{
				std::lock_guard<opsy::isr_lock> guard(tx_mutex_);
				gpdma1.gpdma_c0fcr = gpdma_p::gpdma_cxfcr_r::tcf_f(); // clear any stale TCF before enabling TCIE
				gpdma1.gpdma_c0cr = gpdma_p::gpdma_cxcr_r::tcie_f()
				                  | gpdma_p::gpdma_cxcr_r::en_f();

				// If TXFE was already high (TDR empty), the DMA transferred the data
				// immediately and TCF fired while BASEPRI masked the interrupt.
				// Calling wait() in this state triggers SVC→tail-chain→tx_isr before
				// PendSV saves the task context: wake_up() writes to a stale
				// m_stackPointer and corrupts the stack.
				// Handle the completion here while still holding the mutex instead.
				if (gpdma1.gpdma_c0sr.load().tcf())
					gpdma1.gpdma_c0fcr = gpdma_p::gpdma_cxfcr_r::tcf_f();
				else
					tx_done_.wait(tx_mutex_); // releases tx_mutex_ atomically, re-acquires on wake
			} // guard destructor unlocks the re-acquired mutex

			data = data.subspan(chunk_size);
		}
	}

	/**
	 * @brief Blocks until an IDLE event (or buffer full) and returns the received bytes.
	 *
	 *        On return, the *next* ping-pong buffer is already armed — DMA RX remains
	 *        active during the caller's @c send(), so data arriving concurrently is
	 *        captured in the background.
	 *
	 *        The returned span is valid until the next call to @c receive().
	 *        Not thread-safe: use from a single task only.
	 *
	 * @return Received bytes (empty only if the buffer was filled with 0 bytes, which
	 *         cannot happen in practice).
	 */
	static std::span<const uint8_t> receive()
	{
		std::lock_guard<opsy::isr_lock> guard(rx_mutex_);

		// First call: DMA is not running yet — arm the initial buffer.
		if (!rx_armed_)
		{
			rx_armed_ = true;
			arm_rx_dma();
		}

		// rx_done_ is a sticky flag: if the ISR fired before we reached wait(),
		// the notification is not lost — we skip the wait entirely.
		while (!rx_done_)
			rx_idle_.wait(rx_mutex_);
		rx_done_ = false;

		int const done_buf = rx_fill_;

		// Flip to the other buffer and arm DMA immediately.
		// The mutex is still held, so the ISR cannot fire during the flip + arm,
		// and the dead window where no RX is active is limited to a few instructions.
		rx_fill_ ^= 1;
		arm_rx_dma();

		return std::span<const uint8_t>(rx_buffer_[done_buf], rx_count_[done_buf]);
	}

	/**
	 * @brief GPDMA1 Ch0 ISR — TX transfer complete.
	 *
	 *        Clears the TC flag and wakes @c send().
	 *        Register in startup.cpp: @c .Register<GPDMA1_CH0_IRQn, uart::tx_isr>()
	 */
	static void tx_isr()
	{
		gpdma1.gpdma_c0fcr = gpdma_p::gpdma_cxfcr_r::tcf_f();
		tx_done_.notify_one();
	}

	/**
	 * @brief USART3 ISR — IDLE line detected on RX.
	 *
	 *        Stops the RX DMA, captures the received byte count, clears the
	 *        IDLE flag, and wakes @c receive().
	 *        Register in startup.cpp: @c .Register<USART3_IRQn, uart::rx_isr>()
	 *
	 * @note  RESET has no effect on a running channel. The channel must first
	 *        be suspended (SUSP=1) and quiesced (IDLEF=1) before RESET is safe.
	 */
	static void rx_isr()
	{
		if (!usart3.usart_isr_enabled.load().idle())
			return;

		// If EN=0 the DMA channel already stopped (buffer full, TC auto-cleared EN, or
		// rx_dma_isr() already did RESET). Attempting SUSP + poll IDLEF on a stopped/reset
		// channel hangs forever — RESET clears all SR flags including IDLEF.
		// rx_dma_isr() has already handled (or has a pending IRQ to handle) the count.
		if (!gpdma1.gpdma_c1cr.load().en())
		{
			usart3.usart_icr = usart_p::usart_icr_r::idlecf_f();
			return;
		}

		// Channel is running: suspend — RESET alone has no effect while EN=1.
		gpdma1.gpdma_c1cr = gpdma_p::gpdma_cxcr_r::susp_f();
		while (!gpdma1.gpdma_c1sr.load().idlef())
			;

		// Capture remaining count after the channel is suspended
		auto const remaining = static_cast<std::size_t>(gpdma1.gpdma_c1br1.load().bndt());
		rx_count_[rx_fill_] = rx_buffer_size - remaining;

		// Reset the suspended channel and clear DMA flags
		gpdma1.gpdma_c1cr  = gpdma_p::gpdma_cxcr_r::reset_f();
		gpdma1.gpdma_c1fcr = gpdma_p::gpdma_cxfcr_r::tcf_f()
		                   | gpdma_p::gpdma_cxfcr_r::suspf_f();

		// Clear IDLE flag in USART
		usart3.usart_icr = usart_p::usart_icr_r::idlecf_f();

		rx_done_ = true;
		rx_idle_.notify_one();
	}

	/**
	 * @brief GPDMA1 Ch1 ISR — RX buffer completely full (no IDLE before 256 bytes).
	 *
	 *        Fires when BNDT reaches 0 without an IDLE event first.
	 *        Resets the channel and wakes @c receive() with a full buffer.
	 *        If IDLE fires immediately after (line went idle at exactly the 256th byte),
	 *        its @c notify_one() is harmlessly lost — nobody is waiting.
	 *        Register in startup.cpp: @c .Register<GPDMA1_CH1_IRQn, uart::rx_dma_isr>()
	 */
	static void rx_dma_isr()
	{
		rx_count_[rx_fill_] = rx_buffer_size; // BNDT reached 0: all bytes are in the buffer
		gpdma1.gpdma_c1cr  = gpdma_p::gpdma_cxcr_r::reset_f();
		// Clear flags AFTER reset: reset itself generates SUSPF (and potentially TCF).
		// If TCF were left set, enabling Ch1 with TCIE in the next receive() would
		// trigger an immediate spurious interrupt.
		gpdma1.gpdma_c1fcr = gpdma_p::gpdma_cxfcr_r::tcf_f()
		                   | gpdma_p::gpdma_cxfcr_r::suspf_f();
		rx_done_ = true;
		rx_idle_.notify_one();
	}

private:

	/**
	 * @brief Arms GPDMA1 Ch1 on @c rx_buffer_[rx_fill_].
	 *
	 *        Flushes RDR and clears USART error/IDLE flags to prevent a stale
	 *        byte from triggering a spurious IDLE immediately after enable.
	 *        Must be called while @c rx_mutex_ is held.
	 */
	static void arm_rx_dma()
	{
		// Flush any stale byte from RDR and clear error flags.
		usart3.usart_icr = usart_p::usart_icr_r::orecf_f()
		                 | usart_p::usart_icr_r::fecf_f()
		                 | usart_p::usart_icr_r::necf_f();
		usart3.usart_rqr = usart_p::usart_rqr_r::rxfrq_f();

		// Source: USART3 RDR (byte, fixed) → Dest: rx_buffer_[rx_fill_] (byte, increment)
		// DREQ = 0: source peripheral paces the transfer.
		gpdma1.gpdma_c1sar = gpdma_p::gpdma_cxsar_r::sa_f(reinterpret_cast<uint32_t>(&usart3.usart_rdr));
		gpdma1.gpdma_c1dar = gpdma_p::gpdma_cxdar_r::da_f(reinterpret_cast<uint32_t>(rx_buffer_[rx_fill_]));
		gpdma1.gpdma_c1br1 = gpdma_p::gpdma_cxbr1_r::bndt_f(static_cast<uint16_t>(rx_buffer_size));
		gpdma1.gpdma_c1tr1 = gpdma_p::gpdma_cxtr1_r::dinc_f(); // src fixed (default), dest increment
		gpdma1.gpdma_c1tr2 = gpdma_p::gpdma_cxtr2_r::reqsel_f(25); // USART3_RX, DREQ=0 (src paces)
		// Clear stale flags before enabling: reset_f() generates SUSPF, a leftover TCF
		// with TCIE would fire a spurious interrupt immediately on enable.
		gpdma1.gpdma_c1fcr = gpdma_p::gpdma_cxfcr_r::tcf_f()
		                   | gpdma_p::gpdma_cxfcr_r::suspf_f();
		gpdma1.gpdma_c1cr  = gpdma_p::gpdma_cxcr_r::tcie_f()
		                   | gpdma_p::gpdma_cxcr_r::en_f();

		// Clear IDLE and enable IDLEIE last, while the caller holds rx_mutex_
		// (BASEPRI = isr_priority). The ISR cannot fire until wait() atomically
		// releases the mutex, and the RM guarantees IDLE will not re-assert until
		// RXNE is set (a real byte is received) — so no spurious trigger is possible.
		usart3.usart_icr = usart_p::usart_icr_r::idlecf_f();
		usart3.usart_cr1_enabled |= usart_p::usart_cr1_enabled_r::idleie_f();
	}

	static inline uint8_t                 rx_buffer_[2][rx_buffer_size];
	static inline std::size_t             rx_count_[2]{};
	static inline int                     rx_fill_{0};    ///< Index of the buffer DMA is currently filling
	/// Sticky flag: a buffer is ready to consume. Written by the ISRs, read by the task: it must be
	/// atomic, otherwise the compiler may keep it in a register across wait() and never see the update.
	static inline std::atomic<bool>       rx_done_{false};
	static inline bool                    rx_armed_{false}; ///< True after the first arm_rx_dma() call
	static inline opsy::isr_lock             tx_mutex_{isr_priority};
	static inline opsy::isr_lock             rx_mutex_{isr_priority};
	static inline opsy::condition_variable tx_done_{isr_priority};
	static inline opsy::condition_variable rx_idle_{isr_priority};
};

} // namespace STM32H563
