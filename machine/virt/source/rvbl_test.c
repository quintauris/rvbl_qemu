#include "rvbl/machine/rvbl_machine.h"
#include "rvbl/semihost/rvbl_semihost.h"
#include "rvbl/uart/rvbl_uart_ns16550.h"

static const rvbl_uart *uart = NULL;
static rvbl_pointer_t instance = NULL;

static void enable_pmp()
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
    if (uart != NULL) {
        while (!uart->tx_ready(instance, NULL)) {
        }
        uart->putc(instance, c, NULL);
    }
}
