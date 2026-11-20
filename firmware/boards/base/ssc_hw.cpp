// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// Hardware access layer of the EtherCAT Slave Stack Code on the Bornier base board, see
// ssc_hw.h. Every access to the EtherCAT core goes through esc_bus in quad mode, split into
// aligned pieces of 1, 2 or 4 bytes, the sizes its CSR command register takes.

#include <ssc_hw.h>

#include <opsy.hpp>
#include <esc_bus.hpp>

#include <cstddef>
#include <cstdint>

using namespace STM32H523;

namespace
{

constexpr uint16_t al_event_request = 0x0220;
constexpr uint16_t al_event_mask    = 0x0204;

opsy::time_point timer_origin = opsy::startup;

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
	esc_bus::init();
	esc_bus::set_mode(esc_bus::mode::quad);
	if (esc_bus::read(esc_bus::byte_test) != 0x87654321)
		return 1;

	// No AL event reaches the IRQ pin until the stack asks for one.
	uint32_t mask = 0;
	write_core(reinterpret_cast<const uint8_t*>(&mask), al_event_mask, sizeof(mask));
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

// The LAN9253 reads 8 bytes per EEPROM command (0x0502 bit 6): the stack then serves the
// configuration reload itself and never calls this. Reaching it is an error.
UINT16 HW_EepromReload(void)
{
	return 1;
}

void HW_EscRead(MEM_ADDR* pData, UINT16 Address, UINT16 Len)
{
	read_core(reinterpret_cast<uint8_t*>(pData), Address, Len);
}

void HW_EscReadIsr(MEM_ADDR* pData, UINT16 Address, UINT16 Len)
{
	read_core(reinterpret_cast<uint8_t*>(pData), Address, Len);
}

void HW_EscWrite(MEM_ADDR* pData, UINT16 Address, UINT16 Len)
{
	write_core(reinterpret_cast<const uint8_t*>(pData), Address, Len);
}

void HW_EscWriteIsr(MEM_ADDR* pData, UINT16 Address, UINT16 Len)
{
	write_core(reinterpret_cast<const uint8_t*>(pData), Address, Len);
}

} // extern "C"
