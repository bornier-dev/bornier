// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    application.hpp
 * @author  Thomas Legrand
 * @brief   Entry point of a firmware image on the Bornier base board
 *
 *          The board owns the whole startup (startup.cpp): images are linked without the
 *          C runtime start files (-nostartfiles), so nothing refers to main() and the program
 *          has none. C++ forbids main() from having C linkage and from being called by the
 *          program itself; owning the startup avoids both.
 *
 *          Reset_Handler sets up the core, copies .data, zeroes .bss, runs the static
 *          constructors (.preinit_array, then .init_array), then calls application(), which
 *          each image defines once:
 *
 *          @code
 *          #include <application.hpp>
 *
 *          void application()
 *          {
 *              clock::init();
 *              // start the tasks of the image
 *              opsy::scheduler::start(); // does not return
 *          }
 *          @endcode
 ******************************************************************************
 */

#pragma once

/** @brief Entry point of the image, called once by Reset_Handler. Never returns. */
[[noreturn]] void application();
