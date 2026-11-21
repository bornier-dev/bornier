# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

cmake_minimum_required(VERSION 3.25)

project(bornier LANGUAGES C CXX ASM)

if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 16)
    message(FATAL_ERROR "GCC ${CMAKE_CXX_COMPILER_VERSION} found, the firmware needs GCC 16 (CONTRIBUTING.md)")
endif()

add_subdirectory(firmware)
