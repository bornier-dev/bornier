// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    supplies.hpp
 * @author  Thomas Legrand
 * @brief   Supply voltages of the Bornier base board, measured by ADC1, as a module
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
 *          VREFINT asks for a long sampling time.
 *
 *          The module's task starts the ADC (regulator, calibration, enable), then measures
 *          every 100 ms: one sequence of the two channels, stored by DMA (GPDMA2 channel 4,
 *          request adc1), whose end is signalled by its interrupt. read() returns the last
 *          measurement at once. Nothing waits by polling.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <array>
#include <chrono>
#include <cstdint>
#include <mutex>
#include <optional>
#include <type_traits>

#include <opsy.hpp>
#include <cortex_m.hpp>
#include <mutex.hpp>
#include <semaphore.hpp>

#include <STM32H523/adc.hpp>
#include <STM32H523/gpdma.hpp>
#include <STM32H523/gpio.hpp>
#include <STM32H523/icache.hpp>
#include <STM32H523/interrupts.hpp>
#include <STM32H523/rcc.hpp>

namespace STM32H523
{

using mmio::atomic;

/**
 * @brief Supply voltages of the board, in millivolts, as a module.
 *
 *        All methods are static — no instance needed. init(), isrs and start() are used by
 *        bornier::app; read() is for any task.
 */
class supplies
{
public:

	/** @brief One reading of the supplies. */
	struct reading
	{
		uint32_t vrefint_cal; ///< VREFINT read by the factory with VDDA at 3.3 V, 12 bits
		uint32_t vrefint_raw; ///< VREFINT conversion, 12 bits
		uint32_t vin_raw;     ///< VIN_SENSE conversion, 12 bits
		uint32_t vdda_mv;     ///< VDDA, the 3.3 V rail
		uint32_t vin_mv;      ///< +VIN
	};

	/** @brief Configures PC0, the ADC clock and the DMA channel. The ADC is started by the task. */
	static void init()
	{
		rcc.ahb1enr |= rcc_p::ahb1enr_r::gpdma2en_f() | atomic;
		rcc.ahb2enr |= rcc_p::ahb2enr_r::gpiocen_f() | rcc_p::ahb2enr_r::adcen_f() | atomic;
		gpioc.moder <<= gpio_p::moder_r::mode0_f(0b11) || atomic;

		// CKMODE = 11: HCLK / 4. VREFEN: VREFINT on INP17.
		adcc.ccr = adcc_p::ccr_r::ckmode_f(0b11) | adcc_p::ccr_r::vrefen_f();

		// Half-words from DR to the incrementing results, on the request of ADC1.
		dma().tr1 = gpdma_p::c_c::tr1_r::sdw_log2_f(1) | gpdma_p::c_c::tr1_r::ddw_log2_f(1)
		              | gpdma_p::c_c::tr1_r::dinc_f();
		dma().tr2 = gpdma_p::c_c::tr2_r::reqsel_f(adc1_request);
		dma().sar = gpdma_p::c_c::sar_r::sa_f(reinterpret_cast<std::uint32_t>(&adc.dr));

		opsy::cortex_m::set_priority(GPDMA2_CH4_IRQn, opsy::scheduler::os_callable_priority);
		opsy::cortex_m::enable_interrupt(GPDMA2_CH4_IRQn);
	}

	/** @brief Starts the task that starts the ADC, then measures every 100 ms. */
	static bool start() { return task_.start([] { run(); }); }

	/** @brief The last measurement, or nothing before the first one. */
	static std::optional<reading> read()
	{
		const std::lock_guard lock(latest_lock_);
		return latest_;
	}

private:

	static constexpr std::uintptr_t vrefint_cal_address = 0x08FFF810;
	static constexpr uint32_t vrefint_charac_mv = 3300;
	static constexpr uint32_t full_scale = 4095;
	static constexpr uint32_t r_top = 100'000;   ///< R11, ohms
	static constexpr uint32_t r_bottom = 4'700;  ///< R12, ohms
	static constexpr std::uint8_t adc1_request = 0; ///< GPDMA request, RM0481 table 142

	using channel = std::remove_reference_t<decltype(gpdma2.c[0])>;
	static channel& dma() { return gpdma2.c[4]; }

	static void run()
	{
		using namespace std::chrono_literals;
		power_up();
		const uint32_t calibration = vrefint_cal();
		while (true)
		{
			if (const auto raw = measure())
			{
				const reading r = convert(calibration, (*raw)[0], (*raw)[1]);
				const std::lock_guard lock(latest_lock_);
				latest_ = r;
			}
			opsy::sleep_for(100ms);
		}
	}

	/// Leaves deep power down, starts the regulator, calibrates, enables (RM0481 §28.4.6-28.4.9).
	static void power_up()
	{
		using namespace std::chrono_literals;

		// DEEPPWD is 1 out of reset: writing ADVREGEN alone clears it. The regulator needs
		// 20 us at most.
		adc.cr = adc_p::cr_r::advregen_f();
		opsy::sleep_for(1ms);

		// ADCALDIF = 0: single-ended calibration, a few hundred ADC cycles.
		adc.cr = adc_p::cr_r::advregen_f() | adc_p::cr_r::adcal_f();
		while (adc.cr.load().adcal())
			opsy::sleep_for(1ms);

		// ADEN written within 4 ADC clock cycles of the end of calibration is ignored: it is
		// written again until the ADC is ready.
		adc.isr = adc_p::isr_r::adrdy_f();
		while (!adc.isr.load().adrdy())
		{
			if (!adc.cr.load().aden())
				adc.cr = adc_p::cr_r::advregen_f() | adc_p::cr_r::aden_f();
			opsy::sleep_for(1ms);
		}

		// One sequence of two conversions: VREFINT then VIN_SENSE; results by DMA.
		adc.smpr2 = adc_p::smpr2_r::smp10_f(0b111) | adc_p::smpr2_r::smp17_f(0b111);
		adc.sqr1  = adc_p::sqr1_r::l_f(1) | adc_p::sqr1_r::sq1_f(17) | adc_p::sqr1_r::sq2_f(10);
		adc.cfgr  = adc.cfgr.load() | adc_p::cfgr_r::dmaen_f();
	}

	/// Converts the sequence once, results by DMA; nothing if the end did not come in 10 ms.
	static std::optional<std::array<std::uint16_t, 2>> measure()
	{
		using namespace std::chrono_literals;
		dma().fcr = gpdma_p::c_c::fcr_r::tcf_f() | gpdma_p::c_c::fcr_r::dtef_f()
		              | gpdma_p::c_c::fcr_r::ulef_f() | gpdma_p::c_c::fcr_r::usef_f()
		              | gpdma_p::c_c::fcr_r::tof_f();
		dma().dar = gpdma_p::c_c::dar_r::da_f(reinterpret_cast<std::uint32_t>(raw_.data()));
		dma().br1 = gpdma_p::c_c::br1_r::bndt_f(sizeof(raw_));
		dma().cr  = gpdma_p::c_c::cr_r::en_f() | gpdma_p::c_c::cr_r::tcie_f();
		adc.cr = adc.cr.load() | adc_p::cr_r::adstart_f();
		if (!done_.try_acquire_for(10ms))
			return std::nullopt;
		return raw_;
	}

	static reading convert(uint32_t calibration, uint32_t vrefint_raw, uint32_t vin_raw)
	{
		reading r{};
		r.vrefint_cal = calibration;
		r.vrefint_raw = vrefint_raw;
		r.vin_raw = vin_raw;
		r.vdda_mv = vrefint_charac_mv * calibration / vrefint_raw;
		r.vin_mv = static_cast<uint32_t>(uint64_t{vin_raw} * r.vdda_mv * (r_top + r_bottom)
		                                 / (full_scale * r_bottom));
		return r;
	}

	/// VREFINT_CAL, from the read-only flash area: that area gives a bus error when read
	/// through the instruction cache, which is off for this one read. Disabling the cache
	/// invalidates it; the invalidation (a few cycles) must end before it is enabled again.
	static uint32_t vrefint_cal()
	{
		const bool cached = icache.cr.load().en();
		icache.cr <<= icache_p::cr_r::en_f(false);
		const uint32_t value = *reinterpret_cast<const volatile uint16_t*>(vrefint_cal_address);
		if (cached)
		{
			while (icache.sr.load().busyf()) {}
			icache.cr = icache.cr.load() | icache_p::cr_r::en_f();
		}
		return value;
	}

	static void dma_isr()
	{
		dma().fcr = gpdma_p::c_c::fcr_r::tcf_f();
		done_.release();
	}

	static inline std::array<std::uint16_t, 2> raw_{};
	static inline opsy::binary_semaphore done_{0};
	static inline opsy::mutex latest_lock_;
	static inline std::optional<reading> latest_;
	static inline opsy::task<512> task_;

public:

	/** @brief The handler of the module: end of the DMA transfer of a sequence. */
	static constexpr auto isrs = []<typename Table>(const Table& table) -> Table
	{
		return table.template with<GPDMA2_CH4_IRQn, dma_isr>();
	};
};

} // namespace STM32H523
