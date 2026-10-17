# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

# Register headers generated from STM32H563.svd, included as <STM32H563/xxx.hpp>.
add_library(stm32h563 INTERFACE)
target_include_directories(stm32h563 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(stm32h563 INTERFACE opsy)
target_link_options(stm32h563 INTERFACE -T${CMAKE_CURRENT_SOURCE_DIR}/stm32h563xi.ld)
set_property(TARGET stm32h563 APPEND PROPERTY INTERFACE_LINK_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/stm32h563xi.ld)
