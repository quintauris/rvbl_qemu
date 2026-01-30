cmake_minimum_required(VERSION 3.28)
project(qemu_virt_multicore LANGUAGES C ASM)
enable_testing()

set(host_tools
    "${CMAKE_SOURCE_DIR}/../../../build/local/tool"
    CACHE STRING "Host tools build folder.")

include(../../../base/cmake/support.cmake)

rvbl_machine(RUNNERS qemu)
rvbl_run_generators()

add_subdirectory(../../../base/lib ${CMAKE_CURRENT_BINARY_DIR}/base/lib)
add_subdirectory(../../../base/lib/ns16550
                 ${CMAKE_CURRENT_BINARY_DIR}/base/lib_ns16550)
add_subdirectory(../../../quintauris_internal/lib
                 ${CMAKE_CURRENT_BINARY_DIR}/quintauris_internal/lib)
add_subdirectory(../../../riscv/lib/abi ${CMAKE_CURRENT_BINARY_DIR}/lib/abi)
add_subdirectory(../../../riscv/lib/interrupt
                 ${CMAKE_CURRENT_BINARY_DIR}/lib/interrupt)
add_subdirectory(../../../riscv/lib/semihost
                 ${CMAKE_CURRENT_BINARY_DIR}/riscv/lib/semihost)

add_library(
  rvbl_machine STATIC
  ${generated_files} "${CMAKE_CURRENT_SOURCE_DIR}/source/rvbl_configuration.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/source/rvbl_test.c")
target_include_directories(
  rvbl_machine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/generated/include")
target_link_libraries(rvbl_machine PUBLIC rvbl_core rvbl_boot rvbl_uart_ns16550
                                          rvbl_semihost)

add_subdirectory(example)
