// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    motion.hpp
 * @brief   Simulated motion for the step generator test: one target position per axis and cycle
 *
 *          Each axis loops over its own list of segments. A segment ramps the velocity linearly
 *          from its value at the start of the segment to a target velocity, given in millionths
 *          of the maximum velocity (steps per cycle). Position and velocity are fixed point
 *          16.16, in steps and steps per cycle; the target is the position rounded down.
 *
 *          Once the run duration is reached, each axis finishes its current loop (every loop
 *          ends at rest), then holds its position.
 *
 *          The arithmetic is integer only, so that tools/hil/step_generator.py can replay it
 *          exactly: division truncates toward zero, the shift rounds toward minus infinity.
 ******************************************************************************
 */

#pragma once

#include <array>
#include <cstdint>
#include <span>

namespace motion
{

struct segment
{
	uint32_t cycles;   ///< duration
	int32_t velocity;  ///< velocity reached at the end, millionths of the maximum
};

// ── Profiles ──────────────────────────────────────────────────────────────────

/// Ramps, cruise, stops and reversals at rest, from full speed down to a fraction of a step
/// per cycle, and reversals at speed.
namespace mixed
{
constexpr std::array<segment, 8> axis0{{ {100, 1'000'000}, {300, 1'000'000}, {100, 0}, {50, 0},
                                         {100, -1'000'000}, {300, -1'000'000}, {100, 0}, {50, 0} }};
constexpr std::array<segment, 7> axis1{{ {250, 500'000}, {500, 500'000}, {250, 0}, {1, 0},
                                         {250, -700'000}, {250, 0}, {100, 0} }};
/// Reversal at speed: +20 % to -20 % from one cycle to the next.
constexpr std::array<segment, 6> axis2{{ {1, 200'000}, {20, 200'000}, {1, -200'000}, {20, -200'000},
                                         {1, 0}, {10, 0} }};
/// Fractions of a step per cycle.
constexpr std::array<segment, 8> axis3{{ {500, 400}, {1000, 400}, {500, 0}, {200, 0},
                                         {300, -1500}, {300, -1500}, {300, 0}, {100, 0} }};
} // namespace mixed

/// Every axis at the maximum velocity, axes 1 and 3 backward, for the whole run.
namespace full
{
constexpr std::array<segment, 2> forward{{ {1, 1'000'000}, {1000, 1'000'000} }};
constexpr std::array<segment, 2> backward{{ {1, -1'000'000}, {1000, -1'000'000} }};
} // namespace full

enum class profile : uint8_t { mixed, full };

// ── Generator ─────────────────────────────────────────────────────────────────

class axis
{
public:

	void start(std::span<const segment> segments, int64_t max_velocity)
	{
		segments_ = segments;
		max_velocity_ = max_velocity << 16;
		position_ = 0;
		velocity_ = 0;
		start_velocity_ = 0;
		index_ = 0;
		elapsed_ = 0;
		done_ = false;
	}

	/// Advances one cycle and returns the target position, in steps.
	int32_t next(bool finish)
	{
		if (done_)
			return target();
		if (finish && index_ == 0 && elapsed_ == 0)
		{
			// At the start of a loop, at rest: stop here
			done_ = true;
			velocity_ = 0;
			return target();
		}
		auto const& s = segments_[index_];
		int64_t const end_velocity = max_velocity_ * s.velocity / 1'000'000;
		++elapsed_;
		velocity_ = start_velocity_ + (end_velocity - start_velocity_) * static_cast<int64_t>(elapsed_) / static_cast<int64_t>(s.cycles);
		position_ += velocity_;
		if (elapsed_ == s.cycles)
		{
			start_velocity_ = end_velocity;
			elapsed_ = 0;
			index_ = (index_ + 1) % segments_.size();
		}
		return target();
	}

	[[nodiscard]] bool done() const { return done_; }

private:

	[[nodiscard]] int32_t target() const { return static_cast<int32_t>(position_ >> 16); }

	std::span<const segment> segments_{};
	int64_t max_velocity_ = 0;   ///< 16.16 steps per cycle
	int64_t position_ = 0;       ///< 16.16 steps
	int64_t velocity_ = 0;
	int64_t start_velocity_ = 0; ///< velocity at the start of the current segment
	std::size_t index_ = 0;
	uint32_t elapsed_ = 0;       ///< cycles into the current segment
	bool done_ = false;
};

} // namespace motion
