// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// On-target test for the Bornier base board: talks to the LAN9253 through the OCTOSPI and prints
// a report on SWO, once per second. The same checks run in both bus modes, single then quad:
//
//   byte_test   must read 0x87654321: the bus works and the byte order is right.
//   id_rev      must read 0x9253 in its upper half: the chip is a LAN9253.
//   user_ram    two patterns written to the user RAM of the EtherCAT core (0x0F80) must read
//               back, as 32 bits then as 16 and 8 bits: register writes and core accesses work.
//
// Single mode passing and quad mode failing points at SIO2 or SIO3.
//
// Printed for information:
//   hw_cfg         READY (bit 27) stays 0 until the configuration has been loaded from the SII
//                  EEPROM, which this board emulates: the firmware has to serve it.
//   core_type      first registers of the EtherCAT core: type, revision, build.
//   core_product   product ID of the EtherCAT core.
//   core_al_event  AL event request; bit 5 is a pending request to the EEPROM emulation.
//   core_eeprom    EEPROM configuration (low half) and status (high half); in the status,
//                  bit 5 tells that the EEPROM is emulated and bit 15 that a request waits.

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

constexpr uint16_t core_type     = 0x0000; // type, revision, build (2 bytes)
constexpr uint16_t core_al_event = 0x0220;
constexpr uint16_t core_eeprom   = 0x0500;
constexpr uint16_t core_product  = 0x0E00;
constexpr uint16_t core_user_ram = 0x0F80;

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

// Writes a pattern to the user RAM and reads it back in the three access sizes.
bool user_ram_holds(uint32_t pattern)
{
	esc_bus::core_write(core_user_ram, pattern, 4);
	const uint32_t whole = esc_bus::core_read(core_user_ram, 4);
	const uint32_t upper = esc_bus::core_read(static_cast<uint16_t>(core_user_ram + 2), 2);
	const uint32_t byte1 = esc_bus::core_read(static_cast<uint16_t>(core_user_ram + 1), 1);
	print_register("user_ram", whole);
	return whole == pattern && upper == pattern >> 16 && byte1 == ((pattern >> 8) & 0xFFu);
}

// Runs all the checks in the current bus mode.
bool bus_works()
{
	const uint32_t byte_test = esc_bus::read(esc_bus::byte_test);
	const uint32_t id_rev    = esc_bus::read(esc_bus::id_rev);
	print_register("byte_test", byte_test);
	print_register("id_rev", id_rev);
	print_register("hw_cfg", esc_bus::read(esc_bus::hw_cfg));

	// The core is only reached once the bus itself is proven: a core access polls the chip,
	// and would never end on a dead bus.
	if (byte_test != 0x87654321u || (id_rev >> 16) != 0x9253u)
		return false;

	print_register("core_type", esc_bus::core_read(core_type, 4));
	print_register("core_product", esc_bus::core_read(core_product, 4));
	print_register("core_al_event", esc_bus::core_read(core_al_event, 4));
	print_register("core_eeprom", esc_bus::core_read(core_eeprom, 4));
	const bool first  = user_ram_holds(0xA5C33C5Au);
	const bool second = user_ram_holds(0x5A3CC3A5u);
	return first && second;
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
			esc_bus::set_mode(esc_bus::mode::single);
			trace::write("mode single\r\n");
			const bool single = bus_works();
			trace::write(single ? "single PASS\r\n" : "single FAIL\r\n");

			esc_bus::set_mode(esc_bus::mode::quad);
			trace::write("mode quad\r\n");
			const bool quad = bus_works();
			trace::write(quad ? "quad PASS\r\n" : "quad FAIL\r\n");

			const bool pass = single && quad;
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
