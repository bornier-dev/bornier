// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// On-target test for the Bornier base board: supply voltages read by ADC1. VREFINT against its
// factory calibration gives VDDA, the 3.3 V rail; VIN_SENSE, the divided +VIN, gives +VIN on
// that scale. The board must be supplied through its terminal block (12 or 24 V): on USB alone,
// +VIN is absent and the test fails.
//
// Report in the trace (bornier/trace.hpp), once per second, a supply_monitor::measured event:
//   vrefint_cal  factory reading of VREFINT at 3.3 V, 12 bits
//   vrefint      reading of VREFINT now, 12 bits
//   vin_raw      reading of VIN_SENSE, 12 bits
//   vdda_mv      VDDA in millivolts
//   vin_mv       +VIN in millivolts
//   pass         VDDA within 3.3 V +-5 % and +VIN within 10.8 to 30 V
// or a supply_monitor::no_reading event when the ADC has nothing yet, or is stuck.

#include <application.hpp>
#include <app.hpp>
#include <board.hpp>
#include <bornier/trace.hpp>
#include <opsy.hpp>
#include <cortex_m.hpp>
#include <scheduler.hpp>
#include <clock.hpp>
#include <led.hpp>
#include <supplies.hpp>

#include <chrono>
#include <cstdint>

using namespace std::chrono_literals;
using namespace STM32H523;

/// The events of the test, as `kymo record` prints them: supply_monitor::<name>.
namespace supply_monitor
{

/** @brief One reading of the supplies, and its verdict. */
struct measured
{
	uint32_t vrefint_cal;
	uint32_t vrefint;
	uint32_t vin_raw;
	uint32_t vdda_mv;
	uint32_t vin_mv;
	bool     pass;
};

/** @brief No measurement yet, or the ADC is stuck. */
struct no_reading {};

} // namespace supply_monitor

/** @brief The test, as a module: one task that runs the checks and reports in the trace. */
class supply_monitor_test
{
public:
	static bool start()
	{
		return task_.start([]{
			while (true)
			{
				opsy::sleep_for(1s);

				const auto reading = supplies::read();
				if (!reading)
				{
					bornier::trace::emit(supply_monitor::no_reading{});
					mcu_led::off();
					continue;
				}
				const auto& r = *reading;
				const bool pass = r.vdda_mv >= 3135 && r.vdda_mv <= 3465
				               && r.vin_mv >= 10800 && r.vin_mv <= 30000;
				bornier::trace::emit(supply_monitor::measured{
					r.vrefint_cal, r.vrefint_raw, r.vin_raw, r.vdda_mv, r.vin_mv, pass});

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
using rails      = supplies;

using app = bornier::app<board, status_led, rails, supply_monitor_test>;

void application()
{
	app::run();
}
