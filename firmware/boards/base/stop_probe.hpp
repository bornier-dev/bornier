// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    stop_probe.hpp
 * @author  Thomas Legrand
 * @brief   Emergency stop chain and probe inputs of the Bornier base board, as a module
 *
 *          | Signal   | Pin  | Level                                                   |
 *          |----------|------|---------------------------------------------------------|
 *          | ESTOP_IN | PC15 | low while the stop chain is closed; a broken wire reads |
 *          |          |      | as a stop                                               |
 *          | PROBE    | PA2  | low while the probe conducts                            |
 *
 *          Both come through optocouplers from the terminal block. The board reports them;
 *          it carries no safety function (the stop chain acts on the drives' power, wired).
 *          PROBE is also the capture input of TIM5, for the touch probe of the motion.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <STM32H523/gpio.hpp>
#include <STM32H523/rcc.hpp>

namespace STM32H523
{

using mmio::atomic;

/**
 * @brief Emergency stop chain and probe inputs, as a module.
 *
 *        All methods are static — no instance needed. init() is used by bornier::app.
 */
class stop_probe
{
public:

	/** @brief Both pins as inputs; they are from reset, the clocks are what init() adds. */
	static void init()
	{
		rcc.ahb2enr |= rcc_p::ahb2enr_r::gpioaen_f() | rcc_p::ahb2enr_r::gpiocen_f() | atomic;
		gpioc.moder <<= gpio_p::moder_r::mode15_f(0b00) || atomic;
		gpioa.moder <<= gpio_p::moder_r::mode2_f(0b00) || atomic;
	}

	/** @brief Whether the emergency stop chain is closed: no stop. */
	static bool chain_closed() { return !gpioc.idr.load().id15(); }

	/** @brief Whether the probe conducts. */
	static bool probe_active() { return !gpioa.idr.load().id2(); }
};

} // namespace STM32H523
