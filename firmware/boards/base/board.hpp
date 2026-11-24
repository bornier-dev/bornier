// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    board.hpp
 * @author  Thomas Legrand
 * @brief   Module of the Bornier base board: system clock and base vector table
 *
 *          First module of every image (bornier::app<board, ...>, core/app.hpp):
 *
 *          - init() brings the core to 250 MHz (clock.hpp);
 *          - vectors is the base vector table: stack top, reset handler, Default_Handler for
 *            every slot nobody fills, the three handlers of OpSy, and on_fault() behind the
 *            four fault exceptions. The modules of the image add theirs to it.
 *
 *          A fault, a failed assertion or an unexpected interrupt puts the outputs in their
 *          safe state (safe_outputs()), is recorded (fault_log.hpp) and resets the MCU.
 *
 *          The handlers named here are defined in startup.cpp.
 ******************************************************************************
 */

#pragma once

#include <cstdint>

#include <fault.hpp>
#include <hooks.hpp>
#include <scheduler.hpp>
#include <STM32H523/rcc.hpp>
#include <STM32H523/vectors.hpp>

#include <bornier/trace.hpp>
#include <clock.hpp>
#include <drive_ports.hpp>
#include <step_generator.hpp>

extern "C"
{
extern std::uint32_t _estack;    ///< Top of the main stack (linker script)
[[noreturn]] void Reset_Handler();
[[noreturn]] void Default_Handler();
}

namespace STM32H523
{

/** @brief The fault exceptions, see fault_log.hpp. */
void on_fault(const opsy::fault_status& status, opsy::exception_frame& frame, uint32_t exc_return);

/** @brief The Bornier base board, as a module. */
class board
{
public:

	/** @brief Base vector table of every image on this board. */
	static constexpr auto vectors = vector_table<Default_Handler, opsy::hooked_isr>(&_estack, Reset_Handler)
	    .with(opsy::scheduler::isrs)
	    .with(opsy::fault_isrs<on_fault>);

	/** @brief Brings the system clock to 250 MHz, and starts the time stamps of the trace. */
	static void init()
	{
		clock::init();
		bornier::trace::init();
	}

	/**
	 * @brief The outputs of the board in their safe state, from their registers only: every
	 *        drive disabled, the step generator stopped. For the fault handlers: nothing of
	 *        the software is trusted. A peripheral the image does not clock is left alone.
	 */
	static void safe_outputs()
	{
		if (rcc.ahb2enr.load().gpioeen())
			for (std::size_t n = 0; n < drive_ports::count; ++n)
				drive_ports::enable(n, false);
		step_generator::stop();
	}
};

} // namespace STM32H523
