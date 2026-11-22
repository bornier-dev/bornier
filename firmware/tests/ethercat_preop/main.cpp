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
//   al_errors  error codes the stack wrote to 0x0134 since start; al_error_last and al_error_ms,
//              the last one and when (ms since start): the master clears an error within
//              milliseconds, before a report can see it
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
//   cycle_overruns process data that came in while the stack's interrupt routine ran: acknowledged,
//              not taken, the outputs of that cycle lost
//   sync0_backlog_max  most SYNC0 served in one go, and when (ms since start): more than one, the
//              task was held longer than a cycle and the stack sees them late
//   main_max   longest pass of the stack's main loop (MainLoop() and its timer), in CPU cycles, and
//              when (ms since start)
//   bus_failure 0 while the bus to the LAN9253 works, else the wait that ran out (esc_bus::failure):
//              the axes are then stopped for good
//   starts     starts of the MCU since power-up; faults, the fatal faults among them; fault_*, the
//              last one (fault_log.hpp): the start it ended, its cause, pc, lr, CFSR, HFSR and
//              detail (line of an assertion, exception number of an unexpected interrupt)

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
#include <fault_log.hpp>
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
				// Asleep until the LAN9253 requests the stack, a SYNC0, or the next millisecond. The
				// stack's interrupt routine runs only on a request, the pin low: process data that
				// comes in while it runs counts as a cycle overrun, acknowledged but not taken, so a
				// call on another wake-up would lose the outputs of a frame landing then. A request
				// that came while another was being served gives no new edge: the pin tells.
				(void)esc_irq::wait_until(next_tick);
				if (esc_irq::pending())
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
				uint32_t backlog = 0;
				while (sync0_served_ != sync_latch<esc_irq>::sync0_count())
				{
					marker(true);
					++sync0_served_;
					++backlog;
					Sync0_Isr();
					marker(false);
				}
				if (backlog > sync0_backlog_max_)
				{
					sync0_backlog_max_ = backlog;
					sync0_backlog_ms_ = uptime_ms();
				}

				const auto now = opsy::scheduler::now();
				const uint32_t main_start = opsy::cortex_m::cycle_count();
				if (now >= next_tick)
				{
					ECAT_CheckTimer();
					next_tick += 1ms;
				}
				MainLoop();
				if (const uint32_t cycles = opsy::cortex_m::cycle_count() - main_start; cycles > main_max_)
				{
					main_max_ = cycles;
					main_max_ms_ = uptime_ms();
				}
				ext_watchdog::feed();
				if (now >= next_report)
				{
					// A snapshot only, a few microseconds: the report task prints it.
					auto& r = report_;
					r.al_status = esc_bus<axes>::core_read(0x0130, 2);
					r.al_code = esc_bus<axes>::core_read(0x0134, 2);
					r.al_errors = ssc_hw_al_errors();
					r.eeprom = esc_bus<axes>::core_read(0x0502, 2);
					r.pdi_calls = pdi_calls_;
					r.sync0 = sync0_served_;
					r.sync0_idle = gpioa.idr.load().id4() ? 1u : 0u;
					r.gen = step_generator::statistics();
					r.pdi_mean = pdi_calls_ == 0 ? 0 : static_cast<uint32_t>(pdi_cycles_ / pdi_calls_);
					r.pdi_max = pdi_max_;
					r.cycle_overruns = sSyncManOutPar.u16CycleExceededCounter;
					r.sync0_backlog_max = sync0_backlog_max_;
					r.sync0_backlog_ms = sync0_backlog_ms_;
					r.main_max = main_max_;
					r.main_max_ms = main_max_ms_;
					r.bus_failure = static_cast<uint32_t>(esc_bus<axes>::failed());
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
				print_hex("al_errors", r.al_errors.count);
				if (r.al_errors.count != 0)
				{
					print_hex("al_error_last", r.al_errors.last);
					print_hex("al_error_ms", r.al_errors.last_ms);
				}
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
				print_hex("cycle_overruns", r.cycle_overruns);
				print_hex("sync0_backlog_max", r.sync0_backlog_max);
				print_hex("sync0_backlog_ms", r.sync0_backlog_ms);
				print_hex("main_max", r.main_max);
				print_hex("main_max_ms", r.main_max_ms);
				print_hex("bus_failure", r.bus_failure);
				const auto& f = bornier::last_fault;
				print_hex("starts", f.starts);
				print_hex("faults", f.faults);
				if (f.faults != 0)
				{
					print_hex("fault_start", f.start_of_fault);
					print_hex("fault_cause", static_cast<uint32_t>(f.what));
					print_hex("fault_pc", f.frame.pc);
					print_hex("fault_lr", f.frame.lr);
					print_hex("fault_cfsr", f.cfsr);
					print_hex("fault_hfsr", f.hfsr);
					print_hex("fault_detail", f.detail);
				}
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
	static inline uint32_t sync0_backlog_max_ = 0;
	static inline uint32_t sync0_backlog_ms_ = 0;
	static inline uint32_t main_max_ = 0;
	static inline uint32_t main_max_ms_ = 0;

	static uint32_t uptime_ms() { return static_cast<uint32_t>((opsy::scheduler::now() - opsy::startup).count()); }
	static inline opsy::task<2048> task_;

	/// What the report prints, taken by the stack's task once per second.
	struct report
	{
		uint32_t al_status;
		uint32_t al_code;
		ssc_hw_al_errors_t al_errors;
		uint32_t eeprom;
		uint32_t pdi_calls;
		uint32_t sync0;
		uint32_t sync0_idle;
		step_generator::stats gen;
		uint32_t pdi_mean;
		uint32_t pdi_max;
		uint32_t cycle_overruns;
		uint32_t sync0_backlog_max;
		uint32_t sync0_backlog_ms;
		uint32_t main_max;
		uint32_t main_max_ms;
		uint32_t bus_failure;
	};
	static inline report report_{};
	static inline opsy::binary_semaphore report_ready_{0};
	static inline opsy::task<1024> report_task_;
};

using status_led = mcu_led;
using console    = trace;
using esc        = esc_bus<axes>;   // the bus of the stack (ssc_hw.cpp): a failure stops the axes for good
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
