// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// On-target test for the Bornier base board: isolated RS-485 port, with nothing wired to the
// MODBUS terminal block. The receiver of the transceiver is always on, so every byte sent comes
// back: the test sends the 256 byte values and checks each echo. That path goes through the
// isolated supply of the transceiver, its driver, the biased and terminated line and its
// receiver.
//
// Report on SWO, once per second:
//   idle     1 when the receiver sees the line idle before the test (line bias works)
//   echoed   number of bytes that came back right, out of 256
//   missing  number of bytes that did not come back
//   errors   framing, noise and overrun errors seen (1 each), as three digits
//   verdict  PASS when idle, 256 echoed, none missing and no error

#include <opsy.hpp>
#include <cortex_m.hpp>
#include <scheduler.hpp>
#include <clock.hpp>
#include <led.hpp>
#include <rs485.hpp>
#include <trace.hpp>

#include <charconv>
#include <chrono>
#include <cstdint>
#include <string_view>

using namespace std::chrono_literals;
using namespace STM32H523;

namespace
{

void print_number(std::string_view name, uint32_t value)
{
	char digits[10];
	const auto end = std::to_chars(digits, digits + sizeof(digits), value).ptr;
	trace::write(name);
	trace::write(" ");
	trace::write(std::string_view(digits, end));
	trace::write("\r\n");
}

} // namespace

opsy::task<1024> tester;

int main()
{
	clock::init();
	mcu_led::init();
	trace::init();
	rs485::init();

	const bool system_ok = tester.start([]{
		while (true)
		{
			opsy::sleep_for(1s);

			(void)rs485::take_errors();
			const bool idle = rs485::line_idle();

			// A byte lasts 87 us; 100000 polls last several milliseconds.
			uint32_t echoed = 0;
			uint32_t missing = 0;
			for (uint32_t value = 0; value < 256; ++value)
			{
				rs485::send(static_cast<uint8_t>(value));
				const auto echo = rs485::receive(100000);
				if (!echo)
					++missing;
				else if (*echo == value)
					++echoed;
			}
			const auto errors = rs485::take_errors();

			print_number("idle", idle ? 1 : 0);
			print_number("echoed", echoed);
			print_number("missing", missing);
			trace::write("errors ");
			trace::write(errors.framing ? "1" : "0");
			trace::write(errors.noise ? "1" : "0");
			trace::write(errors.overrun ? "1" : "0");
			trace::write("\r\n");

			const bool pass = idle && echoed == 256 && missing == 0
			               && !errors.framing && !errors.noise && !errors.overrun;
			trace::write(pass ? "verdict PASS\r\n" : "verdict FAIL\r\n");

			if (pass)
				mcu_led::on();
			else
				mcu_led::off();
		}
	});

	if (!system_ok)
		asm volatile("bkpt 0");

	opsy::scheduler::start(); // does not return
}
