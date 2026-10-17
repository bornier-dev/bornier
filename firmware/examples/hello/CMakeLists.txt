# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

add_executable(hello main.cpp)
target_link_libraries(hello PRIVATE board_nucleo_h563zi project_warnings)
target_link_options(hello PRIVATE -Wl,-Map=$<TARGET_FILE_DIR:hello>/hello.map)

add_custom_command(TARGET hello POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:hello> $<TARGET_FILE_DIR:hello>/hello.bin
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:hello>
    VERBATIM
)
