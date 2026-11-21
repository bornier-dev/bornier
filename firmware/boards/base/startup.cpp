// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand

/**
 ******************************************************************************
 * @file    startup.cpp
 * @author  Thomas Legrand
 * @brief   C++ startup file for the Bornier base board, STM32H523VE (Cortex-M33)
 *
 *          Provides Reset_Handler, Default_Handler and the C++ runtime
 *          initialization. Also enforces the no-dynamic-allocation policy by
 *          trapping any call to @c _sbrk, @c operator @c new, or
 *          @c operator @c new[].
 *
 *          The vector table is not here: each image composes its own from the
 *          board's (board.hpp) and its modules' handlers (core/app.hpp).
 ******************************************************************************
 */

#include <cstddef>
#include <cstdint>
#include <new>

#include <algorithm>

#include <cortex_m.hpp>
#include <application.hpp>
#include <board.hpp>
#include <ext_watchdog.hpp>
#include <fault_log.hpp>


// ── Linker symbols (defined in stm32h523xe.ld) ───────────────────────
extern "C"
{
uint32_t SystemCoreClock = 250'000'000; // 250MHz

extern uint32_t _sstack;  ///< Bottom of main stack (= _estack - _Min_Stack_Size)
extern uint32_t _sidata;  ///< Load address of .data in flash
extern uint32_t _sdata;   ///< Start of .data in RAM
extern uint32_t _edata;   ///< End of .data in RAM
extern uint32_t _sbss;    ///< Start of .bss in RAM
extern uint32_t _ebss;    ///< End of .bss in RAM
extern void (*__preinit_array_start[])(); ///< Static initialisation, run first
extern void (*__preinit_array_end[])();
extern void (*__init_array_start[])();    ///< C++ static constructors
extern void (*__init_array_end[])();

// newlib hooks defined below
void* _sbrk(std::ptrdiff_t);
} // extern "C"

// ── Fatal faults ──────────────────────────────────────────────────────────────
[[gnu::noinit]] bornier::fault_log bornier::last_fault;

namespace
{

/// An assertion that failed, until the trap it ends in reaches on_fault().
const char* assert_file = nullptr;
uint32_t assert_line = 0;

/**
 * @brief The end of every fatal fault (fault_log.hpp): safe outputs, record, reset.
 *
 *        Interrupts are masked first: nothing else runs. The outputs go safe before anything
 *        is written, then the record; then the MCU resets, or, when a debugger asked for it
 *        (fault_log::hold), stays here feeding the external watchdog.
 */
[[noreturn]] void fatal(bornier::fault_log::cause what, uint32_t detail, const char* file,
                        const opsy::fault_status* status, const opsy::exception_frame* frame,
                        uint32_t exc_return)
{
    asm volatile("cpsid i" ::: "memory");
    STM32H523::board::safe_outputs();

    auto& log = bornier::last_fault;
    log.key = bornier::fault_log::record_key;
    ++log.faults;
    log.start_of_fault = log.starts;
    log.what = what;
    log.detail = detail;
    log.file = file;
    log.cfsr = status != nullptr ? status->cfsr : 0;
    log.hfsr = status != nullptr ? status->hfsr : 0;
    log.mmfar = status != nullptr ? status->mmfar : 0;
    log.bfar = status != nullptr ? status->bfar : 0;
    log.frame = frame != nullptr ? *frame : opsy::exception_frame{};
    log.exc_return = exc_return;
    log.stack.fill(0);
    if (frame != nullptr)
    {
        // The words above the frame, within the RAM.
        const auto* const from = reinterpret_cast<const uint32_t*>(frame + 1);
        const auto words = std::min<std::size_t>(log.stack.size(),
                                                 static_cast<std::size_t>(&_estack - from));
        std::copy_n(from, words, log.stack.begin());
    }
    asm volatile("dsb" ::: "memory");

    if (log.hold == bornier::fault_log::hold_key)
        while (true)
            STM32H523::ext_watchdog::feed();
    opsy::cortex_m::reset();
}

} // namespace

void STM32H523::on_fault(const opsy::fault_status& status, opsy::exception_frame& frame, uint32_t exc_return)
{
    if (assert_file != nullptr)
        fatal(bornier::fault_log::cause::assertion, assert_line, assert_file, &status, &frame, exc_return);
    fatal(bornier::fault_log::cause::fault, 0, nullptr, &status, &frame, exc_return);
}

// ── Default_Handler ───────────────────────────────────────────────────────────
/**
 * @brief Catches any interrupt nobody handles: a fatal fault, recorded with its exception
 *        number (fault_log.hpp). Straight to fatal(), with no trap: an NMI cannot escalate.
 */
extern "C" [[noreturn]] void Default_Handler()
{
    uint32_t ipsr;
    asm volatile("mrs %0, ipsr" : "=r"(ipsr));
    fatal(bornier::fault_log::cause::interrupt, ipsr & 0x1FFu, nullptr, nullptr, nullptr, 0);
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
 *        -# Run the static initialisers: @c .preinit_array, then @c .init_array (C++ static
 *           constructors). The C runtime start files are not linked (-nostartfiles), so this
 *           is done here rather than by @c __libc_init_array().
 *        -# Call @c application(), the entry point of the image (application.hpp).
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

    for (auto init = __preinit_array_start; init != __preinit_array_end; ++init)
        (*init)();
    for (auto init = __init_array_start; init != __init_array_end; ++init)
        (*init)();

    bornier::last_fault.count_start();
    application();
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
 *        A fatal fault: the file and line are kept for the record (fault_log.hpp), then
 *        a trap takes it to on_fault() with the frame of this call, so the record holds
 *        the call site too.
 */
extern "C" [[noreturn]] void __assert_func(const char* file, int line,
                                           const char*, const char*)
{
    assert_line = static_cast<uint32_t>(line);
    assert_file = file != nullptr ? file : "?";
    __builtin_trap();
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
