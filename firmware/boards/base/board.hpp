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
 *            every slot nobody fills, and the three handlers of OpSy. The modules of the
 *            image add theirs to it.
 *
 *          The handlers named here are defined in startup.cpp.
 ******************************************************************************
 */

#pragma once

#include <cstdint>

#include <hooks.hpp>
#include <scheduler.hpp>
#include <STM32H523/vectors.hpp>

#include <clock.hpp>

extern "C"
{
extern std::uint32_t _estack;    ///< Top of the main stack (linker script)
[[noreturn]] void Reset_Handler();
[[noreturn]] void Default_Handler();
}

namespace STM32H523
{

/** @brief The Bornier base board, as a module. */
class board
{
public:

	/** @brief Base vector table of every image on this board. */
	static constexpr auto vectors = vector_table<Default_Handler, opsy::hooked_isr>(&_estack, Reset_Handler)
	    .with(opsy::scheduler::isrs);

	/** @brief Brings the system clock to 250 MHz. */
	static void init() { clock::init(); }
};

} // namespace STM32H523
