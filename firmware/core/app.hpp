// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    app.hpp
 * @author  Thomas Legrand
 * @brief   Composition of a firmware image from modules, resolved at compile time
 *
 *          A firmware image (an application, or a test of one or several modules) is a list
 *          of modules. app<Board, Modules...> composes them: no registry, no generated code,
 *          no virtual call. Everything is decided by the compiler, and a debugger shows the
 *          concrete types.
 *
 *          A module is a class with static members. Each of these is optional:
 *
 *          | Member                    | Used for                                             |
 *          |---------------------------|------------------------------------------------------|
 *          | static void init()        | set up the hardware, once, in list order             |
 *          | static constexpr isrs     | install the module's interrupt handlers in the table |
 *          | static bool start()       | start the module's tasks; false stops the image      |
 *
 *          isrs is an installer, as opsy::scheduler::isrs: a callable that takes the vector
 *          table and returns it with the module's handlers in their slots. A slot taken twice
 *          does not compile.
 *
 *          A module that depends on another takes it as a template parameter constrained by a
 *          concept, the way a C# class takes an interface in its constructor:
 *
 *          @code
 *          template<switchable Led>
 *          class blinker { ... };                     // needs something it can switch on and off
 *
 *          using app = bornier::app<board, mcu_led, trace, blinker<mcu_led>>;
 *
 *          void application() { app::run(); }        // entry point of the image (application.hpp)
 *          @endcode
 *
 *          Board is the board's module: it provides the base vector table (reset handler,
 *          default handler, the handlers of OpSy) and is initialised first.
 *
 *          See firmware/README.md, "Writing a module", and examples/blink for a complete
 *          module.
 ******************************************************************************
 */

#pragma once

#include <concepts>

#include <opsy.hpp>
#include <scheduler.hpp>

namespace bornier
{

/** @brief A module that sets up its hardware: init() is called once, in list order. */
template<typename Module>
concept initialised = requires { Module::init(); };

/** @brief A module with interrupt handlers: isrs installs them in the vector table. */
template<typename Module>
concept interrupt_driven = requires { Module::isrs; };

/** @brief A module with tasks: start() starts them and tells whether it could. */
template<typename Module>
concept tasked = requires { { Module::start() } -> std::same_as<bool>; };

/**
 * @brief A firmware image made of a board and modules.
 *
 * @tparam Board   The board's module: init() and the base vector table, vectors.
 * @tparam Modules The modules of the image, initialised in this order after the board.
 */
template<typename Board, typename... Modules>
class app
{
public:

	/**
	 * @brief The vector table of the image: the board's, with the handlers of every module.
	 *
	 *        Placed in flash where the linker script expects it (.isr_vector), and kept
	 *        because run() refers to it: an image has exactly one table, the one of the
	 *        app it runs.
	 */
	[[gnu::section(".isr_vector"), gnu::used]]
	static constexpr auto vectors = []
	{
		auto table = Board::vectors;
		([&table]
		{
			if constexpr (interrupt_driven<Modules>)
				table = table.with(Modules::isrs);
		}(), ...);
		return table;
	}();

	/**
	 * @brief Runs the image: initialises the board then each module, starts their tasks,
	 *        then starts the scheduler. Does not return.
	 *
	 *        A module whose start() returns false stops the image on opsy::trap(): an image
	 *        missing one of its tasks must not run.
	 */
	[[noreturn]] static void run()
	{
		(void)&vectors;
		Board::init();
		(init<Modules>(), ...);
		if (!(start<Modules>() && ...))
			opsy::trap();
		opsy::scheduler::start();
	}

private:

	template<typename Module>
	static void init()
	{
		if constexpr (initialised<Module>)
			Module::init();
	}

	template<typename Module>
	static bool start()
	{
		if constexpr (tasked<Module>)
			return Module::start();
		else
			return true;
	}
};

} // namespace bornier
