// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    blinker.hpp
 * @author  Thomas Legrand
 * @brief   Example module: blinks a LED at 1 Hz and traces one numbered event per blink
 *
 *          The template to copy when writing a module (firmware/README.md, "Writing a
 *          module"). It shows:
 *
 *          - dependencies taken as template parameters, constrained by concepts that the
 *            module itself declares: it says what it needs, not which driver gives it;
 *          - a task started by start(), the member bornier::app calls for modules with tasks;
 *          - a report in the trace, one event per blink, that a test script can check: an
 *            event is a plain struct, named for what happened.
 *
 *          It has no init() (it owns no hardware: its LED and its trace are set up by their
 *          own modules) and no isrs (no interrupt).
 ******************************************************************************
 */

#pragma once

#include <chrono>
#include <cstdint>

#include <opsy.hpp>

namespace example
{

/** @brief The event of one blink: its number, from 0. */
struct blink
{
	std::uint32_t count;
};

/** @brief Something that can be switched on and off: a LED, an output. */
template<typename T>
concept switchable = requires
{
	T::on();
	T::off();
};

/** @brief Somewhere to emit events: the trace (bornier::trace). */
template<typename T>
concept event_sink = requires(blink event)
{
	T::emit(event);
};

/**
 * @brief Blinks @p Led at 1 Hz and emits a numbered @ref blink on @p Trace at each blink.
 *
 *        A steady 1 Hz proves the oscillator, the PLL and the scheduler tick.
 *
 * @tparam Led   What blinks.
 * @tparam Trace Where the events go.
 */
template<switchable Led, event_sink Trace>
class blinker
{
public:

	/** @brief Starts the blinking task; false if the scheduler refused it. */
	static bool start() { return task_.start(run); }

private:

	static void run()
	{
		using namespace std::chrono_literals;
		for (std::uint32_t count = 0; ; ++count)
		{
			Trace::emit(blink{count});

			Led::on();
			opsy::sleep_for(500ms);
			Led::off();
			opsy::sleep_for(500ms);
		}
	}

	static inline opsy::task<1024> task_;
};

} // namespace example
