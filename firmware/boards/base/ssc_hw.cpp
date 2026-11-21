// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// Hardware access layer of the EtherCAT Slave Stack Code on the Bornier base board, see
// ssc_hw.h. Accesses go through esc_bus in quad mode. In EtherCAT Direct Mapped mode, the one the
// SII sets, each access is one transaction, any address and length. Before, while the LAN9253 is
// in compatibility mode to load its configuration, through its CSR command register, in aligned
// pieces of 1, 2 or 4 bytes.

#include <ssc_hw.h>

#include <opsy.hpp>
#include <esc_bus.hpp>

#include <cstddef>
#include <cstdint>
#include <span>

using namespace STM32H523;

namespace
{

constexpr uint16_t al_event_request = 0x0220;
constexpr uint16_t al_event_mask    = 0x0204;
constexpr uint16_t eeprom_control   = 0x0502; ///< Written by the EEPROM emulation to answer a command

// Registers of the LAN9253 itself, outside the EtherCAT core.
constexpr uint16_t irq_cfg = 0x0054;         ///< IRQ pin; reset: open drain, active low, disabled
constexpr uint32_t irq_cfg_irq_en = 1u << 8;
constexpr uint16_t int_en = 0x005C;          ///< Interrupt enable
constexpr uint32_t int_en_ecat = 1u << 0;    ///< ECAT_INT_EN: the AL event request of the EtherCAT core

opsy::time_point timer_origin = opsy::startup;

/// The AL event mask as the stack last wrote it: the events that pull ESC_IRQ low.
uint16_t event_mask = 0;

/** @brief Size of the next piece of an access at @p address with @p remaining bytes left. */
uint32_t piece(uint32_t address, uint32_t remaining)
{
	if ((address & 1u) != 0 || remaining == 1)
		return 1;
	if ((address & 2u) != 0 || remaining < 4)
		return 2;
	return 4;
}

void read_core(uint8_t* data, uint16_t address, uint16_t length)
{
	uint32_t at = address;
	uint32_t left = length;
	while (left > 0)
	{
		const uint32_t size = piece(at, left);
		const uint32_t value = esc_bus::core_read(static_cast<uint16_t>(at), size);
		for (uint32_t i = 0; i < size; ++i)
			*data++ = static_cast<uint8_t>(value >> (8 * i));
		at += size;
		left -= size;
	}
}

void write_core(const uint8_t* data, uint16_t address, uint16_t length)
{
	uint32_t at = address;
	uint32_t left = length;
	while (left > 0)
	{
		const uint32_t size = piece(at, left);
		uint32_t value = 0;
		for (uint32_t i = 0; i < size; ++i)
			value |= static_cast<uint32_t>(*data++) << (8 * i);
		esc_bus::core_write(static_cast<uint16_t>(at), value, size);
		at += size;
		left -= size;
	}
}

} // namespace

extern "C" {

UINT32 ssc_hw_timer(void)
{
	return static_cast<UINT32>((opsy::scheduler::now() - timer_origin).count());
}

void ssc_hw_clear_timer(void)
{
	timer_origin = opsy::scheduler::now();
}

UINT8 HW_Init(void)
{
	// The LAN9253 reloads its configuration from the SII the stack emulates: its PDI is then
	// the one of the SII (see esc_bus::expect_pdi_change()).
	if (!esc_bus::reset())
		return 1;
	esc_bus::set_mode(esc_bus::mode::quad);
	if (esc_bus::read(esc_bus::byte_test) != 0x87654321)
		return 1;

	// No AL event reaches the IRQ pin until the stack asks for one (AL event mask); then
	// ESC_IRQ goes low while one is pending (see esc_irq).
	uint32_t mask = 0;
	write_core(reinterpret_cast<const uint8_t*>(&mask), al_event_mask, sizeof(mask));
	event_mask = 0;
	esc_bus::write(int_en, int_en_ecat);
	esc_bus::write(irq_cfg, esc_bus::read(irq_cfg) | irq_cfg_irq_en);
	return 0;
}

void HW_Release(void) {}

UINT16 HW_GetALEventRegister(void)
{
	return static_cast<UINT16>(esc_bus::core_read(al_event_request, 2));
}

UINT16 HW_GetALEventRegister_Isr(void)
{
	return HW_GetALEventRegister();
}

BOOL ssc_hw_event_pending(void)
{
	return (HW_GetALEventRegister() & event_mask) != 0 ? TRUE : FALSE;
}

// The LAN9253 reads 8 bytes per EEPROM command (0x0502 bit 6): the stack then serves the
// configuration reload itself and never calls this. Reaching it is an error.
UINT16 HW_EepromReload(void)
{
	return 1;
}

void HW_EscRead(MEM_ADDR* pData, UINT16 Address, UINT16 Len)
{
	auto* const data = reinterpret_cast<uint8_t*>(pData);
	if (esc_bus::direct())
		esc_bus::direct_read(Address, std::span(data, Len));
	else
		read_core(data, Address, Len);
}

// The stack calls the Isr variants from PDI_Isr() and Sync0_Isr(), which run in the stack's task,
// woken by ESC_IRQ (see esc_irq): an access may sleep on DMA, so never from an interrupt handler.
void HW_EscReadIsr(MEM_ADDR* pData, UINT16 Address, UINT16 Len)
{
	HW_EscRead(pData, Address, Len);
}

void HW_EscWrite(MEM_ADDR* pData, UINT16 Address, UINT16 Len)
{
	const auto* const data = reinterpret_cast<const uint8_t*>(pData);
	if (esc_bus::direct())
		esc_bus::direct_write(Address, std::span(data, Len));
	else
		write_core(data, Address, Len);

	if (Address <= eeprom_control && eeprom_control < Address + Len)
		esc_bus::expect_pdi_change();

	// The stack writes the AL event mask whole (SetALEventMask(), ResetALEventMask()).
	if (Address == al_event_mask && Len >= 2)
		event_mask = static_cast<uint16_t>(data[0] | (data[1] << 8));
}

void HW_EscWriteIsr(MEM_ADDR* pData, UINT16 Address, UINT16 Len)
{
	HW_EscWrite(pData, Address, Len);
}

} // extern "C"
