// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    rs485.hpp
 * @author  Thomas Legrand
 * @brief   Isolated RS-485 port of the Bornier base board (MODBUS terminal block), as a module
 *
 *          | Signal | Pin | Function           |
 *          |--------|-----|--------------------|
 *          | DE     | PD4 | USART2_RTS/DE, AF7 |
 *          | TX     | PD5 | USART2_TX, AF7     |
 *          | RX     | PD6 | USART2_RX, AF7     |
 *
 *          Half duplex. The USART drives DE by itself around each frame. The receiver of the
 *          transceiver is always on: every byte sent comes back on RX, through the isolation
 *          and the line.
 *
 *          115200 baud, 8 data bits, no parity, 1 stop bit.
 *
 *          Frames move by DMA, both ways (GPDMA2: channel 0 receives, request usart2_rx;
 *          channel 1 sends, request usart2_tx; see docs of the board, DMA allocation). The CPU
 *          only starts a transfer and is told when it ends:
 *
 *          - send() returns once the last stop bit has left the pin (USART TC interrupt);
 *          - listen() arms the reception into a buffer; received() waits for the end of the
 *            frame: the line silent for the MODBUS inter-frame time (USART receiver timeout),
 *            or the buffer full (DMA transfer complete), or the deadline.
 *
 *          A sending has a deadline: twice its time on the line, in whole ticks of the RTOS clock,
 *          plus one for the tick under way. Past it the port fails: the sending is stopped, the
 *          board goes to its safe state (Safety::fault()), and the port stays down until the
 *          next reset of the MCU: send() and listen() then return at once, received() gives 0.
 *
 *          The calling task sleeps on a semaphore meanwhile: no polling. Its interrupts are at
 *          the drivers' level (opsy::scheduler::os_callable_priority), from which a semaphore may be
 *          released.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <span>
#include <type_traits>

#include <opsy.hpp>
#include <cortex_m.hpp>
#include <semaphore.hpp>

#include <STM32H523/gpdma.hpp>
#include <STM32H523/gpio.hpp>
#include <STM32H523/interrupts.hpp>
#include <STM32H523/rcc.hpp>
#include <STM32H523/usart.hpp>

namespace STM32H523
{

using mmio::atomic;

/**
 * @brief Isolated RS-485 port, on USART2, as a module.
 *
 *        All methods are static — no instance needed. init() and isrs are used by
 *        bornier::app; send(), listen() and received() are for one task at a time.
 *
 * @tparam Safety Puts the board in its safe state when the port fails, from the calling task: a
 *                static fault().
 */
template<typename Safety>
class rs485
{
public:

	/** @brief Whether the port failed: a sending did not end by its deadline. */
	static bool failed() { return failed_; }

	/** @brief Line errors seen by the receiver since the last call to @c take_errors(). */
	struct errors
	{
		bool framing; ///< A stop bit was read low
		bool noise;   ///< The three samples of a bit disagreed
		bool overrun; ///< A byte arrived before the previous one was read
	};

	/** @brief Configures the pins, USART2 and the two DMA channels. */
	static void init()
	{
		rcc.ahb1enr  |= rcc_p::ahb1enr_r::gpdma2en_f() | atomic;
		rcc.ahb2enr  |= rcc_p::ahb2enr_r::gpioden_f() | atomic;
		rcc.apb1lenr |= rcc_p::apb1lenr_r::usart2en_f() | atomic;

		gpiod.afrl <<= gpio_p::afrl_r::afsel4_f(7) || atomic;
		gpiod.afrl <<= gpio_p::afrl_r::afsel5_f(7) || atomic;
		gpiod.afrl <<= gpio_p::afrl_r::afsel6_f(7) || atomic;
		gpiod.moder <<= gpio_p::moder_r::mode4_f(0b10) || atomic;
		gpiod.moder <<= gpio_p::moder_r::mode5_f(0b10) || atomic;
		gpiod.moder <<= gpio_p::moder_r::mode6_f(0b10) || atomic;

		usart2.brr  = usart_p::brr_r(clock_hz / baud_rate);
		usart2.rtor = usart_p::rtor_r::rto_f(silence_bits);
		usart2.cr2  = usart_p::cr2_r::rtoen_f();

		// DEM: DE driven by the USART, active high. DMAR, DMAT: bytes move by DMA.
		usart2.cr3 = usart_p::cr3_r::dem_f() | usart_p::cr3_r::dmar_f() | usart_p::cr3_r::dmat_f();

		// DEAT, DEDT: DE rises 8 sample times (half a bit) before the start bit and falls as
		// long after the stop bit.
		usart2.cr1 = usart_p::cr1_r::deat_f(8)
		                 | usart_p::cr1_r::dedt_f(8)
		                 | usart_p::cr1_r::te_f()
		                 | usart_p::cr1_r::re_f()
		                 | usart_p::cr1_r::ue_f();

		// Receive: one byte from RDR per request, to an incrementing buffer.
		rx().tr1 = gpdma_p::c_c::tr1_r::dinc_f();
		rx().tr2 = gpdma_p::c_c::tr2_r::reqsel_f(usart2_rx_request);
		rx().sar = gpdma_p::c_c::sar_r::sa_f(reinterpret_cast<std::uint32_t>(&usart2.rdr));

		// Send: one byte per request, from an incrementing buffer to TDR (the request is the
		// destination's).
		tx().tr1 = gpdma_p::c_c::tr1_r::sinc_f();
		tx().tr2 = gpdma_p::c_c::tr2_r::reqsel_f(usart2_tx_request) | gpdma_p::c_c::tr2_r::dreq_f();
		tx().dar = gpdma_p::c_c::dar_r::da_f(reinterpret_cast<std::uint32_t>(&usart2.tdr));

		for (const auto irq : {USART2_IRQn, GPDMA2_CH0_IRQn})
		{
			opsy::cortex_m::set_priority(irq, opsy::scheduler::os_callable_priority);
			opsy::cortex_m::enable_interrupt(irq);
		}
	}

	/**
	 * @brief Sends @p data and returns once its last stop bit has left the pin.
	 *
	 *        The calling task sleeps meanwhile. @p data must stay valid until then. Past the
	 *        deadline, the port fails (see the top of this file).
	 */
	static void send(std::span<const std::uint8_t> data)
	{
		if (data.empty() || failed_)
			return;
		usart2.icr = usart_p::icr_r::tccf_f();
		clear_flags(tx());
		tx().sar = gpdma_p::c_c::sar_r::sa_f(reinterpret_cast<std::uint32_t>(data.data()));
		tx().br1 = gpdma_p::c_c::br1_r::bndt_f(static_cast<std::uint16_t>(data.size()));
		tx().cr  = gpdma_p::c_c::cr_r::en_f();
		usart2.cr1 |= usart_p::cr1_r::tcie_f() | atomic;
		if (sent_.try_acquire_for(opsy::duration(2 * frame_ms(data.size()) + 2)))
			return;
		usart2.cr1 <<= usart_p::cr1_r::tcie_f(false) || atomic;
		stop(tx());
		failed_ = true;
		Safety::fault();
	}

	/**
	 * @brief Arms the reception of one frame into @p buffer.
	 *
	 *        Bytes are stored as they arrive, until the frame ends or the buffer is full;
	 *        received() then tells how many came. @p buffer must stay valid until then.
	 */
	static void listen(std::span<std::uint8_t> buffer)
	{
		if (failed_)
			return;
		stop(rx());
		usart2.rqr = usart_p::rqr_r::rxfrq_f(); // drops a byte left from before
		usart2.icr = usart_p::icr_r::rtocf_f();
		(void)received_.try_acquire();          // an end of frame left from before
		listening_ = static_cast<std::uint16_t>(buffer.size());
		clear_flags(rx());
		rx().dar = gpdma_p::c_c::dar_r::da_f(reinterpret_cast<std::uint32_t>(buffer.data()));
		rx().br1 = gpdma_p::c_c::br1_r::bndt_f(listening_);
		rx().cr  = gpdma_p::c_c::cr_r::en_f() | gpdma_p::c_c::cr_r::tcie_f();
		usart2.cr1 |= usart_p::cr1_r::rtoie_f() | atomic;
	}

	/**
	 * @brief Waits for the end of the frame armed by listen(), at most @p timeout.
	 *
	 * @return The number of bytes received, 0 if none came before the deadline or the port
	 *         failed.
	 */
	static std::size_t received(opsy::duration timeout)
	{
		if (failed_)
			return 0;
		(void)received_.try_acquire_for(timeout);
		usart2.cr1 <<= usart_p::cr1_r::rtoie_f(false) || atomic;
		stop(rx());
		return listening_ - rx().br1.load().bndt();
	}

	/** @brief Tells whether the receiver sees the line idle, between two frames. */
	static bool line_idle() { return !usart2.isr.load().busy(); }

	/** @brief Returns the line errors seen since the last call, and clears them. */
	static errors take_errors()
	{
		const auto status = usart2.isr.load();
		const errors seen{status.fe(), status.ne(), status.ore()};
		usart2.icr = usart_p::icr_r::fecf_f() | usart_p::icr_r::necf_f() | usart_p::icr_r::orecf_f();
		return seen;
	}

private:

	static constexpr uint32_t clock_hz  = 250'000'000; ///< APB1, see clock.hpp
	static constexpr uint32_t baud_rate = 115'200;

	// MODBUS RTU end of frame: 3.5 characters of silence, fixed at 1.75 ms above 19200 baud.
	static constexpr uint32_t silence_bits = baud_rate > 19'200 ? baud_rate * 175 / 100'000 + 1 : 35;

	/// Time of @p bytes on the line, ms, rounded up: 10 bits each.
	static constexpr uint32_t frame_ms(std::size_t bytes)
	{
		return static_cast<uint32_t>((10 * bytes * 1000 + baud_rate - 1) / baud_rate);
	}

	static constexpr std::uint8_t usart2_rx_request = 23; ///< GPDMA request, RM0481 table 142
	static constexpr std::uint8_t usart2_tx_request = 24;

	using channel = std::remove_reference_t<decltype(gpdma2.c[0])>;

	static channel& rx() { return gpdma2.c[0]; }
	static channel& tx() { return gpdma2.c[1]; }

	static void clear_flags(channel& dma)
	{
		dma.fcr = gpdma_p::c_c::fcr_r::tcf_f() | gpdma_p::c_c::fcr_r::htf_f()
		                | gpdma_p::c_c::fcr_r::dtef_f() | gpdma_p::c_c::fcr_r::ulef_f()
		                | gpdma_p::c_c::fcr_r::usef_f() | gpdma_p::c_c::fcr_r::suspf_f()
		                | gpdma_p::c_c::fcr_r::tof_f();
	}

	/// Stops a channel that may still run: a suspended channel is reset at once (RM0481 §16.4.3).
	static void stop(channel& dma)
	{
		if (!dma.cr.load().en())
			return;
		dma.cr = dma.cr.load() | gpdma_p::c_c::cr_r::susp_f();
		while (!dma.sr.load().suspf()) {}   // a few cycles: the current single transfer ends
		dma.cr = gpdma_p::c_c::cr_r::reset_f();
	}

	/// End of sending (TC) or end of frame (receiver timeout).
	static void usart_isr()
	{
		const auto status = usart2.isr.load();
		if (status.tc() && usart2.cr1.load().tcie())
		{
			usart2.cr1 <<= usart_p::cr1_r::tcie_f(false) || atomic;
			usart2.icr = usart_p::icr_r::tccf_f();
			sent_.release();
		}
		if (status.rtof())
		{
			usart2.icr = usart_p::icr_r::rtocf_f();
			received_.release();
		}
	}

	/// Buffer full: the frame is longer than the buffer, or exactly as long.
	static void rx_dma_isr()
	{
		clear_flags(rx());
		received_.release();
	}

	static inline opsy::binary_semaphore sent_{0};
	static inline opsy::binary_semaphore received_{0};
	static inline std::uint16_t listening_ = 0;
	static inline bool failed_ = false;

public:

	/** @brief The handlers of the port: USART2 (end of frame, end of sending), GPDMA2 channel 0 (buffer full). */
	static constexpr auto isrs = []<typename Table>(const Table& table) -> Table
	{
		return table.template with<USART2_IRQn, usart_isr>().template with<GPDMA2_CH0_IRQn, rx_dma_isr>();
	};
};

} // namespace STM32H523
