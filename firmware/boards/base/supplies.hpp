// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    supplies.hpp
 * @author  Thomas Legrand
 * @brief   Supply voltages of the Bornier base board, measured by ADC1
 *
 *          | Signal    | Pin / input  | Source                                      |
 *          |-----------|--------------|---------------------------------------------|
 *          | VIN_SENSE | PC0, INP10   | +VIN through R11 (100 k) and R12 (4.7 k)    |
 *          | VREFINT   | INP17        | internal reference, calibrated at 3.3 V     |
 *
 *          VREF+ is VDDA, the 3.3 V rail through R316 (49.9 ohm): VREFINT against its
 *          factory value gives VDDA, then VIN_SENSE gives +VIN on that scale.
 *
 *          ADC clock: HCLK / 4 = 62.5 MHz (75 MHz at most). Every channel is sampled for
 *          640.5 cycles, 10.2 us: VIN_SENSE has a 4.5 kohm source held by 100 nF, and
 *          VREFINT asks for a long sampling time. One conversion at a time, blocking.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <cstdint>

#include <STM32H523/adc.hpp>
#include <STM32H523/gpio.hpp>
#include <STM32H523/icache.hpp>
#include <STM32H523/rcc.hpp>

namespace STM32H523
{

using mmio::atomic;

/**
 * @brief Supply voltages of the board, in millivolts.
 *
 *        All methods are static — no instance needed.
 *        Call @c init() once, after @c clock::init().
 */
class supplies
{
public:

	/** @brief One reading of the supplies. */
	struct reading
	{
		uint32_t vrefint_raw; ///< VREFINT conversion, 12 bits
		uint32_t vin_raw;     ///< VIN_SENSE conversion, 12 bits
		uint32_t vdda_mv;     ///< VDDA, the 3.3 V rail
		uint32_t vin_mv;      ///< +VIN
	};

	/**
	 * @brief Configures PC0 and ADC1, then calibrates the ADC.
	 *
	 *        The ADC leaves deep power down, its regulator starts, the single-ended
	 *        calibration runs, then the ADC is enabled.
	 */
	static void init()
	{
		rcc.ahb2enr |= rcc_p::ahb2enr_r::gpiocen_f() | rcc_p::ahb2enr_r::adcen_f() | atomic;
		gpioc.moder <<= gpio_p::moder_r::mode0_f(0b11) || atomic;

		// CKMODE = 11: HCLK / 4. VREFEN: VREFINT on INP17.
		adcc.ccr = adcc_p::ccr_r::ckmode_f(0b11) | adcc_p::ccr_r::vrefen_f();

		// DEEPPWD is 1 out of reset: writing ADVREGEN alone clears it.
		adc.cr = adc_p::cr_r::advregen_f();
		for (uint32_t i = 0; i < regulator_startup_loops; ++i)
			asm volatile("nop");

		// ADCALDIF = 0: single-ended calibration.
		adc.cr = adc_p::cr_r::advregen_f() | adc_p::cr_r::adcal_f();
		while (adc.cr.load().adcal()) {}

		// ADEN written within 4 ADC clock cycles of the end of calibration is ignored: it is
		// written again until the ADC is ready.
		adc.isr = adc_p::isr_r::adrdy_f();
		while (!adc.isr.load().adrdy())
			if (!adc.cr.load().aden())
				adc.cr = adc_p::cr_r::advregen_f() | adc_p::cr_r::aden_f();

		adc.smpr2 = adc_p::smpr2_r::smp10_f(0b111) | adc_p::smpr2_r::smp17_f(0b111);

		// The read-only area of the flash gives a bus error when read through the instruction
		// cache, which clock::init() turns on: the cache is off for this one read. Disabling it
		// invalidates it; the invalidation must end (BUSYF = 0) before it is enabled again.
		const bool cached = icache.cr.load().en();
		icache.cr <<= icache_p::cr_r::en_f(false);
		calibration = *reinterpret_cast<const volatile uint16_t*>(vrefint_cal_address);
		if (cached)
		{
			while (icache.sr.load().busyf()) {}
			icache.cr = icache.cr.load() | icache_p::cr_r::en_f();
		}
	}

	/** @brief Converts VREFINT and VIN_SENSE and returns the voltages. */
	static reading read()
	{
		reading r{};
		r.vrefint_raw = convert(17);
		r.vin_raw = convert(10);
		r.vdda_mv = vrefint_charac_mv * calibration / r.vrefint_raw;
		r.vin_mv = static_cast<uint32_t>(uint64_t{r.vin_raw} * r.vdda_mv * (r_top + r_bottom)
		                                 / (full_scale * r_bottom));
		return r;
	}

	/** @brief VREFINT read by the factory with VDDA at 3.3 V, 12 bits; read by @c init(). */
	static uint32_t vrefint_cal() { return calibration; }

private:

	/** @brief Runs one regular conversion of @p channel and returns it, 12 bits. */
	static uint32_t convert(uint8_t channel)
	{
		adc.sqr1 = adc_p::sqr1_r::sq1_f(channel); // L = 0: one conversion
		adc.cr = adc.cr.load() | adc_p::cr_r::adstart_f();
		while (!adc.isr.load().eoc()) {}
		return adc.dr.load().value() & 0xFFFF; // reading DR clears EOC
	}

	static constexpr uintptr_t vrefint_cal_address = 0x08FFF810;
	static constexpr uint32_t vrefint_charac_mv = 3300;
	static constexpr uint32_t full_scale = 4095;
	static constexpr uint32_t r_top = 100'000;   ///< R11, ohms
	static constexpr uint32_t r_bottom = 4'700;  ///< R12, ohms
	static constexpr uint32_t regulator_startup_loops = 10'000; ///< At least 40 us at 250 MHz

	static inline uint32_t calibration = 0; ///< VREFINT_CAL, written once by init()
};

} // namespace STM32H523
