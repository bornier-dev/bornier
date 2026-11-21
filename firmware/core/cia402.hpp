// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    cia402.hpp
 * @author  Thomas Legrand
 * @brief   State machine of a CiA402 drive axis (IEC 61800-7-201, ETG.6010)
 *
 *          The master drives each axis through its controlword (0x6040) and reads its
 *          state in its statusword (0x6041):
 *
 *            not ready to switch on ─► switch on disabled ◄─────────────── fault
 *                                       │  ▲                                ▲
 *                              shutdown │  │ disable voltage, quick stop    │ drive fault
 *                                       ▼  │                                │ (any state)
 *                                 ready to switch on ◄─┐              fault reaction active
 *                                       │  ▲           │ shutdown
 *                             switch on │  │ shutdown  │
 *                                       ▼  │           │
 *                                   switched on ───────┤
 *                                       │  ▲           │
 *                      enable operation │  │ disable operation
 *                                       ▼  │           │
 *                                operation enabled ────┘
 *                                       │ quick stop
 *                                       ▼
 *                                quick stop active ─► switch on disabled
 *
 *          A fault of the drive (its alarm input) leads to fault through fault reaction
 *          active, from any state; a rising edge of the fault reset bit of the controlword
 *          leaves fault once the drive fault is gone. A step/dir axis has no ramp to run: the
 *          fault reaction and the quick stop end on the next update.
 *
 *          Board-independent: the caller reads the controlword and the drive fault, calls
 *          update() once per cycle, writes the statusword, and drives the enable of the drive
 *          from enabled().
 ******************************************************************************
 */

#pragma once

#include <cstdint>

namespace bornier::cia402
{

/** @brief States of the drive state machine. */
enum class state : uint8_t
{
	not_ready_to_switch_on,
	switch_on_disabled,
	ready_to_switch_on,
	switched_on,
	operation_enabled,
	quick_stop_active,
	fault_reaction_active,
	fault,
};

/** @brief One axis: its state, from the controlword and the drive fault. */
class axis
{
public:

	/**
	 * @brief Runs the state machine once.
	 *
	 * @param controlword The controlword the master wrote.
	 * @param drive_fault @c true while the drive reports a fault.
	 */
	constexpr void update(uint16_t controlword, bool drive_fault)
	{
		const bool reset_edge = (controlword & fault_reset) != 0 && (previous_ & fault_reset) == 0;
		previous_ = controlword;

		if (drive_fault && state_ != state::fault)
		{
			state_ = state_ == state::fault_reaction_active ? state::fault : state::fault_reaction_active;
			return;
		}

		switch (state_)
		{
		case state::not_ready_to_switch_on:
			state_ = state::switch_on_disabled;
			break;
		case state::switch_on_disabled:
			if (is(controlword, shutdown))
				state_ = state::ready_to_switch_on;
			break;
		case state::ready_to_switch_on:
			if (is(controlword, disable_voltage) || is(controlword, quick_stop))
				state_ = state::switch_on_disabled;
			else if (is(controlword, switch_on) || is(controlword, enable_operation))
				state_ = state::switched_on;
			break;
		case state::switched_on:
			if (is(controlword, disable_voltage) || is(controlword, quick_stop))
				state_ = state::switch_on_disabled;
			else if (is(controlword, shutdown))
				state_ = state::ready_to_switch_on;
			else if (is(controlword, enable_operation))
				state_ = state::operation_enabled;
			break;
		case state::operation_enabled:
			if (is(controlword, disable_voltage))
				state_ = state::switch_on_disabled;
			else if (is(controlword, quick_stop))
				state_ = state::quick_stop_active;
			else if (is(controlword, shutdown))
				state_ = state::ready_to_switch_on;
			else if (is(controlword, switch_on))
				state_ = state::switched_on; // disable operation
			break;
		case state::quick_stop_active:
			state_ = state::switch_on_disabled; // nothing to slow down
			break;
		case state::fault_reaction_active:
			state_ = state::fault;
			break;
		case state::fault:
			if (reset_edge && !drive_fault)
				state_ = state::switch_on_disabled;
			break;
		}
	}

	/** @brief The statusword of the current state. */
	[[nodiscard]] constexpr uint16_t statusword() const
	{
		switch (state_)
		{
		case state::not_ready_to_switch_on: return 0x0000;
		case state::switch_on_disabled:     return 0x0040;
		case state::ready_to_switch_on:     return 0x0021 | voltage_enabled;
		case state::switched_on:            return 0x0023 | voltage_enabled;
		case state::operation_enabled:      return 0x0027 | voltage_enabled;
		case state::quick_stop_active:      return 0x0007 | voltage_enabled;
		case state::fault_reaction_active:  return 0x000F;
		case state::fault:                  return 0x0008;
		}
		return 0;
	}

	/** @brief Whether the drive may be enabled: operation enabled. */
	[[nodiscard]] constexpr bool enabled() const { return state_ == state::operation_enabled; }

	/** @brief Back to switch on disabled, keeping a fault: when the master stops driving the axis. */
	constexpr void disable()
	{
		if (state_ != state::fault && state_ != state::fault_reaction_active)
			state_ = state::switch_on_disabled;
	}

	/** @brief The current state. */
	[[nodiscard]] constexpr state current() const { return state_; }

private:

	/// A command: the bits of the controlword it looks at, and their values.
	struct command
	{
		uint16_t mask;
		uint16_t value;
	};

	// Commands of the controlword (bits 7, 3, 2, 1, 0).
	static constexpr command shutdown         {0x0087, 0x0006};
	static constexpr command switch_on        {0x008F, 0x0007};
	static constexpr command enable_operation {0x008F, 0x000F};
	static constexpr command disable_voltage  {0x0082, 0x0000};
	static constexpr command quick_stop       {0x0086, 0x0002};
	static constexpr uint16_t fault_reset = 0x0080;

	static constexpr uint16_t voltage_enabled = 0x0010; ///< Statusword bit 4

	static constexpr bool is(uint16_t controlword, command c) { return (controlword & c.mask) == c.value; }

	state state_ = state::not_ready_to_switch_on;
	uint16_t previous_ = 0;
};

} // namespace bornier::cia402
