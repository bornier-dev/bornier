// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// On-target test for the Bornier base board: the EtherCAT Slave Stack Code runs on the board,
// serves the emulated SII EEPROM of the LAN9253 and answers the master. Built only when
// BORNIER_SSC_DIR points at the generated stack. The check is made from the master: it reads
// the SII and brings the slave to PREOP.
//
// The stack runs from one task: its main loop as fast as it goes, its timer every millisecond.
// No ESC interrupt is used yet.
//
// Report on SWO, once per second:
//   al_status  AL status register (0x0130): 1 INIT, 2 PREOP, 4 SAFEOP, 8 OP, bit 4 error
//   al_code    AL status code (0x0134), 0 when no error
//   eeprom     EEPROM control/status (0x0502); bit 12 set while the configuration is not loaded

#include <application.hpp>
#include <board.hpp>
#include <opsy.hpp>
#include <cortex_m.hpp>
#include <scheduler.hpp>
#include <clock.hpp>
#include <esc_bus.hpp>
#include <led.hpp>
#include <trace.hpp>

extern "C" {
#include <applInterface.h>
}

#include <charconv>
#include <chrono>
#include <cstdint>
#include <string_view>

using namespace std::chrono_literals;
using namespace STM32H523;

// Not yet composed from modules (core/app.hpp): the image takes the board's vector table as is.
[[gnu::section(".isr_vector"), gnu::used]]
constexpr auto g_vectors = STM32H523::board::vectors;

namespace
{

void print_hex(std::string_view name, uint32_t value)
{
	char digits[8];
	const auto end = std::to_chars(digits, digits + sizeof(digits), value, 16).ptr;
	trace::write(name);
	trace::write(" 0x");
	trace::write(std::string_view(digits, end));
	trace::write("\r\n");
}

} // namespace

opsy::task<2048> stack;

void application()
{
	clock::init();
	mcu_led::init();
	trace::init();

	const bool system_ok = stack.start([]{
		if (HW_Init() != 0)
		{
			trace::write("verdict FAIL hw_init\r\n");
			return;
		}
		(void)MainInit();
		bRunApplication = TRUE;

		auto next_tick = opsy::scheduler::now() + 1ms;
		auto next_report = opsy::scheduler::now() + 1s;
		while (true)
		{
			MainLoop();

			const auto now = opsy::scheduler::now();
			if (now >= next_tick)
			{
				ECAT_CheckTimer();
				next_tick += 1ms;
			}
			if (now >= next_report)
			{
				const uint32_t al_status = esc_bus::core_read(0x0130, 2);
				print_hex("al_status", al_status);
				print_hex("al_code", esc_bus::core_read(0x0134, 2));
				print_hex("eeprom", esc_bus::core_read(0x0502, 2));
				if ((al_status & 0x0F) >= 2)
					mcu_led::on();
				else
					mcu_led::off();
				next_report += 1s;
			}
		}
	});

	if (!system_ok)
		asm volatile("bkpt 0");

	opsy::scheduler::start(); // does not return
}
