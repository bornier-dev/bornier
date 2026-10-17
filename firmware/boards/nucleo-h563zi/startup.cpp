// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    startup.cpp
 * @author  Thomas Legrand
 * @brief   C++ startup file for STM32H563ZI (Cortex-M33)
 *
 *          Provides the interrupt vector table, Reset_Handler, and C++ runtime
 *          initialization. Also enforces the no-dynamic-allocation policy by
 *          trapping any call to @c _sbrk, @c operator @c new, or
 *          @c operator @c new[].
 *
 *          Peripheral ISRs are registered at compile time via
 *          @c InterruptVector::Register<IRQn, handler>().
 ******************************************************************************
 */

#include <cstddef>
#include <cstdint>
#include <new>

#include <cortex_m.hpp>
#include <STM32H563/interrupts.hpp>
#include <utility/interrupt_vector.hpp>

#include "uart.hpp"



// ── Linker symbols (defined in STM32H563ZITX_FLASH.ld) ───────────────────────
extern "C"
{
uint32_t SystemCoreClock = 250'000'000; // 250MHz

extern uint32_t _estack;  ///< Top of main stack
extern uint32_t _sstack;  ///< Bottom of main stack (= _estack - _Min_Stack_Size)
extern uint32_t _sidata;  ///< Load address of .data in flash
extern uint32_t _sdata;   ///< Start of .data in RAM
extern uint32_t _edata;   ///< End of .data in RAM
extern uint32_t _sbss;    ///< Start of .bss in RAM
extern uint32_t _ebss;    ///< End of .bss in RAM
extern void __libc_init_array(); ///< Calls C++ static constructors (.init_array)
extern int  main();

// Handlers defined in this file. SVC_Handler, PendSV_Handler and SysTick_Handler are declared by
// OpSy (scheduler.hpp) and defined in scheduler.cpp.
[[noreturn]] void Default_Handler();
[[noreturn]] void Reset_Handler();

// newlib hooks defined below
void* _sbrk(std::ptrdiff_t);
} // extern "C"

// ── Interrupt vector table ────────────────────────────────────────────────────
/**
 * @brief STM32H563 interrupt vector table, built entirely at compile time.
 *
 *        System exception handlers are passed to the
 *        @c opsy::utility::interrupt_vector constructor. Peripheral ISRs are
 *        registered via @c .with_handler<IRQn, handler>() — add calls here as
 *        drivers are written. Unregistered peripheral slots are @c nullptr;
 *        the hardware will escalate any unexpected IRQ to a HardFault, caught
 *        by @c Default_Handler.
 */
__attribute__((section(".isr_vector"), used))
constexpr auto g_vectors = opsy::utility::interrupt_vector<irq_count>(
    &_estack,
    Reset_Handler,
    SysTick_Handler,
    SVC_Handler,
    PendSV_Handler,
    Default_Handler,  // NMI
    Default_Handler,  // HardFault
    Default_Handler,  // MemManage
    Default_Handler,  // BusFault
    Default_Handler,  // UsageFault
    Default_Handler   // DebugMonitor
)
    .with_handler<GPDMA1_CH0_IRQn, STM32H563::uart::tx_isr>()
    .with_handler<GPDMA1_CH1_IRQn, STM32H563::uart::rx_dma_isr>()
    .with_handler<USART3_IRQn,     STM32H563::uart::rx_isr>();

// ── Default_Handler ───────────────────────────────────────────────────────────
/**
 * @brief Catches any unhandled exception or unexpected interrupt.
 *
 *        Triggers a breakpoint so a connected debugger halts immediately.
 *        The infinite loop prevents spurious execution if no debugger is attached.
 */
extern "C" [[noreturn]] void Default_Handler()
{
    asm volatile("bkpt 0");
    while (true) {}
}

// ── Reset_Handler ─────────────────────────────────────────────────────────────
/**
 * @brief First code executed after a system reset.
 *
 *        Performs the full Cortex-M33 bring-up sequence:
 *        -# Reset MSP to the top of the main stack.
 *        -# Set MSPLIM to the bottom of the main stack (M33 hardware stack-limit).
 *        -# Enable the FPU (CP10/CP11 full-access in CPACR).
 *        -# Copy initialised data from flash (@c _sidata) to RAM (@c .data).
 *        -# Zero the uninitialised data section (@c .bss).
 *        -# Call @c __libc_init_array() to run C++ static constructors.
 *        -# Branch to @c main().
 */
extern "C" [[noreturn]] void Reset_Handler()
{
    opsy::cortex_m::set_msp(&_estack);
    opsy::cortex_m::set_msplim(&_sstack);
    opsy::cortex_m::enable_fpu();

    for (auto src = &_sidata, dst = &_sdata; dst != &_edata; ++src, ++dst)
        *dst = *src;

    for (auto ptr = &_sbss; ptr != &_ebss; ++ptr)
        *ptr = 0u;

    __libc_init_array();

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
	main();
#pragma GCC diagnostic pop

    asm volatile("bkpt 0"); // main() must not return
    while (true) {}
}

// ── No dynamic allocation ─────────────────────────────────────────────────────
/**
 * @brief Traps any attempt to grow the heap via @c malloc or @c realloc.
 *
 *        Dynamic allocation is forbidden in this project. Any call that reaches
 *        @c _sbrk indicates a bug — trap immediately so it is caught early.
 */
extern "C" void* _sbrk(std::ptrdiff_t) { __builtin_trap(); }

/// @brief Traps any direct call to @c operator @c new.
void* operator new  (std::size_t) { __builtin_trap(); }
/// @brief Traps any direct call to @c operator @c new[].
void* operator new[](std::size_t) { __builtin_trap(); }

// delete operators are no-ops: they are required by the ABI but will never be
// reached since new always traps before any object can be constructed.
void  operator delete  (void*)              noexcept {}
void  operator delete[](void*)              noexcept {}
void  operator delete  (void*, std::size_t) noexcept {}
void  operator delete[](void*, std::size_t) noexcept {}

// ── assert override ───────────────────────────────────────────────────────────
/**
 * @brief Replaces newlib's @c __assert_func to avoid pulling in @c fprintf.
 *
 *        The default newlib implementation calls @c fiprintf(stderr, ...) which
 *        drags in the entire printf machinery (@c _printf_i, @c _printf_common,
 *        @c _vfprintf_r, @c __sfvwrite_r, ...) — about 20 KB of flash for a
 *        message that is never read on a target without stdout.
 *
 *        At the breakpoint, the four arguments are still live in registers
 *        thanks to the @c "r" constraints, so the debugger can inspect:
 *        - r0 / @p file — source file path
 *        - r1 / @p line — line number
 *        - r2 / @p func — enclosing function signature
 *        - r3 / @p expr — failed expression text
 *        @c LR points at the call site, recoverable via a backtrace.
 */
extern "C" [[noreturn]] void __assert_func(const char* file, int line,
                                           const char* func, const char* expr)
{
    asm volatile("bkpt 0" :: "r"(file), "r"(line), "r"(func), "r"(expr));
    while (true) {}
}

// ── Syscall stubs ─────────────────────────────────────────────────────────────
// Minimal implementations required by newlib. I/O is not supported; these stubs
// satisfy the linker without pulling in the default nosys.specs versions.
#include <sys/stat.h>

extern "C"
{
int _close (int);
int _fstat (int, struct stat*);
int _getpid();
int _isatty(int);
int _kill  (int, int);
int _lseek (int, int, int);
int _read  (int, char*, int);
int _write (int, char*, int);

int _close (int)                    { return -1; }
int _fstat (int, struct stat* st)   { st->st_mode = S_IFCHR; return 0; }
int _getpid()                       { return 1; }
int _isatty(int)                    { return 1; }
int _kill  (int, int)               { return -1; }
int _lseek (int, int, int)          { return 0; }
int _read  (int, char*, int)        { return 0; }
int _write (int, char*, int)        { return 0; }
}
