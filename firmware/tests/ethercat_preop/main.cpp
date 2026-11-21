// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// On-target test for the Bornier base board: the EtherCAT Slave Stack Code runs on the board,
// serves the emulated SII EEPROM of the LAN9253 and answers the master. Built only when
// BORNIER_SSC_DIR points at the generated stack. The check is made from the master: it reads
// the SII and brings the slave to PREOP; LinuxCNC with lcec, configured for the 8 bytes of
// process data each way, brings it to OP.
//
// The stack runs from one task, asleep but on a request of the LAN9253 (ESC_IRQ) or on the next
// millisecond: on a request, its interrupt routine PDI_Isr() (process data); every millisecond,
// its timer; each time, its main loop (AL control, mailbox).
//
// Report on SWO, once per second:
//   al_status  AL status register (0x0130): 1 INIT, 2 PREOP, 4 SAFEOP, 8 OP, bit 4 error
//   al_code    AL status code (0x0134), 0 when no error
//   eeprom     EEPROM control/status (0x0502); bit 12 set while the configuration is not loaded
//   pdi_calls  calls to PDI_Isr() since start, on requests of the LAN9253
//   pdi_mean   mean duration of a call, in CPU cycles at 250 MHz (elapsed: DMA waits included)
//   pdi_max    longest call, in CPU cycles

#include <application.hpp>
#include <app.hpp>
#include <board.hpp>
#include <opsy.hpp>
#include <cortex_m.hpp>
#include <scheduler.hpp>
#include <clock.hpp>
#include <esc_bus.hpp>
#include <esc_irq.hpp>
#include <led.hpp>
#include <trace.hpp>

extern "C" {
#include <applInterface.h>
}

#include <algorithm>
#include <charconv>
#include <chrono>
#include <cstdint>
#include <string_view>

using namespace std::chrono_literals;
using namespace STM32H523;


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

/** @brief The test, as a module: one task that runs the checks and reports on SWO. */
class ethercat_preop_test
{
public:
	static bool start()
	{
		return task_.start([]{
			if (HW_Init() != 0)
			{
				trace::write("verdict FAIL hw_init\r\n");
				return;
			}
			(void)opsy::cortex_m::enable_cycle_count();
			(void)MainInit();
			bRunApplication = TRUE;

			auto next_tick = opsy::scheduler::now() + 1ms;
			auto next_report = opsy::scheduler::now() + 1s;
			while (true)
			{
				// Asleep until the LAN9253 requests the stack, or the next millisecond.
				if (esc_irq::wait_until(next_tick))
				{
					// The request stays pending, ESC_IRQ low, until the stack has served it.
					for (uint32_t pass = 0; pass < max_passes; ++pass)
					{
						const uint32_t start = opsy::cortex_m::cycle_count();
						PDI_Isr();
						const uint32_t cycles = opsy::cortex_m::cycle_count() - start;
						pdi_cycles_ = pdi_cycles_ + cycles;
						pdi_max_ = std::max(pdi_max_, cycles);
						pdi_calls_ = pdi_calls_ + 1;
						if (!esc_irq::pending())
							break;
					}
				}

				const auto now = opsy::scheduler::now();
				if (now >= next_tick)
				{
					ECAT_CheckTimer();
					next_tick += 1ms;
				}
				MainLoop();
				if (now >= next_report)
				{
					const uint32_t al_status = esc_bus::core_read(0x0130, 2);
					print_hex("al_status", al_status);
					print_hex("al_code", esc_bus::core_read(0x0134, 2));
					print_hex("eeprom", esc_bus::core_read(0x0502, 2));
					print_hex("pdi_calls", pdi_calls_);
					print_hex("pdi_mean", pdi_calls_ == 0 ? 0 : static_cast<uint32_t>(pdi_cycles_ / pdi_calls_));
					print_hex("pdi_max", pdi_max_);
					if ((al_status & 0x0F) >= 2)
						mcu_led::on();
					else
						mcu_led::off();
					next_report += 1s;
				}
			}
		});
	}

private:
	/// Calls to PDI_Isr() for one request at most: the stack clears what it serves.
	static constexpr uint32_t max_passes = 8;

	static inline uint32_t pdi_calls_ = 0;
	static inline uint64_t pdi_cycles_ = 0;
	static inline uint32_t pdi_max_ = 0;
	static inline opsy::task<2048> task_;
};

using status_led = mcu_led;
using console    = trace;
using esc        = esc_bus;
using esc_events = esc_irq;

using app = bornier::app<board, status_led, console, esc, esc_events, ethercat_preop_test>;

void application()
{
	app::run();
}
