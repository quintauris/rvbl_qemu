#[[
  Copyright 2026 Quintauris GmbH
  Licensed under the Apache License, Version 2.0 (the "License").
  https://www.apache.org/licenses/LICENSE-2.0
]]

rvbl_executable(
  NAME
  hello_world
  SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/main.c
  LIBRARIES
  uart_ns16550
  BINARY
  BINARY_SIZE
  32M
  TEST
  TEST_EXPECTED_OUTPUT
  "Hello world!"
  TEST_TIMEOUT
  30)
