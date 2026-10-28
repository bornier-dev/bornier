# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

add_executable(step_generator main.cpp)
target_link_libraries(step_generator PRIVATE board_nucleo_h563zi project_warnings)
target_link_options(step_generator PRIVATE -Wl,-Map=$<TARGET_FILE_DIR:step_generator>/step_generator.map)

add_custom_command(TARGET step_generator POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:step_generator> $<TARGET_FILE_DIR:step_generator>/step_generator.bin
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:step_generator>
    VERBATIM
)
