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
 *          A transaction ends as soon as its last bit is on the bus: the next one first waits
 *          for the OCTOSPI to be idle, SCS# high for long enough, and that time overlaps with
 *          the software in between.
 *
 *          Every wait has a deadline, drawn from the length of the transaction: twice its time
 *          on the bus, and for a transfer moved by DMA, that time in whole ticks of the RTOS
 *          clock. A wait that runs out is a failure of the bus: the transaction is aborted, the
 *          board goes to its safe state (Safety::fault()), and the bus stays down until the
 *          next reset of the MCU: every access then returns at once, reads giving 0. failed()
 *          tells what ran out.
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
#include <cstring>
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
 *
 * @tparam Safety Puts the board in its safe state when the bus fails, from the calling task: a
 *                static fault().
 */
template<typename Safety>
class esc_bus
{
public:

	/** @brief The wait that ran out when the bus failed, see the top of this file. */
	enum class failure : uint8_t
	{
		none,         ///< The bus works
		transfer,     ///< The OCTOSPI did not end a transaction
		dma,          ///< A transfer moved by DMA did not end
		core_command, ///< The LAN9253 did not run a command of its EtherCAT core
	};

	/** @brief Why the bus failed, @c failure::none while it works. */
	static failure failed() { return failure_; }

	static constexpr uint16_t id_rev    = 0x0050; ///< Chip ID (upper half) and revision (lower half)
	static constexpr uint16_t byte_test = 0x0064; ///< Reads 0x87654321 when the byte order is right
	static constexpr uint16_t hw_cfg    = 0x0074; ///< Bit 27, READY: set once the configuration is loaded from the SII EEPROM
	static constexpr uint32_t hw_cfg_ready = 1u << 27;

	/** @brief Bus mode, see the table at the top of this file. */
	enum class mode
	{
		spi, ///< single mode: one data line
		sqi, ///< quad mode: four data lines
	};

	/**
	 * @brief Configures the pins, the OCTOSPI and the DMA channel, and leaves the bus in single
	 *        mode.
	 *
	 *        The LAN9253 keeps its bus mode and its PDI mode through a reset of the MCU alone:
	 *        it is sent the command that leaves quad mode, which it ignores when in single mode,
	 *        and BYTE_TEST tells its PDI mode. A LAN9253 found in Direct Mapped mode may not
	 *        have its dummy bytes set: reset() it before any access to its core.
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
		// CKMODE 0: clock low while SCS# is high (SPI mode 0). CSHT: see prepare().
		octospi.dcr1 = octospi_p::dcr1_r::devsize_f(15)
		                     | octospi_p::dcr1_r::csht_f(cs_high_compatibility);
		cs_high_ = cs_high_compatibility;
		octospi.dcr2 = octospi_p::dcr2_r::prescaler_f(prescaler_single);
		octospi.cr   = octospi_p::cr_r::en_f();

		(void)opsy::cortex_m::enable_cycle_count(); // the deadlines of the waits; runs on this core
		command(lines_quad, reset_quad);
		quad_ = false;

		// In compatibility mode BYTE_TEST answers at its own address; in Direct Mapped mode,
		// that address is in the EtherCAT core, and BYTE_TEST answers 0x3000 above.
		direct_ = read(byte_test) != byte_test_value
		          && read(byte_test | direct_registers) == byte_test_value;
		pdi_change_ = false;

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
		const bool sqi = wanted == mode::sqi;
		if (sqi == quad_ || down())
			return;

		// The command goes out in the mode the chip is still in; the clock changes once the
		// OCTOSPI is idle.
		if (sqi)
			command(lines_single, enable_quad);
		else
			command(lines_quad, reset_quad);
		quad_ = sqi;
		idle();
		octospi.dcr2 = octospi_p::dcr2_r::prescaler_f(prescaler());
	}

	/**
	 * @brief Resets the LAN9253 (DIGITAL_RST) and waits, asleep, until it answers again.
	 *
	 *        The LAN9253 then reloads its configuration from the SII EEPROM, which this board
	 *        emulates: the PDI it uses afterwards is the one of the SII (see
	 *        expect_pdi_change()). It comes back in single mode, in compatibility mode, with the
	 *        default dummy bytes. For tasks only.
	 *
	 * @return @c false if it does not answer within 10 ms, or the bus failed.
	 */
	static bool reset()
	{
		using namespace std::chrono_literals;
		if (down())
			return false;
		write(reset_ctl, digital_reset);
		quad_ = false;
		direct_ = false;
		pdi_change_ = false;
		idle();
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
	 * @brief Tells that the EEPROM emulation has answered a command: the LAN9253 may be
	 *        loading its configuration, and then take the PDI of the SII.
	 *
	 *        From then on, each access to the core first checks the PDI mode, until the
	 *        configuration is loaded in compatibility mode (HW_CFG READY) or the LAN9253 is in
	 *        EtherCAT Direct Mapped mode (PDI 0x82): the bus then follows. No effect in Direct
	 *        Mapped mode.
	 */
	static void expect_pdi_change() { pdi_change_ = !direct_; }

	/** @brief Whether the LAN9253 is in EtherCAT Direct Mapped mode, see expect_pdi_change(). */
	static bool direct() { return direct_; }

	/**
	 * @brief Reads one 32-bit register of the LAN9253, outside the EtherCAT core.
	 *
	 *        8-bit instruction, 16-bit address, in quad mode the length and dummy bytes, then
	 *        4 data bytes, least significant first.
	 *
	 * @param address Register address, as in compatibility mode.
	 * @return        Register value, 0 once the bus failed.
	 */
	static uint32_t read(uint16_t address)
	{
		if (!start(0b01, quad_ ? fast_read_instruction : read_instruction))
			return 0;
		octospi.ar = octospi_p::ar_r(direct_ ? address | direct_registers : address); // starts the transfer

		if (!transferred(4))
			return 0;
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
		if (!start(0b00, write_instruction))
			return;
		octospi.ar = octospi_p::ar_r(direct_ ? address | direct_registers : address);
		octospi.dr = octospi_p::dr_r(value); // starts the transfer

		if (transferred(4))
			finish();
	}

	/**
	 * @brief Reads a register of the EtherCAT core (addresses of the EtherCAT slave controller
	 *        register map, 0x0000 to 0x0FFF).
	 *
	 *        In compatibility mode, through the ECAT_CSR_CMD and ECAT_CSR_DATA registers: the
	 *        command is written, then polled until the LAN9253 has run it. In Direct Mapped
	 *        mode, one transaction.
	 *
	 * @param address Address in the EtherCAT core, aligned on @p size.
	 * @param size    Number of bytes: 1, 2 or 4.
	 * @return        Value read, in the low @p size bytes; 0 once the bus failed.
	 */
	static uint32_t core_read(uint16_t address, uint32_t size)
	{
		if (pdi_change_)
			follow_pdi();
		const uint32_t mask = size == 4 ? ~0u : (1u << (8 * size)) - 1u;
		if (direct_)
			return word_read(address, size) & mask;
		write(ecat_csr_cmd, csr_busy | csr_read | (size << 16) | address);
		if (!core_command_done())
			return 0;
		return read(ecat_csr_data) & mask;
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
		if (pdi_change_)
			follow_pdi();
		if (direct_)
		{
			word_write(address, value, size);
			return;
		}
		write(ecat_csr_data, value);
		write(ecat_csr_cmd, csr_busy | (size << 16) | address);
		(void)core_command_done();
	}

	/**
	 * @brief Reads bytes of the EtherCAT core, registers or process RAM, in Direct Mapped mode.
	 *
	 *        One SPI transaction per 64 bytes at most. A read within one word is synchronous;
	 *        a longer one is moved by DMA while the calling task sleeps. The LAN9253 sends
	 *        padding bytes before the first byte to align it, and dummy bytes between words.
	 *
	 * @param address First byte, any alignment, 0x0000 to 0x2FFF.
	 * @param data    Where the bytes go; left as they are from where the bus failed.
	 */
	static void direct_read(uint16_t address, std::span<uint8_t> data)
	{
		while (!data.empty() && !down())
		{
			const std::size_t pad = address & 3u;
			const std::size_t length = std::min(data.size(), chunk - pad);
			if (pad + length <= 4)
			{
				const uint32_t value = word_read(address, static_cast<uint32_t>(length));
				std::memcpy(data.data(), &value, length);
			}
			else
			{
				const std::size_t words = (pad + length + 3) / 4;
				const std::size_t stream = pad + length + read_gap * (words - 1);

				// FASTREAD, the address incremented (bits 15:14 = 01), the length, the dummy
				// bytes. The DMA starts once the command is set up: data in the FIFO of the
				// OCTOSPI makes it busy, and a busy OCTOSPI ignores the writes that set up a
				// command.
				dma_bytes(true, stream);
				if (!start(0b01, fast_read_instruction, static_cast<uint32_t>(stream),
				           octospi_p::cr_r(octospi_p::cr_r::dmaen_f()), static_cast<uint8_t>(length)))
					return;
				octospi.ar = octospi_p::ar_r(increment | address);
				dma().cr = gpdma_p::c_c::cr_r::en_f() | gpdma_p::c_c::cr_r::tcie_f();
				if (!moved(stream))
					return;
				finish();

				// Word w of the stream starts at w * (4 + read_gap); the padding comes first.
				std::size_t done = std::min(4 - pad, length);
				std::memcpy(data.data(), &stream_[pad], done);
				for (std::size_t at = 4 + read_gap; done < length; at += 4 + read_gap)
				{
					if (length - done >= 4)
					{
						std::memcpy(&data[done], &stream_[at], 4);
						done += 4;
					}
					else
					{
						std::memcpy(&data[done], &stream_[at], length - done);
						done = length;
					}
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
	 * @param data    The bytes; none written from where the bus failed.
	 */
	static void direct_write(uint16_t address, std::span<const uint8_t> data)
	{
		while (!data.empty() && !down())
		{
			const std::size_t pad = address & 3u;
			const std::size_t length = std::min(data.size(), chunk - pad);
			if (pad + length <= 4)
			{
				uint32_t value = 0;
				std::memcpy(&value, data.data(), length);
				word_write(address, value, static_cast<uint32_t>(length));
			}
			else
			{
				// The words, each after the dummy bytes that follow the one before; what the
				// dummy bytes hold does not matter.
				std::size_t done = std::min(4 - pad, length);
				std::memcpy(stream_.data(), data.data(), done);
				std::size_t stream = done;
				while (done < length)
				{
					stream += write_gap;
					const std::size_t bytes = std::min<std::size_t>(4, length - done);
					if (bytes == 4)
						std::memcpy(&stream_[stream], &data[done], 4);
					else
						std::memcpy(&stream_[stream], &data[done], bytes);
					stream += bytes;
					done += bytes;
				}

				if (pad != 0 || (pad + length) % 4 != 0)
					settle();
				dma_bytes(false, stream);
				if (!start(0b00, write_instruction, static_cast<uint32_t>(stream),
				           octospi_p::cr_r(octospi_p::cr_r::dmaen_f() | octospi_p::cr_r::tcie_f())))
					return;
				octospi.ar = octospi_p::ar_r(dword_buffering | address); // starts, waits for data
				dma().cr = gpdma_p::c_c::cr_r::en_f();
				if (!moved(stream))
					return;
				finish();
			}
			address = static_cast<uint16_t>(address + length);
			data = data.subspan(length);
		}
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

	// SCS# high between two commands, CSHT + 1 cycles: 50 ns at least, and after a write of
	// the core in Direct Mapped mode, until the LAN9253 has written it (490 ns at most).
	static constexpr uint8_t cs_high_compatibility = 7; ///< 8 cycles, 128 ns at 62.5 MHz
	static constexpr uint8_t cs_high_direct = 2;        ///< 3 cycles, 72 ns at 41.7 MHz
	static constexpr uint8_t write_guard = 20;          ///< 21 cycles, 504 ns at 41.7 MHz

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

	static constexpr uint32_t cycles_per_us = 250;          ///< SYSCLK, see clock.hpp
	static constexpr uint32_t cycles_per_ms = 1000 * cycles_per_us;

	/// Longest wait for the LAN9253 to run a command of its core, compatibility mode. Measured on
	/// the board (tests/esc_probe): the command is done at the first poll, a register read of
	/// 1.4 us in quad mode, 7 us in single mode; 100 us is 14 polls at the least.
	static constexpr uint32_t core_command_cycles = 100 * cycles_per_us;

	// Values of the IMODE, ADMODE and DMODE fields.
	static constexpr uint8_t lines_single = 1;
	static constexpr uint8_t lines_quad   = 3;

	static inline bool quad_ = false;       ///< Bus mode the LAN9253 is in
	static inline bool direct_ = false;     ///< PDI mode the LAN9253 is in
	static inline bool pdi_change_ = false; ///< The PDI may change, see expect_pdi_change()
	static inline uint8_t cs_high_ = cs_high_compatibility; ///< CSHT field now in DCR1
	static inline bool wrote_ = false;      ///< The last transaction was a write
	static inline failure failure_ = failure::none;

	/// A transaction of direct_read() or direct_write(): data, padding and dummy bytes.
	static inline std::array<uint8_t, chunk + read_gap * (chunk / 4)> stream_{};
	static inline opsy::binary_semaphore done_{0};

	using dma_channel = std::remove_reference_t<decltype(gpdma.c[0])>;
	static dma_channel& dma() { return gpdma.c[7]; }

	static uint8_t prescaler()
	{
		return !quad_ ? prescaler_single : direct_ ? prescaler_direct : prescaler_quad;
	}

	static bool down() { return failure_ != failure::none; }

	/// Longest a transaction with @p bytes data, padding and dummy bytes may take, in CPU
	/// cycles: twice its time on the bus at the current clock and lines (instruction, address,
	/// length byte, the bytes, the most dummy cycles), plus 1 us for the accesses of the CPU
	/// around it.
	static uint32_t limit(std::size_t bytes)
	{
		const uint32_t lines = quad_ ? 4 : 1;
		const uint32_t clocks = (32 + 8 * static_cast<uint32_t>(bytes)) / lines + 2 * direct_initial;
		return 2 * clocks * (prescaler() + 1u) + cycles_per_us;
	}

	/// Polls until @p done, at most @p cycles CPU cycles. Checked once more past the deadline: a
	/// task preempted beyond it does not take a finished transaction for a stuck one.
	template<typename Done>
	static bool wait(Done done, uint32_t cycles)
	{
		const uint32_t begin = opsy::cortex_m::cycle_count();
		while (!done())
			if (opsy::cortex_m::cycle_count() - begin > cycles)
				return done();
		return true;
	}

	/// Waits for the end of the transaction under way, @p bytes long; @c false, the bus failed,
	/// past limit().
	static bool transferred(std::size_t bytes)
	{
		if (wait([] { return octospi.sr.load().tcf(); }, limit(bytes)))
			return true;
		fail(failure::transfer);
		return false;
	}

	/// Sleeps until the end of a transfer moved by DMA, @p bytes long; @c false, the bus failed,
	/// past limit() in whole ticks of the RTOS clock, plus one for the tick under way.
	static bool moved(std::size_t bytes)
	{
		if (done_.try_acquire_for(opsy::duration(limit(bytes) / cycles_per_ms + 2)))
			return true;
		fail(failure::dma);
		return false;
	}

	/// Polls the command register until the LAN9253 has run the command, compatibility mode;
	/// @c false, the bus failed.
	static bool core_command_done()
	{
		if (wait([] { return (read(ecat_csr_cmd) & csr_busy) == 0; }, core_command_cycles))
			return !down();
		fail(failure::core_command);
		return false;
	}

	/// A wait ran out: the transfer is stopped, the board goes to its safe state, the bus stays
	/// down. The first failure is the one kept.
	static void fail(failure why)
	{
		if (!down())
			failure_ = why;
		if (dma().cr.load().en())
		{
			dma().cr = dma().cr.load() | gpdma_p::c_c::cr_r::susp_f();
			(void)wait([] { return dma().sr.load().suspf(); }, cycles_per_us);
			dma().cr = gpdma_p::c_c::cr_r::reset_f();
		}
		octospi.cr = octospi.cr.load() | octospi_p::cr_r::abort_f();
		Safety::fault();
	}

	/// Checks the PDI mode after the EEPROM emulation has answered, see expect_pdi_change().
	static void follow_pdi()
	{
		if (read(byte_test) == byte_test_value)
		{
			if ((read(hw_cfg) & hw_cfg_ready) != 0)
				pdi_change_ = false; // loaded: the PDI of the SII is the compatibility mode
			return;
		}
		if (read(byte_test | direct_registers) != byte_test_value)
			return; // switching: the next access checks again
		set_configuration();
		direct_ = true;
		pdi_change_ = false;
		idle();
		octospi.dcr2 = octospi_p::dcr2_r::prescaler_f(prescaler());
	}

	/// Before a write that does not cover whole words only, in Direct Mapped mode. Measured on
	/// the board, and not in the datasheet: when the transaction before was a write, the
	/// LAN9253 drops such a write, whatever the time in between; a read in between clears it.
	static void settle()
	{
		if (wrote_)
			(void)read(byte_test);
	}

	/// Reads @p size bytes at @p address within one word, Direct Mapped mode.
	static uint32_t word_read(uint16_t address, uint32_t size)
	{
		const uint32_t pad = address & 3u;
		if (!start(0b01, fast_read_instruction, pad + size, octospi_p::cr_r(0u), static_cast<uint8_t>(size)))
			return 0;
		octospi.ar = octospi_p::ar_r(increment | address); // starts the transfer
		if (!transferred(pad + size))
			return 0;
		const uint32_t value = octospi.dr.load().value();
		finish();
		return value >> (8 * pad);
	}

	/// Writes the low @p size bytes of @p value at @p address within one word, Direct Mapped
	/// mode, DWORD buffered: the LAN9253 writes them when SCS# rises.
	static void word_write(uint16_t address, uint32_t value, uint32_t size)
	{
		if (size < 4)
			settle();
		if (!start(0b00, write_instruction, size))
			return;
		octospi.ar = octospi_p::ar_r(dword_buffering | address); // starts, waits for data
		auto* const fifo = reinterpret_cast<volatile uint8_t*>(&octospi.dr);
		for (uint32_t i = 0; i < size; ++i)
			*fifo = static_cast<uint8_t>(value >> (8 * i));
		if (transferred(size))
			finish();
	}

	/// Sends SETCFG with the dummy bytes of Direct Mapped mode. In quad mode.
	static void set_configuration()
	{
		if (!idle())
			return;
		octospi.cr  = octospi_p::cr_r::en_f(); // indirect write
		octospi.dlr = octospi_p::dlr_r(configuration.size() - 1);
		octospi.ccr = octospi_p::ccr_r::imode_f(lines_quad) | octospi_p::ccr_r::dmode_f(lines_quad);
		octospi.tcr = octospi_p::tcr_r(0u);
		octospi.ir  = octospi_p::ir_r(set_configuration_instruction);
		auto* const fifo = reinterpret_cast<volatile uint8_t*>(&octospi.dr);
		for (const uint8_t byte : configuration)
		{
			// The FIFO holds 32 bytes, sent in 0.6 us.
			if (!wait([] { return octospi.sr.load().ftf(); }, limit(configuration.size())))
			{
				fail(failure::transfer);
				return;
			}
			*fifo = byte;
		}
		if (transferred(configuration.size()))
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

	/// Waits until the OCTOSPI is idle: the previous transaction over, SCS# high for CSHT.
	/// Meanwhile it ignores the writes that set up a command, which would never start.
	/// @c false, the bus failed or fails, when it stays busy past limit().
	static bool idle()
	{
		if (down())
			return false;
		if (wait([] { return !octospi.sr.load().busy(); }, limit(0)))
			return true;
		fail(failure::transfer);
		return false;
	}

	/// Waits until the OCTOSPI is idle, then sets how long SCS# stays high after the next
	/// transaction: a write of the core in Direct Mapped mode needs @c write_guard. @c false,
	/// the bus failed.
	static bool prepare(bool core_write)
	{
		if (!idle())
			return false;
		const uint8_t wanted = !direct_ ? cs_high_compatibility : core_write ? write_guard : cs_high_direct;
		if (wanted != cs_high_)
		{
			octospi.dcr1 = octospi_p::dcr1_r::devsize_f(15) | octospi_p::dcr1_r::csht_f(wanted);
			cs_high_ = wanted;
		}
		return true;
	}

	/// Sends an instruction alone, on the given lines.
	static void command(uint8_t lines, uint32_t instruction)
	{
		if (!idle())
			return;
		octospi.cr  = octospi_p::cr_r::en_f(); // indirect write
		octospi.ccr = octospi_p::ccr_r::imode_f(lines);
		octospi.tcr = octospi_p::tcr_r(0u);
		octospi.ir  = octospi_p::ir_r(instruction); // starts the transfer

		if (transferred(0))
			finish();
	}

	/// Sets up a transfer of @p bytes with a 16-bit address, once the OCTOSPI is idle; the
	/// caller then gives the address. @p extra adds to the control register (DMA request,
	/// interrupt). A FASTREAD tells the LAN9253 @p length data bytes (127 at most), @p bytes
	/// when 0: in Direct Mapped mode the transfer also carries padding and dummy bytes.
	/// @c false, the bus failed: nothing set up.
	static bool start(uint8_t functional_mode, uint32_t instruction, uint32_t bytes = 4,
	                  octospi_p::cr_r extra = octospi_p::cr_r(0u), uint8_t length = 0)
	{
		const bool fast_read = instruction == fast_read_instruction;
		wrote_ = instruction == write_instruction;
		if (!prepare(wrote_))
			return false;
		const uint8_t lines = quad_ ? lines_quad : lines_single;
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
		return true;
	}

	/// Ends a transfer: its last bit is on the bus; SCS# rises after it, see idle().
	static void finish()
	{
		octospi.fcr = octospi_p::fcr_r::ctcf_f();
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
