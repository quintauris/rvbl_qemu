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
