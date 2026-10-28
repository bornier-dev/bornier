// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    clock.hpp
 * @author  Thomas Legrand
 * @brief   STM32H563 system clock configuration — 250 MHz from HSE via PLL1, instruction cache on
 *
 *          No HAL. All register accesses go through the typed wrappers in
 *          @c rcc.hpp, @c pwr.hpp and @c flash.hpp.
 *
 * @par PLL1 configuration (HSE → 250 MHz)
 *   | Parameter | Value | Note                                  |
 *   |-----------|-------|---------------------------------------|
 *   | Source    | HSE   | 8 MHz from the ST-LINK MCO, on PH0    |
 *   | DIVM1     | 2     | PLL input = 4 MHz (RGE 10: 4–8 MHz)  |
 *   | DIVN1     | 125   | VCO = 500 MHz (wide VCO, VCOSEL = 0) |
 *   | DIVP1     | 1(÷2) | PLL1P = 250 MHz → SYSCLK              |
 *
 * @par Bus clock tree
 *   | Bus   | Prescaler | Frequency |
 *   |-------|-----------|-----------|
 *   | AHB   | /1        | 250 MHz   |
 *   | APB1  | /1        | 250 MHz   |
 *   | APB2  | /1        | 250 MHz   |
 *   | APB3  | /1        | 250 MHz   |
 ******************************************************************************
 */

#pragma once

#include <cstdint>

#include <STM32H563/flash.hpp>
#include <STM32H563/icache.hpp>
#include <STM32H563/pwr.hpp>
#include <STM32H563/rcc.hpp>

namespace STM32H563
{

// The `atomic` postfix tag used in `| atomic` / `|| atomic` lives in
// opsy::utility — pull it into namespace scope so the BSP register
// helper expressions read naturally.
using opsy::utility::atomic;

/**
 * @brief System clock initialisation for STM32H563.
 *
 *        Brings the core to 250 MHz from the 8 MHz clock the ST-LINK
 *        drives on PH0 (MCO, crystal based; solder bridge SB49, the board
 *        default). The HSI wanders by several hundred ppm from one
 *        millisecond to the next, too much for timing measurements; the
 *        Bornier board also runs from an external oscillator in bypass.
 *        All steps are performed in the order mandated by the reference
 *        manual: voltage scaling first, then flash latency, then PLL,
 *        then bus dividers, then clock switch.
 */
class clock
{
public:

	/**
	 * @brief Configures and switches the system clock to 250 MHz.
	 *
	 *        Call once, early in @c main(), before any driver that depends
	 *        on the final clock frequency (timers, UART baud rates, …).
	 *        Safe to call from the main stack — does not interact with the
	 *        RTOS scheduler.
	 */
	static void init()
	{
		// ── 1. Voltage scaling ────────────────────────────────────────────
		// VOS0 (Scale 0) is required for SYSCLK > 200 MHz.
		// On STM32H563, VOS encoding: 0b11 = Scale 0 (highest, 250 MHz), 0b00 = Scale 3 (lowest, reset value).
		// The reset value is 0b00 (Scale 3), so we must set it to 0b11 explicitly and
		// wait for VOSRDY to guarantee the regulator has settled before we
		// increase the frequency.
		pwr.pwr_voscr = pwr_p::pwr_voscr_r::vos_f(3); // VOS0 = Scale 0 = 0b11 (supports 250 MHz)
		while (!pwr.pwr_vossr.load().vosrdy()) {}

		// ── 2. Flash access latency and prefetch ──────────────────────────
		// At 250 MHz with VOS0: 5 wait states, WRHIGHFREQ = 2.
		// Must be programmed *before* the clock frequency is increased.
		// PRFTEN: smart prefetch, recommended as soon as there is a wait state;
		// read back so that it is taken into account before going on.
		flash.flash_acr = flash_p::flash_acr_r::latency_f(5)
		                | flash_p::flash_acr_r::wrhighfreq_f(2)
		                | flash_p::flash_acr_r::prften_f();
		(void)flash.flash_acr.load();

		// ── 3. HSE in digital bypass ──────────────────────────────────────
		// The ST-LINK MCO is a digital square wave: bypass the oscillator
		// (HSEBYP) in digital mode (HSEEXT, written while HSE is off).
		rcc.rcc_cr = rcc.rcc_cr.load() | rcc_p::rcc_cr_r::hsebyp_f() | rcc_p::rcc_cr_r::hseext_f();
		rcc.rcc_cr = rcc.rcc_cr.load() | rcc_p::rcc_cr_r::hseon_f();
		while (!rcc.rcc_cr.load().hserdy()) {}

		// ── 4. PLL1 configuration ─────────────────────────────────────────
		// HSE (8 MHz) / DIVM1(2) = 4 MHz → × DIVN1(125) = 500 MHz VCO
		//   → / DIVP1(1→÷2) = 250 MHz PLL1P_CK (SYSCLK source)
		//
		// PLL1SRC = 11: HSE
		// PLL1RGE = 10: 4–8 MHz input range
		// VCOSEL  =  0: wide VCO (128–560 MHz) — default, not written
		// P output enabled; Q and R outputs left disabled
		rcc.rcc_pll1cfgr = rcc_p::rcc_pll1cfgr_r::pll1src_f(0b11)
		                 | rcc_p::rcc_pll1cfgr_r::pll1rge_f(0b10)
		                 | rcc_p::rcc_pll1cfgr_r::divm1_f(2)
		                 | rcc_p::rcc_pll1cfgr_r::pll1pen_f()
		                 | rcc_p::rcc_pll1cfgr_r::pll1fracen_f();

		rcc.rcc_pll1divr = rcc_p::rcc_pll1divr_r::pll1n_f(124)  // N-1 encoding: register 124 → actual ×125
		                 | rcc_p::rcc_pll1divr_r::pll1p_f(1);   // P-1 encoding: register 1   → actual ÷2

		// ── 5. Enable PLL1 and wait for lock ─────────────────────────────
		rcc.rcc_cr = rcc.rcc_cr.load() | rcc_p::rcc_cr_r::pll1on_f();
		while (!rcc.rcc_cr.load().pll1rdy()) {}

		// ── 6. Bus prescalers ─────────────────────────────────────────────
		// HPRE  = 0 → AHB  = SYSCLK / 1 = 250 MHz
		// PPREx = 0 → APBx = HCLK  / 1 = 250 MHz
		rcc.rcc_cfgr2 = rcc_p::rcc_cfgr2_r::hpre_f(0)
		              | rcc_p::rcc_cfgr2_r::ppre1_f(0)
		              | rcc_p::rcc_cfgr2_r::ppre2_f(0)
		              | rcc_p::rcc_cfgr2_r::ppre3_f(0);

		// ── 7. Switch SYSCLK to PLL1P and wait for confirmation ──────────
		// SW = 011: PLL1 P-output as system clock source
		rcc.rcc_cfgr1 = rcc_p::rcc_cfgr1_r::sw_f(0b011);
		while (static_cast<uint8_t>(rcc.rcc_cfgr1.load().sws()) != 0b011u) {}

		// ── 8. Instruction cache ─────────────────────────────────────────
		// Code runs from flash with 5 wait states: without the cache, every
		// fetch outside the prefetch buffer stalls. The invalidation started
		// at reset must be over (BUSYF = 0) before the cache is enabled,
		// otherwise accesses stay non-cacheable until it ends.
		while (icache.icache_sr.load().busyf()) {}
		icache.icache_cr = icache.icache_cr.load() | icache_p::icache_cr_r::en_f();
	}
};

} // namespace STM32H563
