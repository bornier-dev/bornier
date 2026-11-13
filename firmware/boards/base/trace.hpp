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
 *          starts listening; without a probe nothing is sent and @c write() returns at once.
 *
 *          Output only: SWO has no return path.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <cstdint>
#include <string_view>

#include <STM32H523/dbgmcu.hpp>

namespace STM32H523
{

/**
 * @brief Text output on SWO.
 *
 *        All methods are static — no instance needed.
 *        Call @c init() once before @c write().
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
		dbgmcu.dbgmcu_cr = dbgmcu.dbgmcu_cr.load()
		                 | dbgmcu_p::dbgmcu_cr_r::trace_ioen_f()
		                 | dbgmcu_p::dbgmcu_cr_r::trace_en_f();
	}

	/**
	 * @brief Sends text on stimulus port 0, blocking while the ITM buffer is full.
	 *
	 *        Not reentrant: call it from a single task. The text is dropped when no probe has
	 *        enabled the ITM and its port 0.
	 *
	 * @param text Characters to send.
	 */
	static void write(std::string_view text)
	{
		if ((reg32(itm_tcr) & itm_tcr_itmena) == 0 || (reg32(itm_ter) & 1u) == 0)
			return;

		for (const char c : text)
		{
			// Reading a stimulus port gives 1 when it accepts a new value.
			while ((reg32(itm_stim0) & 1u) == 0) {}
			reg8(itm_stim0) = static_cast<uint8_t>(c);
		}
	}

private:

	// ITM registers of the Cortex-M33 (Armv8-M Architecture Reference Manual).
	static constexpr uintptr_t itm_stim0 = 0xE0000000; ///< Stimulus port 0; a byte write sends one byte
	static constexpr uintptr_t itm_ter   = 0xE0000E00; ///< Trace enable, one bit per stimulus port
	static constexpr uintptr_t itm_tcr   = 0xE0000E80; ///< Trace control
	static constexpr uint32_t  itm_tcr_itmena = 1u << 0;

	static volatile uint32_t& reg32(uintptr_t address) { return *reinterpret_cast<volatile uint32_t*>(address); }
	static volatile uint8_t&  reg8(uintptr_t address)  { return *reinterpret_cast<volatile uint8_t*>(address); }
};

} // namespace STM32H523
