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

#include <STM32H523/gpio.hpp>
#include <STM32H523/rcc.hpp>

namespace STM32H523
{

using mmio::atomic;

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
		rcc.ahb2enr |= rcc_p::ahb2enr_r::gpiocen_f() | atomic;

		// Pin high before it becomes an output: the LED stays off.
		off();
		gpioc.moder <<= gpio_p::moder_r::mode13_f(0b01) || atomic;
	}

	/** @brief Turns the LED on (pin low). BSRR is write-only: the write is atomic by nature. */
	static void on() { gpioc.bsrr = gpio_p::bsrr_r::br13_f(); }

	/** @brief Turns the LED off (pin high). */
	static void off() { gpioc.bsrr = gpio_p::bsrr_r::bs13_f(); }
};

} // namespace STM32H523
