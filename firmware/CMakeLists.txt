# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS ON)

set(CMAKE_C_FLAGS_DEBUG     "-Og -g3")
set(CMAKE_CXX_FLAGS_DEBUG   "-Og -g3")
set(CMAKE_C_FLAGS_RELEASE   "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-Os -DNDEBUG")

# ── Cortex-M33 with single-precision FPU (STM32H5) ────────────────────────────
add_library(cortex_m33 INTERFACE)
target_compile_options(cortex_m33 INTERFACE
    -mcpu=cortex-m33 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard
    --specs=nano.specs
    -ffunction-sections -fdata-sections -fstack-usage
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions -fno-rtti -fno-use-cxa-atexit>
    $<$<COMPILE_LANGUAGE:ASM>:-x assembler-with-cpp>
)
target_link_options(cortex_m33 INTERFACE
    -mcpu=cortex-m33 -mthumb -mfpu=fpv5-sp-d16 -mfloat-abi=hard
    --specs=nano.specs --specs=nosys.specs
    -static -Wl,--gc-sections
)

# Every warning that makes sense for embedded C++, as errors.
add_library(project_warnings INTERFACE)
target_compile_options(project_warnings INTERFACE
    -Wall -Wextra -Wpedantic -Werror
    -Wshadow -Wcast-align=strict -Wcast-qual -Wnull-dereference -Wpointer-arith
    -Wconversion -Wsign-conversion -Wdouble-promotion -Wfloat-equal
    -Wlogical-op -Wduplicated-cond -Wduplicated-branches
    -Wformat=2 -Wformat-overflow=2 -Wformat-truncation=2
    -Wundef -Wredundant-decls -Wmissing-declarations
    -Wvla -Walloca -Wstack-usage=1024
    -Wno-psabi
    $<$<COMPILE_LANGUAGE:CXX>:
        -Wold-style-cast -Wzero-as-null-pointer-constant
        -Wnon-virtual-dtor -Woverloaded-virtual=2 -Wsuggest-override
        -Wextra-semi -Wvolatile -Wdeprecated-copy-dtor -Wcomma-subscript
        -Wmismatched-tags -Wredundant-tags -Wctad-maybe-unsupported>
)
# Linker warnings too: -Werror does not reach them.
target_link_options(project_warnings INTERFACE -Wl,--fatal-warnings)

# ── OpSy RTOS ─────────────────────────────────────────────────────────────────
add_library(opsy STATIC third_party/opsy/scheduler.cpp)
target_include_directories(opsy PUBLIC third_party/opsy)
target_link_libraries(opsy PUBLIC cortex_m33 PRIVATE project_warnings)

# ── Devices ───────────────────────────────────────────────────────────────────
add_subdirectory(devices/STM32H563)

# ── Boards ────────────────────────────────────────────────────────────────────
add_subdirectory(boards/nucleo-h563zi)

# ── Examples ──────────────────────────────────────────────────────────────────
add_subdirectory(examples/hello)

# ── On-target tests ───────────────────────────────────────────────────────────
add_subdirectory(tests/atomic_mmio)
add_subdirectory(tests/step_generator)
