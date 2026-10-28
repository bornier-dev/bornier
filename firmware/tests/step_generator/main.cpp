// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// On-target test of the step generator (step_generator.hpp): four STEP/DIR axes on TIM1 slots,
// locked on a simulated SYNC0, driven by a simulated motion (motion.hpp).
//
// TIM16 plays SYNC0 on PB8; a wire takes it to PA4. The outputs are checked with a logic
// analyzer by tools/hil/step_generator.py, which also replays the motion to know the expected
// step counts. The firmware checks what it can see on its own: final positions on target,
// no DMA error, no loss of phase lock, fill done in time.
//
// Commands on the ST-LINK virtual COM port (115200 8N1), one per line:
//   run [key=value ...]  start a run. Keys and defaults:
//                        rate=1000000 cycle=1000000 (ns) steplen=500 stepspace=500
//                        dirsetup=1000 dirhold=1000 (ns)
//                        detune=0 (ns added to the SYNC0 period, rounded down to 16 ns)
//                        profile=mixed|full seconds=10
//                        load=none|gpdma2|gpdma1 (competing memory-to-memory DMA, dma_load.hpp)
//                        tolerance=3 (missed cycles extrapolated) decel=0 (stop deceleration,
//                        steps/s^2, all axes; 0: f_max to rest in 100 ms)
//                        drop_every=0 drop_burst=1: from cycle drop_every on, the first
//                        drop_burst cycles of every drop_every are missed
//                        outage=0 outage_len=0: cycles [outage, outage + outage_len) missed
//                        speed=1000: profile velocities in thousandths of the maximum
//                        rebase=1: after a fault, the simulated master acknowledges and resumes
//                        from the position the axes stopped at (0: it does not, targets refused)
//   report               print the report of the last run, or "busy"
//   load <controller> <ms>  competing DMA alone, generator stopped: bytes per second
//   stop                 abort the run

#include <opsy.hpp>
#include <cortex_m.hpp>
#include <scheduler.hpp>
#include <clock.hpp>
#include <uart.hpp>

#include "dma_load.hpp"
#include "motion.hpp"
#include "step_generator.hpp"
#include "sync_simulator.hpp"

#include <algorithm>
#include <array>
#include <atomic>
#include <charconv>
#include <chrono>
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <span>
#include <string_view>

using namespace STM32H563;

namespace {

constexpr opsy::isr_priority fill_priority{0x20};
constexpr opsy::isr_priority load_priority{0xC0};

struct run_config
{
	step_generator::config generator{};
	int32_t detune = 0;
	motion::profile profile = motion::profile::mixed;
	dma_load::controller load = dma_load::controller::none;
	uint32_t seconds = 10;
	uint32_t drop_every = 0;
	uint32_t drop_burst = 1;
	uint32_t outage = 0;
	uint32_t outage_len = 0;
	uint32_t rebase = 1;
	uint32_t speed = 1000; ///< profile velocities, thousandths of max_steps
};

// ── Run, shared with the fill interrupt ───────────────────────────────────────

run_config run;
std::array<motion::axis, step_generator::axis_count> axes;
std::array<int32_t, step_generator::axis_count> targets{}; ///< of the simulated master, offset included
std::array<int32_t, step_generator::axis_count> offsets{}; ///< master resumed from where the axes stopped
bool acknowledged = false; ///< the simulated master acknowledged the current fault
uint32_t run_cycles = 0;    ///< cycles of motion so far
uint32_t finish_cycles = 0; ///< cycles after which the axes finish their loop
uint32_t idle_cycles = 0;   ///< cycles at rest after every axis is done
uint32_t profile_cycles_max = 0;

/// Set by the interrupt when the motion is over and the last steps are played.
std::atomic<bool> finished{false};
std::atomic<bool> running{false};
uint32_t load_blocks = 0; ///< blocks the competing DMA copied during the run

constexpr uint32_t idle_after_done = 20;

/// Frames the simulated network loses: tools/hil/step_generator.py replays the same rule.
bool missed(uint32_t cycle)
{
	bool const dropped = run.drop_every != 0 && cycle >= run.drop_every && cycle % run.drop_every < run.drop_burst;
	bool const outage = run.outage_len != 0 && cycle >= run.outage && cycle < run.outage + run.outage_len;
	return dropped || outage;
}

void tim5_isr()
{
	(void)step_generator::fill([]{
		auto const t0 = step_generator::cycle_counter();
		bool const finish = run_cycles >= finish_cycles;
		bool all_done = true;
		for (std::size_t a = 0; a < axes.size(); ++a)
		{
			targets[a] = axes[a].next(finish) + offsets[a];
			all_done &= axes[a].done();
		}
		bool const lost = missed(run_cycles);
		++run_cycles;
		if (all_done && ++idle_cycles == idle_after_done)
			finished.store(true, std::memory_order_release);

		// A master that sees the axes at rest in fault acknowledges once, and with rebase
		// resumes from where they stopped
		if (step_generator::state() != step_generator::mode::faulted)
			acknowledged = false;
		else if (!lost && !acknowledged)
		{
			acknowledged = true;
			step_generator::acknowledge();
			if (run.rebase != 0)
				for (std::size_t a = 0; a < axes.size(); ++a)
				{
					int32_t const stop = step_generator::statistics().axes[a].target;
					offsets[a] += stop - targets[a];
					targets[a] = stop;
				}
		}
		profile_cycles_max = std::max(profile_cycles_max, step_generator::cycle_counter() - t0);
		return step_generator::command{ !lost, targets };
	});
}

void start_run()
{
	sync_simulator::stop();
	step_generator::stop();

	step_generator::derived d;
	(void)step_generator::derive(run.generator, d);
	auto const vmax = static_cast<int64_t>(d.max_steps) * run.speed / 1000;
	switch (run.profile)
	{
	case motion::profile::mixed:
		axes[0].start(motion::mixed::axis0, vmax);
		axes[1].start(motion::mixed::axis1, vmax);
		axes[2].start(motion::mixed::axis2, vmax);
		axes[3].start(motion::mixed::axis3, vmax);
		break;
	case motion::profile::full:
		axes[0].start(motion::full::forward, vmax);
		axes[1].start(motion::full::backward, vmax);
		axes[2].start(motion::full::forward, vmax);
		axes[3].start(motion::full::backward, vmax);
		break;
	}
	targets = {};
	offsets = {};
	acknowledged = false;
	run_cycles = 0;
	idle_cycles = 0;
	profile_cycles_max = 0;
	finish_cycles = static_cast<uint32_t>(uint64_t{run.seconds} * 1'000'000'000u / run.generator.cycle_ns);
	finished.store(false, std::memory_order_relaxed);
	running.store(true, std::memory_order_relaxed);

	step_generator::start(run.generator, fill_priority);
	sync_simulator::start(static_cast<uint32_t>(static_cast<int32_t>(run.generator.cycle_ns) + run.detune), 1000);
	dma_load::start(run.load, load_priority);
}

void stop_run()
{
	load_blocks = dma_load::blocks();
	dma_load::stop();
	sync_simulator::stop();
	step_generator::stop();
	running.store(false, std::memory_order_relaxed);
}

// ── Commands ──────────────────────────────────────────────────────────────────

std::array<char, 320> line;

void print(int length)
{
	if (length > 0)
		uart::send(std::span<const uint8_t>(reinterpret_cast<const uint8_t*>(line.data()),
		                                    std::min(static_cast<std::size_t>(length), line.size() - 1)));
}

template<typename T>
bool parse_number(std::string_view text, T& value)
{
	auto const [end, ec] = std::from_chars(text.data(), text.data() + text.size(), value);
	return ec == std::errc{} && end == text.data() + text.size();
}

bool parse_option(std::string_view key, std::string_view value, run_config& c)
{
	auto& g = c.generator;
	if (key == "rate")      return parse_number(value, g.slot_rate_hz);
	if (key == "cycle")     return parse_number(value, g.cycle_ns);
	if (key == "steplen")   return parse_number(value, g.steplen_ns);
	if (key == "stepspace") return parse_number(value, g.stepspace_ns);
	if (key == "dirsetup")  return parse_number(value, g.dirsetup_ns);
	if (key == "dirhold")   return parse_number(value, g.dirhold_ns);
	if (key == "detune")    return parse_number(value, c.detune);
	if (key == "seconds")   return parse_number(value, c.seconds);
	if (key == "tolerance") return parse_number(value, g.missed_tolerance);
	if (key == "decel")
	{
		uint32_t v = 0;
		if (!parse_number(value, v))
			return false;
		g.stop_decel.fill(v);
		return true;
	}
	if (key == "drop_every") return parse_number(value, c.drop_every);
	if (key == "drop_burst") return parse_number(value, c.drop_burst);
	if (key == "outage")     return parse_number(value, c.outage);
	if (key == "outage_len") return parse_number(value, c.outage_len);
	if (key == "rebase")     return parse_number(value, c.rebase);
	if (key == "speed")      return parse_number(value, c.speed);
	if (key == "load")
	{
		if (value == "none")   { c.load = dma_load::controller::none; return true; }
		if (value == "gpdma2") { c.load = dma_load::controller::on_gpdma2; return true; }
		if (value == "gpdma1") { c.load = dma_load::controller::on_gpdma1; return true; }
		return false;
	}
	if (key == "profile")
	{
		if (value == "mixed") { c.profile = motion::profile::mixed; return true; }
		if (value == "full")  { c.profile = motion::profile::full; return true; }
	}
	return false;
}

constexpr std::array error_names{ "none", "rate", "cycle", "pulse" };
constexpr std::array profile_names{ "mixed", "full" };
constexpr std::array load_names{ "none", "gpdma2", "gpdma1" };

void print_config()
{
	auto const& g = run.generator;
	auto const& d = step_generator::values();
	print(std::snprintf(line.data(), line.size(),
		"config rate=%" PRIu32 " cycle=%" PRIu32 " steplen=%" PRIu32 " stepspace=%" PRIu32
		" dirsetup=%" PRIu32 " dirhold=%" PRIu32
		" detune=%" PRId32 " profile=%s seconds=%" PRIu32 "\r\n",
		g.slot_rate_hz, g.cycle_ns, g.steplen_ns, g.stepspace_ns, g.dirsetup_ns, g.dirhold_ns,
		run.detune, profile_names[static_cast<std::size_t>(run.profile)], run.seconds));
	print(std::snprintf(line.data(), line.size(),
		"derived prescaler=%" PRIu32 " slot_ticks=%" PRIu32 " cycle_slots=%" PRIu32 " pulse_ticks=%" PRIu32
		" pulse_slots=%" PRIu32 " gap_slots=%" PRIu32 " dir_ticks=%" PRIu32 " guard_slots=%" PRIu32
		" fill_ticks=%" PRIu32 " max_steps=%" PRIu32 "\r\n",
		d.prescaler, d.slot_ticks, d.cycle_slots, d.pulse_ticks, d.pulse_slots, d.gap_slots,
		d.dir_ticks, d.guard_slots, d.fill_ticks, d.max_steps));
	print(std::snprintf(line.data(), line.size(),
		"frames tolerance=%" PRIu32 " decel=%" PRIu32 " stop_step=%" PRId32 " drop_every=%" PRIu32
		" drop_burst=%" PRIu32 " outage=%" PRIu32 " outage_len=%" PRIu32 " rebase=%" PRIu32 " speed=%" PRIu32 "\r\n",
		g.missed_tolerance, g.stop_decel[0], static_cast<int32_t>(d.stop_step_x65536[0]), run.drop_every,
		run.drop_burst, run.outage, run.outage_len, run.rebase, run.speed));
}

void report()
{
	auto const& s = step_generator::statistics();
	print_config();

	bool pass = true;
	for (std::size_t a = 0; a < s.axes.size(); ++a)
	{
		auto const& x = s.axes[a];
		// With frames missed, catching up after an extrapolation may need more steps than a cycle
		// holds: they are deferred, not lost (the logic analyzer checks the counts)
		pass &= x.position == x.target && (x.deferred == 0 || s.missed != 0);
		print(std::snprintf(line.data(), line.size(),
			"axis %u target=%" PRId32 " position=%" PRId32 " pulses=%" PRIu32 " deferred=%" PRIu32
			" reversals=%" PRIu32 " master=%" PRId32 "\r\n",
			static_cast<unsigned>(a), x.target, x.position, x.pulses, x.deferred, x.reversals, targets[a]));
	}

	uint32_t const cycle_ticks = run.generator.cycle_ns / 4u;
	pass &= s.resyncs == 0 && s.dma_errors == 0 && s.fill_end_max < cycle_ticks;
	print(std::snprintf(line.data(), line.size(),
		"sync cycles=%" PRIu32 " unsynced=%" PRIu32 " resyncs=%" PRIu32
		" phase=%" PRId32 ",%" PRId32 " correction=%" PRId32 ",%" PRId32
		" dma_errors=%" PRIu32 " position_retries=%" PRIu32 "\r\n",
		s.cycles, s.unsynced, s.resyncs, s.phase_min, s.phase_max, s.correction_min, s.correction_max,
		s.dma_errors, s.position_retries));
	constexpr std::array mode_names{ "running", "stopping", "faulted" };
	print(std::snprintf(line.data(), line.size(),
		"missed count=%" PRIu32 " extrapolated=%" PRIu32 " faults=%" PRIu32 " refused=%" PRIu32 " state=%s\r\n",
		s.missed, s.extrapolated, s.faults, s.refused,
		mode_names[static_cast<std::size_t>(step_generator::state())]));

	auto const mean = s.cycles == 0 ? 0u : static_cast<uint32_t>(s.fill_cycles_sum / s.cycles);
	print(std::snprintf(line.data(), line.size(),
		"cpu fill_max=%" PRIu32 " fill_max_cycle=%" PRIu32 " fill_mean=%" PRIu32 " fill_end_max_ticks=%" PRIu32
		" profile_max=%" PRIu32 " cycle_cpu=%" PRIu32 "\r\n",
		s.fill_cycles_max, s.fill_max_cycle, mean, s.fill_end_max, profile_cycles_max,
		run.generator.cycle_ns / 4u)); // 250 MHz core: 1 cycle per 4 ns

	auto const& f = s.fill_max_split;
	print(std::snprintf(line.data(), line.size(),
		"split place=%" PRIu32 " axis0=%" PRIu32 " axis1=%" PRIu32 " axis2=%" PRIu32 " axis3=%" PRIu32
		" steps=%" PRIu32 ",%" PRIu32 ",%" PRIu32 ",%" PRIu32 "\r\n",
		f[0], f[2], f[3], f[4], f[5], s.fill_max_steps[0], s.fill_max_steps[1], s.fill_max_steps[2], s.fill_max_steps[3]));

	// Bytes per second over the cycles run (one cycle per cycle_ns)
	uint64_t const run_ns = uint64_t{s.cycles} * run.generator.cycle_ns;
	auto const load_rate = run_ns == 0 ? 0u : static_cast<uint32_t>(uint64_t{load_blocks} * dma_load::block_bytes * 1'000'000'000u / run_ns);
	print(std::snprintf(line.data(), line.size(), "load controller=%s blocks=%" PRIu32 " bytes_per_s=%" PRIu32 "\r\n",
		load_names[static_cast<std::size_t>(run.load)], load_blocks, load_rate));

	print(std::snprintf(line.data(), line.size(), "verdict %s\r\nend\r\n", pass ? "PASS" : "FAIL"));
}

void handle(std::string_view command)
{
	auto const space = command.find(' ');
	auto const verb = command.substr(0, space);
	if (verb == "run")
	{
		run_config c;
		std::string_view rest = space == std::string_view::npos ? std::string_view{} : command.substr(space + 1);
		while (!rest.empty())
		{
			auto const next = rest.find(' ');
			auto const token = rest.substr(0, next);
			rest = next == std::string_view::npos ? std::string_view{} : rest.substr(next + 1);
			if (token.empty())
				continue;
			auto const equal = token.find('=');
			if (equal == std::string_view::npos || !parse_option(token.substr(0, equal), token.substr(equal + 1), c))
			{
				print(std::snprintf(line.data(), line.size(), "error option %.*s\r\n",
				                    static_cast<int>(std::min<std::size_t>(token.size(), 64)), token.data()));
				return;
			}
		}
		step_generator::derived d;
		auto const e = step_generator::derive(c.generator, d);
		if (e != step_generator::error::none)
		{
			print(std::snprintf(line.data(), line.size(), "error config %s\r\n", error_names[static_cast<std::size_t>(e)]));
			return;
		}
		stop_run();
		run = c;
		start_run();
		print_config();
		print(std::snprintf(line.data(), line.size(), "started\r\n"));
	}
	else if (verb == "report")
	{
		if (running.load(std::memory_order_relaxed) && !finished.load(std::memory_order_acquire))
			print(std::snprintf(line.data(), line.size(), "busy cycles=%" PRIu32 "\r\n", step_generator::statistics().cycles));
		else
		{
			if (running.load(std::memory_order_relaxed))
				stop_run();
			report();
		}
	}
	else if (verb == "load")
	{
		// load <controller> <ms>: the competing DMA alone, as a reference
		std::string_view rest = space == std::string_view::npos ? std::string_view{} : command.substr(space + 1);
		auto const gap = rest.find(' ');
		run_config c;
		uint32_t ms = 0;
		if (gap == std::string_view::npos || !parse_option("load", rest.substr(0, gap), c) || !parse_number(rest.substr(gap + 1), ms))
		{
			print(std::snprintf(line.data(), line.size(), "error load\r\n"));
			return;
		}
		stop_run();
		dma_load::start(c.load, load_priority);
		opsy::sleep_for(std::chrono::milliseconds(ms));
		uint32_t const blocks = dma_load::blocks();
		dma_load::stop();
		auto const rate = ms == 0 ? 0u : static_cast<uint32_t>(uint64_t{blocks} * dma_load::block_bytes * 1000u / ms);
		print(std::snprintf(line.data(), line.size(), "load controller=%s blocks=%" PRIu32 " bytes_per_s=%" PRIu32 "\r\n",
			load_names[static_cast<std::size_t>(c.load)], blocks, rate));
	}
	else if (verb == "stop")
	{
		stop_run();
		print(std::snprintf(line.data(), line.size(), "stopped\r\n"));
	}
	else
		print(std::snprintf(line.data(), line.size(), "error command\r\n"));
}

alignas(1024) std::array<opsy::cortex_m::isr_handler_t, opsy::cortex_m::system_irqs_count + irq_count> ram_vectors;

opsy::task<2048> console;

} // namespace

int main()
{
	clock::init();
	uart::init();

	opsy::cortex_m::move_vtor(ram_vectors.data(), ram_vectors.size());
	opsy::cortex_m::set_isr_handler(TIM5_IRQn, tim5_isr);
	opsy::cortex_m::set_isr_handler(GPDMA2_CH0_IRQn, dma_load::gpdma2_isr);
	opsy::cortex_m::set_isr_handler(GPDMA1_CH5_IRQn, dma_load::gpdma1_isr);

	bool const system_ok = console.start([]{
		std::array<char, 256> command{};
		std::size_t length = 0;
		while (true)
		{
			for (auto const byte : uart::receive())
			{
				auto const c = static_cast<char>(byte);
				if (c == '\r' || c == '\n')
				{
					if (length > 0)
						handle(std::string_view(command.data(), length));
					length = 0;
				}
				else if (length < command.size())
					command[length++] = c;
			}
		}
	});

	if (!system_ok)
		asm volatile("bkpt 0");

	opsy::scheduler::start(); // does not return
}
