// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    esc_bus.hpp
 * @author  Thomas Legrand
 * @brief   Register access to the LAN9253 EtherCAT slave controller of the Bornier base board
 *
 *          The OCTOSPI is the bus master, in indirect mode:
 *
 *          | Signal   | Pin  | Function            |
 *          |----------|------|---------------------|
 *          | SCK      | PB2  | OCTOSPI1_CLK, AF9   |
 *          | SCS#     | PB10 | OCTOSPI1_NCS, AF9   |
 *          | SI/SIO0  | PB1  | OCTOSPI1_IO0, AF6   |
 *          | SO/SIO1  | PB0  | OCTOSPI1_IO1, AF6   |
 *          | SIO2     | PA7  | OCTOSPI1_IO2, AF10  |
 *          | SIO3     | PA6  | OCTOSPI1_IO3, AF6   |
 *
 *          Two bus modes:
 *
 *          | Mode   | Lines | Clock    | Read command                       |
 *          |--------|-------|----------|------------------------------------|
 *          | single | 1     | 10 MHz   | READ (0x03)                        |
 *          | quad   | 4     | 62.5 MHz | FASTREAD (0x0B), 8 dummy cycles    |
 *
 *          Single mode only needs SCK, SCS#, SI and SO: it tells a fault of the bus from a
 *          fault of SIO2 or SIO3. Quad mode (SQI) is the one to work in.
 *
 *          Blocking transfers, 32 bits at a time. Not reentrant: the registers of the
 *          EtherCAT core go through one shared command register, so all the calls must come
 *          from a single task.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <cstdint>

#include <STM32H523/gpio.hpp>
#include <STM32H523/octospi.hpp>
#include <STM32H523/rcc.hpp>

namespace STM32H523
{

using mmio::atomic;

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
	static constexpr uint16_t hw_cfg    = 0x0074; ///< Bit 27, READY: set once the configuration is loaded from the SII EEPROM
	static constexpr uint32_t hw_cfg_ready = 1u << 27;

	/** @brief Bus mode, see the table at the top of this file. */
	enum class mode
	{
		single,
		quad,
	};

	/**
	 * @brief Configures the pins and the OCTOSPI, and leaves the bus in single mode.
	 *
	 *        The LAN9253 keeps its bus mode through a reset of the MCU alone: it is sent the
	 *        command that leaves quad mode, which it ignores when in single mode.
	 *
	 *        The OCTOSPI is clocked by HCLK, its reset selection. HCLK equals SYSCLK on this
	 *        board, the condition under which that selection gives correct data.
	 */
	static void init()
	{
		rcc.ahb2enr |= (rcc_p::ahb2enr_r::gpioaen_f() | rcc_p::ahb2enr_r::gpioben_f()) | atomic;
		rcc.ahb4enr |= rcc_p::ahb4enr_r::octospi1en_f() | atomic;

		gpioa.afrl <<= gpio_p::afrl_r::afsel6_f(6) || atomic;  // PA6  IO3
		gpioa.afrl <<= gpio_p::afrl_r::afsel7_f(10) || atomic; // PA7  IO2
		gpiob.afrl <<= gpio_p::afrl_r::afsel0_f(6) || atomic;  // PB0  IO1
		gpiob.afrl <<= gpio_p::afrl_r::afsel1_f(6) || atomic;  // PB1  IO0
		gpiob.afrl <<= gpio_p::afrl_r::afsel2_f(9) || atomic;  // PB2  CLK
		gpiob.afrh <<= gpio_p::afrh_r::afsel10_f(9) || atomic; // PB10 NCS

		// High speed (0b10) on the six pins, then alternate function mode (0b10).
		gpioa.ospeedr <<= gpio_p::ospeedr_r::ospeed6_f(0b10) || atomic;
		gpioa.ospeedr <<= gpio_p::ospeedr_r::ospeed7_f(0b10) || atomic;
		gpiob.ospeedr <<= gpio_p::ospeedr_r::ospeed0_f(0b10) || atomic;
		gpiob.ospeedr <<= gpio_p::ospeedr_r::ospeed1_f(0b10) || atomic;
		gpiob.ospeedr <<= gpio_p::ospeedr_r::ospeed2_f(0b10) || atomic;
		gpiob.ospeedr <<= gpio_p::ospeedr_r::ospeed10_f(0b10) || atomic;
		gpioa.moder <<= gpio_p::moder_r::mode6_f(0b10) || atomic;
		gpioa.moder <<= gpio_p::moder_r::mode7_f(0b10) || atomic;
		gpiob.moder <<= gpio_p::moder_r::mode0_f(0b10) || atomic;
		gpiob.moder <<= gpio_p::moder_r::mode1_f(0b10) || atomic;
		gpiob.moder <<= gpio_p::moder_r::mode2_f(0b10) || atomic;
		gpiob.moder <<= gpio_p::moder_r::mode10_f(0b10) || atomic;

		// DEVSIZE 15: 64 KB address space, the 16-bit addresses of the LAN9253.
		// CSHT 7: SCS# stays high 8 clock cycles between two commands (50 ns needed).
		// CKMODE 0: clock low while SCS# is high (SPI mode 0).
		octospi.dcr1 = octospi_p::dcr1_r::devsize_f(15)
		                     | octospi_p::dcr1_r::csht_f(7);
		octospi.dcr2 = octospi_p::dcr2_r::prescaler_f(prescaler_single);
		octospi.cr   = octospi_p::cr_r::en_f();

		command(lines_quad, reset_quad);
		quad_ = false;
	}

	/**
	 * @brief Switches the LAN9253 and the OCTOSPI to a bus mode.
	 *
	 * @param wanted Bus mode to work in from now on.
	 */
	static void set_mode(mode wanted)
	{
		const bool quad = wanted == mode::quad;
		if (quad == quad_)
			return;

		// The command goes out in the mode the chip is still in; the clock changes while the
		// OCTOSPI is idle, which command() guarantees on return.
		if (quad)
			command(lines_single, enable_quad);
		else
			command(lines_quad, reset_quad);
		octospi.dcr2 = octospi_p::dcr2_r::prescaler_f(quad ? prescaler_quad : prescaler_single);
		quad_ = quad;
	}

	/**
	 * @brief Reads one 32-bit register of the LAN9253.
	 *
	 *        8-bit instruction, 16-bit address, dummy cycles in quad mode, then 4 data bytes,
	 *        least significant first.
	 *
	 * @param address Register address.
	 * @return        Register value.
	 */
	static uint32_t read(uint16_t address)
	{
		start(0b01, quad_ ? fast_read_instruction : read_instruction, quad_ ? fast_read_dummy_cycles : 0);
		octospi.ar = octospi_p::ar_r(address); // starts the transfer

		while (!octospi.sr.load().tcf()) {}
		const uint32_t value = octospi.dr.load().value();
		finish();
		return value;
	}

	/**
	 * @brief Writes one 32-bit register of the LAN9253.
	 *
	 *        WRITE command (0x02): 8-bit instruction, 16-bit address, 4 data bytes, least
	 *        significant first.
	 *
	 * @param address Register address.
	 * @param value   Value to write.
	 */
	static void write(uint16_t address, uint32_t value)
	{
		start(0b00, write_instruction, 0);
		octospi.ar = octospi_p::ar_r(address);
		octospi.dr = octospi_p::dr_r(value); // starts the transfer

		while (!octospi.sr.load().tcf()) {}
		finish();
	}

	/**
	 * @brief Reads a register of the EtherCAT core (addresses of the EtherCAT slave controller
	 *        register map, 0x0000 to 0x0FFF).
	 *
	 *        The core is reached through the ECAT_CSR_CMD and ECAT_CSR_DATA registers: the
	 *        command is written, then polled until the LAN9253 has run it.
	 *
	 * @param address Address in the EtherCAT core, aligned on @p size.
	 * @param size    Number of bytes: 1, 2 or 4.
	 * @return        Value read, in the low @p size bytes.
	 */
	static uint32_t core_read(uint16_t address, uint32_t size)
	{
		write(ecat_csr_cmd, csr_busy | csr_read | (size << 16) | address);
		while (read(ecat_csr_cmd) & csr_busy) {}
		const uint32_t value = read(ecat_csr_data);
		return size == 4 ? value : value & ((1u << (8 * size)) - 1u);
	}

	/**
	 * @brief Writes a register of the EtherCAT core.
	 *
	 * @param address Address in the EtherCAT core, aligned on @p size.
	 * @param value   Value to write, in the low @p size bytes.
	 * @param size    Number of bytes: 1, 2 or 4.
	 */
	static void core_write(uint16_t address, uint32_t value, uint32_t size)
	{
		write(ecat_csr_data, value);
		write(ecat_csr_cmd, csr_busy | (size << 16) | address);
		while (read(ecat_csr_cmd) & csr_busy) {}
	}

private:

	static constexpr uint16_t ecat_csr_data = 0x0300; ///< Data of an EtherCAT core access
	static constexpr uint16_t ecat_csr_cmd  = 0x0304; ///< Command: busy, direction, size, address
	static constexpr uint32_t csr_busy = 1u << 31;    ///< Written 1 to start, reads 1 until done
	static constexpr uint32_t csr_read = 1u << 30;

	static constexpr uint32_t read_instruction      = 0x03; ///< READ, at most 30 MHz
	static constexpr uint32_t fast_read_instruction = 0x0B; ///< FASTREAD
	static constexpr uint32_t write_instruction     = 0x02; ///< WRITE
	static constexpr uint32_t enable_quad           = 0x38; ///< EQIO: single to quad
	static constexpr uint32_t reset_quad            = 0xFF; ///< RSTQIO: quad to single

	/// Dummy clock cycles between address and data of a FASTREAD in quad mode: measured on the
	/// board, the only count out of 0 to 11 that reads BYTE_TEST right, from 10 to 83 MHz.
	static constexpr uint8_t fast_read_dummy_cycles = 8;

	static constexpr uint8_t prescaler_single = 24; ///< 250 MHz / 25 = 10 MHz
	static constexpr uint8_t prescaler_quad   = 3;  ///< 250 MHz / 4 = 62.5 MHz (80 MHz at most)

	// Values of the IMODE, ADMODE and DMODE fields.
	static constexpr uint8_t lines_single = 1;
	static constexpr uint8_t lines_quad   = 3;

	static inline bool quad_ = false; ///< Bus mode the LAN9253 is in

	/// Sends an instruction alone, on the given lines, and returns once the OCTOSPI is idle.
	static void command(uint8_t lines, uint32_t instruction)
	{
		octospi.cr  = octospi_p::cr_r::en_f(); // indirect write
		octospi.ccr = octospi_p::ccr_r::imode_f(lines);
		octospi.tcr = octospi_p::tcr_r(0u);
		octospi.ir  = octospi_p::ir_r(instruction); // starts the transfer

		while (!octospi.sr.load().tcf()) {}
		finish();
	}

	/// Sets up a 4-byte transfer with a 16-bit address; the caller then gives the address.
	static void start(uint8_t functional_mode, uint32_t instruction, uint8_t dummy_cycles)
	{
		const uint8_t lines = quad_ ? lines_quad : lines_single;
		octospi.cr  = octospi_p::cr_r::en_f() | octospi_p::cr_r::fmode_f(functional_mode);
		octospi.dlr = octospi_p::dlr_r(3u); // 4 bytes
		octospi.ccr = octospi_p::ccr_r::imode_f(lines)
		                    | octospi_p::ccr_r::admode_f(lines)
		                    | octospi_p::ccr_r::adsize_f(1) // 16 bits
		                    | octospi_p::ccr_r::dmode_f(lines);
		octospi.tcr = octospi_p::tcr_r::dcyc_f(dummy_cycles);
		octospi.ir  = octospi_p::ir_r(instruction);
	}

	/// Ends a transfer and leaves the OCTOSPI ready for the next one.
	static void finish()
	{
		octospi.fcr = octospi_p::fcr_r::ctcf_f();

		// The OCTOSPI stays busy after the last data bit, until SCS# has been high long enough.
		// Meanwhile it ignores the writes that set up the next command, which would never start.
		while (octospi.sr.load().busy()) {}
	}
};

} // namespace STM32H523
