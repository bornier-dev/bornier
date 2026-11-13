# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

# Bornier base board (hardware/base): clock tree, MCU LED, startup and vector table.
# The startup file is an interface source so the vector table lands in every firmware image.
add_library(board_base INTERFACE)
target_sources(board_base INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/startup.cpp)
target_include_directories(board_base INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(board_base INTERFACE stm32h523)
