// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// Bring-up example for the Bornier base board, and the reference for composing an image from
// modules: the board, the MCU LED, and the example module that blinks the first and reports in
// the trace. Checked by tools/hil/blink.py.

#include <application.hpp>
#include <app.hpp>
#include <board.hpp>
#include <bornier/trace.hpp>
#include <led.hpp>

#include "blinker.hpp"

using namespace STM32H523;

// One alias per module, named by its role in the image: the list of the app reads as a list of
// modules, and swapping a driver (or a test double) changes one line.
using status_led = mcu_led;
using heartbeat  = example::blinker<status_led, bornier::trace>;

using app = bornier::app<board, status_led, heartbeat>;

void application()
{
	app::run();
}
