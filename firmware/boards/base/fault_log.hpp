// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    fault_log.hpp
 * @author  Thomas Legrand
 * @brief   Record of the last fatal fault of the Bornier base board, kept through the reset
 *
 *          A fault of the core (HardFault, MemManage, BusFault, UsageFault, a trap of OpSy
 *          among them), a failed assertion or an interrupt nobody handles all end in one place
 *          (startup.cpp):
 *
 *          1. the outputs go to their safe state at once, from their registers only
 *             (board::safe_outputs());
 *          2. what happened is written here: fault status, the frame the core stacked, the
 *             stack above it;
 *          3. the MCU resets.
 *
 *          The record sits in .noinit, a RAM section the startup neither copies nor clears: it
 *          is kept through any reset but a power cycle (a reset of the MCU alone, the external
 *          watchdog's included). @c key tells a record from what RAM holds after power-up.
 *
 *          For the bench: a debugger may write @c hold_key into @c hold. A fault then leaves
 *          the outputs safe and stays in its handler, feeding the external watchdog, instead
 *          of resetting: the whole RAM is there to read.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <array>
#include <cstdint>

#include <fault.hpp>

namespace bornier
{

/** @brief The last fatal fault, and the starts since power-up; see the top of this file. */
struct fault_log
{
	/** @brief What ended in the fault handler. */
	enum class cause : uint32_t
	{
		none,      ///< No fault since power-up
		fault,     ///< A fault exception of the core, a trap of OpSy among them
		assertion, ///< A failed assertion: @c file, @c detail its line
		interrupt, ///< An interrupt nobody handles: @c detail its exception number
	};

	static constexpr uint32_t record_key = 0xB0A2'D1E5;
	static constexpr uint32_t hold_key   = 0x4010'1D00;

	uint32_t key;    ///< record_key once written since power-up
	uint32_t hold;   ///< hold_key: a fault stays in its handler instead of resetting
	uint32_t starts; ///< Starts since power-up, this one included
	uint32_t faults; ///< Fatal faults since power-up
	uint32_t start_of_fault; ///< The start the last fault happened in

	cause what;
	uint32_t cfsr;   ///< Fault status, see opsy::fault_status
	uint32_t hfsr;
	uint32_t mmfar;
	uint32_t bfar;
	opsy::exception_frame frame; ///< Registers stacked by the fault; zero for an interrupt
	uint32_t exc_return;
	uint32_t detail;
	const char* file;
	std::array<uint32_t, 48> stack; ///< The stack above the frame: return addresses, for a backtrace

	/** @brief Counts a start; called once, by the startup, before the application. */
	void count_start()
	{
		if (key != record_key)
		{
			*this = fault_log{};
			key = record_key;
		}
		++starts;
	}
};

/** @brief The record, in .noinit (defined in startup.cpp); see the top of this file. */
extern fault_log last_fault;

} // namespace bornier
