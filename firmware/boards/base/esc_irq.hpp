// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    esc_irq.hpp
 * @author  Thomas Legrand
 * @brief   Interrupt request of the LAN9253 EtherCAT slave controller, as a module
 *
 *          | Signal   | Pin  | Function                                        |
 *          |----------|------|-------------------------------------------------|
 *          | ESC_IRQ  | PC5  | EXTI5, falling edge; open drain, pulled up (R21) |
 *
 *          The LAN9253 pulls ESC_IRQ low while one of its enabled interrupts is
 *          pending; for the EtherCAT core, while the AL event request and the AL event
 *          mask share a bit. The interrupt handler only wakes the task that waits in
 *          wait_until(): the requests are served there, where accesses to the LAN9253 may
 *          sleep. Since the pin stays low as long as a request is pending, the task checks
 *          it again after serving (pending()), a falling edge coming only once.
 *
 *          SYNC0 wakes the same task (wake(), from sync_latch): one wait for every request.
 *
 *          The LAN9253 side (IRQ_CFG, INT_EN) is set up by whoever drives it, after any
 *          reset of the chip: see esc_bus.
 *
 *          No HAL. No dynamic allocation.
 ******************************************************************************
 */

#pragma once

#include <atomic>

#include <opsy.hpp>
#include <cortex_m.hpp>
#include <semaphore.hpp>

#include <STM32H523/exti.hpp>
#include <STM32H523/gpio.hpp>
#include <STM32H523/interrupts.hpp>
#include <STM32H523/rcc.hpp>

namespace STM32H523
{

using mmio::atomic;

/**
 * @brief Interrupt request of the LAN9253, as a module.
 *
 *        All methods are static — no instance needed. init() and isrs are used by bornier::app;
 *        wait_until() and pending() are for the one task that serves the requests.
 */
class esc_irq
{
public:

	/** @brief PC5 as an input on EXTI5, falling edge. */
	static void init()
	{
		rcc.ahb2enr |= rcc_p::ahb2enr_r::gpiocen_f() | atomic;
		gpioc.moder <<= gpio_p::moder_r::mode5_f(0b00) || atomic; // input, pulled up by R21

		exti.exticr2 <<= exti_p::exticr2_r::exti5_f(port_c) || atomic;
		exti.ftsr1 |= exti_p::ftsr1_r::ft5_f() | atomic;
		exti.fpr1 = exti_p::fpr1_r::fpif5_f();
		exti.imr1 |= exti_p::imr1_r::im5_f() | atomic;

		opsy::cortex_m::set_priority(EXTI5_IRQn, opsy::scheduler::os_callable_priority);
		opsy::cortex_m::enable_interrupt(EXTI5_IRQn);
	}

	/**
	 * @brief Sleeps until a falling edge of ESC_IRQ, a wake(), or @p deadline.
	 *
	 * @return @c true on an edge or a wake().
	 */
	static bool wait_until(opsy::time_point deadline)
	{
		if (!edge_.try_acquire_until(deadline))
			return false;
		// After the acquire: a wake in between finds the flag still set and releases nothing,
		// but the task looks for requests only from here on, so it sees that one too.
		woken_.store(false, std::memory_order_release);
		return true;
	}

	/** @brief Wakes the task in wait_until(). From an interrupt handler too. */
	static void wake()
	{
		// At most one release before the task takes it: the semaphore is binary.
		if (!woken_.exchange(true, std::memory_order_acq_rel))
			edge_.release();
	}

	/** @brief Whether ESC_IRQ is low: a request is pending. */
	static bool pending()
	{
		return !gpioc.idr.load().id5();
	}

private:

	static constexpr uint8_t port_c = 0x02; ///< EXTICR value of port C

	static void isr()
	{
		exti.fpr1 = exti_p::fpr1_r::fpif5_f();
		wake();
	}

	static inline opsy::binary_semaphore edge_{0};
	static inline std::atomic<bool> woken_{false};

public:

	/** @brief The handler of the module: a falling edge of ESC_IRQ. */
	static constexpr auto isrs = []<typename Table>(const Table& table) -> Table
	{
		return table.template with<EXTI5_IRQn, isr>();
	};
};

} // namespace STM32H523
