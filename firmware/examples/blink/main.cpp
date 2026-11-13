// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// Bring-up example for the Bornier base board: blinks the MCU LED at 1 Hz from an OpSy task.
// A steady 1 Hz proves the 25 MHz oscillator, the PLL and the scheduler tick.

#include <opsy.hpp>
#include <cortex_m.hpp>
#include <scheduler.hpp>
#include <clock.hpp>
#include <led.hpp>

#include <chrono>

using namespace std::chrono_literals;
using namespace STM32H523;

opsy::task<512> blinker;

int main()
{
	clock::init();
	mcu_led::init();

	const bool system_ok = blinker.start([]{
		while (true)
		{
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
