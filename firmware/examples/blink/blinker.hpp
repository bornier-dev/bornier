// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    blinker.hpp
 * @author  Thomas Legrand
 * @brief   Example module: blinks a LED at 1 Hz and prints one numbered line per blink
 *
 *          The template to copy when writing a module (firmware/README.md, "Writing a
 *          module"). It shows:
 *
 *          - dependencies taken as template parameters, constrained by concepts that the
 *            module itself declares: it says what it needs, not which driver gives it;
 *          - a task started by start(), the member bornier::app calls for modules with tasks;
 *          - a report on the text output, one line per event, that a test script can parse.
 *
 *          It has no init() (it owns no hardware: its LED and its output are set up by their
 *          own modules) and no isrs (no interrupt).
 ******************************************************************************
 */

#pragma once

#include <charconv>
#include <chrono>
#include <cstdint>
#include <string_view>

#include <opsy.hpp>

namespace example
{

/** @brief Something that can be switched on and off: a LED, an output. */
template<typename T>
concept switchable = requires
{
	T::on();
	T::off();
};

/** @brief Somewhere to write text: the SWO console, a UART. */
template<typename T>
concept text_output = requires(std::string_view text)
{
	T::write(text);
};

/**
 * @brief Blinks @p Led at 1 Hz and writes "Bornier base blink <n>" on @p Output at each blink.
 *
 *        A steady 1 Hz proves the oscillator, the PLL and the scheduler tick.
 *
 * @tparam Led    What blinks.
 * @tparam Output Where the lines go.
 */
template<switchable Led, text_output Output>
class blinker
{
public:

	/** @brief Starts the blinking task; false if the scheduler refused it. */
	static bool start() { return task_.start([] { run(); }); }

private:

	static void run()
	{
		using namespace std::chrono_literals;
		for (std::uint32_t count = 0; ; ++count)
		{
			char digits[10];
			const auto end = std::to_chars(digits, digits + sizeof(digits), count).ptr;
			Output::write("Bornier base blink ");
			Output::write(std::string_view(digits, end));
			Output::write("\r\n");

			Led::on();
			opsy::sleep_for(500ms);
			Led::off();
			opsy::sleep_for(500ms);
		}
	}

	static inline opsy::task<1024> task_;
};

} // namespace example
