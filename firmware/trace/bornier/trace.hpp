// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    trace.hpp
 * @author  Thomas Legrand
 * @brief   The trace of every Bornier image: Kymo events in a ring the host reads through SWD
 *
 *          An event is a plain struct, written with bornier::trace::emit(event): it costs a
 *          few dozen cycles, never waits, never masks interrupts, and may be emitted from a
 *          task or an interrupt handler. The ring is a Kymo ring in RAM; the host reads it
 *          through the debug port while the program runs (`kymo record`), and finds the
 *          layout and name of each event in the ELF. The target sends no text.
 *
 *          What OpSy does (tasks, interrupts, mutexes) is traced too, through its hooks
 *          (opsy_hooks.hpp), into the same ring.
 *
 *          When the ring is full, the oldest events are overwritten: the host counts what it
 *          missed. Without a probe, nothing reads the ring and nothing else changes.
 *
 *          This header must not include OpSy: OpSy includes it, through opsy_hooks.hpp.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <cstddef>
#include <cstdint>

#include <kymo/kymo.hpp>

namespace bornier
{

/// Slots of the trace ring, 16 bytes each. An event of up to 8 bytes takes one slot.
constexpr std::size_t trace_slots = 512;

/// The trace ring, the only one of every image: `kymo record` drains it.
inline kymo::ring<trace_slots> trace_ring;

/**
 * @brief The tracer of every image, as a module: init() starts the cycle counter the events
 *        are stamped with; emit() writes an event.
 *
 *        All methods are static — no instance needed.
 */
struct trace : kymo::tracer<trace>
{
	/** @brief Every family goes to the one ring. */
	template<kymo::family F>
	static auto& channel(kymo::on<F> /*family*/)
	{
		return trace_ring;
	}

	/**
	 * @brief Starts the DWT cycle counter, the time stamp of every event.
	 *
	 *        TRCENA in DEMCR powers the DWT, CYCCNTENA in DWT_CTRL starts the counter; both
	 *        keep counting once a probe leaves.
	 */
	static void init()
	{
		reg32(demcr) = reg32(demcr) | demcr_trcena;
		reg32(dwt_ctrl) = reg32(dwt_ctrl) | dwt_ctrl_cyccntena;
	}

private:

	// Debug registers of the Cortex-M33 (Armv8-M Architecture Reference Manual).
	static constexpr std::uintptr_t demcr    = 0xE000EDFC; ///< Debug Exception and Monitor Control
	static constexpr std::uintptr_t dwt_ctrl = 0xE0001000; ///< DWT control
	static constexpr std::uint32_t demcr_trcena       = 1u << 24;
	static constexpr std::uint32_t dwt_ctrl_cyccntena = 1u << 0;

	static volatile std::uint32_t& reg32(std::uintptr_t address)
	{
		return *reinterpret_cast<volatile std::uint32_t*>(address);
	}
};

} // namespace bornier
