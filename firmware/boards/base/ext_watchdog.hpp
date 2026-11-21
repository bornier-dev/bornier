// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    ext_watchdog.hpp
 * @author  Thomas Legrand
 * @brief   External watchdog of the Bornier base board (TPS3828), as a module
 *
 *          | Signal | Pin  | Function                                                   |
 *          |--------|------|------------------------------------------------------------|
 *          | WDI    | PD15 | an edge every 0.9 s at least, or the MCU is reset (200 ms) |
 *
 *          The reset turns every output off: their pull resistors hold them inactive. WDI left
 *          floating (pin analog, as after reset) disables the watchdog: the system bootloader
 *          never drives it.
 *
 *          With a debugger attached at start, the pin stays floating: a halt on a breakpoint
 *          would otherwise reset the MCU. On the bench, with the probe always connected, the
 *          watchdog is therefore off.
 *
 *          feed() is called by the task whose life it watches: one edge per call.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <cstdint>

#include <STM32H523/gpio.hpp>
#include <STM32H523/rcc.hpp>

namespace STM32H523
{

using mmio::atomic;

/**
 * @brief External watchdog, as a module.
 *
 *        All methods are static — no instance needed. init() is used by bornier::app.
 */
class ext_watchdog
{
public:

	/** @brief Drives WDI, unless a debugger is attached. */
	static void init()
	{
		armed_ = !debugger_attached();
		if (!armed_)
			return;
		rcc.ahb2enr |= rcc_p::ahb2enr_r::gpioden_f() | atomic;
		gpiod.moder <<= gpio_p::moder_r::mode15_f(0b01) || atomic;
	}

	/** @brief One edge on WDI: the watched task is alive. */
	static void feed()
	{
		if (!armed_)
			return;
		high_ = !high_;
		if (high_)
			gpiod.bsrr = gpio_p::bsrr_r::bs15_f();
		else
			gpiod.bsrr = gpio_p::bsrr_r::br15_f();
	}

	/** @brief Whether the watchdog runs: no debugger was attached at start. */
	static bool armed() { return armed_; }

private:

	/// DHCSR, Debug Halting Control and Status Register; C_DEBUGEN (bit 0) is set while a
	/// debugger has debug enabled.
	static bool debugger_attached()
	{
		return (*reinterpret_cast<volatile const uint32_t*>(dhcsr) & c_debugen) != 0;
	}

	static constexpr uintptr_t dhcsr = 0xE000EDF0;
	static constexpr uint32_t c_debugen = 1u << 0;

	static inline bool armed_ = false;
	static inline bool high_ = false;
};

} // namespace STM32H523
