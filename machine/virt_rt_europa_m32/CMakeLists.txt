cmake_minimum_required(VERSION 3.28)
project(qemu_virt_rt_europa_m32 LANGUAGES C ASM)
enable_testing()

include(../../../core/cmake/support.cmake)

rvbl_machine(LIBRARIES semihost uart_ns16550 RUNNERS qemu)

rvbl_use(
  core/lib
  core/lib/ns16550
  quintauris/lib/uart_semihost
  quintauris/lib/dhrystone
  riscv/lib/abi
  riscv/lib/interrupt
  riscv/lib/semihost
  riscv/lib/aclint
  riscv/lib/memory
  riscv/lib/atomic
  riscv/lib/concurrency)

add_subdirectory(example)
