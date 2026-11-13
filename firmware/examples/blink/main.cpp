// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// Bring-up example for the Bornier base board: blinks the MCU LED at 1 Hz from an OpSy task and
// prints one numbered line per blink on SWO. A steady 1 Hz proves the 25 MHz oscillator, the PLL
// and the scheduler tick.

#include <opsy.hpp>
#include <cortex_m.hpp>
#include <scheduler.hpp>
#include <clock.hpp>
#include <led.hpp>
#include <trace.hpp>

#include <charconv>
#include <chrono>
#include <cstdint>
#include <string_view>

using namespace std::chrono_literals;
using namespace STM32H523;

opsy::task<1024> blinker;

int main()
{
	clock::init();
	mcu_led::init();
	trace::init();

	const bool system_ok = blinker.start([]{
		for (uint32_t count = 0; ; ++count)
		{
			char digits[10];
			const auto end = std::to_chars(digits, digits + sizeof(digits), count).ptr;
			trace::write("Bornier base blink ");
			trace::write(std::string_view(digits, end));
			trace::write("\r\n");

			mcu_led::on();
			opsy::sleep_for(500ms);
			mcu_led::off();
			opsy::sleep_for(500ms);
		}
	});

	if (!system_ok)
		asm volatile("bkpt 0");

	opsy::scheduler::start(); // does not return
}
