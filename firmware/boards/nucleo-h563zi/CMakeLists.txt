# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

# NUCLEO-H563ZI: clock tree, user LEDs, ST-LINK virtual COM port, startup and vector table.
# The startup file is an interface source so the vector table lands in every firmware image.
add_library(board_nucleo_h563zi INTERFACE)
target_sources(board_nucleo_h563zi INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/startup.cpp)
target_include_directories(board_nucleo_h563zi INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(board_nucleo_h563zi INTERFACE stm32h563)
