// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    axes.hpp
 * @author  Thomas Legrand
 * @brief   The four step/dir axes of the Bornier base board under CiA402, cyclic synchronous
 *          position (CSP), as a module
 *
 *          Each axis runs the CiA402 state machine (cia402.hpp) from its controlword and from
 *          the alarm of its drive (drive_ports), and its steps come from step_generator: every
 *          SYNC0, the fill takes the target position of each axis, in steps.
 *
 *          The master writes, every cycle, the controlword and the target position of each
 *          axis (outputs()); the stack's task then runs the state machines (run()), and the
 *          fill interrupt, at a fixed time after the next SYNC0, takes the targets the task
 *          published last. An axis follows its target only:
 *          - while the outputs are allowed (OP), its state is operation enabled and its drive
 *            is enabled;
 *          - from a target within one cycle of steps of where it stands: an axis enabled with a
 *            target far away holds until the master brings the target to it, instead of
 *            running there at the maximum rate.
 *          Otherwise it holds where it stands, and outside OP every axis holds, so that the
 *          generator sees no missed frame.
 *
 *          A fault of the generator (more frames missed in a row than its tolerance, see
 *          step_generator) puts every axis in fault; a fault reset of the master acknowledges
 *          it, and the axes resume from where they stand.
 *
 *          outputs(), run() and the readers are for the stack's task.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <array>
#include <atomic>
#include <cstddef>
#include <cstdint>

#include <opsy.hpp>
#include <cia402.hpp>
#include <drive_ports.hpp>
#include <step_generator.hpp>

#include <STM32H523/interrupts.hpp>

namespace STM32H523
{

namespace detail
{

/// What the fill of the axes takes: published by axes::run(), the fill reads the other half of
/// the pair.
struct axes_publication
{
	std::array<int32_t, step_generator::axis_count> targets{};
	uint32_t follow = 0; ///< axes that follow their target
	bool held = true;    ///< outside OP: every axis holds, no frame counts as missed
};

} // namespace detail

/**
 * @brief The step/dir axes under CiA402 CSP, as a module.
 *
 *        All methods are static — no instance needed. start() and isrs are used by
 *        bornier::app.
 */
class axes
{
public:

	static constexpr std::size_t count = step_generator::axis_count;
	static_assert(count == drive_ports::count);

	/** @brief Starts the step generator; its slot grid locks on the next SYNC0. */
	static bool start()
	{
		step_generator::derived d{};
		if (step_generator::derive(settings, d) != step_generator::error::none)
			return false;
		max_steps_ = d.max_steps;
		step_generator::start(settings, opsy::scheduler::os_callable_priority);
		return true;
	}

	/**
	 * @brief The outputs of the master for the next cycle.
	 *
	 * @param controlwords Controlword of each axis (0x6040 + 0x800n).
	 * @param targets      Target position of each axis, steps (0x607A + 0x800n).
	 */
	static void outputs(std::array<uint16_t, count> const& controlwords, std::array<int32_t, count> const& targets)
	{
		controlwords_ = controlwords;
		targets_ = targets;
	}

	/**
	 * @brief Runs the state machines, drives the enables and publishes the targets for the
	 *        next fill. Once per cycle.
	 *
	 * @param outputs_allowed Whether the outputs may be driven (OP).
	 */
	static void run(bool outputs_allowed)
	{
		const bool generator_fault = step_generator::state() != step_generator::mode::running;
		bool reset = false;
		auto& next = published_[1 - current_.load(std::memory_order_relaxed)];
		next.follow = 0;
		for (std::size_t n = 0; n < count; ++n)
		{
			const uint16_t controlword = outputs_allowed ? controlwords_[n] : 0;
			reset = reset || (controlword & fault_reset) != 0;
			state_[n].update(controlword, drive_ports::alarm(n) || generator_fault);
			const bool enabled = outputs_allowed && state_[n].enabled();
			drive_ports::enable(n, enabled);

			// Follows the target from one within reach of where the axis stands.
			const int32_t gap = targets_[n] - position(n);
			if (!enabled)
				following_[n] = false;
			else if (!following_[n] && gap <= static_cast<int32_t>(max_steps_) && -gap <= static_cast<int32_t>(max_steps_))
				following_[n] = true;
			if (following_[n])
				next.follow |= 1u << n;
			next.targets[n] = targets_[n];
		}
		next.held = !outputs_allowed;
		current_.store(1 - current_.load(std::memory_order_relaxed), std::memory_order_release);
		fresh_.store(true, std::memory_order_release);
		if (generator_fault && reset)
			step_generator::acknowledge();
	}

	/** @brief Stops following and disables every drive at once: leaving OP. */
	static void disable_all()
	{
		for (std::size_t n = 0; n < count; ++n)
		{
			drive_ports::enable(n, false);
			state_[n].disable();
			following_[n] = false;
		}
		auto& next = published_[1 - current_.load(std::memory_order_relaxed)];
		next.follow = 0;
		next.held = true;
		current_.store(1 - current_.load(std::memory_order_relaxed), std::memory_order_release);
	}

	/** @brief Statusword of an axis (0x6041 + 0x800n). */
	static uint16_t statusword(std::size_t n) { return state_[n].statusword(); }

	/** @brief Position of an axis, steps scheduled: all are emitted (0x6064 + 0x800n). */
	static int32_t position(std::size_t n) { return step_generator::statistics().axes[n].position; }

	/// Settings of the generator: 1 MHz slots, the 1 ms cycle of the master.
	static constexpr step_generator::config settings{};

private:

	static constexpr uint16_t fault_reset = 0x0080;

	/// Fill interrupt (TIM5 CC2): the command of the next cycle.
	static void fill_isr()
	{
		(void)step_generator::fill([] {
			const auto& p = published_[current_.load(std::memory_order_acquire)];
			const bool fresh = fresh_.exchange(false, std::memory_order_acq_rel);
			step_generator::command c{};
			c.received = fresh || p.held;
			for (std::size_t n = 0; n < count; ++n)
				c.targets[n] = (p.follow & (1u << n)) != 0 ? p.targets[n] : step_generator::statistics().axes[n].position;
			return c;
		});
	}

	static inline std::array<bornier::cia402::axis, count> state_{};
	static inline std::array<uint16_t, count> controlwords_{};
	static inline std::array<int32_t, count> targets_{};
	static inline std::array<bool, count> following_{};
	static inline uint32_t max_steps_ = 0;
	static inline std::array<detail::axes_publication, 2> published_{};
	static inline std::atomic<uint32_t> current_{0};
	static inline std::atomic<bool> fresh_{false};

public:

	/** @brief The handler of the module: the fill of the step generator. */
	static constexpr auto isrs = []<typename Table>(const Table& table) -> Table
	{
		return table.template with<TIM5_IRQn, fill_isr>();
	};
};

} // namespace STM32H523
