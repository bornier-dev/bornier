# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

# The trace of every image: Kymo's target headers, its OpSy adapter, the trace ring and OpSy's
# hooks (opsy_hooks.hpp). OpSy links it, so the scheduler and the images see the same hooks.
add_library(bornier_trace INTERFACE)
target_include_directories(bornier_trace INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/kymo/target/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../third_party/kymo/target/opsy/include)
