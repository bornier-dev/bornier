// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    led.hpp
 * @author  Thomas Legrand
 * @brief   User LED driver for NUCLEO-H563ZI
 *
 *          Covers all three user LEDs:
 *            - LD1 green  : PB0
 *            - LD2 yellow : PF4
 *            - LD3 red    : PG4
 *
 *          No HAL. No dynamic allocation.
 *          Register accesses on shared peripherals (RCC, GPIO MODER) use
 *          the atomic operators from Memory.hpp to avoid lost-update races.
 ******************************************************************************
 */

#pragma once

#include <STM32H563/gpio.hpp>
#include <STM32H563/rcc.hpp>

namespace STM32H563
{

// The `atomic` postfix tag used in `| atomic` / `|| atomic` lives in
// opsy::utility — pull it into namespace scope so the BSP register
// helper expressions read naturally.
using opsy::utility::atomic;

/**
 * @brief Driver for the three user LEDs on NUCLEO-H563ZI.
 *
 *        All methods are static — no instance needed.
 *        Call @c init() once before any other method.
 */
class user_leds
{
public:

	/** @brief Selects one of the three user LEDs. */
	enum class led
	{
		ld1, ///< Green  — PB0
		ld2, ///< Yellow — PF4
		ld3, ///< Red    — PG4
	};

	/**
	 * @brief Enables GPIO clocks and configures LED pins as push-pull outputs.
	 *
	 *        Must be called after @c clock::init() (GPIOs run on HCLK).
	 *
	 *        RCC and MODER accesses are atomic: multiple drivers may enable
	 *        clocks or configure pins concurrently without lost-update races.
	 */
	static void init()
	{
		// Enable GPIOB (LD1), GPIOF (LD2), GPIOG (LD3) clocks on AHB2.
		// fetch_or via |= … | atomic — safe if called from multiple contexts.
		rcc.rcc_ahb2enr |= (rcc_p::rcc_ahb2enr_r::gpioben_f()
		                  | rcc_p::rcc_ahb2enr_r::gpiofen_f()
		                  | rcc_p::rcc_ahb2enr_r::gpiogen_f()) | atomic;

		// Set pins to general-purpose output mode (MODER field = 0b01).
		// CAS-loop via <<= … || atomic — clears the 2-bit field and sets the
		// new value without disturbing any other pin's configuration.
		gpiob.gpiob_moder <<= gpiob_p::gpiob_moder_r::mode0_f(0b01) || atomic; // PB0
		gpiof.gpio_moder  <<= gpioc_p::gpio_moder_r::mode4_f(0b01)  || atomic; // PF4
		gpiog.gpio_moder  <<= gpioc_p::gpio_moder_r::mode4_f(0b01)  || atomic; // PG4
	}

	/**
	 * @brief Turns a LED on.
	 *
	 *        BSRR is a write-only set/reset register: a single 32-bit write
	 *        is inherently atomic — no read-modify-write, no race.
	 *
	 * @param which Which LED to turn on.
	 */
	static void on(led which)
	{
		switch (which)
		{
		case led::ld1: gpiob.gpiob_bsrr = gpiob_p::gpiob_bsrr_r::bs0_f(); break;
		case led::ld2: gpiof.gpio_bsrr  = gpioc_p::gpio_bsrr_r::bs4_f();  break;
		case led::ld3: gpiog.gpio_bsrr  = gpioc_p::gpio_bsrr_r::bs4_f();  break;
		}
	}

	/**
	 * @brief Turns a LED off.
	 *
	 * @param which Which LED to turn off.
	 */
	static void off(led which)
	{
		switch (which)
		{
		case led::ld1: gpiob.gpiob_bsrr = gpiob_p::gpiob_bsrr_r::br0_f(); break;
		case led::ld2: gpiof.gpio_bsrr  = gpioc_p::gpio_bsrr_r::br4_f();  break;
		case led::ld3: gpiog.gpio_bsrr  = gpioc_p::gpio_bsrr_r::br4_f();  break;
		}
	}
};

} // namespace STM32H563
