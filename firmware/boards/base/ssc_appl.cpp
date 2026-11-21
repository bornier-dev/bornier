// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// Application of the Bornier base board under the Beckhoff EtherCAT Slave Stack Code (SSC).
//
// The SSC Tool generates, at each generation, an application file from the object dictionary
// of the board: the dictionary objects, generic APPL_* functions and empty ones to fill in. It
// carries the license of the stack and stays out of this repository. The build renames, in that
// file only, the functions defined here (see firmware/CMakeLists.txt): the stack calls these.
//
// Object dictionary (from the dictionary file given to the SSC Tool):
//
// | Index           | Name                        | Type  | PDO    |
// |-----------------|-----------------------------|-------|--------|
// | 0x2000:01       | Emergency stop chain closed | USINT | 0x1A00 |
// | 0x2000:02       | Probe active                | USINT | 0x1A00 |
// | 0x2000:03       | Supply voltage (mV)         | UINT  | 0x1A00 |
// | 0x2000:04       | Outputs enabled             | USINT | 0x1A00 |
// | 0x2000:05       | Reserved                    | USINT | 0x1A00 |
// | 0x6040 + 0x800n | Controlword of axis n       | UINT  | 0x1600 |
// | 0x6041 + 0x800n | Statusword of axis n        | UINT  | 0x1A00 |
//
// Each axis runs the CiA402 state machine from its controlword and the alarm of its drive; the
// drive is enabled only in operation enabled, and only while the outputs are allowed (OP). When
// they no longer are, every drive is disabled at once and every axis falls back to switch on
// disabled. All runs in the stack's task.

#include <cia402.hpp>
#include <drive_ports.hpp>
#include <stop_probe.hpp>
#include <supplies.hpp>

extern "C" {
#include <ecat_def.h>
#include <applInterface.h>
#include <BornierBase.h>
}

#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>

using namespace STM32H523;

namespace
{

constexpr std::size_t axes_count = drive_ports::count;

/// RxPDO 0x1600, master to slave.
struct outputs
{
	uint16_t controlword[axes_count];
};

/// TxPDO 0x1A00, slave to master.
struct inputs
{
	uint8_t stop_chain_closed;
	uint8_t probe_active;
	uint16_t supply_mv;
	uint8_t outputs_enabled;
	uint8_t reserved;
	uint16_t statusword[axes_count];
};

static_assert(sizeof(outputs) == 8, "RxPDO 0x1600 is 8 bytes");
static_assert(sizeof(inputs) == 14, "TxPDO 0x1A00 is 14 bytes");

std::array<bornier::cia402::axis, axes_count> axes{};
outputs received{};
bool outputs_allowed = false;

// The dictionary objects of each axis, for the SDO accesses.
const std::array<UINT16*, axes_count> controlword_objects{
	&Axis0Controlword0x6040, &Axis1Controlword0x6840, &Axis2Controlword0x7040, &Axis3Controlword0x7840};
const std::array<UINT16*, axes_count> statusword_objects{
	&Axis0Statusword0x6041, &Axis1Statusword0x6841, &Axis2Statusword0x7041, &Axis3Statusword0x7841};

} // namespace

extern "C" {

void APPL_OutputMapping(UINT16* pData)
{
	std::memcpy(&received, pData, sizeof(received));
	for (std::size_t n = 0; n < axes_count; ++n)
		*controlword_objects[n] = received.controlword[n];
}

void APPL_InputMapping(UINT16* pData)
{
	inputs sent{};
	sent.stop_chain_closed = stop_probe::chain_closed() ? 1 : 0;
	sent.probe_active = stop_probe::probe_active() ? 1 : 0;
	const auto supply = supplies::read();
	sent.supply_mv = supply ? static_cast<uint16_t>(supply->vin_mv) : 0;
	sent.outputs_enabled = outputs_allowed ? 1 : 0;
	for (std::size_t n = 0; n < axes_count; ++n)
	{
		sent.statusword[n] = axes[n].statusword();
		*statusword_objects[n] = sent.statusword[n];
	}

	BoardInputs0x2000.EmergencyStopChainClosed = sent.stop_chain_closed;
	BoardInputs0x2000.ProbeActive = sent.probe_active;
	BoardInputs0x2000.SupplyVoltage = sent.supply_mv;
	BoardInputs0x2000.OutputsEnabled = sent.outputs_enabled;
	std::memcpy(pData, &sent, sizeof(sent));
}

void APPL_Application(void)
{
	for (std::size_t n = 0; n < axes_count; ++n)
	{
		axes[n].update(outputs_allowed ? received.controlword[n] : 0, drive_ports::alarm(n));
		drive_ports::enable(n, outputs_allowed && axes[n].enabled());
	}
}

UINT16 APPL_StartOutputHandler(void)
{
	outputs_allowed = true;
	return ALSTATUSCODE_NOERROR;
}

UINT16 APPL_StopOutputHandler(void)
{
	outputs_allowed = false;
	for (std::size_t n = 0; n < axes_count; ++n)
	{
		drive_ports::enable(n, false);
		axes[n].disable();
	}
	return ALSTATUSCODE_NOERROR;
}

} // extern "C"
