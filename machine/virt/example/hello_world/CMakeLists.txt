set(example_name hello_world)
set(example_sources ${CMAKE_CURRENT_SOURCE_DIR}/main.c)
set(example_extra_libraries rvbl_uart_ns16550)
set(example_expected_output "Hello world!")
set(example_build_for_flash FALSE)
set(example_test_timeout 30)
set(example_truncate_size 32M)

include(../../../../../base/cmake/example.cmake)
