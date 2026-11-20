// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// Bring-up example for the Bornier base board, and the reference for composing an image from
// modules: the board, the MCU LED, the SWO console, and the example module that blinks the
// first and reports on the second. Checked by tools/hil/blink_swo.py.

#include <application.hpp>
#include <app.hpp>
#include <board.hpp>
#include <led.hpp>
#include <trace.hpp>

#include "blinker.hpp"

using namespace STM32H523;

using app = bornier::app<board, mcu_led, trace, example::blinker<mcu_led, trace>>;

void application()
{
	app::run();
}
