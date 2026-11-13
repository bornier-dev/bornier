// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    esc_bus.hpp
 * @author  Thomas Legrand
 * @brief   Register access to the LAN9253 EtherCAT slave controller of the Bornier base board
 *
 *          The OCTOSPI runs as a single-line SPI master, in indirect mode:
 *
 *          | Signal | Pin  | Function            |
 *          |--------|------|---------------------|
 *          | SCK    | PB2  | OCTOSPI1_CLK, AF9   |
 *          | SCS#   | PB10 | OCTOSPI1_NCS, AF9   |
 *          | SI     | PB1  | OCTOSPI1_IO0, AF6   |
 *          | SO     | PB0  | OCTOSPI1_IO1, AF6   |
 *
 *          SIO2 (PA7) and SIO3 (PA6) are left to the pull-ups of the LAN9253: they only serve
 *          in quad mode, which this driver does not use.
 *
 *          Reads only, blocking, 10 MHz: enough to identify the chip.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <cstdint>

#include <STM32H523/gpiob.hpp>
#include <STM32H523/octospi.hpp>
#include <STM32H523/rcc.hpp>

namespace STM32H523
{

using opsy::utility::atomic;

/**
 * @brief Register access to the LAN9253 through the OCTOSPI.
 *
 *        All methods are static — no instance needed.
 *        Call @c init() once, after @c clock::init().
 */
class esc_bus
{
public:

	static constexpr uint16_t id_rev    = 0x0050; ///< Chip ID (upper half) and revision (lower half)
	static constexpr uint16_t byte_test = 0x0064; ///< Reads 0x87654321 when the byte order is right

	/**
	 * @brief Configures the pins and the OCTOSPI: SPI mode 0, 10 MHz.
	 *
	 *        The OCTOSPI is clocked by HCLK, its reset selection. HCLK equals SYSCLK on this
	 *        board, the condition under which that selection gives correct data.
	 */
	static void init()
	{
		rcc.rcc_ahb2enr |= rcc_p::rcc_ahb2enr_r::gpioben_f() | atomic;
		rcc.rcc_ahb4enr |= rcc_p::rcc_ahb4enr_r::octospi1en_f() | atomic;

		gpiob.gpiob_afrl <<= gpiob_p::gpiob_afrl_r::afsel0_f(6) || atomic;  // PB0  IO1
		gpiob.gpiob_afrl <<= gpiob_p::gpiob_afrl_r::afsel1_f(6) || atomic;  // PB1  IO0
		gpiob.gpiob_afrl <<= gpiob_p::gpiob_afrl_r::afsel2_f(9) || atomic;  // PB2  CLK
		gpiob.gpiob_afrh <<= gpiob_p::gpiob_afrh_r::afsel10_f(9) || atomic; // PB10 NCS

		// High speed (0b10) on the four pins, then alternate function mode (0b10).
		gpiob.gpiob_ospeedr <<= gpiob_p::gpiob_ospeedr_r::ospeed0_f(0b10) || atomic;
		gpiob.gpiob_ospeedr <<= gpiob_p::gpiob_ospeedr_r::ospeed1_f(0b10) || atomic;
		gpiob.gpiob_ospeedr <<= gpiob_p::gpiob_ospeedr_r::ospeed2_f(0b10) || atomic;
		gpiob.gpiob_ospeedr <<= gpiob_p::gpiob_ospeedr_r::ospeed10_f(0b10) || atomic;
		gpiob.gpiob_moder <<= gpiob_p::gpiob_moder_r::mode0_f(0b10) || atomic;
		gpiob.gpiob_moder <<= gpiob_p::gpiob_moder_r::mode1_f(0b10) || atomic;
		gpiob.gpiob_moder <<= gpiob_p::gpiob_moder_r::mode2_f(0b10) || atomic;
		gpiob.gpiob_moder <<= gpiob_p::gpiob_moder_r::mode10_f(0b10) || atomic;

		// DEVSIZE 15: 64 KB address space, the 16-bit addresses of the LAN9253.
		// CSHT 7: SCS# stays high 8 clock cycles between two commands (800 ns, 50 ns needed).
		// CKMODE 0: clock low while SCS# is high (SPI mode 0).
		octospi.octospi_dcr1 = octospi_p::octospi_dcr1_r::devsize_f(15)
		                     | octospi_p::octospi_dcr1_r::csht_f(7);
		octospi.octospi_dcr2 = octospi_p::octospi_dcr2_r::prescaler_f(24); // 250 MHz / 25 = 10 MHz
		octospi.octospi_cr   = octospi_p::octospi_cr_r::en_f() | octospi_p::octospi_cr_r::fmode_f(0b01); // indirect read
	}

	/**
	 * @brief Reads one 32-bit register of the LAN9253.
	 *
	 *        READ command (0x03, at most 30 MHz): 8-bit instruction, 16-bit address, 4 data
	 *        bytes, least significant first, all on single lines.
	 *
	 * @param address Register address.
	 * @return        Register value.
	 */
	static uint32_t read(uint16_t address)
	{
		octospi.octospi_dlr = octospi_p::octospi_dlr_r(3u); // 4 bytes
		octospi.octospi_ccr = octospi_p::octospi_ccr_r::imode_f(1)
		                    | octospi_p::octospi_ccr_r::admode_f(1)
		                    | octospi_p::octospi_ccr_r::adsize_f(1) // 16 bits
		                    | octospi_p::octospi_ccr_r::dmode_f(1);
		octospi.octospi_tcr = octospi_p::octospi_tcr_r(0u);   // no dummy cycle
		octospi.octospi_ir  = octospi_p::octospi_ir_r(0x03u);
		octospi.octospi_ar  = octospi_p::octospi_ar_r(address); // starts the transfer

		while (!octospi.octospi_sr.load().tcf()) {}
		const uint32_t value = octospi.octospi_dr.load().value();
		octospi.octospi_fcr = octospi_p::octospi_fcr_r::ctcf_f();

		// The OCTOSPI stays busy after the last data bit, until SCS# has been high long enough.
		// Meanwhile it ignores the writes that set up the next command, which would never start.
		while (octospi.octospi_sr.load().busy()) {}
		return value;
	}
};

} // namespace STM32H523
