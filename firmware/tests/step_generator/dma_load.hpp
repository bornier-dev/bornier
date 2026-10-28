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
		case controller::on_gpdma2: start_channel<channel_gpdma2>(gpdma2, GPDMA2_CH0_IRQn, priority); break;
		case controller::on_gpdma1: start_channel<channel_gpdma1>(gpdma1, GPDMA1_CH5_IRQn, priority); break;
		}
	}

	static void stop()
	{
		switch (controller_)
		{
		case controller::none:   break;
		case controller::on_gpdma2: stop_channel<channel_gpdma2>(gpdma2, GPDMA2_CH0_IRQn); break;
		case controller::on_gpdma1: stop_channel<channel_gpdma1>(gpdma1, GPDMA1_CH5_IRQn); break;
		}
		controller_ = controller::none;
	}

	/// Blocks copied since start.
	[[nodiscard]] static uint32_t blocks() { return blocks_.load(std::memory_order_relaxed); }

	static void gpdma2_isr() { isr<channel_gpdma2>(gpdma2); }
	static void gpdma1_isr() { isr<channel_gpdma1>(gpdma1); }

private:

	/// Registers of one GPDMA channel, as members of gpdma_p.
	template<auto cr, auto sr, auto fcr, auto tr1, auto tr2, auto br1, auto sar, auto dar, auto lbar, auto llr>
	struct channel
	{
		static constexpr auto cr_ = cr;
		static constexpr auto sr_ = sr;
		static constexpr auto fcr_ = fcr;
		static constexpr auto tr1_ = tr1;
		static constexpr auto tr2_ = tr2;
		static constexpr auto br1_ = br1;
		static constexpr auto sar_ = sar;
		static constexpr auto dar_ = dar;
		static constexpr auto lbar_ = lbar;
		static constexpr auto llr_ = llr;
	};

	using channel_gpdma2 = channel<&gpdma_p::gpdma_c0cr, &gpdma_p::gpdma_c0sr, &gpdma_p::gpdma_c0fcr,
	                               &gpdma_p::gpdma_c0tr1, &gpdma_p::gpdma_c0tr2, &gpdma_p::gpdma_c0br1,
	                               &gpdma_p::gpdma_c0sar, &gpdma_p::gpdma_c0dar, &gpdma_p::gpdma_c0lbar,
	                               &gpdma_p::gpdma_c0llr>;
	using channel_gpdma1 = channel<&gpdma_p::gpdma_c5cr, &gpdma_p::gpdma_c5sr, &gpdma_p::gpdma_c5fcr,
	                               &gpdma_p::gpdma_c5tr1, &gpdma_p::gpdma_c5tr2, &gpdma_p::gpdma_c5br1,
	                               &gpdma_p::gpdma_c5sar, &gpdma_p::gpdma_c5dar, &gpdma_p::gpdma_c5lbar,
	                               &gpdma_p::gpdma_c5llr>;

	struct lli
	{
		uint32_t br1;
		uint32_t sar;
		uint32_t dar;
	};

	template<typename TChannel>
	static void start_channel(gpdma_p& dma, uint32_t irq, opsy::isr_priority priority)
	{
		using r = gpdma_p;
		auto const address = [](auto const* p) { return reinterpret_cast<uint32_t>(p); };
		rcc.rcc_ahb1enr |= (rcc_p::rcc_ahb1enr_r::gpdma1en_f() | rcc_p::rcc_ahb1enr_r::gpdma2en_f()) | opsy::utility::atomic;

		lli_ = { block_bytes, address(source_.data()), address(destination_.data()) };
		// Words, 16-beat bursts, both sides incremented, software request: as fast as allowed
		(dma.*TChannel::tr1_) = r::gpdma_cxtr1_r::sdw_log2_f(2) | r::gpdma_cxtr1_r::sinc_f() | r::gpdma_cxtr1_r::sbl_1_f(15)
		                       | r::gpdma_cxtr1_r::ddw_log2_f(2) | r::gpdma_cxtr1_r::dinc_f() | r::gpdma_cxtr1_r::dbl_1_f(15);
		(dma.*TChannel::tr2_) = r::gpdma_cxtr2_r::swreq_f();
		(dma.*TChannel::br1_) = r::gpdma_cxbr1_r::bndt_f(static_cast<uint16_t>(block_bytes));
		(dma.*TChannel::sar_) = r::gpdma_cxsar_r::sa_f(address(source_.data()));
		(dma.*TChannel::dar_) = r::gpdma_cxdar_r::da_f(address(destination_.data()));
		(dma.*TChannel::lbar_) = r::gpdma_cxlbar_r::lba_f(static_cast<uint16_t>(address(&lli_) >> 16));
		(dma.*TChannel::llr_) = r::gpdma_cxllr_r::ub1_f() | r::gpdma_cxllr_r::usa_f() | r::gpdma_cxllr_r::uda_f()
		                       | r::gpdma_cxllr_r::la_f(static_cast<uint16_t>((address(&lli_) & 0xFFFFu) >> 2));
		(dma.*TChannel::fcr_) = r::gpdma_cxfcr_r::tcf_f();

		opsy::cortex_m::set_priority(irq, priority);
		opsy::cortex_m::clear_pending(irq);
		opsy::cortex_m::enable_interrupt(irq);
		// Lowest priority: the step channels, at the highest, go first
		(dma.*TChannel::cr_) = r::gpdma_cxcr_r::prio_f(0) | r::gpdma_cxcr_r::tcie_f() | r::gpdma_cxcr_r::en_f();
	}

	template<typename TChannel>
	static void stop_channel(gpdma_p& dma, uint32_t irq)
	{
		opsy::cortex_m::disable_interrupt(irq);
		if (!(dma.*TChannel::cr_).load().en())
			return;
		(dma.*TChannel::cr_) = gpdma_p::gpdma_cxcr_r::susp_f();
		for (uint32_t i = 0; i < 100'000 && !(dma.*TChannel::sr_).load().suspf(); ++i) {}
		(dma.*TChannel::cr_) = gpdma_p::gpdma_cxcr_r::reset_f();
	}

	template<typename TChannel>
	static void isr(gpdma_p& dma)
	{
		(dma.*TChannel::fcr_) = gpdma_p::gpdma_cxfcr_r::tcf_f();
		blocks_.fetch_add(1, std::memory_order_relaxed);
	}

	static inline controller controller_ = controller::none;
	static inline std::atomic<uint32_t> blocks_{0};
	alignas(4) static inline lli lli_{};
	alignas(4) static inline std::array<uint32_t, block_bytes / 4> source_{};
	alignas(4) static inline std::array<uint32_t, block_bytes / 4> destination_{};
};

} // namespace STM32H563
