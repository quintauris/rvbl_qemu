#[[
  Copyright 2026 Quintauris GmbH
  Licensed under the Apache License, Version 2.0 (the "License").
  https://www.apache.org/licenses/LICENSE-2.0
]]

cmake_minimum_required(VERSION 3.28)
project(qemu_virt_rvi20u32 LANGUAGES C ASM)
enable_testing()

include(../../../core/cmake/support.cmake)

rvbl_machine(LIBRARIES semihost uart_ns16550 RUNNERS qemu)

rvbl_use(
  core/lib
  core/lib/ns16550
  core/lib/uart_semihost
  riscv/lib/abi
  riscv/lib/interrupt
  riscv/lib/semihost
  riscv/lib/aclint
  riscv/lib/atomic
  riscv/lib/concurrency)

add_subdirectory(example)
