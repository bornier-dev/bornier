# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

add_executable(rs485_echo main.cpp)
target_link_libraries(rs485_echo PRIVATE board_base project_warnings)
target_link_options(rs485_echo PRIVATE -Wl,-Map=$<TARGET_FILE_DIR:rs485_echo>/rs485_echo.map)

add_custom_command(TARGET rs485_echo POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:rs485_echo> $<TARGET_FILE_DIR:rs485_echo>/rs485_echo.bin
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:rs485_echo>
    VERBATIM
)
