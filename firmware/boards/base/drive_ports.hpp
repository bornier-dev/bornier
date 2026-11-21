// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    drive_ports.hpp
 * @author  Thomas Legrand
 * @brief   Enable and alarm signals of the four drive ports of the Bornier base board,
 *          as a module
 *
 *          | Axis | ENA (output)  | ALM (input)   |
 *          |------|---------------|---------------|
 *          | 0    | PE2           | PA8           |
 *          | 1    | PE3           | PB9           |
 *          | 2    | PE6           | PC14          |
 *          | 3    | PE4           | PC3           |
 *
 *          ENA drives the enable of the drive through a low-side switch: pin high, drive
 *          enabled. A pull-down holds it disabled from reset until the firmware drives it.
 *          ALM comes from the alarm output of the drive through an optocoupler: pin low while
 *          the alarm current flows (red ALM LED on), high with nothing wired.
 *
 *          The step and direction signals of the ports belong to the step generator.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

#include <STM32H523/gpio.hpp>
#include <STM32H523/rcc.hpp>

namespace STM32H523
{

using mmio::atomic;

/**
 * @brief Enable and alarm signals of the drive ports, as a module.
 *
 *        All methods are static — no instance needed. init() is used by bornier::app.
 */
class drive_ports
{
public:

	static constexpr std::size_t count = 4; ///< Drive ports on the board

	/** @brief ENA pins as outputs, low: every drive disabled. ALM pins are inputs from reset. */
	static void init()
	{
		rcc.ahb2enr |= rcc_p::ahb2enr_r::gpioaen_f() | rcc_p::ahb2enr_r::gpioben_f()
		             | rcc_p::ahb2enr_r::gpiocen_f() | rcc_p::ahb2enr_r::gpioeen_f() | atomic;
		for (std::size_t axis = 0; axis < count; ++axis)
			enable(axis, false);
		gpioe.moder <<= gpio_p::moder_r::mode2_f(0b01) || atomic;
		gpioe.moder <<= gpio_p::moder_r::mode3_f(0b01) || atomic;
		gpioe.moder <<= gpio_p::moder_r::mode6_f(0b01) || atomic;
		gpioe.moder <<= gpio_p::moder_r::mode4_f(0b01) || atomic;
		gpioa.moder <<= gpio_p::moder_r::mode8_f(0b00) || atomic;
		gpiob.moder <<= gpio_p::moder_r::mode9_f(0b00) || atomic;
		gpioc.moder <<= gpio_p::moder_r::mode14_f(0b00) || atomic;
		gpioc.moder <<= gpio_p::moder_r::mode3_f(0b00) || atomic;
	}

	/**
	 * @brief Enables or disables the drive of a port. BSRR is write-only: atomic by nature.
	 *
	 * @param axis Port, 0 to 3.
	 * @param on   @c true to enable the drive.
	 */
	static void enable(std::size_t axis, bool on)
	{
		const uint32_t pin = ena_pins[axis];
		gpioe.bsrr = gpio_p::bsrr_r(on ? 1u << pin : 1u << (pin + 16));
	}

	/**
	 * @brief Whether the drive of a port reports an alarm.
	 *
	 * @param axis Port, 0 to 3.
	 */
	static bool alarm(std::size_t axis)
	{
		const auto& [port, pin] = alm_pins[axis];
		return (port->idr.load().value() & (1u << pin)) == 0;
	}

private:

	struct input
	{
		gpio_p* port;
		uint32_t pin;
	};

	static constexpr std::array<uint32_t, count> ena_pins{2, 3, 6, 4}; ///< On GPIOE

	static inline const std::array<input, count> alm_pins{{
		{&gpioa, 8}, {&gpiob, 9}, {&gpioc, 14}, {&gpioc, 3},
	}};
};

} // namespace STM32H523
