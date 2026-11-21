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
// Object dictionary (from the dictionary file given to the SSC Tool), n the axis, 0 to 3:
//
// | Index           | Name                            | Type  | PDO    |
// |-----------------|---------------------------------|-------|--------|
// | 0x2000:01       | Emergency stop chain closed     | USINT | 0x1A00 |
// | 0x2000:02       | Probe active                    | USINT | 0x1A00 |
// | 0x2000:03       | Supply voltage (mV)             | UINT  | 0x1A00 |
// | 0x2000:04       | Outputs enabled                 | USINT | 0x1A00 |
// | 0x2000:05       | Reserved                        | USINT | 0x1A00 |
// | 0x6040 + 0x800n | Controlword                     | UINT  | 0x1600 |
// | 0x6041 + 0x800n | Statusword                      | UINT  | 0x1A00 |
// | 0x6060 + 0x800n | Modes of operation (8: CSP)     | SINT  |        |
// | 0x6061 + 0x800n | Modes of operation display      | SINT  |        |
// | 0x6064 + 0x800n | Position actual value (steps)   | DINT  | 0x1A00 |
// | 0x607A + 0x800n | Target position (steps)         | DINT  | 0x1600 |
//
// RxPDO 0x1600 (24 bytes): controlword, target position, for each axis in turn.
// TxPDO 0x1A00 (30 bytes): 0x2000:01 to :05, then statusword, position actual value, for each
// axis in turn. The axes themselves are in axes.hpp. All runs in the stack's task.
//
// The step generator runs on the SYNC0 period the master sets up (register 0x09A0), from
// SAFEOP: without Distributed Clocks, or on a period it cannot run on, the slave refuses SAFEOP
// (AL status codes 0x0028, synchronization mode not supported, and 0x0036, SYNC0 cycle time).
// The period is 2 ms at most, a whole number of microseconds (axes.hpp).

#include <axes.hpp>
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

constexpr std::size_t axis_output_bytes = 6; ///< Controlword, target position
constexpr std::size_t board_input_bytes = 6; ///< 0x2000:01 to :05
constexpr std::size_t axis_input_bytes = 6;  ///< Statusword, position actual value

bool outputs_allowed = false;

// The dictionary objects of each axis, for the SDO accesses.
const std::array<UINT16*, axes::count> controlword_objects{
	&Axis0Controlword0x6040, &Axis1Controlword0x6840, &Axis2Controlword0x7040, &Axis3Controlword0x7840};
const std::array<INT32*, axes::count> target_objects{
	&Axis0TargetPosition0x607A, &Axis1TargetPosition0x687A, &Axis2TargetPosition0x707A, &Axis3TargetPosition0x787A};
const std::array<UINT16*, axes::count> statusword_objects{
	&Axis0Statusword0x6041, &Axis1Statusword0x6841, &Axis2Statusword0x7041, &Axis3Statusword0x7841};
const std::array<INT32*, axes::count> position_objects{
	&Axis0PositionActualValue0x6064, &Axis1PositionActualValue0x6864,
	&Axis2PositionActualValue0x7064, &Axis3PositionActualValue0x7864};

template<typename T>
T get(const uint8_t* bytes)
{
	T value;
	std::memcpy(&value, bytes, sizeof(value));
	return value;
}

template<typename T>
void put(uint8_t* bytes, T value)
{
	std::memcpy(bytes, &value, sizeof(value));
}

} // namespace

extern "C" {

void APPL_OutputMapping(UINT16* pData)
{
	const auto* bytes = reinterpret_cast<const uint8_t*>(pData);
	std::array<uint16_t, axes::count> controlwords{};
	std::array<int32_t, axes::count> targets{};
	for (std::size_t n = 0; n < axes::count; ++n)
	{
		const uint8_t* axis = bytes + n * axis_output_bytes;
		controlwords[n] = get<uint16_t>(axis);
		targets[n] = get<int32_t>(axis + 2);
		*controlword_objects[n] = controlwords[n];
		*target_objects[n] = targets[n];
	}
	axes::outputs(controlwords, targets);
}

void APPL_InputMapping(UINT16* pData)
{
	auto* bytes = reinterpret_cast<uint8_t*>(pData);
	const auto supply = supplies::read();
	BoardInputs0x2000.EmergencyStopChainClosed = stop_probe::chain_closed() ? 1 : 0;
	BoardInputs0x2000.ProbeActive = stop_probe::probe_active() ? 1 : 0;
	BoardInputs0x2000.SupplyVoltage = supply ? static_cast<uint16_t>(supply->vin_mv) : 0;
	BoardInputs0x2000.OutputsEnabled = outputs_allowed ? 1 : 0;
	bytes[0] = BoardInputs0x2000.EmergencyStopChainClosed;
	bytes[1] = BoardInputs0x2000.ProbeActive;
	put<uint16_t>(bytes + 2, BoardInputs0x2000.SupplyVoltage);
	bytes[4] = BoardInputs0x2000.OutputsEnabled;
	bytes[5] = 0;
	for (std::size_t n = 0; n < axes::count; ++n)
	{
		uint8_t* axis = bytes + board_input_bytes + n * axis_input_bytes;
		*statusword_objects[n] = axes::statusword(n);
		*position_objects[n] = axes::position(n);
		put<uint16_t>(axis, *statusword_objects[n]);
		put<int32_t>(axis + 2, *position_objects[n]);
	}
}

UINT16 APPL_StartInputHandler(UINT16* pIntMask)
{
	(void)pIntMask;
	// The steps need SYNC0, at the period the master set up for the Distributed Clocks.
	UINT32 cycle_ns = 0;
	HW_EscRead(reinterpret_cast<MEM_ADDR*>(&cycle_ns), ESC_DC_SYNC0_CYCLETIME_OFFSET, sizeof(cycle_ns));
	if (cycle_ns == 0)
		return ALSTATUSCODE_SYNCHRONNOTSUPPORTED;
	if (!axes::start_generator(cycle_ns))
		return ALSTATUSCODE_DCSYNC0CYCLETIME;
	return ALSTATUSCODE_NOERROR;
}

UINT16 APPL_StopInputHandler(void)
{
	axes::stop_generator();
	return ALSTATUSCODE_NOERROR;
}

void APPL_Application(void)
{
	axes::run(outputs_allowed);
}

UINT16 APPL_StartOutputHandler(void)
{
	outputs_allowed = true;
	return ALSTATUSCODE_NOERROR;
}

UINT16 APPL_StopOutputHandler(void)
{
	outputs_allowed = false;
	axes::disable_all();
	return ALSTATUSCODE_NOERROR;
}

} // extern "C"
