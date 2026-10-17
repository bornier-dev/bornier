// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// On-target test of exclusive accesses (LDREX/STREX) to peripheral registers.
//
// OpSy's `| atomic` / `|| atomic` register updates compile to LDREX/STREX loops. ARMv8-M treats
// Device memory as shareable and leaves the global exclusive monitor to the SoC, so whether
// these loops are safe on peripheral registers is a property of the chip, not of the language.
// This test measures it on the STM32H563.
//
// Phase 1, probes: hand-written LDREX ... STREX sequences, with a write to the same register
// forced in between. Each probe toggles bit A with the exclusive pair; the interference toggles
// bit B. If STREX reports success and B is back to its old value, the interfering write was lost.
//   quiet  no interference: STREX must succeed.
//   isr    an interrupt, pended inside the window, toggles B: STREX must fail (exception entry
//          and return clear the local monitor).
//   dma    GPDMA toggles B (another bus master, no exception): only a global monitor can make
//          STREX fail. Informative: the firmware never shares a register with a DMA writer.
//
// Phase 2, stress: the OpSy operators run in a tight loop on bit A while a timer interrupt
// (about 450 kHz, jittered period) toggles bit B and checks that its previous toggle survived.
// The plain (non-atomic) operator must lose updates, which proves the detector works; the
// atomic ones must not.
//
// Results are printed on the ST-LINK virtual COM port (115200 8N1) each time a byte is received.
// Host side: tools/hil/atomic_mmio.py.

#include <opsy.hpp>
#include <cortex_m.hpp>
#include <scheduler.hpp>
#include <clock.hpp>
#include <uart.hpp>
#include <STM32H563/gpdma.hpp>
#include <STM32H563/gpio.hpp>
#include <STM32H563/interrupts.hpp>
#include <STM32H563/rcc.hpp>
#include <STM32H563/tim.hpp>

#include <algorithm>
#include <array>
#include <atomic>
#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <iterator>
#include <span>

using namespace STM32H563;
using opsy::utility::atomic;

namespace {

// ── Test targets ──────────────────────────────────────────────────────────────

/// Stand-in for a normal-memory word, as a reference for the peripheral targets.
std::uint32_t sram_word;

struct target
{
	const char* name;
	std::uint32_t address;
	std::uint32_t a; ///< Bit toggled by the code under test
	std::uint32_t b; ///< Bit toggled by the interfering writer
};

// Addresses are taken at run time: the peripheral objects are references, not constants.
std::array<target, 4> make_targets()
{
	return {{
		{ "sram",        reinterpret_cast<std::uint32_t>(&sram_word),          1u << 0, 1u << 1 },
		{ "tim2_ccr1",   reinterpret_cast<std::uint32_t>(&tim2.tim2_ccr1),     1u << 0, 1u << 1 }, // APB1
		{ "gpioe_odr",   reinterpret_cast<std::uint32_t>(&gpioe.gpio_odr),     1u << 0, 1u << 1 }, // AHB2, pins left in analog mode
		{ "rcc_ahb2enr", reinterpret_cast<std::uint32_t>(&rcc.rcc_ahb2enr),    1u << 7, 1u << 8 }, // AHB3, GPIOH/GPIOI clocks (unused)
	}};
}

std::uint32_t read(std::uint32_t address)
{
	return *reinterpret_cast<volatile std::uint32_t*>(address);
}

// ── Interfering interrupt ─────────────────────────────────────────────────────

/// Register and bit the ISRs toggle; null when disarmed.
std::atomic<volatile std::uint32_t*> isr_target{nullptr};
std::atomic<std::uint32_t> isr_mask{0};
/// Value of the ISR's bit as the ISR last wrote it.
std::atomic<std::uint32_t> isr_shadow{0};
std::atomic<std::uint32_t> isr_count{0};
/// Times the ISR found its previous write undone.
std::atomic<std::uint32_t> isr_lost{0};

constexpr opsy::isr_priority test_priority{0x40};

// The check lives in the ISR so the code under test runs with interrupts enabled throughout:
// a check under PRIMASK in the main loop would make every interrupt land at the same place.
void toggle_from_isr()
{
	auto* const reg = isr_target.load(std::memory_order_relaxed);
	if (reg == nullptr)
		return;
	auto const mask = isr_mask.load(std::memory_order_relaxed);
	// Plain read-modify-write: nothing preempts this handler that touches the register.
	auto const current = *reg;
	if ((current & mask) != isr_shadow.load(std::memory_order_relaxed))
		isr_lost.fetch_add(1, std::memory_order_relaxed);
	auto const next = current ^ mask;
	*reg = next;
	isr_shadow.store(next & mask, std::memory_order_relaxed);
	isr_count.fetch_add(1, std::memory_order_relaxed);
}

/// Software-pended only, from inside the probe window.
void tim7_isr()
{
	toggle_from_isr();
}

std::uint32_t jitter_state = 0xACE1u; ///< Only touched by tim6_isr

/// Interference for the stress phase. A fixed period would lock in phase with the loop under
/// test and always hit the same instruction: each period is drawn between 300 and 811 cycles.
void tim6_isr()
{
	tim6.tim6_sr = tim6_p::tim6_sr_r::uif_f(false);
	jitter_state ^= jitter_state << 13; // xorshift32
	jitter_state ^= jitter_state >> 17;
	jitter_state ^= jitter_state << 5;
	tim6.tim6_arr = tim6_p::tim6_arr_r::arr_f(300u + (jitter_state & 511u));
	toggle_from_isr();
}

void arm_isr(std::uint32_t address, std::uint32_t mask)
{
	isr_mask.store(mask, std::memory_order_relaxed);
	isr_shadow.store(read(address) & mask, std::memory_order_relaxed);
	isr_count.store(0, std::memory_order_relaxed);
	isr_lost.store(0, std::memory_order_relaxed);
	isr_target.store(reinterpret_cast<volatile std::uint32_t*>(address), std::memory_order_relaxed);
}

void disarm_isr()
{
	isr_target.store(nullptr, std::memory_order_relaxed);
}

alignas(1024) std::array<opsy::cortex_m::isr_handler_t, opsy::cortex_m::system_irqs_count + irq_count> ram_vectors;

void init_test_hardware()
{
	rcc.rcc_ahb2enr  |= rcc_p::rcc_ahb2enr_r::gpioeen_f() | atomic;
	rcc.rcc_apb1lenr |= (rcc_p::rcc_apb1lenr_r::tim2en_f()
	                   | rcc_p::rcc_apb1lenr_r::tim6en_f()
	                   | rcc_p::rcc_apb1lenr_r::tim7en_f()) | atomic;

	// TIM6: update interrupt, period set by tim6_isr, started by the stress phase
	tim6.tim6_psc  = tim6_p::tim6_psc_r::psc_f(0);
	tim6.tim6_arr  = tim6_p::tim6_arr_r::arr_f(499);
	tim6.tim6_egr  = tim6_p::tim6_egr_r::ug_f();
	tim6.tim6_sr   = tim6_p::tim6_sr_r::uif_f(false);
	tim6.tim6_dier = tim6_p::tim6_dier_r::uie_f();

	// GPDMA1 channel 2: one word, memory to register, software request
	gpdma1.gpdma_c2tr1 = gpdma_p::gpdma_cxtr1_r::sdw_log2_f(2)
	                   | gpdma_p::gpdma_cxtr1_r::ddw_log2_f(2);
	gpdma1.gpdma_c2tr2 = gpdma_p::gpdma_cxtr2_r::swreq_f();

	opsy::cortex_m::move_vtor(ram_vectors.data(), ram_vectors.size());
	opsy::cortex_m::set_isr_handler(TIM6_IRQn, tim6_isr);
	opsy::cortex_m::set_isr_handler(TIM7_IRQn, tim7_isr);
	opsy::cortex_m::set_priority(TIM6_IRQn, test_priority);
	opsy::cortex_m::set_priority(TIM7_IRQn, test_priority);
	opsy::cortex_m::enable_interrupt(TIM6_IRQn);
	opsy::cortex_m::enable_interrupt(TIM7_IRQn);
}

void release_test_hardware()
{
	tim6.tim6_cr1 = tim6_p::tim6_cr1_r::cen_f(false);
	opsy::cortex_m::disable_interrupt(TIM6_IRQn);
	opsy::cortex_m::disable_interrupt(TIM7_IRQn);
}

// ── Phase 1: probes ───────────────────────────────────────────────────────────

// Each probe is a single asm block, so the compiler cannot insert anything between LDREX and
// STREX. It returns the STREX status: 0 when the store happened.

std::uint32_t probe_quiet(std::uint32_t address, std::uint32_t a)
{
	std::uint32_t value;
	std::uint32_t status;
	asm volatile(
		"ldrex %[value], [%[address]]\n\t"
		"eor   %[value], %[value], %[a]\n\t"
		"strex %[status], %[value], [%[address]]"
		: [value] "=&r"(value), [status] "=&r"(status)
		: [address] "r"(address), [a] "r"(a)
		: "memory");
	return status;
}

constexpr std::uint32_t nvic_ispr = 0xE000E200u;

std::uint32_t probe_isr(std::uint32_t address, std::uint32_t a)
{
	auto const ispr = nvic_ispr + 4u * (std::uint32_t{TIM7_IRQn} / 32u);
	auto const pend = 1u << (std::uint32_t{TIM7_IRQn} % 32u);
	std::uint32_t value;
	std::uint32_t status;
	asm volatile(
		"ldrex %[value], [%[address]]\n\t"
		"str   %[pend], [%[ispr]]\n\t"    // pend TIM7
		"dsb\n\t"
		"isb\n\t"                         // the interrupt is taken here
		"eor   %[value], %[value], %[a]\n\t"
		"strex %[status], %[value], [%[address]]"
		: [value] "=&r"(value), [status] "=&r"(status)
		: [address] "r"(address), [a] "r"(a), [ispr] "r"(ispr), [pend] "r"(pend)
		: "memory");
	return status;
}

/// Word GPDMA copies into the target; must stay in memory, the DMA reads it.
volatile std::uint32_t dma_source;

std::uint32_t probe_dma(std::uint32_t address, std::uint32_t a, std::uint32_t b, bool& timed_out)
{
	dma_source = read(address) ^ b;
	gpdma1.gpdma_c2fcr = gpdma_p::gpdma_cxfcr_r::tcf_f()
	                   | gpdma_p::gpdma_cxfcr_r::htf_f()
	                   | gpdma_p::gpdma_cxfcr_r::dtef_f()
	                   | gpdma_p::gpdma_cxfcr_r::ulef_f()
	                   | gpdma_p::gpdma_cxfcr_r::usef_f()
	                   | gpdma_p::gpdma_cxfcr_r::suspf_f()
	                   | gpdma_p::gpdma_cxfcr_r::tof_f();
	gpdma1.gpdma_c2sar = gpdma_p::gpdma_cxsar_r::sa_f(reinterpret_cast<std::uint32_t>(&dma_source));
	gpdma1.gpdma_c2dar = gpdma_p::gpdma_cxdar_r::da_f(address);
	gpdma1.gpdma_c2br1 = gpdma_p::gpdma_cxbr1_r::bndt_f(4);

	auto const cr = reinterpret_cast<std::uint32_t>(&gpdma1.gpdma_c2cr);
	auto const sr = reinterpret_cast<std::uint32_t>(&gpdma1.gpdma_c2sr);
	std::uint32_t const enable = gpdma_p::gpdma_cxcr_r::en_f::mask;
	std::uint32_t const tcf = gpdma_p::gpdma_cxsr_r::tcf_f::mask;
	std::uint32_t remaining = 100000;
	std::uint32_t value;
	std::uint32_t status;
	std::uint32_t flags;
	asm volatile(
		"ldrex %[value], [%[address]]\n\t"
		"str   %[enable], [%[cr]]\n\t"    // start the DMA transfer
		"1:\n\t"
		"ldr   %[flags], [%[sr]]\n\t"
		"tst   %[flags], %[tcf]\n\t"
		"bne   2f\n\t"
		"subs  %[remaining], %[remaining], #1\n\t"
		"bne   1b\n\t"
		"2:\n\t"
		"eor   %[value], %[value], %[a]\n\t"
		"strex %[status], %[value], [%[address]]"
		: [value] "=&r"(value), [status] "=&r"(status), [flags] "=&r"(flags), [remaining] "+r"(remaining)
		: [address] "r"(address), [a] "r"(a), [cr] "r"(cr), [sr] "r"(sr), [enable] "r"(enable), [tcf] "r"(tcf)
		: "cc", "memory");
	timed_out = remaining == 0 || gpdma1.gpdma_c2sr.load().dtef();
	return status;
}

enum class probe_kind { quiet, isr, dma };

struct probe_result
{
	std::uint32_t stored = 0;    ///< STREX succeeded
	std::uint32_t failed = 0;    ///< STREX failed
	std::uint32_t lost = 0;      ///< STREX succeeded and erased the interfering write
	std::uint32_t anomalies = 0; ///< STREX status contradicts the register content
	std::uint32_t timeouts = 0;  ///< DMA did not complete (error or timeout)
};

constexpr std::uint32_t probe_iterations = 10000;

probe_result run_probe(target const& t, probe_kind kind)
{
	probe_result r;
	if (kind == probe_kind::isr)
		arm_isr(t.address, t.b);

	for (std::uint32_t i = 0; i < probe_iterations; ++i)
	{
		auto const before = read(t.address);
		bool timed_out = false;
		std::uint32_t status = 0;
		switch (kind)
		{
		case probe_kind::quiet: status = probe_quiet(t.address, t.a); break;
		case probe_kind::isr:   status = probe_isr(t.address, t.a); break;
		case probe_kind::dma:   status = probe_dma(t.address, t.a, t.b, timed_out); break;
		}
		opsy::cortex_m::data_barrier();
		auto const after = read(t.address);
		bool const a_toggled = ((before ^ after) & t.a) != 0;
		bool const b_toggled = ((before ^ after) & t.b) != 0;

		if (timed_out)
			++r.timeouts;
		if (status == 0)
		{
			++r.stored;
			if (!a_toggled)
				++r.anomalies;
			if (kind != probe_kind::quiet && !b_toggled && !timed_out)
				++r.lost;
		}
		else
		{
			++r.failed;
			if (a_toggled)
				++r.anomalies;
		}
	}

	disarm_isr();
	return r;
}

// ── Phase 2: stress of the OpSy operators ─────────────────────────────────────

enum class update { plain, fetch_xor, compare_exchange };

struct stress_result
{
	std::uint32_t lost = 0;       ///< Updates of the ISR's bit erased by the code under test
	std::uint32_t interrupts = 0; ///< ISR runs during the loop
};

constexpr std::uint32_t stress_iterations = 200000;

template<typename TInt, typename TReg>
stress_result run_stress(opsy::utility::memory<TInt, TReg>& reg, target const& t, update mode)
{
	stress_result r;
	auto const a = TReg{static_cast<TInt>(t.a)};
	auto const none = TReg{static_cast<TInt>(0)};

	arm_isr(t.address, t.b);
	tim6.tim6_cnt = tim6_p::tim6_cnt_r::cnt_f(0);
	tim6.tim6_cr1 = tim6_p::tim6_cr1_r::cen_f();

	for (std::uint32_t i = 0; i < stress_iterations; ++i)
	{
		switch (mode)
		{
		case update::plain:            reg ^= a; break;
		case update::fetch_xor:        reg ^= a | atomic; break;
		case update::compare_exchange: reg <<= opsy::utility::clear_set<TReg>(a, (i % 2u == 0u) ? a : none) || atomic; break;
		}
	}

	tim6.tim6_cr1 = tim6_p::tim6_cr1_r::cen_f(false);
	disarm_isr();
	// A write undone after the last interrupt is not seen by the ISR: check it here.
	auto const final_lost = (static_cast<std::uint32_t>(reg.load().value()) & t.b) != isr_shadow.load(std::memory_order_relaxed);
	r.lost = isr_lost.load(std::memory_order_relaxed) + (final_lost ? 1u : 0u);
	r.interrupts = isr_count.load(std::memory_order_relaxed);
	return r;
}

// ── Results ───────────────────────────────────────────────────────────────────

constexpr std::array probe_names{ "quiet", "isr", "dma" };
constexpr std::array update_names{ "plain", "fetch_xor", "compare_exchange" };

std::array<std::array<probe_result, probe_names.size()>, 4> probes;
std::array<std::array<stress_result, update_names.size()>, 4> stresses;
std::array<target, 4> targets;

void run_all()
{
	targets = make_targets();
	for (std::size_t t = 0; t < targets.size(); ++t)
	{
		probes[t][0] = run_probe(targets[t], probe_kind::quiet);
		probes[t][1] = run_probe(targets[t], probe_kind::isr);
		probes[t][2] = run_probe(targets[t], probe_kind::dma);
	}

	// sram (index 0) is not an OpSy register: no stress phase for it
	constexpr std::array modes{ update::plain, update::fetch_xor, update::compare_exchange };
	for (std::size_t m = 0; m < modes.size(); ++m)
	{
		stresses[1][m] = run_stress(tim2.tim2_ccr1, targets[1], modes[m]);
		stresses[2][m] = run_stress(gpioe.gpio_odr, targets[2], modes[m]);
		stresses[3][m] = run_stress(rcc.rcc_ahb2enr, targets[3], modes[m]);
	}
}

bool verdict()
{
	bool pass = true;
	for (std::size_t t = 0; t < targets.size(); ++t)
	{
		auto const& quiet = probes[t][0];
		auto const& isr = probes[t][1];
		pass &= quiet.failed == 0 && quiet.anomalies == 0;
		pass &= isr.lost == 0 && isr.anomalies == 0;
		if (t == 0)
			continue;
		pass &= stresses[t][0].lost > 0; // the detector must catch the plain operator
		pass &= stresses[t][1].lost == 0 && stresses[t][2].lost == 0;
	}
	return pass;
}

std::array<char, 128> line;

void print(int length)
{
	if (length > 0)
		uart::send(std::span<const uint8_t>(reinterpret_cast<const uint8_t*>(line.data()),
		                                    std::min(static_cast<std::size_t>(length), line.size() - 1)));
}

void report()
{
	for (std::size_t t = 0; t < targets.size(); ++t)
		for (std::size_t k = 0; k < probe_names.size(); ++k)
		{
			auto const& r = probes[t][k];
			print(std::snprintf(line.data(), line.size(),
				"probe  %-11s %-5s n=%" PRIu32 " stored=%" PRIu32 " failed=%" PRIu32
				" lost=%" PRIu32 " anomalies=%" PRIu32 " timeouts=%" PRIu32 "\r\n",
				targets[t].name, probe_names[k], probe_iterations,
				r.stored, r.failed, r.lost, r.anomalies, r.timeouts));
		}

	for (std::size_t t = 1; t < targets.size(); ++t)
		for (std::size_t m = 0; m < update_names.size(); ++m)
		{
			auto const& r = stresses[t][m];
			print(std::snprintf(line.data(), line.size(),
				"stress %-11s %-16s n=%" PRIu32 " interrupts=%" PRIu32 " lost=%" PRIu32 "\r\n",
				targets[t].name, update_names[m], stress_iterations, r.interrupts, r.lost));
		}

	print(std::snprintf(line.data(), line.size(), "verdict %s\r\nend\r\n", verdict() ? "PASS" : "FAIL"));
}

opsy::task<1024> reporter;

} // namespace

int main()
{
	clock::init();
	uart::init();

	// Both phases run before the scheduler starts, so SysTick and task switches stay out of
	// the measurements.
	init_test_hardware();
	run_all();
	release_test_hardware();

	bool const system_ok = reporter.start([]{
		while (true)
		{
			(void)uart::receive();
			report();
		}
	});

	if (!system_ok)
		asm volatile("bkpt 0");

	opsy::scheduler::start(); // does not return
}
