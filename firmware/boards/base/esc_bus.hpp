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
 *          | quad   | 4     | 62.5 MHz | FASTREAD (0x0B), length, 3 dummy   |
 *
 *          Single mode only needs SCK, SCS#, SI and SO: it tells a fault of the bus from a
 *          fault of SIO2 or SIO3. Quad mode (SQI) is the one to work in.
 *
 *          Registers: blocking transfers, 32 bits at a time. Blocks of the process RAM: through
 *          the FIFOs of the LAN9253, in bursts moved by DMA (GPDMA1 channel 7) while the calling
 *          task sleeps. Within a burst the LAN9253 needs 610 ns per word read (DS00003421B,
 *          section 9.2.7), and paces nothing itself: bursts run at 11.9 MHz, 672 ns per word.
 *          Not reentrant: the registers of the EtherCAT core go through one shared command
 *          register, so all the calls must come from a single task.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <algorithm>
#include <array>
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

		// The LAN9253 also keeps a block transfer through a reset of the MCU alone: both are
		// cancelled, with their FIFOs.
		write(pram_read_cmd, pram_abort);
		write(pram_write_cmd, pram_abort);

		// Bursts to and from the FIFOs of the process RAM (ram_read, ram_write): GPDMA1 channel 7.
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
		octospi.dcr2 = octospi_p::dcr2_r::prescaler_f(quad ? prescaler_quad : prescaler_single);
		quad_ = quad;
	}

	/**
	 * @brief Reads one 32-bit register of the LAN9253.
	 *
	 *        8-bit instruction, 16-bit address, in quad mode the length and dummy bytes, then
	 *        4 data bytes, least significant first.
	 *
	 * @param address Register address.
	 * @return        Register value.
	 */
	static uint32_t read(uint16_t address)
	{
		start(0b01, quad_ ? fast_read_instruction : read_instruction);
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
		start(0b00, write_instruction);
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

	/**
	 * @brief Reads a block of the process RAM of the EtherCAT core (0x1000 to 0x1FFF).
	 *
	 *        Through the read FIFO of the LAN9253 (16 words): the block is requested, then read
	 *        in bursts of the words the FIFO holds, each burst one SPI transaction at the
	 *        constant FIFO address, moved by DMA. The calling task sleeps during each burst: for
	 *        tasks only, after init() and in quad mode.
	 *
	 *        Between bursts, the count of words in the FIFO is read: the core fills it faster
	 *        than one such read, so a second one is the most it takes.
	 *
	 * @param address First byte, any alignment.
	 * @param data    Where the bytes go; the block must stay within 0x1000-0x1FFF.
	 */
	static void ram_read(uint16_t address, std::span<uint8_t> data)
	{
		if (data.empty())
			return;
		write(pram_read_addr_len, (static_cast<uint32_t>(data.size()) << 16) | address);
		write(pram_read_cmd, pram_busy);

		// The FIFO delivers whole words from the aligned address below: the first bytes of the
		// first word are not part of the block.
		std::size_t skip = address & 3u;
		std::size_t done = 0;
		while (done < data.size())
		{
			const uint32_t available = (read(pram_read_cmd) >> 8) & pram_count_mask;
			if (available == 0)
				continue;
			const std::size_t words = std::min<std::size_t>(available, (skip + data.size() - done + 3) / 4);
			burst(dma_read, words);
			const auto bytes = std::as_bytes(std::span(fifo_.data(), words));
			for (std::size_t i = skip; i < bytes.size() && done < data.size(); ++i)
				data[done++] = static_cast<uint8_t>(bytes[i]);
			skip = 0;
		}
	}

	/**
	 * @brief Writes a block of the process RAM of the EtherCAT core (0x1000 to 0x1FFF).
	 *
	 *        Through the write FIFO of the LAN9253, in bursts of the words it has room for, each
	 *        one SPI transaction at the constant FIFO address, moved by DMA while the calling task
	 *        sleeps;
	 *        returns once the LAN9253 has written the whole block to the core, a few hundred ns
	 *        after the last burst. For tasks only, after init() and in quad mode.
	 *
	 * @param address First byte, any alignment.
	 * @param data    The bytes; the block must stay within 0x1000-0x1FFF.
	 */
	static void ram_write(uint16_t address, std::span<const uint8_t> data)
	{
		if (data.empty())
			return;
		write(pram_write_addr_len, (static_cast<uint32_t>(data.size()) << 16) | address);
		write(pram_write_cmd, pram_busy);

		// The FIFO takes whole words from the aligned address below: the bytes before the block
		// in the first word are ignored by the LAN9253.
		std::size_t skip = address & 3u;
		std::size_t done = 0;
		while (done < data.size())
		{
			const uint32_t room = (read(pram_write_cmd) >> 8) & pram_count_mask;
			if (room == 0)
				continue;
			const std::size_t words = std::min<std::size_t>(room, (skip + data.size() - done + 3) / 4);
			auto bytes = std::as_writable_bytes(std::span(fifo_.data(), words));
			for (std::size_t i = 0; i < bytes.size(); ++i)
				bytes[i] = std::byte{i >= skip && done < data.size() ? data[done++] : uint8_t{0}};
			skip = 0;
			burst(dma_write, words);
		}
		while (read(pram_write_cmd) & pram_busy) {}
	}

private:

	// Data FIFOs. Address bits 15:14 = 00: the address stays the same through a burst, one
	// word after the other (section 9.2.5 for reads, 9.2.6 for writes).
	static constexpr uint16_t pram_read_fifo      = 0x0000;
	static constexpr uint16_t pram_write_fifo     = 0x0020;
	static constexpr uint16_t pram_read_addr_len  = 0x0308; ///< Address (low half), length (high half)
	static constexpr uint16_t pram_read_cmd       = 0x030C; ///< Busy (bit 31), words available (12:8)
	static constexpr uint16_t pram_write_addr_len = 0x0310;
	static constexpr uint16_t pram_write_cmd      = 0x0314; ///< Busy (bit 31), room in words (12:8)
	static constexpr uint32_t pram_busy       = 1u << 31;   ///< Written 1 to start the block
	static constexpr uint32_t pram_abort      = 1u << 30;   ///< Written 1 to cancel it, with the FIFO
	static constexpr uint32_t pram_count_mask = 0x1Fu;

	static constexpr std::uint8_t ospi1_request = 57;        ///< GPDMA request, RM0481 table 142
	static constexpr bool dma_read = true;
	static constexpr bool dma_write = false;

	using dma_channel = std::remove_reference_t<decltype(gpdma.c[0])>;
	static dma_channel& dma() { return gpdma.c[7]; }

	/// Moves @p words between a FIFO of the LAN9253 and fifo_, in one SPI transaction by DMA,
	/// and sleeps until the transaction is over: the end of the DMA for a read, the end of the
	/// transfer on the bus for a write.
	static void burst(bool reading, std::size_t words)
	{
		const auto bytes = static_cast<uint32_t>(words * 4);
		dma().fcr = gpdma_p::c_c::fcr_r::tcf_f() | gpdma_p::c_c::fcr_r::dtef_f()
		              | gpdma_p::c_c::fcr_r::ulef_f() | gpdma_p::c_c::fcr_r::usef_f()
		              | gpdma_p::c_c::fcr_r::tof_f();
		const auto buffer = reinterpret_cast<std::uint32_t>(fifo_.data());
		const auto data_register = reinterpret_cast<std::uint32_t>(&octospi.dr);
		if (reading)
		{
			dma().tr1 = gpdma_p::c_c::tr1_r::sdw_log2_f(2) | gpdma_p::c_c::tr1_r::ddw_log2_f(2)
			              | gpdma_p::c_c::tr1_r::dinc_f();
			dma().tr2 = gpdma_p::c_c::tr2_r::reqsel_f(ospi1_request);
			dma().sar = gpdma_p::c_c::sar_r::sa_f(data_register);
			dma().dar = gpdma_p::c_c::dar_r::da_f(buffer);
		}
		else
		{
			dma().tr1 = gpdma_p::c_c::tr1_r::sdw_log2_f(2) | gpdma_p::c_c::tr1_r::ddw_log2_f(2)
			              | gpdma_p::c_c::tr1_r::sinc_f();
			dma().tr2 = gpdma_p::c_c::tr2_r::reqsel_f(ospi1_request) | gpdma_p::c_c::tr2_r::dreq_f();
			dma().sar = gpdma_p::c_c::sar_r::sa_f(buffer);
			dma().dar = gpdma_p::c_c::dar_r::da_f(data_register);
		}
		dma().br1 = gpdma_p::c_c::br1_r::bndt_f(static_cast<std::uint16_t>(bytes));

		// The OCTOSPI is idle: finish() returned. FTHRES = 3: a DMA request per word. The DMA
		// starts once the command is set up: data in the FIFO of the OCTOSPI makes it busy,
		// and a busy OCTOSPI ignores the writes that set up a command.
		octospi.dcr2 = octospi_p::dcr2_r::prescaler_f(prescaler_burst);
		const auto request = octospi_p::cr_r::dmaen_f() | octospi_p::cr_r::fthres_f(3);
		if (reading)
		{
			start(0b01, fast_read_instruction, bytes, request);
			octospi.ar = octospi_p::ar_r(pram_read_fifo); // starts the transfer
		}
		else
		{
			start(0b00, write_instruction, bytes, request | octospi_p::cr_r::tcie_f());
			octospi.ar = octospi_p::ar_r(pram_write_fifo); // starts the transfer, which waits for data
		}
		dma().cr = reading ? gpdma_p::c_c::cr_r::en_f() | gpdma_p::c_c::cr_r::tcie_f()
		                   : gpdma_p::c_c::cr_r::en_f();
		done_.acquire();
		finish();
		octospi.dcr2 = octospi_p::dcr2_r::prescaler_f(prescaler_quad);
	}

	/// End of a read burst: the DMA has moved the last word.
	static void dma_isr()
	{
		dma().fcr = gpdma_p::c_c::fcr_r::tcf_f();
		done_.release();
	}

	/// End of a write burst: the last bit is on the bus.
	static void octospi_isr()
	{
		octospi.cr <<= octospi_p::cr_r::tcie_f(false);
		done_.release();
	}

	alignas(4) static inline std::array<uint32_t, 16> fifo_{};
	static inline opsy::binary_semaphore done_{0};

public:

	/** @brief The handlers of the module: end of a burst from or to a FIFO of the LAN9253. */
	static constexpr auto isrs = []<typename Table>(const Table& table) -> Table
	{
		return table.template with<GPDMA1_CH7_IRQn, dma_isr>()
		            .template with<OCTOSPI1_IRQn, octospi_isr>();
	};

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

	/// A FASTREAD in quad mode sends, after the address, the length of the transfer in one byte
	/// (up to 127), then the dummy bytes the LAN9253 expects by default: 3, 6 clock cycles. The
	/// length tells it where to stop: it never reads ahead, which would lose a word of a FIFO.
	static constexpr uint8_t fast_read_dummy_cycles = 6;

	static constexpr uint8_t prescaler_single = 24; ///< 250 MHz / 25 = 10 MHz
	static constexpr uint8_t prescaler_quad   = 3;  ///< 250 MHz / 4 = 62.5 MHz (80 MHz at most)
	static constexpr uint8_t prescaler_burst  = 20; ///< 250 MHz / 21 = 11.9 MHz: 672 ns per word

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

	/// Sets up a transfer of @p bytes (127 at most) with a 16-bit address; the caller then gives
	/// the address. @p extra adds to the control register (DMA request, FIFO threshold).
	static void start(uint8_t functional_mode, uint32_t instruction, uint32_t bytes = 4,
	                  octospi_p::cr_r extra = octospi_p::cr_r(0u))
	{
		const uint8_t lines = quad_ ? lines_quad : lines_single;
		const bool fast_read = instruction == fast_read_instruction;
		octospi.cr  = octospi_p::cr_r::en_f() | octospi_p::cr_r::fmode_f(functional_mode) | extra;
		octospi.dlr = octospi_p::dlr_r(bytes - 1);
		octospi.abr = octospi_p::abr_r(bytes); // the length byte of a FASTREAD
		octospi.ccr = octospi_p::ccr_r::imode_f(lines)
		                    | octospi_p::ccr_r::admode_f(lines)
		                    | octospi_p::ccr_r::adsize_f(1) // 16 bits
		                    | octospi_p::ccr_r::abmode_f(fast_read ? lines : 0) // 8 bits
		                    | octospi_p::ccr_r::dmode_f(lines);
		octospi.tcr = octospi_p::tcr_r::dcyc_f(fast_read ? fast_read_dummy_cycles : 0);
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
