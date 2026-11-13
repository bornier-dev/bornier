# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

# Register headers generated from STM32H523.svd, included as <STM32H523/xxx.hpp>.
add_library(stm32h523 INTERFACE)
target_include_directories(stm32h523 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(stm32h523 INTERFACE opsy)
target_link_options(stm32h523 INTERFACE -T${CMAKE_CURRENT_SOURCE_DIR}/stm32h523xe.ld)
set_property(TARGET stm32h523 APPEND PROPERTY INTERFACE_LINK_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/stm32h523xe.ld)
