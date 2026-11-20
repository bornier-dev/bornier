# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand

# Needs the EtherCAT Slave Stack Code (BORNIER_SSC_DIR), see firmware/CMakeLists.txt.
add_executable(ethercat_preop main.cpp ../../boards/base/ssc_hw.cpp)
target_link_libraries(ethercat_preop PRIVATE board_base project_warnings ssc)
target_link_options(ethercat_preop PRIVATE -Wl,-Map=$<TARGET_FILE_DIR:ethercat_preop>/ethercat_preop.map)

add_custom_command(TARGET ethercat_preop POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:ethercat_preop> $<TARGET_FILE_DIR:ethercat_preop>/ethercat_preop.bin
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:ethercat_preop>
    VERBATIM
)
