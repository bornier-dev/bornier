// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// On-target test for the Bornier base board: reads the identification registers of the LAN9253
// through the OCTOSPI and prints them on SWO, once per second.
//
//   BYTE_TEST must read 0x87654321: the bus works and the byte order is right.
//   ID_REV must read 0x9253 in its upper half: the chip is a LAN9253.

#include <opsy.hpp>
#include <cortex_m.hpp>
#include <scheduler.hpp>
#include <clock.hpp>
#include <esc_bus.hpp>
#include <led.hpp>
#include <trace.hpp>

#include <charconv>
#include <chrono>
#include <cstdint>
#include <string_view>

using namespace std::chrono_literals;
using namespace STM32H523;

namespace
{

void print_register(std::string_view name, uint32_t value)
{
	char digits[8];
	const auto end = std::to_chars(digits, digits + sizeof(digits), value, 16).ptr;
	trace::write(name);
	trace::write(" 0x");
	trace::write(std::string_view("00000000").substr(0, sizeof(digits) - static_cast<std::size_t>(end - digits)));
	trace::write(std::string_view(digits, end));
	trace::write("\r\n");
}

} // namespace

opsy::task<1024> prober;

int main()
{
	clock::init();
	mcu_led::init();
	trace::init();
	esc_bus::init();

	const bool system_ok = prober.start([]{
		while (true)
		{
			const uint32_t byte_test = esc_bus::read(esc_bus::byte_test);
			const uint32_t id_rev    = esc_bus::read(esc_bus::id_rev);
			const bool pass = byte_test == 0x87654321u && (id_rev >> 16) == 0x9253u;

			print_register("byte_test", byte_test);
			print_register("id_rev", id_rev);
			trace::write(pass ? "verdict PASS\r\n" : "verdict FAIL\r\n");

			if (pass)
				mcu_led::on();
			else
				mcu_led::off();
			opsy::sleep_for(1s);
		}
	});

	if (!system_ok)
		asm volatile("bkpt 0");

	opsy::scheduler::start(); // does not return
}
