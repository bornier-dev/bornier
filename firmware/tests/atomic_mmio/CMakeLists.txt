# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

add_executable(atomic_mmio main.cpp)
target_link_libraries(atomic_mmio PRIVATE board_nucleo_h563zi project_warnings)
target_link_options(atomic_mmio PRIVATE -Wl,-Map=$<TARGET_FILE_DIR:atomic_mmio>/atomic_mmio.map)

add_custom_command(TARGET atomic_mmio POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:atomic_mmio> $<TARGET_FILE_DIR:atomic_mmio>/atomic_mmio.bin
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:atomic_mmio>
    VERBATIM
)
