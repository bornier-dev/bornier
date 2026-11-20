# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

add_executable(supply_monitor main.cpp)
target_link_libraries(supply_monitor PRIVATE board_base project_warnings)
target_link_options(supply_monitor PRIVATE -Wl,-Map=$<TARGET_FILE_DIR:supply_monitor>/supply_monitor.map)

add_custom_command(TARGET supply_monitor POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:supply_monitor> $<TARGET_FILE_DIR:supply_monitor>/supply_monitor.bin
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:supply_monitor>
    VERBATIM
)
