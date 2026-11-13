// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    dma_load.hpp
 * @brief   Competing DMA traffic for the step generator test: endless memory-to-memory copies
 *
 *          Stands for the transfers of the EtherCAT slave controller interface, to measure
 *          what the step DMA leaves to them and whether the steps suffer. One channel, lowest
 *          priority, copies a 4 KB block over and over (linked list pointing to itself),
 *          16-word bursts, on GPDMA2 (the controller the slave controller would use) or on
 *          GPDMA1 (the step generator's own controller, the hardest case). A transfer complete
 *          interrupt counts the blocks.
 ******************************************************************************
 */

#pragma once

#include <array>
#include <atomic>
#include <cstdint>

#include <cortex_m.hpp>

#include <STM32H563/gpdma.hpp>
#include <STM32H563/interrupts.hpp>
#include <STM32H563/rcc.hpp>

namespace STM32H563
{

class dma_load
{
public:

	enum class controller : uint8_t { none, on_gpdma2, on_gpdma1 };

	static constexpr uint32_t block_bytes = 4096;

	static void start(controller c, opsy::isr_priority priority)
	{
		stop();
		controller_ = c;
		blocks_.store(0, std::memory_order_relaxed);
		switch (c)
		{
		case controller::none:   break;
		case controller::on_gpdma2: start_channel(gpdma2.c[channel_gpdma2], GPDMA2_CH0_IRQn, priority); break;
		case controller::on_gpdma1: start_channel(gpdma1.c[channel_gpdma1], GPDMA1_CH5_IRQn, priority); break;
		}
	}

	static void stop()
	{
		switch (controller_)
		{
		case controller::none:   break;
		case controller::on_gpdma2: stop_channel(gpdma2.c[channel_gpdma2], GPDMA2_CH0_IRQn); break;
		case controller::on_gpdma1: stop_channel(gpdma1.c[channel_gpdma1], GPDMA1_CH5_IRQn); break;
		}
		controller_ = controller::none;
	}

	/// Blocks copied since start.
	[[nodiscard]] static uint32_t blocks() { return blocks_.load(std::memory_order_relaxed); }

	static void gpdma2_isr() { isr(gpdma2.c[channel_gpdma2]); }
	static void gpdma1_isr() { isr(gpdma1.c[channel_gpdma1]); }

private:

	static constexpr unsigned channel_gpdma2 = 0; ///< Channel used on GPDMA2
	static constexpr unsigned channel_gpdma1 = 5; ///< Channel used on GPDMA1

	struct lli
	{
		uint32_t br1;
		uint32_t sar;
		uint32_t dar;
	};

	static void start_channel(gpdma_p::c_c& channel, uint32_t irq, opsy::isr_priority priority)
	{
		using r = gpdma_p::c_c;
		auto const address = [](auto const* p) { return reinterpret_cast<uint32_t>(p); };
		rcc.ahb1enr |= (rcc_p::ahb1enr_r::gpdma1en_f() | rcc_p::ahb1enr_r::gpdma2en_f()) | mmio::atomic;

		lli_ = { block_bytes, address(source_.data()), address(destination_.data()) };
		// Words, 16-beat bursts, both sides incremented, software request: as fast as allowed
		channel.tr1 = r::tr1_r::sdw_log2_f(2) | r::tr1_r::sinc_f() | r::tr1_r::sbl_1_f(15)
		                       | r::tr1_r::ddw_log2_f(2) | r::tr1_r::dinc_f() | r::tr1_r::dbl_1_f(15);
		channel.tr2 = r::tr2_r::swreq_f();
		channel.br1 = r::br1_r::bndt_f(static_cast<uint16_t>(block_bytes));
		channel.sar = r::sar_r::sa_f(address(source_.data()));
		channel.dar = r::dar_r::da_f(address(destination_.data()));
		channel.lbar = r::lbar_r::lba_f(static_cast<uint16_t>(address(&lli_) >> 16));
		channel.llr = r::llr_r::ub1_f() | r::llr_r::usa_f() | r::llr_r::uda_f()
		                       | r::llr_r::la_f(static_cast<uint16_t>((address(&lli_) & 0xFFFFu) >> 2));
		channel.fcr = r::fcr_r::tcf_f();

		opsy::cortex_m::set_priority(irq, priority);
		opsy::cortex_m::clear_pending(irq);
		opsy::cortex_m::enable_interrupt(irq);
		// Lowest priority: the step channels, at the highest, go first
		channel.cr = r::cr_r::prio_f(0) | r::cr_r::tcie_f() | r::cr_r::en_f();
	}

	static void stop_channel(gpdma_p::c_c& channel, uint32_t irq)
	{
		opsy::cortex_m::disable_interrupt(irq);
		if (!channel.cr.load().en())
			return;
		channel.cr = gpdma_p::c_c::cr_r::susp_f();
		for (uint32_t i = 0; i < 100'000 && !channel.sr.load().suspf(); ++i) {}
		channel.cr = gpdma_p::c_c::cr_r::reset_f();
	}

	static void isr(gpdma_p::c_c& channel)
	{
		channel.fcr = gpdma_p::c_c::fcr_r::tcf_f();
		blocks_.fetch_add(1, std::memory_order_relaxed);
	}

	static inline controller controller_ = controller::none;
	static inline std::atomic<uint32_t> blocks_{0};
	alignas(4) static inline lli lli_{};
	alignas(4) static inline std::array<uint32_t, block_bytes / 4> source_{};
	alignas(4) static inline std::array<uint32_t, block_bytes / 4> destination_{};
};

} // namespace STM32H563
