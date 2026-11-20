// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// On-target test for the Bornier base board: supply voltages read by ADC1. VREFINT against its
// factory calibration gives VDDA, the 3.3 V rail; VIN_SENSE, the divided +VIN, gives +VIN on
// that scale. The board must be supplied through its terminal block (12 or 24 V): on USB alone,
// +VIN is absent and the test fails.
//
// Report on SWO, once per second:
//   vrefint_cal  factory reading of VREFINT at 3.3 V, 12 bits
//   vrefint      reading of VREFINT now, 12 bits
//   vin_raw      reading of VIN_SENSE, 12 bits
//   vdda_mv      VDDA in millivolts
//   vin_mv       +VIN in millivolts
//   verdict      PASS when VDDA is within 3.3 V +-5 % and +VIN within 10.8 to 30 V

#include <application.hpp>
#include <app.hpp>
#include <board.hpp>
#include <opsy.hpp>
#include <cortex_m.hpp>
#include <scheduler.hpp>
#include <clock.hpp>
#include <led.hpp>
#include <supplies.hpp>
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

/** @brief The test, as a module: one task that runs the checks and reports on SWO. */
class supply_monitor_test
{
public:
	static bool start()
	{
		return task_.start([]{
			while (true)
			{
				opsy::sleep_for(1s);

				const auto r = supplies::read();
				print_number("vrefint_cal", supplies::vrefint_cal());
				print_number("vrefint", r.vrefint_raw);
				print_number("vin_raw", r.vin_raw);
				print_number("vdda_mv", r.vdda_mv);
				print_number("vin_mv", r.vin_mv);

				const bool pass = r.vdda_mv >= 3135 && r.vdda_mv <= 3465
				               && r.vin_mv >= 10800 && r.vin_mv <= 30000;
				trace::write(pass ? "verdict PASS\r\n" : "verdict FAIL\r\n");

				if (pass)
					mcu_led::on();
				else
					mcu_led::off();
			}
		});
	}

private:
	static inline opsy::task<1024> task_;
};

using status_led = mcu_led;
using console    = trace;
using rails      = supplies;

using app = bornier::app<board, status_led, console, rails, supply_monitor_test>;

void application()
{
	app::run();
}
