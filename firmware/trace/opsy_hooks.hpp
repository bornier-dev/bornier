// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    opsy_hooks.hpp
 * @author  Thomas Legrand
 * @brief   OpSy's hooks in every Bornier image: Kymo's OpSy adapter, writing to the trace ring
 *
 *          OpSy includes this file because it is on its include path (hooks.hpp), in the
 *          scheduler and in every image: they must all see the same hooks.
 *
 *          The adapter records which task runs and why it woke, the interrupt handlers, the
 *          mutexes and the faults. Its idle task spins instead of sleeping (WFI): on the
 *          STM32H5, the probe reads zeros from RAM while the core sleeps.
 ******************************************************************************
 */

#pragma once

#include <bornier/trace.hpp>

#include <kymo/opsy/hooks.hpp>

namespace opsy
{
/// A class, not an alias: OpSy's task_control_block names it as a friend.
class hooks : public kymo::opsy::hooks<bornier::trace>
{};
} // namespace opsy
