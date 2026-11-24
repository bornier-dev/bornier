// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// On-target test for the Bornier base board: isolated RS-485 port, with nothing wired to the
// MODBUS terminal block. The receiver of the transceiver is always on, so every byte sent comes
// back: the test sends the 256 byte values as one frame, by DMA, and checks the echo, received by
// DMA too. That path goes through the isolated supply of the transceiver, its driver, the biased
// and terminated line and its receiver.
//
// Report in the trace (bornier/trace.hpp), one rs485_echo::run event per second:
//   idle     the receiver saw the line idle before the test (line bias works)
//   echoed   number of bytes that came back right, out of 256
//   missing  number of bytes that did not come back
//   errors   framing, noise and overrun errors seen
//   failed   a sending missed its deadline: the port is down until the next reset
//   pass     idle, 256 echoed, none missing, no error and the port not failed

#include <application.hpp>
#include <app.hpp>
#include <board.hpp>
#include <bornier/trace.hpp>
#include <opsy.hpp>
#include <cortex_m.hpp>
#include <scheduler.hpp>
#include <clock.hpp>
#include <led.hpp>
#include <rs485.hpp>

#include <array>
#include <chrono>
#include <cstdint>

using namespace std::chrono_literals;
using namespace STM32H523;

namespace
{

/// Nothing to put in a safe state in this test: a failure of the port shows in its verdict.
struct no_outputs
{
	static void fault() {}
};
using port = rs485<no_outputs>;

} // namespace

/// The event of the test, as `kymo record` prints it: rs485_echo::run.
namespace rs485_echo
{

/** @brief One run of the test: 256 bytes sent, their echo checked. */
struct run
{
	bool          idle;
	uint32_t      echoed;
	uint32_t      missing;
	port::errors  errors;
	bool          failed;
	bool          pass;
};

} // namespace rs485_echo

/** @brief The test, as a module: one task that runs the checks and reports in the trace. */
class rs485_echo_test
{
public:
	static bool start()
	{
		return task_.start([]{
			while (true)
			{
				opsy::sleep_for(1s);

				(void)port::take_errors();
				const bool idle = port::line_idle();

				// The 256 values go out as one frame, by DMA; the echo comes back into another
				// buffer, by DMA, and ends when the line falls silent. 256 bytes last 22 ms.
				for (uint32_t value = 0; value < 256; ++value)
					sent_[value] = static_cast<uint8_t>(value);
				echo_.fill(0);
				port::listen(echo_);
				port::send(sent_);
				const std::size_t count = port::received(100ms);

				uint32_t echoed = 0;
				for (std::size_t i = 0; i < count; ++i)
					if (echo_[i] == sent_[i])
						++echoed;
				const uint32_t missing = static_cast<uint32_t>(sent_.size() - count);
				const auto errors = port::take_errors();
				const bool failed = port::failed();
				const bool pass = idle && echoed == 256 && missing == 0 && !failed
				               && !errors.framing && !errors.noise && !errors.overrun;
				bornier::trace::emit(rs485_echo::run{idle, echoed, missing, errors, failed, pass});

				if (pass)
					mcu_led::on();
				else
					mcu_led::off();
			}
		});
	}

private:
	static inline std::array<uint8_t, 256> sent_{};
	static inline std::array<uint8_t, 256> echo_{};
	static inline opsy::task<1024> task_;
};

using status_led = mcu_led;
using fieldbus   = port;

using app = bornier::app<board, status_led, fieldbus, rs485_echo_test>;

void application()
{
	app::run();
}
