// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// Bring-up example: blinks LD1 and echoes UART input (ST-LINK virtual COM port, 115200 8N1).

#include <opsy.hpp>
#include <cortex_m.hpp>
#include <scheduler.hpp>
#include <clock.hpp>
#include <led.hpp>
#include <uart.hpp>

#include <chrono>

using namespace std::chrono_literals;
using namespace STM32H563;


opsy::task<512>  blinker;
opsy::task<1024> serial;

int main()
{
	clock::init();
	user_leds::init();
	uart::init();

	bool system_ok = true;

	system_ok &= blinker.start([]{
		while (true)
		{
			user_leds::on(user_leds::led::ld1);
			opsy::sleep_for(500ms);
			user_leds::off(user_leds::led::ld1);
			opsy::sleep_for(500ms);
		}
	});

	system_ok &= serial.start([]{
		const char greeting[] = "NUCLEO-H563ZI ready\r\n";
		uart::send(std::span<const uint8_t>(reinterpret_cast<const uint8_t*>(greeting), sizeof(greeting) - 1));

		while (true)
		{
			auto rx = uart::receive();
			if (!rx.empty())
				uart::send(rx); // echo back
		}
	});





	if (!system_ok)
		asm volatile("bkpt 0");

	opsy::scheduler::start(); // does not return
}
