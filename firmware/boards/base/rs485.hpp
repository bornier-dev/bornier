// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    rs485.hpp
 * @author  Thomas Legrand
 * @brief   Isolated RS-485 port of the Bornier base board (MODBUS terminal block)
 *
 *          | Signal | Pin | Function           |
 *          |--------|-----|--------------------|
 *          | DE     | PD4 | USART2_RTS/DE, AF7 |
 *          | TX     | PD5 | USART2_TX, AF7     |
 *          | RX     | PD6 | USART2_RX, AF7     |
 *
 *          Half duplex. The USART drives DE by itself around each frame. The receiver of the
 *          transceiver is always on: every byte sent comes back on RX, through the isolation
 *          and the line.
 *
 *          115200 baud, 8 data bits, no parity, 1 stop bit. Blocking, one byte at a time.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <cstdint>
#include <optional>

#include <STM32H523/gpiod.hpp>
#include <STM32H523/rcc.hpp>
#include <STM32H523/usart.hpp>

namespace STM32H523
{

using opsy::utility::atomic;

/**
 * @brief Isolated RS-485 port, on USART2.
 *
 *        All methods are static — no instance needed.
 *        Call @c init() once, after @c clock::init().
 */
class rs485
{
public:

	/** @brief Line errors seen by the receiver since the last call to @c take_errors(). */
	struct errors
	{
		bool framing; ///< A stop bit was read low
		bool noise;   ///< The three samples of a bit disagreed
		bool overrun; ///< A byte arrived before the previous one was read
	};

	/** @brief Configures the pins and USART2. */
	static void init()
	{
		rcc.rcc_ahb2enr  |= rcc_p::rcc_ahb2enr_r::gpioden_f() | atomic;
		rcc.rcc_apb1lenr |= rcc_p::rcc_apb1lenr_r::usart2en_f() | atomic;

		gpiod.gpiod_afrl <<= gpiod_p::gpiod_afrl_r::afsel4_f(7) || atomic;
		gpiod.gpiod_afrl <<= gpiod_p::gpiod_afrl_r::afsel5_f(7) || atomic;
		gpiod.gpiod_afrl <<= gpiod_p::gpiod_afrl_r::afsel6_f(7) || atomic;
		gpiod.gpiod_moder <<= gpiod_p::gpiod_moder_r::mode4_f(0b10) || atomic;
		gpiod.gpiod_moder <<= gpiod_p::gpiod_moder_r::mode5_f(0b10) || atomic;
		gpiod.gpiod_moder <<= gpiod_p::gpiod_moder_r::mode6_f(0b10) || atomic;

		usart2.usart_brr = usart_p::usart_brr_r(clock_hz / baud_rate);

		// DEM: DE driven by the USART, active high.
		usart2.usart_cr3 = usart_p::usart_cr3_r::dem_f();

		// DEAT, DEDT: DE rises 8 sample times (half a bit) before the start bit and falls as
		// long after the stop bit.
		usart2.usart_cr1 = usart_p::usart_cr1_r::deat_f(8)
		                 | usart_p::usart_cr1_r::dedt_f(8)
		                 | usart_p::usart_cr1_r::te_f()
		                 | usart_p::usart_cr1_r::re_f()
		                 | usart_p::usart_cr1_r::ue_f();
	}

	/** @brief Sends one byte, once the previous one has left the transmit register. */
	static void send(uint8_t byte)
	{
		while (!usart2.usart_isr.load().txfnf()) {}
		usart2.usart_tdr = usart_p::usart_tdr_r(byte);
	}

	/**
	 * @brief Waits for one byte.
	 *
	 * @param polls Number of times the receiver is polled before giving up.
	 * @return      The byte, or nothing when none came.
	 */
	static std::optional<uint8_t> receive(uint32_t polls)
	{
		for (; polls > 0; --polls)
			if (usart2.usart_isr.load().rxfne())
				return static_cast<uint8_t>(usart2.usart_rdr.load().value());
		return std::nullopt;
	}

	/** @brief Tells whether the receiver sees the line idle, between two frames. */
	static bool line_idle() { return !usart2.usart_isr.load().busy(); }

	/** @brief Returns the line errors seen since the last call, and clears them. */
	static errors take_errors()
	{
		const auto status = usart2.usart_isr.load();
		const errors seen{status.fe(), status.ne(), status.ore()};
		usart2.usart_icr = usart_p::usart_icr_r::fecf_f() | usart_p::usart_icr_r::necf_f() | usart_p::usart_icr_r::orecf_f();
		return seen;
	}

private:

	static constexpr uint32_t clock_hz  = 250'000'000; ///< APB1, see clock.hpp
	static constexpr uint32_t baud_rate = 115'200;
};

} // namespace STM32H523
