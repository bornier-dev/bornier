# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

add_executable(esc_probe main.cpp)
target_link_libraries(esc_probe PRIVATE board_base project_warnings)
target_link_options(esc_probe PRIVATE -Wl,-Map=$<TARGET_FILE_DIR:esc_probe>/esc_probe.map)

add_custom_command(TARGET esc_probe POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:esc_probe> $<TARGET_FILE_DIR:esc_probe>/esc_probe.bin
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:esc_probe>
    VERBATIM
)
