# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

add_executable(blink main.cpp)
target_link_libraries(blink PRIVATE board_base project_warnings)
target_link_options(blink PRIVATE -Wl,-Map=$<TARGET_FILE_DIR:blink>/blink.map)

add_custom_command(TARGET blink POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:blink> $<TARGET_FILE_DIR:blink>/blink.bin
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:blink>
    VERBATIM
)
