// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    sync_latch.hpp
 * @author  Thomas Legrand
 * @brief   SYNC0 of the LAN9253 to the LATCH line of the local bus, by timers, as a module
 *
 *          | Signal    | Pin | Function                                            |
 *          |-----------|-----|-----------------------------------------------------|
 *          | ESC_SYNC0 | PA4 | TIM5_ETR (AF2): each SYNC0 edge resets TIM5         |
 *          | BUS_LATCH | PE5 | TIM15_CH1 (AF4): a pulse started by that reset      |
 *
 *          SYNC0 is the Distributed Clocks event of the EtherCAT slave controller, the same
 *          instant on every slave. The edge resets TIM5 (slave reset mode, trigger ETRF),
 *          whose reset is its trigger output; TIM15 takes it as trigger (ITR4) and, in one
 *          pulse mode, drives LATCH high for pulse_width. No software in between: LATCH follows
 *          SYNC0 by a few timer clocks, and the extension modules latch their inputs on it.
 *          LATCH is pin 26 of the HE10, with a ground on pin 25 and 27.
 *
 *          TIM5 also counts, at the timer clock, the time since the last SYNC0: the step
 *          generator and the probe capture will use it.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <cstdint>

#include <STM32H523/gpio.hpp>
#include <STM32H523/rcc.hpp>
#include <STM32H523/tim.hpp>

namespace STM32H523
{

using mmio::atomic;

/**
 * @brief SYNC0 to LATCH, as a module.
 *
 *        All methods are static — no instance needed. init() is used by bornier::app.
 */
class sync_latch
{
public:

	/** @brief Both timers and both pins: LATCH pulses on each SYNC0 from then on. */
	static void init()
	{
		rcc.ahb2enr |= rcc_p::ahb2enr_r::gpioaen_f() | rcc_p::ahb2enr_r::gpioeen_f() | atomic;
		rcc.apb1lenr |= rcc_p::apb1lenr_r::tim5en_f() | atomic;
		rcc.apb2enr |= rcc_p::apb2enr_r::tim15en_f() | atomic;

		// TIM5: free-running at the timer clock, reset by each SYNC0 edge (ETRF), its reset
		// as trigger output (MMS = 000).
		tim5.arr = tim2_p::arr_r(0xFFFF'FFFFu);
		tim5.smcr = tim2_p::smcr_r::sms_f(slave_reset) | tim2_p::smcr_r::ts_f(trigger_etrf)
		          | tim2_p::smcr_r::etp_f(sync0_falling);
		tim5.cr1 = tim2_p::cr1_r::cen_f();

		// TIM15: one pulse on CH1, started by the trigger of TIM5 (ITR4: TS = 0b01000), PWM mode
		// 2: active from CCR1 to ARR.
		tim15.psc = tim15_p::psc_r(0u);
		tim15.ccr1 = tim15_p::ccr1_r(1u);
		tim15.arr = tim15_p::arr_r(pulse_ticks + 1);
		tim15.ccmr1_alternate1 = tim15_p::ccmr1_alternate1_r::oc1m_f(pwm_mode_2);
		tim15.ccer = tim15_p::ccer_r::cc1e_f();
		tim15.bdtr = tim15_p::bdtr_r::moe_f();
		tim15.smcr = tim15_p::smcr_r::sms_f(slave_trigger) | tim15_p::smcr_r::ts_1_f(1);
		tim15.cr1 = tim15_p::cr1_r::opm_f();

		gpioa.afrl <<= gpio_p::afrl_r::afsel4_f(2) || atomic;  // PA4 TIM5_ETR
		gpioe.afrl <<= gpio_p::afrl_r::afsel5_f(4) || atomic;  // PE5 TIM15_CH1
		gpioa.moder <<= gpio_p::moder_r::mode4_f(0b10) || atomic;
		gpioe.ospeedr <<= gpio_p::ospeedr_r::ospeed5_f(0b10) || atomic;
		gpioe.moder <<= gpio_p::moder_r::mode5_f(0b10) || atomic;
	}

	/** @brief Timer clocks since the last SYNC0. */
	static uint32_t since_sync0() { return tim5.cnt.load().value(); }

private:

	static constexpr uint32_t timer_hz = 250'000'000;
	static constexpr uint32_t pulse_ticks = timer_hz / 100'000; ///< LATCH high 10 us

	static constexpr uint8_t slave_reset = 0b100;
	static constexpr uint8_t slave_trigger = 0b110;
	static constexpr uint8_t trigger_etrf = 0b111;
	static constexpr uint8_t pwm_mode_2 = 0b111;
	/// SYNC0 polarity, from the configuration the SII gives the LAN9253: active low.
	static constexpr bool sync0_falling = true;
};

} // namespace STM32H523
