// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// On-target test for the Bornier base board: the EtherCAT Slave Stack Code runs on the board,
// serves the emulated SII EEPROM of the LAN9253 and answers the master. Built only when
// BORNIER_SSC_DIR points at the generated stack. The check is made from the master: it reads
// the SII and brings the slave to PREOP; LinuxCNC with lcec, configured for the 8 bytes of
// process data each way, brings it to OP.
//
// The stack runs from one task, asleep but on a request of the LAN9253 (ESC_IRQ), a SYNC0 or the
// next millisecond: on a request, its interrupt routine PDI_Isr() (process data); on each SYNC0
// counted by sync_latch, Sync0_Isr(), late ones included; every millisecond, its timer; each
// time, its main loop (AL control, mailbox), and the external watchdog is fed.
// The application of the board runs in the stack (boards/base/ssc_appl.cpp): four step/dir axes
// under CiA402 in cyclic synchronous position (axes, step_generator), stop chain, probe, supply
// voltage.
//
// Report on SWO, once per second, from a task of its own below the stack's: printing takes a few
// milliseconds, more than a cycle.
//   al_status  AL status register (0x0130): 1 INIT, 2 PREOP, 4 SAFEOP, 8 OP, bit 4 error
//   al_code    AL status code (0x0134), 0 when no error
//   eeprom     EEPROM control/status (0x0502); bit 12 set while the configuration is not loaded
//   pdi_calls  calls to PDI_Isr() since start, on requests of the LAN9253
//   sync0      SYNC0 pulses since start, each served by a call to Sync0_Isr()
//   sync0_idle level of ESC_SYNC0 (PA4) when sampled, mostly its idle level
//   gen_*      step generator: cycles filled, fills without SYNC0, phase resyncs, DMA errors,
//              longest fill (CPU cycles), latest end of fill (TIM5 ticks after SYNC0), and for
//              axis 0 the steps scheduled, the cycles that deferred steps and the reversals
//
// For a logic analyser on the HE10 of the local bus: pin 26, LATCH, a 10 us pulse on each SYNC0
// (sync_latch); pin 1, CS0, low while the task serves the LAN9253; ground on pin 25.
//   pdi_mean   mean duration of a call, in CPU cycles at 250 MHz (elapsed: DMA waits included)
//   pdi_max    longest call, in CPU cycles

#include <application.hpp>
#include <app.hpp>
#include <board.hpp>
#include <opsy.hpp>
#include <cortex_m.hpp>
#include <scheduler.hpp>
#include <semaphore.hpp>
#include <clock.hpp>
#include <esc_bus.hpp>
#include <axes.hpp>
#include <drive_ports.hpp>
#include <esc_irq.hpp>
#include <ext_watchdog.hpp>
#include <led.hpp>
#include <stop_probe.hpp>
#include <supplies.hpp>
#include <sync_latch.hpp>
#include <trace.hpp>

extern "C" {
#include <applInterface.h>
#include <ssc_hw.h>
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
		const bool started = task_.start([]{
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
				// Asleep until the LAN9253 requests the stack, or the next millisecond. A request that
				// came while another was being served gives no new edge: the pin is checked too.
				if (esc_irq::wait_until(next_tick) || esc_irq::pending())
				{
					marker(true);
					// Served again while an asked-for AL event is pending: the AL event request
					// tells, the pin may take a moment to rise once the stack has cleared it.
					for (uint32_t pass = 0; pass < max_passes; ++pass)
					{
						const uint32_t start = opsy::cortex_m::cycle_count();
						PDI_Isr();
						const uint32_t cycles = opsy::cortex_m::cycle_count() - start;
						pdi_cycles_ = pdi_cycles_ + cycles;
						pdi_max_ = std::max(pdi_max_, cycles);
						pdi_calls_ = pdi_calls_ + 1;
						if (!ssc_hw_event_pending())
							break;
					}
					marker(false);
				}

				// Every SYNC0 counted, in turn: the stack's counters see each one.
				while (sync0_served_ != sync_latch<esc_irq>::sync0_count())
				{
					marker(true);
					++sync0_served_;
					Sync0_Isr();
					marker(false);
				}

				const auto now = opsy::scheduler::now();
				if (now >= next_tick)
				{
					ECAT_CheckTimer();
					next_tick += 1ms;
				}
				MainLoop();
				ext_watchdog::feed();
				if (now >= next_report)
				{
					// A snapshot only, a few microseconds: the report task prints it.
					auto& r = report_;
					r.al_status = esc_bus::core_read(0x0130, 2);
					r.al_code = esc_bus::core_read(0x0134, 2);
					r.eeprom = esc_bus::core_read(0x0502, 2);
					r.pdi_calls = pdi_calls_;
					r.sync0 = sync0_served_;
					r.sync0_idle = gpioa.idr.load().id4() ? 1u : 0u;
					r.gen = step_generator::statistics();
					r.pdi_mean = pdi_calls_ == 0 ? 0 : static_cast<uint32_t>(pdi_cycles_ / pdi_calls_);
					r.pdi_max = pdi_max_;
					if ((r.al_status & 0x0F) >= 2)
						mcu_led::on();
					else
						mcu_led::off();
					report_ready_.release();
					next_report += 1s;
				}
			}
		});
		if (!started)
			return false;
		// Above the report: its prints on SWO take milliseconds, longer than a cycle.
		task_.priority(opsy::task_priority::high);
		return report_task_.start([]{
			while (true)
			{
				report_ready_.acquire();
				const auto r = report_;
				print_hex("al_status", r.al_status);
				print_hex("al_code", r.al_code);
				print_hex("eeprom", r.eeprom);
				print_hex("pdi_calls", r.pdi_calls);
				print_hex("sync0", r.sync0);
				print_hex("sync0_idle", r.sync0_idle);
				print_hex("gen_cycles", r.gen.cycles);
				print_hex("gen_unsynced", r.gen.unsynced);
				print_hex("gen_resyncs", r.gen.resyncs);
				print_hex("gen_dma_errors", r.gen.dma_errors);
				print_hex("gen_fill_max", r.gen.fill_cycles_max);
				print_hex("gen_fill_end", r.gen.fill_end_max);
				print_hex("gen_pulses0", r.gen.axes[0].pulses);
				print_hex("gen_deferred0", r.gen.axes[0].deferred);
				print_hex("gen_reversals0", r.gen.axes[0].reversals);
				print_hex("pdi_mean", r.pdi_mean);
				print_hex("pdi_max", r.pdi_max);
			}
		});
	}

	/// CS0 of the local bus (PD0, pin 1 of the HE10), unused without modules: a marker for the
	/// logic analyser, low from the wake-up of the task to the end of the requests it serves.
	static void init()
	{
		rcc.ahb2enr |= rcc_p::ahb2enr_r::gpioden_f() | mmio::atomic;
		marker(false);
		gpiod.moder <<= gpio_p::moder_r::mode0_f(0b01) || mmio::atomic;
	}

private:
	static void marker(bool serving)
	{
		if (serving)
			gpiod.bsrr = gpio_p::bsrr_r::br0_f();
		else
			gpiod.bsrr = gpio_p::bsrr_r::bs0_f();
	}

	/// Calls to PDI_Isr() for one request at most: the stack clears what it serves.
	static constexpr uint32_t max_passes = 8;

	static inline uint32_t pdi_calls_ = 0;
	static inline uint64_t pdi_cycles_ = 0;
	static inline uint32_t pdi_max_ = 0;
	static inline uint32_t sync0_served_ = 0;
	static inline opsy::task<2048> task_;

	/// What the report prints, taken by the stack's task once per second.
	struct report
	{
		uint32_t al_status;
		uint32_t al_code;
		uint32_t eeprom;
		uint32_t pdi_calls;
		uint32_t sync0;
		uint32_t sync0_idle;
		step_generator::stats gen;
		uint32_t pdi_mean;
		uint32_t pdi_max;
	};
	static inline report report_{};
	static inline opsy::binary_semaphore report_ready_{0};
	static inline opsy::task<1024> report_task_;
};

using status_led = mcu_led;
using console    = trace;
using esc        = esc_bus;
using esc_events = esc_irq;
using drives     = drive_ports;
using machine    = stop_probe;
using rails      = supplies;
using watchdog   = ext_watchdog;
using latch      = sync_latch<esc_events>;
using motion     = axes;

using app = bornier::app<board, status_led, console, esc, esc_events, drives, machine, rails, watchdog, latch, motion,
                         ethercat_preop_test>;

void application()
{
	app::run();
}
