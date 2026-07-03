/*
 * Copyright 2026 Quintauris GmbH
 * Licensed under the Apache License, Version 2.0 (the "License").
 * https://www.apache.org/licenses/LICENSE-2.0
 */

#include "rvbl/machine/rvbl_machine.h"
#include "rvbl/semihost/rvbl_semihost.h"
#include "rvbl/uart/rvbl_uart_ns16550.h"

int main(void)
{
    const char *hello = "Hello world!\n";
    const char *p = hello;

    while (rvbl_mhartid_read() != 0) {
    }

    rvbl_semihost_initialize();

    rvbl_uart_ns16550.init(&rvbl_uart_ns16550_instance_default);

    while (*p != '\0') {
        while (!rvbl_uart_ns16550.tx_ready(&rvbl_uart_ns16550_instance_default, NULL)) {
        }
        rvbl_uart_ns16550.putc(&rvbl_uart_ns16550_instance_default, *p, NULL);
        ++p;
    }

    rvbl_semihost_exit(rvbl_semihost_exit_code_success);

    return 0;
}
