/*
 * Copyright 2026 Quintauris GmbH
 * Licensed under the Apache License, Version 2.0 (the "License").
 * https://www.apache.org/licenses/LICENSE-2.0
 */

#include "rvbl/test/rvbl_test.h"
#include "rvbl/hardware/rvbl_hardware.h"
#include "rvbl/machine/rvbl_machine.h"
#include "rvbl/semihost/rvbl_semihost.h"
#include "rvbl/uart/rvbl_uart_ns16550.h"

static const rvbl_uart *uart = NULL;
static rvbl_pointer_t instance = NULL;

static void enable_pmp(void)
{
    __asm__ volatile("csrw pmpaddr0, %0\n\t"
                     "csrw pmpaddr1, %1\n\t"
                     "csrw pmpcfg0, %2\n\t"
                     :
                     : "r"(0x80000000), "r"(0x81000000), "r"(0x0F0F)
                     :);
}

void rvbl_test_initialize(void)
{
    enable_pmp();
    rvbl_semihost_initialize();

    uart = &rvbl_uart_ns16550;
    instance = (rvbl_pointer_t)&rvbl_uart_ns16550_instance_default;
    uart->init(instance);
}

void rvbl_test_putc(int c, void *p)
{
    (void)p;

    if (uart != NULL) {
        while (!uart->tx_ready(instance, NULL)) {
        }
        uart->putc(instance, c, NULL);
    }
}

static void rvbl_test_machine_supervisor_software_interrupt_prepare(void)
{
    RVBL_REGISTER_FIELD_SET(riscv_hart, privileged, &rvbl_riscv_hart_instance_0, mie, ssie);
}

static void rvbl_test_machine_supervisor_software_interrupt_trigger(void)
{
    RVBL_REGISTER_FIELD_SET(riscv_hart, privileged, &rvbl_riscv_hart_instance_0, mip, ssip);
}

static void rvbl_test_machine_supervisor_software_interrupt_cleanup(void)
{
    RVBL_REGISTER_FIELD_CLEAR(riscv_hart, privileged, &rvbl_riscv_hart_instance_0, mie, ssie);
}

const rvbl_test_interrupt_control rvbl_test_machine_interrupt_control = {
    .can_trigger_interrupt = rvbl_true,
    .interrupt_code = rvbl_riscv_hart_privileged_mcause_code_values_Interrupt_SupervisorSoftware,
    .prepare_interrupt = rvbl_test_machine_supervisor_software_interrupt_prepare,
    .trigger_interrupt = rvbl_test_machine_supervisor_software_interrupt_trigger,
    .cleanup_interrupt = rvbl_test_machine_supervisor_software_interrupt_cleanup,
};

const rvbl_test_interrupt_control rvbl_test_supervisor_interrupt_control = {
    .can_trigger_interrupt = rvbl_false,
    .interrupt_code = 0,
    .prepare_interrupt = NULL,
    .trigger_interrupt = NULL,
    .cleanup_interrupt = NULL,
};
