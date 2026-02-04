cmake_minimum_required(VERSION 3.28)
project(qemu_virt_multicore LANGUAGES C ASM)
enable_testing()

include(../../../base/cmake/support.cmake)

rvbl_machine(LIBRARIES semihost uart_ns16550 RUNNERS qemu)

rvbl_use(
  base/lib
  base/lib/ns16550
  quintauris_internal/lib
  riscv/lib/abi
  riscv/lib/interrupt
  riscv/lib/semihost
  riscv/lib/aclint
  quintauris/lib/dhrystone)

add_subdirectory(example)
