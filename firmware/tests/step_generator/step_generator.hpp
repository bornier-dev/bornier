// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    step_generator.hpp
 * @brief   Four STEP/DIR axes from TIM1 slots, a DMA burst per slot and a phase accumulator
 *
 * @par Principle
 *   TIM1 runs at the maximum step rate (one counter period = one slot), PWM mode 1, upcounting,
 *   CCR and ARR preload on. In each slot every axis emits zero or one step: CCRx = 0 holds the
 *   output low, CCRx = pulse width gives one pulse at the start of the slot. On each update
 *   event a DMA burst writes ARR, RCR and CCR1..CCR4 through TIMx_DMAR, so that every slot
 *   carries its own length. The buffer holds six bytes per slot; GPDMA reads bytes and writes
 *   words padded with zeros.
 *
 *   Once per cycle (the SYNC0 period), the next cycle is filled with a phase accumulator per
 *   axis: N steps spread over the usable slots of the cycle, the remainder carried over to the
 *   next cycle. DIR is constant during a cycle. It is written by DMA to GPIOE_BSRR on a compare
 *   of TIM5, at a fixed time after SYNC0, so that the last step of the previous cycle is
 *   followed by dirhold and the first step of the new one is preceded by dirsetup.
 *
 *   SYNC0 resets TIM5 through its ETR input. The first SYNC0 starts TIM1 (trigger mode on
 *   tim5_trgo, ITR4); TIM1 then runs free and is never reset, so no slot is ever cut short or
 *   played twice.
 *
 * @par Phase lock
 *   Each cycle the DMA position, TIM1 and TIM5 give, to the timer tick, when the first slot of
 *   the cycle started after SYNC0. The drift per cycle follows from the last two readings; the
 *   next cycle lengthens or shortens that many slots by one tick (4 ns), spread evenly, so that
 *   the slot grid stays on SYNC0 without any gap in the pulses.
 *
 * @par Closed loop on the steps
 *   The step count of the next cycle is the target minus the position already scheduled, so a
 *   step that did not fit is emitted in the following cycle and the position never drifts.
 *
 * @par Resources (same as the Bornier base board)
 *   | Axis | STEP          | DIR  |
 *   |------|---------------|------|
 *   | 0    | PE9,  TIM1_CH1 | PE10 |
 *   | 1    | PE14, TIM1_CH4 | PE15 |
 *   | 2    | PE13, TIM1_CH3 | PE12 |
 *   | 3    | PE11, TIM1_CH2 | PE8  |
 *
 *   SYNC0 on PA4 (TIM5_ETR). GPDMA1 channel 2: step slots, on tim1_upd_dma. Channels 3 and 4:
 *   DIR. GPDMA reads a memory source ahead into its FIFO as soon as a transfer ends, which
 *   would take the DIR word of the next cycle before the fill has written it. So channel 3, on
 *   tim5_cc1_dma, only copies a dummy word, and its transfer complete triggers channel 4, whose
 *   reads are each gated by that trigger (software request, trigger at burst level): it reads
 *   the DIR word at that moment and writes it to GPIOE_BSRR. TIM5 CC2 interrupt runs the fill,
 *   after the DIR write of the cycle.
 ******************************************************************************
 */

#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstring>

#include <cortex_m.hpp>

#include <STM32H563/gpdma.hpp>
#include <STM32H563/gpio.hpp>
#include <STM32H563/rcc.hpp>
#include <STM32H563/tim.hpp>

namespace STM32H563
{

using opsy::utility::atomic;

class step_generator
{
public:

	static constexpr std::size_t axis_count = 4;

	/// Timer kernel clock: TIM1 on APB2, TIM5 on APB1, both at 250 MHz (prescalers at 1).
	static constexpr uint32_t kernel_hz = 250'000'000;

	/// Slots in the DMA ring. Must hold two cycles plus margin: up to 2000 slots per cycle.
	static constexpr uint32_t ring_slots = 4096;
	static_assert((ring_slots & (ring_slots - 1)) == 0, "ring index wraps with a mask");

	/// Cycles after which the phase lock has settled (statistics start there).
	static constexpr uint32_t lock_cycles = 32;

	/// Bytes per slot: the DMA burst writes ARR, RCR and CCR1..CCR4.
	static constexpr uint32_t slot_bytes = 6;

	/// Upper bound of the delay from TIM5 CC1 to the DIR write through two DMA channels.
	static constexpr uint32_t dir_latency_ns = 500;

	/// Slots between the DMA position and the slot being played: at the update that starts
	/// slot j, the burst writes the preload of slot j + 1.
	static constexpr uint32_t pipeline_slots = 2;

	struct config
	{
		uint32_t slot_rate_hz = 1'000'000; ///< f_max: slots per second, at most one step per slot
		uint32_t cycle_ns = 1'000'000;     ///< SYNC0 period
		uint32_t steplen_ns = 500;         ///< STEP high time
		uint32_t stepspace_ns = 500;       ///< STEP low time between two steps
		uint32_t dirsetup_ns = 1000;       ///< DIR stable before the first step
		uint32_t dirhold_ns = 1000;        ///< DIR stable after the last step
	};

	/// Values derived from a config; all times in timer ticks or slots.
	struct derived
	{
		uint32_t prescaler = 1;      ///< TIM1 clock divider
		uint32_t slot_ticks = 0;     ///< TIM1 ticks per slot (ARR + 1), at most 253 (one more when corrected)
		uint32_t cycle_slots = 0;    ///< S, slots per SYNC0 period
		uint32_t pulse_ticks = 0;    ///< steplen in TIM1 ticks
		uint32_t pulse_slots = 0;    ///< slots covered by a pulse
		uint32_t pulse_last = 0;     ///< CCR of the last slot of a pulse, in (0, slot_ticks]
		uint32_t gap_slots = 0;      ///< minimum slots from one step to the next
		uint32_t dir_ticks = 0;      ///< DIR write, TIM5 ticks after SYNC0
		uint32_t guard_slots = 0;    ///< slots kept empty after SYNC0 on a direction change
		uint32_t fill_ticks = 0;     ///< fill interrupt, TIM5 ticks after SYNC0
		uint32_t max_steps = 0;      ///< steps per cycle an axis can take without reversal
	};

	enum class error
	{
		none,
		rate,       ///< slot rate does not divide the kernel clock into at most 253 ticks
		cycle,      ///< not an integer number of slots per cycle, or too many for the ring
		pulse,      ///< steplen + stepspace does not fit, or pulse longer than a cycle allows
	};

	struct axis_stats
	{
		int32_t position = 0;   ///< steps scheduled, signed (all of them are played)
		uint32_t pulses = 0;    ///< steps scheduled, both directions
		uint32_t deferred = 0;  ///< cycles that could not take all the requested steps
		uint32_t reversals = 0; ///< direction changes
	};

	struct stats
	{
		std::array<axis_stats, axis_count> axes{};
		uint32_t cycles = 0;          ///< cycles filled
		uint32_t unsynced = 0;        ///< fill interrupts without a SYNC0 since the previous one
		uint32_t resyncs = 0;         ///< phase lost by more than half a cycle: grid locked again
		int32_t phase_min = 0;        ///< phase error once locked, timer kernel ticks (4 ns)
		int32_t phase_max = 0;
		int32_t correction_min = 0;   ///< slots lengthened (+) or shortened (-) by one tick, per cycle
		int32_t correction_max = 0;
		uint32_t dma_errors = 0;      ///< transfer, link or user setting errors on either channel
		uint32_t fill_cycles_max = 0; ///< CPU cycles of one fill, maximum
		uint32_t fill_max_cycle = 0;  ///< index of the cycle with the longest fill
		/// Longest fill split: placement and clear, then each axis, in CPU cycles
		std::array<uint32_t, 2 + axis_count> fill_max_split{};
		uint64_t fill_cycles_sum = 0; ///< CPU cycles of all fills
		uint32_t fill_end_max = 0;    ///< end of fill, TIM5 ticks after SYNC0, maximum
		uint32_t position_retries = 0; ///< DMA position readings taken again (FIFO moving, burst in progress)
	};

	/**
	 * @brief Computes the derived values of a configuration.
	 * @return error::none and @p out filled, or the reason it is not usable.
	 */
	static error derive(config const& c, derived& out)
	{
		derived d;
		// Smallest prescaler giving an integer number of ticks per slot, at most 253 so that a
		// slot lengthened by one tick still has ARR <= 253 < 255: a byte holds any CCR and
		// ARR, and 255 (> ARR), which holds the output high for a whole slot, marks the slots a
		// pulse continues after: the last slot of a pulse is never 255.
		d.prescaler = 0;
		for (uint32_t p = 1; p <= 64; ++p)
		{
			if (c.slot_rate_hz == 0 || kernel_hz % (p * c.slot_rate_hz) != 0)
				continue;
			if (kernel_hz / (p * c.slot_rate_hz) <= 253)
			{
				d.prescaler = p;
				break;
			}
		}
		if (d.prescaler == 0)
			return error::rate;
		d.slot_ticks = kernel_hz / (d.prescaler * c.slot_rate_hz);

		uint64_t const slots = uint64_t{c.cycle_ns} * c.slot_rate_hz;
		if (slots % 1'000'000'000u != 0)
			return error::cycle;
		d.cycle_slots = static_cast<uint32_t>(slots / 1'000'000'000u);
		if (d.cycle_slots < 8 || 2 * d.cycle_slots + 64 > ring_slots)
			return error::cycle;

		uint32_t const tick_ns_x1000 = 1'000'000u / (kernel_hz / 1'000'000u) * d.prescaler; // ps per tick
		auto const ticks = [&](uint32_t ns) { return (ns * 1000u + tick_ns_x1000 - 1) / tick_ns_x1000; };
		// A slot may be one tick short (phase lock): one tick of margin on each slot a pulse
		// covers entirely, and on the space after it.
		d.pulse_ticks = std::max<uint32_t>(1, ticks(c.steplen_ns));
		d.pulse_slots = (d.pulse_ticks + d.slot_ticks - 1) / d.slot_ticks;
		d.pulse_ticks += d.pulse_slots - 1;
		d.pulse_slots = (d.pulse_ticks + d.slot_ticks - 1) / d.slot_ticks;
		d.pulse_last = d.pulse_ticks - (d.pulse_slots - 1) * d.slot_ticks;
		d.gap_slots = std::max<uint32_t>(1, (d.pulse_ticks + ticks(c.stepspace_ns) + 1 + d.slot_ticks - 1) / d.slot_ticks);

		uint32_t const slot_ns = c.cycle_ns / d.cycle_slots;
		// The last pulse of a cycle ends at the cycle boundary at the latest, plus one slot of
		// margin for the phase error of the grid: DIR changes dirhold after that.
		d.dir_ticks = (slot_ns + c.dirhold_ns + 40u) / 4u;
		// The DMA chain writes DIR a little after TIM5 CC1: dir_latency_ns of margin
		d.guard_slots = (slot_ns + c.dirhold_ns + 40u + dir_latency_ns + c.dirsetup_ns + slot_ns - 1) / slot_ns + 1;
		d.fill_ticks = d.dir_ticks + 250; // 1 us after the DIR write

		uint32_t const reserved = d.guard_slots + d.pulse_slots - 1;
		if (reserved + d.gap_slots >= d.cycle_slots)
			return error::pulse;
		d.max_steps = (d.cycle_slots - reserved) / d.gap_slots;
		out = d;
		return error::none;
	}

	/**
	 * @brief Configures pins, TIM1, TIM5 and both DMA channels, and starts them.
	 *
	 *        The outputs stay low until the first fill. The slot grid locks on the first SYNC0.
	 *        Call @c derive() first: @p c must be valid.
	 *
	 * @param fill_priority priority of the TIM5 interrupt that runs the fill
	 */
	static void start(config const& c, opsy::isr_priority fill_priority)
	{
		stop();
		config_ = c;
		(void)derive(c, d_);
		stats_ = {};
		state_ = {};
		clear_slots(0, ring_slots);
		dir_bits_ = (1u << axis_count) - 1; // all forward, as axis_state::forward
		for (auto& w : dir_ring_)
			w = dir_word();

		enable_clocks();
		configure_pins();
		configure_tim1();
		configure_tim5();
		configure_dma();

		opsy::cortex_m::set_priority(TIM5_IRQn, fill_priority);
		opsy::cortex_m::clear_pending(TIM5_IRQn);
		opsy::cortex_m::enable_interrupt(TIM5_IRQn);

		// TIM1 is started by the first SYNC0 (trigger mode sets CEN)
		tim5.tim5_cr1 = tim5_p::tim5_cr1_r::urs_f() | tim5_p::tim5_cr1_r::cen_f();
	}

	/// Stops the timers and the DMA channels, outputs low.
	static void stop()
	{
		opsy::cortex_m::disable_interrupt(TIM5_IRQn);
		if (rcc.rcc_apb2enr.load().tim1en())
		{
			tim1.tim1_cr1 = tim1_p::tim1_cr1_r::cen_f(false);
			tim1.tim1_dier = tim1_p::tim1_dier_r::ude_f(false);
			tim1.tim1_ccr1 = tim1_p::tim1_ccr1_r(0);
			tim1.tim1_ccr2 = tim1_p::tim1_ccr2_r(0);
			tim1.tim1_ccr3 = tim1_p::tim1_ccr3_r(0);
			tim1.tim1_ccr4 = tim1_p::tim1_ccr4_r(0);
			tim1.tim1_egr = tim1_p::tim1_egr_r::ug_f();
		}
		if (rcc.rcc_apb1lenr.load().tim5en())
		{
			tim5.tim5_cr1 = tim5_p::tim5_cr1_r::cen_f(false);
			tim5.tim5_dier = tim5_p::tim5_dier_r(0);
		}
		if (rcc.rcc_ahb1enr.load().gpdma1en())
		{
			abort_channel(gpdma1.gpdma_c2cr, gpdma1.gpdma_c2sr);
			abort_channel(gpdma1.gpdma_c3cr, gpdma1.gpdma_c3sr);
			abort_channel(gpdma1.gpdma_c4cr, gpdma1.gpdma_c4sr);
		}
	}

	/**
	 * @brief TIM5 interrupt: fills the next cycle.
	 *
	 * @param targets callable returning the target position of each axis at the end of the
	 *        next cycle, in steps (std::array<int32_t, axis_count>). Called once per SYNC0;
	 *        the steps of the next cycle are the target minus the position already scheduled.
	 *        Its run time is not counted in the fill statistics.
	 * @return false when the interrupt was not a fill (no SYNC0 since the previous one).
	 */
	template<typename TTargets>
	static bool fill(TTargets&& targets)
	{
		auto const sr = tim5.tim5_sr.load();
		tim5.tim5_sr = ~tim5_p::tim5_sr_r(tim5_p::tim5_sr_r::cc2if_f() | tim5_p::tim5_sr_r::tif_f());
		if (!sr.tif())
		{
			++stats_.unsynced;
			return false;
		}
		std::array<int32_t, axis_count> const next = targets();
		auto const t0 = cycle_counter();

		check_dma_errors();
		lock_phase();

		uint32_t const start = state_.next_start;
		uint32_t const n = d_.cycle_slots;
		clear_slots(start, n);
		apply_correction(start, state_.correction);

		std::array<uint32_t, 2 + axis_count> split{};
		split[0] = cycle_counter() - t0;
		for (std::size_t a = 0; a < axis_count; ++a)
		{
			auto const ta = cycle_counter();
			fill_axis(a, start, next[a]);
			split[2 + a] = cycle_counter() - ta;
		}

		// DIR of the next cycle: the DIR channel has already written the word of this cycle.
		dir_ring_[dir_index()] = dir_word();

		state_.next_start = start + n;
		++stats_.cycles;

		auto const elapsed = cycle_counter() - t0;
		if (elapsed > stats_.fill_cycles_max)
		{
			stats_.fill_cycles_max = elapsed;
			stats_.fill_max_cycle = stats_.cycles - 1;
			stats_.fill_max_split = split;
		}
		stats_.fill_cycles_sum += elapsed;
		stats_.fill_end_max = std::max(stats_.fill_end_max, static_cast<uint32_t>(tim5.tim5_cnt.load().cnt()));
		return true;
	}

	[[nodiscard]] static stats const& statistics() { return stats_; }
	[[nodiscard]] static derived const& values() { return d_; }

	/// DWT cycle counter, enabled on first use.
	static uint32_t cycle_counter()
	{
		return *reinterpret_cast<volatile uint32_t*>(dwt_cyccnt);
	}

	static void enable_cycle_counter()
	{
		auto& demcr = *reinterpret_cast<volatile uint32_t*>(scb_demcr);
		auto& ctrl = *reinterpret_cast<volatile uint32_t*>(dwt_ctrl);
		demcr = demcr | (1u << 24); // TRCENA
		ctrl = ctrl | 1u;            // CYCCNTENA
	}

private:

	// Core debug registers: not in the device SVD.
	static constexpr uint32_t scb_demcr = 0xE000EDFCu;
	static constexpr uint32_t dwt_ctrl = 0xE0001000u;
	static constexpr uint32_t dwt_cyccnt = 0xE0001004u;

	/// Byte of each axis in a slot: CCR1..CCR4 order of the DMA burst.
	static constexpr std::array<std::size_t, axis_count> channel_of_axis{ 0, 3, 2, 1 };
	/// DIR pin of each axis, on GPIOE.
	static constexpr std::array<uint32_t, axis_count> dir_pin{ 10, 15, 12, 8 };

	static constexpr uint32_t dir_ring_words = 4;

	struct axis_state
	{
		uint32_t acc = 0;        ///< phase accumulator, in [0, usable slots)
		uint32_t last_step = 0;  ///< absolute slot of the last step
		bool has_last = false;
		bool forward = true;     ///< direction of the cycle being filled
	};

	struct run_state
	{
		std::array<axis_state, axis_count> axes{};
		uint32_t next_start = 0;    ///< absolute slot where the next cycle starts
		bool locked = false;        ///< slot grid known
		bool numbered = false;      ///< slot numbers set by a first lock
		int32_t reference = 0;      ///< phase at lock, kernel ticks after SYNC0
		int32_t last_phase = 0;     ///< phase of the previous cycle
		int32_t last_correction = 0; ///< correction of the previous cycle, TIM1 ticks
		int32_t correction = 0;     ///< correction of the cycle playing, TIM1 ticks
		int32_t drift_x16 = 0;      ///< filtered drift per cycle, kernel ticks x 16
		uint32_t cycles_locked = 0;
	};

	/// One slot as the DMA burst writes it: ARR, RCR, CCR1..CCR4.
	struct slot
	{
		uint8_t arr;
		uint8_t rcr;
		std::array<uint8_t, axis_count> ccr;
	};
	static_assert(sizeof(slot) == slot_bytes);

	struct lli
	{
		uint32_t br1;
		uint32_t sar;
	};

	static void enable_clocks()
	{
		rcc.rcc_ahb1enr |= rcc_p::rcc_ahb1enr_r::gpdma1en_f() | atomic;
		rcc.rcc_ahb2enr |= (rcc_p::rcc_ahb2enr_r::gpioaen_f() | rcc_p::rcc_ahb2enr_r::gpioeen_f()) | atomic;
		rcc.rcc_apb1lenr |= rcc_p::rcc_apb1lenr_r::tim5en_f() | atomic;
		rcc.rcc_apb2enr |= rcc_p::rcc_apb2enr_r::tim1en_f() | atomic;
	}

	static void configure_pins()
	{
		// DIR: outputs, forward until the first change
		gpioe.gpio_bsrr = gpioc_p::gpio_bsrr_r(dir_word());
		for (auto const pin : dir_pin)
		{
			gpioe.gpio_moder <<= opsy::utility::clear_set<gpioc_p::gpio_moder_r>(
				gpioc_p::gpio_moder_r(0b11u << (2 * pin)), gpioc_p::gpio_moder_r(0b01u << (2 * pin))) || atomic;
			gpioe.gpio_ospeedr |= gpioc_p::gpio_ospeedr_r(0b11u << (2 * pin)) | atomic;
		}
		// STEP: TIM1_CH1..CH4, AF1
		gpioe.gpio_afrh <<= (gpioc_p::gpio_afrh_r::afsel9_f(1)
		                  || gpioc_p::gpio_afrh_r::afsel11_f(1)
		                  || gpioc_p::gpio_afrh_r::afsel13_f(1)
		                  || gpioc_p::gpio_afrh_r::afsel14_f(1)) || atomic;
		gpioe.gpio_ospeedr |= (gpioc_p::gpio_ospeedr_r::ospeed9_f(0b11)
		                    | gpioc_p::gpio_ospeedr_r::ospeed11_f(0b11)
		                    | gpioc_p::gpio_ospeedr_r::ospeed13_f(0b11)
		                    | gpioc_p::gpio_ospeedr_r::ospeed14_f(0b11)) | atomic;
		gpioe.gpio_moder <<= (gpioc_p::gpio_moder_r::mode9_f(0b10)
		                   || gpioc_p::gpio_moder_r::mode11_f(0b10)
		                   || gpioc_p::gpio_moder_r::mode13_f(0b10)
		                   || gpioc_p::gpio_moder_r::mode14_f(0b10)) || atomic;
		// SYNC0: PA4, TIM5_ETR, AF2, pull-down as on the board
		gpioa.gpioa_pupdr <<= gpioa_p::gpioa_pupdr_r::pupd4_f(0b10) || atomic;
		gpioa.gpioa_afrl <<= gpioa_p::gpioa_afrl_r::afsel4_f(2) || atomic;
		gpioa.gpioa_moder <<= gpioa_p::gpioa_moder_r::mode4_f(0b10) || atomic;
	}

	static void configure_tim1()
	{
		using r = tim1_p;
		tim1.tim1_cr1 = r::tim1_cr1_r::urs_f() | r::tim1_cr1_r::arpe_f();
		tim1.tim1_psc = r::tim1_psc_r::psc_f(static_cast<uint16_t>(d_.prescaler - 1));
		tim1.tim1_arr = r::tim1_arr_r::arr_f(d_.slot_ticks - 1);
		tim1.tim1_ccr1 = r::tim1_ccr1_r(0);
		tim1.tim1_ccr2 = r::tim1_ccr2_r(0);
		tim1.tim1_ccr3 = r::tim1_ccr3_r(0);
		tim1.tim1_ccr4 = r::tim1_ccr4_r(0);
		// PWM mode 1 (0110), preload on, all four channels
		tim1.tim1_ccmr1_output = r::tim1_ccmr1_output_r::oc1m_f(0b110) | r::tim1_ccmr1_output_r::oc1pe_f()
		                       | r::tim1_ccmr1_output_r::oc2m_f(0b110) | r::tim1_ccmr1_output_r::oc2pe_f();
		tim1.tim1_ccmr2_output = r::tim1_ccmr2_output_r::oc3m_f(0b110) | r::tim1_ccmr2_output_r::oc3pe_f()
		                       | r::tim1_ccmr2_output_r::oc4m_f(0b110) | r::tim1_ccmr2_output_r::oc4pe_f();
		tim1.tim1_ccer = r::tim1_ccer_r::cc1e_f() | r::tim1_ccer_r::cc2e_f()
		               | r::tim1_ccer_r::cc3e_f() | r::tim1_ccer_r::cc4e_f();
		tim1.tim1_bdtr = r::tim1_bdtr_r::moe_f();
		// Load PSC, ARR and the zero CCRs; URS = 1, so no DMA request for it
		tim1.tim1_egr = r::tim1_egr_r::ug_f();
		tim1.tim1_sr = r::tim1_sr_r(0);
		// Trigger mode (0110) on tim_itr4 = tim5_trgo, TS[4:0] = 01000: the first SYNC0 starts the
		// counter, later ones are ignored
		tim1.tim1_smcr = r::tim1_smcr_r::sms_f(0b110) | r::tim1_smcr_r::ts_f(0b000) | r::tim1_smcr_r::ts_1_f(0b01);
		// Burst of 6 transfers from ARR (offset 0x2C = 11 words): ARR, RCR, CCR1..CCR4, on update
		tim1.tim1_dcr = r::tim1_dcr_r::dba_f(11) | r::tim1_dcr_r::dbl_f(5) | r::tim1_dcr_r::dbss_f(1);
		tim1.tim1_dier = r::tim1_dier_r::ude_f();
	}

	static void configure_tim5()
	{
		using r = tim5_p;
		tim5.tim5_cr1 = r::tim5_cr1_r::urs_f();
		tim5.tim5_psc = r::tim5_psc_r::psc_f(0);
		tim5.tim5_arr = r::tim5_arr_r::arr_f(0xFFFF'FFFFu);
		tim5.tim5_ccr1 = r::tim5_ccr1_r::ccr1_f(d_.dir_ticks);
		tim5.tim5_ccr2 = r::tim5_ccr2_r::ccr2_f(d_.fill_ticks);
		tim5.tim5_egr = r::tim5_egr_r::ug_f();
		// TRGO on reset (MMS = 000); ETR = TIM5_ETR pin, rising edge. Filter ETF = 0011: 8
		// samples at 250 MHz, so that a glitch under 32 ns (crosstalk) is not taken for SYNC0
		tim5.tim5_cr2 = r::tim5_cr2_r(0);
		tim5.tim5_af1 = r::tim5_af1_r::etrsel_f(0);
		// Reset mode on tim_etrf: TS[4:0] = 00111
		tim5.tim5_smcr = r::tim5_smcr_r::sms_f(0b100) | r::tim5_smcr_r::ts_f(0b111) | r::tim5_smcr_r::etf_f(0b0011);
		tim5.tim5_sr = r::tim5_sr_r(0);
		tim5.tim5_dier = r::tim5_dier_r::cc1de_f() | r::tim5_dier_r::cc2ie_f();
	}

	static void configure_dma()
	{
		using r = gpdma_p;
		auto const address = [](auto const* p) { return reinterpret_cast<uint32_t>(p); };

		// Channel 2: slot bytes → TIM1_DMAR, one byte read and one word written per request
		uint32_t const ring_bytes = ring_slots * slot_bytes;
		step_lli_ = { ring_bytes, address(ring_.data()) };
		gpdma1.gpdma_c2tr1 = r::gpdma_cxtr1_r::sdw_log2_f(0) | r::gpdma_cxtr1_r::sinc_f()
		                   | r::gpdma_cxtr1_r::pam_f(0) | r::gpdma_cxtr1_r::ddw_log2_f(2);
		gpdma1.gpdma_c2tr2 = r::gpdma_cxtr2_r::reqsel_f(62) | r::gpdma_cxtr2_r::dreq_f(); // tim1_upd_dma
		gpdma1.gpdma_c2br1 = r::gpdma_cxbr1_r::bndt_f(static_cast<uint16_t>(ring_bytes));
		gpdma1.gpdma_c2sar = r::gpdma_cxsar_r::sa_f(address(ring_.data()));
		gpdma1.gpdma_c2dar = r::gpdma_cxdar_r::da_f(address(&tim1.tim1_dmar));
		gpdma1.gpdma_c2lbar = r::gpdma_cxlbar_r::lba_f(static_cast<uint16_t>(address(&step_lli_) >> 16));
		gpdma1.gpdma_c2llr = r::gpdma_cxllr_r::ub1_f() | r::gpdma_cxllr_r::usa_f()
		                   | r::gpdma_cxllr_r::la_f(static_cast<uint16_t>((address(&step_lli_) & 0xFFFFu) >> 2));
		gpdma1.gpdma_c2cr = r::gpdma_cxcr_r::prio_f(3) | r::gpdma_cxcr_r::en_f();

		// Channel 3: one dummy word per TIM5 CC1; its transfer complete triggers channel 4
		dummy_lli_ = { 4, 0 };
		gpdma1.gpdma_c3tr1 = r::gpdma_cxtr1_r::sdw_log2_f(2) | r::gpdma_cxtr1_r::ddw_log2_f(2);
		gpdma1.gpdma_c3tr2 = r::gpdma_cxtr2_r::reqsel_f(88) | r::gpdma_cxtr2_r::dreq_f(); // tim5_cc1_dma
		gpdma1.gpdma_c3br1 = r::gpdma_cxbr1_r::bndt_f(4);
		gpdma1.gpdma_c3sar = r::gpdma_cxsar_r::sa_f(address(&dummy_source_));
		gpdma1.gpdma_c3dar = r::gpdma_cxdar_r::da_f(address(&dummy_destination_));
		gpdma1.gpdma_c3lbar = r::gpdma_cxlbar_r::lba_f(static_cast<uint16_t>(address(&dummy_lli_) >> 16));
		gpdma1.gpdma_c3llr = r::gpdma_cxllr_r::ub1_f()
		                   | r::gpdma_cxllr_r::la_f(static_cast<uint16_t>((address(&dummy_lli_) & 0xFFFFu) >> 2));
		gpdma1.gpdma_c3cr = r::gpdma_cxcr_r::prio_f(3) | r::gpdma_cxcr_r::en_f();

		// Channel 4: DIR words → GPIOE_BSRR, each read gated by gpdma1_ch3_tc (trigger 21)
		uint32_t const dir_bytes = dir_ring_words * 4;
		dir_lli_ = { dir_bytes, address(dir_ring_.data()) };
		gpdma1.gpdma_c4tr1 = r::gpdma_cxtr1_r::sdw_log2_f(2) | r::gpdma_cxtr1_r::sinc_f()
		                   | r::gpdma_cxtr1_r::ddw_log2_f(2);
		gpdma1.gpdma_c4tr2 = r::gpdma_cxtr2_r::swreq_f() | r::gpdma_cxtr2_r::trigm_f(0b11)
		                   | r::gpdma_cxtr2_r::trigsel_f(21) | r::gpdma_cxtr2_r::trigpol_f(0b01);
		gpdma1.gpdma_c4br1 = r::gpdma_cxbr1_r::bndt_f(static_cast<uint16_t>(dir_bytes));
		gpdma1.gpdma_c4sar = r::gpdma_cxsar_r::sa_f(address(dir_ring_.data()));
		gpdma1.gpdma_c4dar = r::gpdma_cxdar_r::da_f(address(&gpioe.gpio_bsrr));
		gpdma1.gpdma_c4lbar = r::gpdma_cxlbar_r::lba_f(static_cast<uint16_t>(address(&dir_lli_) >> 16));
		gpdma1.gpdma_c4llr = r::gpdma_cxllr_r::ub1_f() | r::gpdma_cxllr_r::usa_f()
		                   | r::gpdma_cxllr_r::la_f(static_cast<uint16_t>((address(&dir_lli_) & 0xFFFFu) >> 2));
		gpdma1.gpdma_c4cr = r::gpdma_cxcr_r::prio_f(3) | r::gpdma_cxcr_r::en_f();
	}

	template<typename TCr, typename TSr>
	static void abort_channel(TCr& cr, TSr& sr)
	{
		if (!cr.load().en())
			return;
		cr = gpdma_p::gpdma_cxcr_r::susp_f();
		// A channel waiting for a request suspends at once; bounded anyway
		for (uint32_t i = 0; i < 100'000 && !sr.load().suspf(); ++i) {}
		cr = gpdma_p::gpdma_cxcr_r::reset_f();
	}

	static void check_dma_errors()
	{
		// The field accessors overload || (field combination): test the raw value
		uint32_t const errors = gpdma_p::gpdma_cxsr_r::dtef_f::mask | gpdma_p::gpdma_cxsr_r::ulef_f::mask
		                      | gpdma_p::gpdma_cxsr_r::usef_f::mask;
		if (((gpdma1.gpdma_c2sr.load().value() | gpdma1.gpdma_c3sr.load().value()
		      | gpdma1.gpdma_c4sr.load().value()) & errors) != 0)
		{
			++stats_.dma_errors;
			auto const clear = gpdma_p::gpdma_cxfcr_r::dtef_f() | gpdma_p::gpdma_cxfcr_r::ulef_f()
			                 | gpdma_p::gpdma_cxfcr_r::usef_f();
			gpdma1.gpdma_c2fcr = clear;
			gpdma1.gpdma_c3fcr = clear;
			gpdma1.gpdma_c4fcr = clear;
		}
	}

	/**
	 * @brief Measures the phase of the slot grid and sets the correction of the next cycle.
	 *
	 *        phase = when the first slot of this cycle started, in kernel ticks after SYNC0.
	 *        With c the correction of a cycle (in TIM1 ticks) and D the drift per cycle,
	 *        phase(k + 1) = phase(k) + c(k) x prescaler - D. D is read from the last two
	 *        cycles and low-pass filtered (it only moves with temperature); the correction of
	 *        the cycle being filled (k + 1) is D plus a quarter of the phase error expected at
	 *        k + 1. A reading error, tens of ticks in the debug image, then only moves the
	 *        corrections by a few ticks instead of being copied into the next cycle.
	 */
	static void lock_phase()
	{
		uint32_t const ring_bytes = ring_slots * slot_bytes;
		uint32_t written = 0;
		uint32_t tim1_count = 0;
		uint32_t since_sync = 0;
		// GPDMA reads the source ahead into its FIFO: BNDT counts bytes read, FIFOL the words
		// (one per byte here) not yet written to TIM1. Take a reading where both agree, away
		// from an update, so that no burst is in progress. Bounded: a slot lasts 254 ticks at
		// most.
		// The two counters are read back to back, TIM5 between two readings of TIM1: bus
		// accesses slow down by a varying amount under the DMA bursts, and a reading is kept
		// only when both TIM1 values are close, their middle facing the TIM5 value.
		for (uint32_t attempt = 0; attempt < 64; ++attempt)
		{
			uint32_t const fifo = gpdma1.gpdma_c2sr.load().fifol();
			uint32_t const remaining = gpdma1.gpdma_c2br1.load().bndt();
			uint32_t const before = tim1.tim1_cnt.load().cnt();
			since_sync = tim5.tim5_cnt.load().cnt();
			uint32_t const after = tim1.tim1_cnt.load().cnt();
			bool const stable = fifo == gpdma1.gpdma_c2sr.load().fifol()
			                 && remaining == gpdma1.gpdma_c2br1.load().bndt();
			written = (2 * ring_bytes - remaining - fifo) % ring_bytes;
			tim1_count = (before + after) / 2;
			if (stable && written % slot_bytes == 0 && after >= before && (after - before) * d_.prescaler <= 48
			    && before >= 24 / d_.prescaler + 2)
				break;
			++stats_.position_retries;
		}

		// Slot playing and its start, in kernel ticks after SYNC0. Slots are numbered from the
		// first lock on, without wrapping: the ring index is the number modulo ring_slots.
		uint32_t const n = d_.cycle_slots;
		uint32_t playing = wrap(written / slot_bytes - pipeline_slots);
		auto const playing_start = static_cast<int32_t>(since_sync) - static_cast<int32_t>(tim1_count * d_.prescaler);
		uint32_t const first = state_.next_start - n; // first slot of this cycle, once numbered
		auto const offset = static_cast<int32_t>(wrap(playing - first + ring_slots / 2)) - static_cast<int32_t>(ring_slots / 2);
		if (state_.numbered)
			playing = first + static_cast<uint32_t>(offset);

		auto const slot_kernel = static_cast<int32_t>(d_.slot_ticks * d_.prescaler);
		if (!state_.locked)
		{
			// First fill, or lost: this cycle starts with the first slot that started at or
			// after SYNC0. The phase is then driven to 0, cycle boundaries on SYNC0, which is
			// where DIR timings are counted from.
			int32_t const before = playing_start >= 0 ? playing_start / slot_kernel
			                                          : -1 - (-playing_start - 1) / slot_kernel;
			state_.next_start = playing - static_cast<uint32_t>(before) + n;
			state_.numbered = true;
			state_.reference = 0;
			state_.last_phase = playing_start - before * slot_kernel;
			state_.last_correction = 0;
			state_.correction = 0;
			state_.cycles_locked = 0;
			state_.locked = true;
			return;
		}

		// Start of the first slot of this cycle: walk the slot lengths from the playing one
		int32_t phase = playing_start;
		if (offset >= 0)
			for (uint32_t s = first; s != first + static_cast<uint32_t>(offset); ++s)
				phase -= static_cast<int32_t>(slot_length(s));
		else
			for (uint32_t s = playing; s != first; ++s)
				phase += static_cast<int32_t>(slot_length(s));

		int32_t const error = phase - state_.reference;
		if (error > static_cast<int32_t>(n * d_.slot_ticks * d_.prescaler / 2) || error < -static_cast<int32_t>(n * d_.slot_ticks * d_.prescaler / 2))
		{
			// Lost (SYNC0 missing or moved): lock again on the slot playing
			++stats_.resyncs;
			state_.locked = false;
			lock_phase();
			return;
		}

		// Drift of the last cycle (filtered, x16), then the correction of the next one
		auto const p = static_cast<int32_t>(d_.prescaler);
		int32_t const drift = state_.last_phase + state_.last_correction * p - phase;
		if (state_.cycles_locked == 0)
			state_.drift_x16 = drift * 16;
		else
			state_.drift_x16 += (drift * 16 - state_.drift_x16) / 8;
		int32_t const next_phase = phase + state_.correction * p - state_.drift_x16 / 16;
		int32_t const wanted = (state_.drift_x16 + 4 * (state_.reference - next_phase)) / 16;
		int32_t const limit = static_cast<int32_t>(n / 2);
		int32_t const correction = std::clamp((wanted + (wanted >= 0 ? p / 2 : -p / 2)) / p, -limit, limit);

		// Statistics of the locked state: the first cycles bring the cycle boundary onto SYNC0
		if (state_.cycles_locked >= lock_cycles)
		{
			stats_.phase_min = std::min(stats_.phase_min, error);
			stats_.phase_max = std::max(stats_.phase_max, error);
			stats_.correction_min = std::min(stats_.correction_min, correction);
			stats_.correction_max = std::max(stats_.correction_max, correction);
		}

		state_.last_phase = phase;
		state_.last_correction = state_.correction;
		state_.correction = correction;
		++state_.cycles_locked;
	}

	/// Length of a slot in kernel ticks, from its ARR byte.
	static uint32_t slot_length(uint32_t slot)
	{
		return (uint32_t{ring_[wrap(slot)].arr} + 1) * d_.prescaler;
	}

	/// Lengthens (correction > 0) or shortens |correction| slots of a cycle by one tick, evenly.
	static void apply_correction(uint32_t start, int32_t correction)
	{
		if (correction == 0)
			return;
		uint32_t const count = static_cast<uint32_t>(correction > 0 ? correction : -correction);
		auto const arr = static_cast<uint8_t>(correction > 0 ? d_.slot_ticks : d_.slot_ticks - 2);
		uint32_t const n = d_.cycle_slots;
		for (uint32_t i = 0; i < count; ++i)
			ring_[wrap(start + i * n / count)].arr = arr;
	}

	/// Empty slots of nominal length.
	static void clear_slots(uint32_t start, uint32_t count)
	{
		slot const empty{ static_cast<uint8_t>(d_.slot_ticks - 1), 0, {} };
		for (uint32_t s = start; s != start + count; ++s)
			ring_[wrap(s)] = empty;
	}

	static constexpr uint32_t wrap(uint32_t slot) { return slot & (ring_slots - 1); }

	static void fill_axis(std::size_t a, uint32_t start, int32_t target)
	{
		auto& st = stats_.axes[a];
		auto& ax = state_.axes[a];
		int32_t const wanted = target - st.position;
		if (wanted == 0)
			return;

		bool const forward = wanted > 0;
		bool const reverse = forward != ax.forward;
		if (reverse)
		{
			ax.forward = forward;
			++st.reversals;
			if (forward)
				dir_bits_ |= 1u << a;
			else
				dir_bits_ &= ~(1u << a);
		}

		uint32_t const head = reverse ? d_.guard_slots : 0u;
		uint32_t const usable = d_.cycle_slots - head - (d_.pulse_slots - 1);
		uint32_t const steps = static_cast<uint32_t>(forward ? wanted : -wanted);
		uint32_t const first = start + head;
		uint32_t const end = first + usable; // no pulse starts at or after this slot

		ax.acc = std::min(ax.acc, usable - 1);
		// Step j falls in usable slot ceil((j * usable - acc) / steps) - 1, the first slot where
		// acc + (i + 1) * steps reaches j * usable. Walked incrementally: x = j * usable - acc - 1
		// kept as quotient and remainder by steps, so that the slot is first + quotient.
		uint32_t const step_quotient = usable / steps;
		uint32_t const step_remainder = usable % steps;
		uint32_t const quotient = (usable - ax.acc - 1) / steps;
		uint32_t const remainder = (usable - ax.acc - 1) % steps;
		uint32_t const gap = d_.gap_slots;
		walk_state w{ quotient, remainder, ax.has_last ? ax.last_step : first - gap, 0 };
		walk_params const p{ &ring_[0].ccr[channel_of_axis[a]], first, end, steps, step_quotient, step_remainder,
		                     gap, d_.pulse_slots - 1, static_cast<uint8_t>(d_.pulse_last) };
		// Fast path when no check is needed: the first step clears the previous cycle by the
		// minimum gap, and steps x gap <= usable, so that the walk spaces steps by at least
		// floor(usable / steps) >= gap and its last step lands before the end.
		bool const fast = static_cast<int32_t>(first + quotient - (w.last + gap)) >= 0 && uint32_t{steps} * gap <= usable;
		if (p.continued == 0)
			w = fast ? walk<false, false>(p, w) : walk<false, true>(p, w);
		else
			w = fast ? walk<true, false>(p, w) : walk<true, true>(p, w);
		uint32_t const emitted = w.emitted;
		ax.last_step = w.last;
		ax.has_last = ax.has_last || emitted > 0;
		if (emitted < steps)
			++st.deferred;
		st.pulses += emitted;
		st.position += forward ? static_cast<int32_t>(emitted) : -static_cast<int32_t>(emitted);
	}

	struct walk_params
	{
		uint8_t* column;         ///< byte of the axis in slot 0; slots are slot_bytes apart
		uint32_t first;          ///< first usable slot
		uint32_t end;            ///< no step starts at or after this slot
		uint32_t steps;
		uint32_t step_quotient;  ///< usable / steps
		uint32_t step_remainder; ///< usable % steps
		uint32_t gap;            ///< minimum slots from one step to the next
		uint32_t continued;      ///< slots a pulse covers after its first one
		uint8_t pulse_last;      ///< CCR of the last slot of a pulse
	};

	struct walk_state
	{
		uint32_t quotient;  ///< slot of the next step, from first
		uint32_t remainder; ///< (j * usable - acc - 1) % steps
		uint32_t last;      ///< slot of the last step written
		uint32_t emitted;
	};

	/**
	 * @brief Writes the steps of one axis for one cycle.
	 *
	 *        Parameters by value and a plain loop, so that everything stays in registers, in
	 *        the debug image too. @p checked enforces the minimum gap and the end of the cycle
	 *        on every step; without it the caller guarantees both.
	 */
	template<bool long_pulse, bool checked>
	static walk_state walk(walk_params const p, walk_state w)
	{
		uint8_t* const column = p.column;
		uint32_t quotient = w.quotient;
		uint32_t remainder = w.remainder;
		uint32_t last = w.last;
		uint32_t emitted = 0;
		for (; emitted < p.steps; ++emitted)
		{
			uint32_t slot = p.first + quotient;
			if constexpr (checked)
			{
				if (static_cast<int32_t>(slot - (last + p.gap)) < 0)
					slot = last + p.gap;
				if (static_cast<int32_t>(slot - p.end) >= 0)
					break;
			}
			if constexpr (long_pulse)
			{
				for (uint32_t k = 0; k < p.continued; ++k)
					column[wrap(slot + k) * slot_bytes] = 255; // above ARR: high for the whole slot
				column[wrap(slot + p.continued) * slot_bytes] = p.pulse_last;
			}
			else
				column[wrap(slot) * slot_bytes] = p.pulse_last;
			last = slot;
			quotient += p.step_quotient;
			remainder += p.step_remainder;
			if (remainder >= p.steps)
			{
				remainder -= p.steps;
				++quotient;
			}
		}
		return { quotient, remainder, last, emitted };
	}

	static uint32_t dir_mask()
	{
		uint32_t m = 0;
		for (auto const pin : dir_pin)
			m |= 1u << pin;
		return m;
	}

	static uint32_t dir_word()
	{
		uint32_t set = 0;
		for (std::size_t a = 0; a < axis_count; ++a)
			if ((dir_bits_ & (1u << a)) != 0)
				set |= 1u << dir_pin[a];
		return set | ((dir_mask() & ~set) << 16);
	}

	/// Index of the DIR word the channel writes next.
	static std::size_t dir_index()
	{
		uint32_t const remaining = gpdma1.gpdma_c4br1.load().bndt();
		uint32_t const consumed = (dir_ring_words * 4 - remaining) % (dir_ring_words * 4);
		return consumed / 4;
	}

	// Defined after the class: their types have default member initializers.
	static config config_;
	static derived d_;
	static stats stats_;
	static run_state state_;
	static inline uint32_t dir_bits_ = 0; ///< bit a: axis a forward (DIR high)

	alignas(4) static inline std::array<slot, ring_slots> ring_{};
	alignas(4) static inline std::array<uint32_t, dir_ring_words> dir_ring_{};
	alignas(4) static inline lli step_lli_{};
	alignas(4) static inline lli dir_lli_{};
	alignas(4) static inline lli dummy_lli_{};
	static inline uint32_t dummy_source_ = 0;
	static inline uint32_t dummy_destination_ = 0;
};

inline step_generator::config step_generator::config_{};
inline step_generator::derived step_generator::d_{};
inline step_generator::stats step_generator::stats_{};
inline step_generator::run_state step_generator::state_{};

} // namespace STM32H563
