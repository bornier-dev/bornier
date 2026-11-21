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
 *          | quad   | 4     | 62.5 MHz | FASTREAD (0x0B), length, dummy     |
 *
 *          Single mode only needs SCK, SCS#, SI and SO: it tells a fault of the bus from a
 *          fault of SIO2 or SIO3. Quad mode (SQI) is the one to work in.
 *
 *          Two PDI modes of the LAN9253 (DS00003421B, sections 9.2 and 9.3):
 *
 *          - LAN9252 compatibility (PDI 0x80), set by the straps of the board: the one it
 *            starts in. The EtherCAT core is reached through a command register, 1, 2 or 4
 *            bytes at a time (core_read(), core_write()). It serves the EEPROM emulation
 *            until the configuration is loaded from the SII.
 *          - EtherCAT Direct Mapped (PDI 0x82), set by the SII: the one to work in. The core
 *            is in the address space, any length in one transaction (direct_read(),
 *            direct_write()), at 41.7 MHz with dummy bytes for its access times. Transfers
 *            longer than a word are moved by DMA (GPDMA1 channel 7) while the calling task
 *            sleeps.
 *
 *          Not reentrant: all the calls must come from a single task.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <algorithm>
#include <array>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <span>
#include <type_traits>

#include <opsy.hpp>
#include <cortex_m.hpp>
#include <semaphore.hpp>

#include <STM32H523/gpdma.hpp>
#include <STM32H523/gpio.hpp>
#include <STM32H523/interrupts.hpp>
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
	 * @brief Configures the pins, the OCTOSPI and the DMA channel, and leaves the bus in single
	 *        mode.
	 *
	 *        The LAN9253 keeps its bus mode and its PDI mode through a reset of the MCU alone:
	 *        it is sent the command that leaves quad mode, which it ignores when in single mode,
	 *        and BYTE_TEST tells its PDI mode.
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
		                     | octospi_p::dcr1_r::csht_f(cs_high);
		octospi.dcr2 = octospi_p::dcr2_r::prescaler_f(prescaler_single);
		octospi.cr   = octospi_p::cr_r::en_f();

		command(lines_quad, reset_quad);
		quad_ = false;

		// In compatibility mode BYTE_TEST answers at its own address; in Direct Mapped mode,
		// that address is in the EtherCAT core, and BYTE_TEST answers 0x3000 above.
		direct_ = read(byte_test) != byte_test_value
		          && read(byte_test | direct_registers) == byte_test_value;

		// Transfers of more than a word in Direct Mapped mode: GPDMA1 channel 7.
		rcc.ahb1enr |= rcc_p::ahb1enr_r::gpdma1en_f() | atomic;
		opsy::cortex_m::set_priority(GPDMA1_CH7_IRQn, opsy::scheduler::os_callable_priority);
		opsy::cortex_m::enable_interrupt(GPDMA1_CH7_IRQn);
		opsy::cortex_m::set_priority(OCTOSPI1_IRQn, opsy::scheduler::os_callable_priority);
		opsy::cortex_m::enable_interrupt(OCTOSPI1_IRQn);
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
		quad_ = quad;
		octospi.dcr2 = octospi_p::dcr2_r::prescaler_f(prescaler());
	}

	/**
	 * @brief Resets the LAN9253 (DIGITAL_RST) and waits, asleep, until it answers again.
	 *
	 *        The LAN9253 then reloads its configuration from the SII EEPROM, which this board
	 *        emulates: the PDI it uses afterwards is the one of the SII (see follow_pdi()). It
	 *        comes back in single mode, in compatibility mode, with the default dummy bytes.
	 *        For tasks only.
	 *
	 * @return @c false if it does not answer within 10 ms.
	 */
	static bool reset()
	{
		using namespace std::chrono_literals;
		write(reset_ctl, digital_reset);
		quad_ = false;
		direct_ = false;
		octospi.dcr2 = octospi_p::dcr2_r::prescaler_f(prescaler());
		for (int attempt = 0; attempt < 10; ++attempt)
		{
			opsy::sleep_for(1ms); // about 1.3 ms
			if (read(byte_test) == byte_test_value)
				return true;
		}
		return false;
	}

	/**
	 * @brief Follows the PDI of the LAN9253 into EtherCAT Direct Mapped mode (PDI 0x82).
	 *
	 *        The LAN9253 takes the PDI of the SII once its configuration is loaded, at least
	 *        1.5 us after the last write of the EEPROM emulation. Called after each such write:
	 *        when the LAN9253 has switched, the bus switches too. In quad mode.
	 *
	 * @return @c true once in Direct Mapped mode.
	 */
	static bool follow_pdi()
	{
		if (direct_)
			return true;
		// Three reads span the 1.5 us of the switch.
		for (int attempt = 0; attempt < 3; ++attempt)
			if (read(byte_test) != byte_test_value)
				break;
			else if (attempt == 2)
				return false;
		if (read(byte_test | direct_registers) != byte_test_value)
			return false;
		set_configuration();
		direct_ = true;
		octospi.dcr2 = octospi_p::dcr2_r::prescaler_f(prescaler());
		return true;
	}

	/** @brief Whether the LAN9253 is in EtherCAT Direct Mapped mode, see follow_pdi(). */
	static bool direct() { return direct_; }

	/**
	 * @brief Reads one 32-bit register of the LAN9253, outside the EtherCAT core.
	 *
	 *        8-bit instruction, 16-bit address, in quad mode the length and dummy bytes, then
	 *        4 data bytes, least significant first.
	 *
	 * @param address Register address, as in compatibility mode.
	 * @return        Register value.
	 */
	static uint32_t read(uint16_t address)
	{
		start(0b01, quad_ ? fast_read_instruction : read_instruction);
		octospi.ar = octospi_p::ar_r(direct_ ? address | direct_registers : address); // starts the transfer

		while (!octospi.sr.load().tcf()) {}
		const uint32_t value = octospi.dr.load().value();
		finish();
		return value;
	}

	/**
	 * @brief Writes one 32-bit register of the LAN9253, outside the EtherCAT core.
	 *
	 *        WRITE command (0x02): 8-bit instruction, 16-bit address, 4 data bytes, least
	 *        significant first.
	 *
	 * @param address Register address, as in compatibility mode.
	 * @param value   Value to write.
	 */
	static void write(uint16_t address, uint32_t value)
	{
		start(0b00, write_instruction);
		octospi.ar = octospi_p::ar_r(direct_ ? address | direct_registers : address);
		octospi.dr = octospi_p::dr_r(value); // starts the transfer

		while (!octospi.sr.load().tcf()) {}
		finish();
	}

	/**
	 * @brief Reads a register of the EtherCAT core (addresses of the EtherCAT slave controller
	 *        register map, 0x0000 to 0x0FFF).
	 *
	 *        In compatibility mode, through the ECAT_CSR_CMD and ECAT_CSR_DATA registers: the
	 *        command is written, then polled until the LAN9253 has run it.
	 *
	 * @param address Address in the EtherCAT core, aligned on @p size.
	 * @param size    Number of bytes: 1, 2 or 4.
	 * @return        Value read, in the low @p size bytes.
	 */
	static uint32_t core_read(uint16_t address, uint32_t size)
	{
		if (direct_)
		{
			uint32_t value = 0;
			direct_read(address, std::span(reinterpret_cast<uint8_t*>(&value), size));
			return value;
		}
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
		if (direct_)
		{
			direct_write(address, std::span(reinterpret_cast<const uint8_t*>(&value), size));
			return;
		}
		write(ecat_csr_data, value);
		write(ecat_csr_cmd, csr_busy | (size << 16) | address);
		while (read(ecat_csr_cmd) & csr_busy) {}
	}

	/**
	 * @brief Reads bytes of the EtherCAT core, registers or process RAM, in Direct Mapped mode.
	 *
	 *        One SPI transaction per 64 bytes at most. A read within one word is synchronous;
	 *        a longer one is moved by DMA while the calling task sleeps. The LAN9253 sends
	 *        padding bytes before the first byte to align it, and dummy bytes between words.
	 *
	 * @param address First byte, any alignment, 0x0000 to 0x2FFF.
	 * @param data    Where the bytes go.
	 */
	static void direct_read(uint16_t address, std::span<uint8_t> data)
	{
		while (!data.empty())
		{
			const std::size_t pad = address & 3u;
			const std::size_t length = std::min(data.size(), chunk - pad);
			const std::size_t words = (pad + length + 3) / 4;
			const std::size_t stream = pad + length + read_gap * (words - 1);

			// FASTREAD, the address incremented (bits 15:14 = 01), the length, the dummy bytes.
			const auto request = words > 1 ? octospi_p::cr_r(octospi_p::cr_r::dmaen_f()) : octospi_p::cr_r(0u);
			start(0b01, fast_read_instruction, static_cast<uint32_t>(stream), request,
			      static_cast<uint8_t>(length));
			if (words == 1)
			{
				octospi.ar = octospi_p::ar_r(increment | address); // starts the transfer
				while (!octospi.sr.load().tcf()) {}
				const uint32_t value = octospi.dr.load().value();
				finish();
				for (std::size_t i = 0; i < length; ++i)
					data[i] = static_cast<uint8_t>(value >> (8 * (pad + i)));
			}
			else
			{
				// The DMA starts once the command is set up: data in the FIFO of the OCTOSPI
				// makes it busy, and a busy OCTOSPI ignores the writes that set up a command.
				dma_bytes(true, stream);
				octospi.ar = octospi_p::ar_r(increment | address);
				dma().cr = gpdma_p::c_c::cr_r::en_f() | gpdma_p::c_c::cr_r::tcie_f();
				done_.acquire();
				finish();
				for (std::size_t i = 0; i < length; ++i)
				{
					const std::size_t k = pad + i;
					data[i] = stream_[k + (k / 4) * read_gap];
				}
			}
			address = static_cast<uint16_t>(address + length);
			data = data.subspan(length);
		}
	}

	/**
	 * @brief Writes bytes of the EtherCAT core, registers or process RAM, in Direct Mapped mode.
	 *
	 *        One SPI transaction per 64 bytes at most, DWORD buffered: the LAN9253 writes each
	 *        word once whole, the last one at the end of the transaction. Dummy bytes between
	 *        words give it the time to; SCS# then stays high until the last write is done. A
	 *        write within one word is synchronous; a longer one is moved by DMA while the
	 *        calling task sleeps.
	 *
	 * @param address First byte, any alignment, 0x0000 to 0x2FFF.
	 * @param data    The bytes.
	 */
	static void direct_write(uint16_t address, std::span<const uint8_t> data)
	{
		octospi.dcr1 = octospi_p::dcr1_r::devsize_f(15) | octospi_p::dcr1_r::csht_f(write_guard);
		while (!data.empty())
		{
			const std::size_t pad = address & 3u;
			const std::size_t length = std::min(data.size(), chunk - pad);
			std::size_t stream = 0;
			for (std::size_t i = 0; i < length; ++i)
			{
				stream_[stream++] = data[i];
				if (((pad + i) & 3u) == 3u && i + 1 < length)
					for (std::size_t gap = 0; gap < write_gap; ++gap)
						stream_[stream++] = 0;
			}

			const bool one_word = pad + length <= 4;
			const auto request = one_word ? octospi_p::cr_r(0u)
			                              : octospi_p::cr_r(octospi_p::cr_r::dmaen_f() | octospi_p::cr_r::tcie_f());
			start(0b00, write_instruction, static_cast<uint32_t>(stream), request);
			octospi.ar = octospi_p::ar_r(dword_buffering | address); // starts, waits for data
			if (one_word)
			{
				auto* const fifo = reinterpret_cast<volatile uint8_t*>(&octospi.dr);
				for (std::size_t i = 0; i < stream; ++i)
					*fifo = stream_[i];
				while (!octospi.sr.load().tcf()) {}
			}
			else
			{
				dma_bytes(false, stream);
				dma().cr = gpdma_p::c_c::cr_r::en_f();
				done_.acquire();
			}
			finish(); // SCS# high for write_guard: the last word is written meanwhile
			address = static_cast<uint16_t>(address + length);
			data = data.subspan(length);
		}
		octospi.dcr1 = octospi_p::dcr1_r::devsize_f(15) | octospi_p::dcr1_r::csht_f(cs_high);
	}

private:

	static constexpr uint32_t byte_test_value = 0x87654321;
	static constexpr uint16_t reset_ctl = 0x01F8;      ///< RESET_CTL
	static constexpr uint32_t digital_reset = 1u << 0; ///< DIGITAL_RST: the whole chip but the PHYs

	static constexpr uint16_t ecat_csr_data = 0x0300; ///< Data of an EtherCAT core access
	static constexpr uint16_t ecat_csr_cmd  = 0x0304; ///< Command: busy, direction, size, address
	static constexpr uint32_t csr_busy = 1u << 31;    ///< Written 1 to start, reads 1 until done
	static constexpr uint32_t csr_read = 1u << 30;

	// EtherCAT Direct Mapped mode (DS00003421B, section 9.3): the core at 0x0000-0x2FFF, the
	// other registers moved to 0x3000 above their address in compatibility mode.
	static constexpr uint16_t direct_registers = 0x3000;
	static constexpr uint16_t increment        = 0x4000; ///< Address bits 15:14 = 01
	static constexpr uint16_t dword_buffering  = 0xC000; ///< Address bits 15:14 = 11, writes

	static constexpr uint32_t read_instruction      = 0x03; ///< READ, at most 30 MHz
	static constexpr uint32_t fast_read_instruction = 0x0B; ///< FASTREAD
	static constexpr uint32_t write_instruction     = 0x02; ///< WRITE
	static constexpr uint32_t enable_quad           = 0x38; ///< EQIO: single to quad
	static constexpr uint32_t reset_quad            = 0xFF; ///< RSTQIO: quad to single
	static constexpr uint32_t set_configuration_instruction = 0x01; ///< SETCFG

	static constexpr uint8_t prescaler_single = 24; ///< 250 MHz / 25 = 10 MHz
	static constexpr uint8_t prescaler_quad   = 3;  ///< 250 MHz / 4 = 62.5 MHz (80 MHz at most)
	static constexpr uint8_t prescaler_direct = 5;  ///< 250 MHz / 6 = 41.7 MHz, 24 ns a cycle

	static constexpr uint8_t cs_high     = 7;  ///< SCS# high 8 cycles between commands
	static constexpr uint8_t write_guard = 20; ///< 21 cycles, 504 ns, after a write of the core

	/// A FASTREAD in quad mode sends, after the address, the length of the transfer in one byte
	/// (up to 127), then dummy bytes. The length tells the LAN9253 where to stop: it never
	/// reads ahead. Compatibility mode: the 3 dummy bytes of the default, 6 cycles.
	static constexpr uint8_t fast_read_dummy_cycles = 6;

	// Direct Mapped mode, at 41.7 MHz (48 ns a byte in quad mode). Reads: the first data
	// 610 ns after the length, then 610 ns a word. Writes: 490 ns a word, and as much before
	// the next transaction (DS00003421B, section 9.3.2.3).
	static constexpr uint8_t direct_initial = 13;     ///< 26 cycles, data sampled 648 ns after the length
	static constexpr std::size_t read_gap = 12;       ///< 32 cycles from word to word, 768 ns
	static constexpr std::size_t write_gap = 10;      ///< 28 cycles from word to word, 672 ns
	static constexpr std::size_t chunk = 64;          ///< Bytes per transaction, the length in one byte

	/// Dummy bytes per instruction, in the order of DS00003421B table 9-3: the defaults, but for
	/// FASTREAD and WRITE in quad mode (SQI).
	static constexpr std::array<uint8_t, 40> configuration{
		0, 0, 0,  1, 0, 0,  1, 0, 0,  2, 0, 0,  1, 0, 0,  4, 0, 0,  // READ .. SQIOR
		0, 0, 0,  0, 0, 0,  0, 0, 0,  0, 0, 0,  0, 0, 0,           // WRITE .. SQADW
		direct_initial, 0, read_gap,                              // FASTREAD (SQI)
		0, 0, write_gap,                                          // WRITE (SQI)
		0};

	static constexpr std::uint8_t ospi1_request = 57; ///< GPDMA request, RM0481 table 142

	// Values of the IMODE, ADMODE and DMODE fields.
	static constexpr uint8_t lines_single = 1;
	static constexpr uint8_t lines_quad   = 3;

	static inline bool quad_ = false;   ///< Bus mode the LAN9253 is in
	static inline bool direct_ = false; ///< PDI mode the LAN9253 is in, see follow_pdi()

	/// A transaction of direct_read() or direct_write(): data, padding and dummy bytes.
	static inline std::array<uint8_t, chunk + read_gap * (chunk / 4)> stream_{};
	static inline opsy::binary_semaphore done_{0};

	using dma_channel = std::remove_reference_t<decltype(gpdma.c[0])>;
	static dma_channel& dma() { return gpdma.c[7]; }

	static uint8_t prescaler()
	{
		return !quad_ ? prescaler_single : direct_ ? prescaler_direct : prescaler_quad;
	}

	/// Sends SETCFG with the dummy bytes of Direct Mapped mode. In quad mode.
	static void set_configuration()
	{
		octospi.cr  = octospi_p::cr_r::en_f(); // indirect write
		octospi.dlr = octospi_p::dlr_r(configuration.size() - 1);
		octospi.ccr = octospi_p::ccr_r::imode_f(lines_quad) | octospi_p::ccr_r::dmode_f(lines_quad);
		octospi.tcr = octospi_p::tcr_r(0u);
		octospi.ir  = octospi_p::ir_r(set_configuration_instruction);
		auto* const fifo = reinterpret_cast<volatile uint8_t*>(&octospi.dr);
		for (const uint8_t byte : configuration)
		{
			while (!octospi.sr.load().ftf()) {} // the FIFO holds 32 bytes, sent in 0.6 us
			*fifo = byte;
		}
		while (!octospi.sr.load().tcf()) {}
		finish();
	}

	/// Sets up the DMA channel to move @p bytes, one byte at a time, between the OCTOSPI and
	/// stream_; the caller enables it once the command is set up.
	static void dma_bytes(bool reading, std::size_t bytes)
	{
		dma().fcr = gpdma_p::c_c::fcr_r::tcf_f() | gpdma_p::c_c::fcr_r::dtef_f()
		              | gpdma_p::c_c::fcr_r::ulef_f() | gpdma_p::c_c::fcr_r::usef_f()
		              | gpdma_p::c_c::fcr_r::tof_f();
		const auto buffer = reinterpret_cast<std::uint32_t>(stream_.data());
		const auto data_register = reinterpret_cast<std::uint32_t>(&octospi.dr);
		if (reading)
		{
			dma().tr1 = gpdma_p::c_c::tr1_r::dinc_f();
			dma().tr2 = gpdma_p::c_c::tr2_r::reqsel_f(ospi1_request);
			dma().sar = gpdma_p::c_c::sar_r::sa_f(data_register);
			dma().dar = gpdma_p::c_c::dar_r::da_f(buffer);
		}
		else
		{
			dma().tr1 = gpdma_p::c_c::tr1_r::sinc_f();
			dma().tr2 = gpdma_p::c_c::tr2_r::reqsel_f(ospi1_request) | gpdma_p::c_c::tr2_r::dreq_f();
			dma().sar = gpdma_p::c_c::sar_r::sa_f(buffer);
			dma().dar = gpdma_p::c_c::dar_r::da_f(data_register);
		}
		dma().br1 = gpdma_p::c_c::br1_r::bndt_f(static_cast<std::uint16_t>(bytes));
	}

	/// End of a read moved by DMA: the DMA has moved the last byte.
	static void dma_isr()
	{
		dma().fcr = gpdma_p::c_c::fcr_r::tcf_f();
		done_.release();
	}

	/// End of a write moved by DMA: the last bit is on the bus.
	static void octospi_isr()
	{
		octospi.cr <<= octospi_p::cr_r::tcie_f(false);
		done_.release();
	}

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

	/// Sets up a transfer of @p bytes with a 16-bit address; the caller then gives the address.
	/// @p extra adds to the control register (DMA request, interrupt). A FASTREAD tells the
	/// LAN9253 @p length data bytes (127 at most), @p bytes when 0: in Direct Mapped mode the
	/// transfer also carries padding and dummy bytes.
	static void start(uint8_t functional_mode, uint32_t instruction, uint32_t bytes = 4,
	                  octospi_p::cr_r extra = octospi_p::cr_r(0u), uint8_t length = 0)
	{
		const uint8_t lines = quad_ ? lines_quad : lines_single;
		const bool fast_read = instruction == fast_read_instruction;
		const uint8_t dummy_cycles = direct_ ? 2 * direct_initial : fast_read_dummy_cycles;
		octospi.cr  = octospi_p::cr_r::en_f() | octospi_p::cr_r::fmode_f(functional_mode) | extra;
		octospi.dlr = octospi_p::dlr_r(bytes - 1);
		octospi.abr = octospi_p::abr_r(length != 0 ? length : bytes); // the length byte of a FASTREAD
		octospi.ccr = octospi_p::ccr_r::imode_f(lines)
		                    | octospi_p::ccr_r::admode_f(lines)
		                    | octospi_p::ccr_r::adsize_f(1) // 16 bits
		                    | octospi_p::ccr_r::abmode_f(fast_read ? lines : 0) // 8 bits
		                    | octospi_p::ccr_r::dmode_f(lines);
		octospi.tcr = octospi_p::tcr_r::dcyc_f(fast_read ? dummy_cycles : 0);
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

public:

	/** @brief The handlers of the module: end of a transfer moved by DMA. */
	static constexpr auto isrs = []<typename Table>(const Table& table) -> Table
	{
		return table.template with<GPDMA1_CH7_IRQn, dma_isr>()
		            .template with<OCTOSPI1_IRQn, octospi_isr>();
	};
};

} // namespace STM32H523
