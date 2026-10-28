// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    sync_simulator.hpp
 * @brief   Stand-in for the SYNC0 output of the EtherCAT slave controller: TIM16 PWM on PB8
 *
 *          Test bench only: TIM16 does not exist on the STM32H523. A wire takes PB8 to PA4,
 *          the SYNC0 input of the step generator. The period can be detuned to play the drift
 *          between the distributed clock and the local oscillator.
 *
 *          TIM16 counts on 16 bits (the 20-bit ARR field is for dithering): it is clocked at
 *          250 MHz / 4, so a period up to 4.19 ms is set to 16 ns.
 ******************************************************************************
 */

#pragma once

#include <cstdint>

#include <STM32H563/gpio.hpp>
#include <STM32H563/rcc.hpp>
#include <STM32H563/tim.hpp>

namespace STM32H563
{

using opsy::utility::atomic;

class sync_simulator
{
public:

	static constexpr uint32_t tick_ns = 16;

	/**
	 * @brief Starts SYNC0 pulses on PB8.
	 * @param period_ns period, rounded down to 16 ns, at most 1 048 560 ns
	 * @param pulse_ns high time, rounded down to 16 ns
	 */
	static void start(uint32_t period_ns, uint32_t pulse_ns)
	{
		uint32_t const period_ticks = period_ns / tick_ns;
		uint32_t const pulse_ticks = pulse_ns / tick_ns;
		using r = tim16_p;
		rcc.rcc_ahb2enr |= rcc_p::rcc_ahb2enr_r::gpioben_f() | atomic;
		rcc.rcc_apb2enr |= rcc_p::rcc_apb2enr_r::tim16en_f() | atomic;

		tim16.tim16_cr1 = r::tim16_cr1_r::cen_f(false);
		tim16.tim16_psc = r::tim16_psc_r::psc_f(3);
		tim16.tim16_arr = r::tim16_arr_r::arr_f(period_ticks - 1);
		tim16.tim16_ccr1 = r::tim16_ccr1_r::ccr1_f(pulse_ticks);
		tim16.tim16_ccmr1_output = r::tim16_ccmr1_output_r::oc1m1_f(0b110) | r::tim16_ccmr1_output_r::oc1pe_f();
		tim16.tim16_ccer = r::tim16_ccer_r::cc1e_f();
		tim16.tim16_bdtr = r::tim16_bdtr_r::moe_f();
		tim16.tim16_egr = r::tim16_egr_r::ug_f();

		gpiob.gpiob_ospeedr <<= gpiob_p::gpiob_ospeedr_r::ospeed8_f(0b11) || atomic;
		gpiob.gpiob_afrh <<= gpiob_p::gpiob_afrh_r::afsel8_f(1) || atomic;
		gpiob.gpiob_moder <<= gpiob_p::gpiob_moder_r::mode8_f(0b10) || atomic;

		tim16.tim16_cr1 = r::tim16_cr1_r::cen_f();
	}

	/// Stops the pulses, PB8 low.
	static void stop()
	{
		if (!rcc.rcc_apb2enr.load().tim16en())
			return;
		tim16.tim16_cr1 = tim16_p::tim16_cr1_r::cen_f(false);
		tim16.tim16_ccr1 = tim16_p::tim16_ccr1_r::ccr1_f(0);
		tim16.tim16_egr = tim16_p::tim16_egr_r::ug_f();
	}
};

} // namespace STM32H563
