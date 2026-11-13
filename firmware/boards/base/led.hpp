// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    led.hpp
 * @author  Thomas Legrand
 * @brief   MCU LED driver for the Bornier base board
 *
 *          The LED hangs between 3.3 V and PC13: the pin sinks its current,
 *          so the LED is on when the pin is low. PC13 is supplied through
 *          the backup domain switch, which cannot source current and is
 *          limited to 2 MHz.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <STM32H523/gpioc.hpp>
#include <STM32H523/rcc.hpp>

namespace STM32H523
{

using opsy::utility::atomic;

/**
 * @brief Driver for the MCU LED of the Bornier base board.
 *
 *        All methods are static — no instance needed.
 *        Call @c init() once before any other method.
 */
class mcu_led
{
public:

	/**
	 * @brief Enables the GPIOC clock and configures PC13 as an output, LED off.
	 *
	 *        RCC and MODER accesses are atomic: other drivers may enable
	 *        clocks or configure pins concurrently without lost-update races.
	 */
	static void init()
	{
		rcc.rcc_ahb2enr |= rcc_p::rcc_ahb2enr_r::gpiocen_f() | atomic;

		// Pin high before it becomes an output: the LED stays off.
		off();
		gpioc.gpioc_moder <<= gpioc_p::gpioc_moder_r::mode13_f(0b01) || atomic;
	}

	/** @brief Turns the LED on (pin low). BSRR is write-only: the write is atomic by nature. */
	static void on() { gpioc.gpioc_bsrr = gpioc_p::gpioc_bsrr_r::br13_f(); }

	/** @brief Turns the LED off (pin high). */
	static void off() { gpioc.gpioc_bsrr = gpioc_p::gpioc_bsrr_r::bs13_f(); }
};

} // namespace STM32H523
