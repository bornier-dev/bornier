// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    trace.hpp
 * @author  Thomas Legrand
 * @brief   Text output of the Bornier base board on SWO (PB3, pin 6 of the debug connector)
 *
 *          The text leaves through stimulus port 0 of the ITM, the trace unit of the
 *          Cortex-M33. The debug probe sets up the ITM and the bit rate of the pin when it
 *          starts listening.
 *
 *          Writing never waits: write() stores the text in a queue, and a task of this module
 *          (start()) hands it to the ITM, sleeping while the stimulus port is busy. Text that
 *          does not fit in the queue is dropped and counted (dropped()), never waited for.
 *          Without a probe listening, or once it has stopped, the task sleeps and nothing else
 *          is affected: the ITM keeps its settings through a reset of the MCU, so a probe that
 *          has listened once leaves a port that may never become ready again.
 *
 *          write() is for tasks, not interrupt handlers. Writers are serialised by a mutex:
 *          the text of one call is never interleaved with another's.
 *
 *          Output only: SWO has no return path.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <mutex>
#include <string_view>

#include <opsy.hpp>
#include <mutex.hpp>
#include <queue.hpp>

#include <STM32H523/dbgmcu.hpp>

namespace STM32H523
{

/**
 * @brief Text output on SWO, as a module: init() hands PB3 to the trace port, start() starts
 *        the task that empties the queue.
 *
 *        All methods are static — no instance needed.
 */
class trace
{
public:

	/**
	 * @brief Hands PB3 to the trace port, in asynchronous (SWO) mode.
	 *
	 *        PB3 is the trace output from reset (alternate function 0): only the trace port
	 *        itself has to be switched on. TRACE_MODE keeps its reset value, 0: asynchronous.
	 */
	static void init()
	{
		dbgmcu.cr = dbgmcu.cr.load()
		                 | dbgmcu_p::cr_r::trace_ioen_f()
		                 | dbgmcu_p::cr_r::trace_en_f();
	}

	/** @brief Starts the task that hands the queued text to the ITM. */
	static bool start() { return task_.start([] { run(); }); }

	/**
	 * @brief Queues @p text for SWO; what does not fit is dropped.
	 *
	 * @param text Characters to send.
	 */
	static void write(std::string_view text)
	{
		const std::lock_guard lock(writers_);
		for (const char c : text)
			(void)queue_.try_push(c);
	}

	/** @brief Characters dropped because the queue was full. */
	static std::size_t dropped() { return queue_.dropped(); }

private:

	static constexpr std::size_t capacity = 2048;

	static void run()
	{
		using namespace std::chrono_literals;
		while (const auto c = queue_.pop())
		{
			// Without a probe, the ITM or its port 0 is off: the text is dropped.
			if ((reg32(itm_tcr) & itm_tcr_itmena) == 0 || (reg32(itm_ter) & 1u) == 0)
				continue;
			// Reading a stimulus port gives 1 when it accepts a new value.
			while ((reg32(itm_stim0) & 1u) == 0)
				opsy::sleep_for(1ms);
			reg8(itm_stim0) = static_cast<uint8_t>(*c);
		}
	}

	// ITM registers of the Cortex-M33 (Armv8-M Architecture Reference Manual).
	static constexpr uintptr_t itm_stim0 = 0xE0000000; ///< Stimulus port 0; a byte write sends one byte
	static constexpr uintptr_t itm_ter   = 0xE0000E00; ///< Trace enable, one bit per stimulus port
	static constexpr uintptr_t itm_tcr   = 0xE0000E80; ///< Trace control
	static constexpr uint32_t  itm_tcr_itmena = 1u << 0;

	static volatile uint32_t& reg32(uintptr_t address) { return *reinterpret_cast<volatile uint32_t*>(address); }
	static volatile uint8_t&  reg8(uintptr_t address)  { return *reinterpret_cast<volatile uint8_t*>(address); }

	static inline opsy::queue<char, capacity> queue_;
	static inline opsy::mutex writers_;
	static inline opsy::task<512> task_;
};

} // namespace STM32H523
