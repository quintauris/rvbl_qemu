#include "rvbl/machine/rvbl_machine.h"
#include "rvbl/semihost/rvbl_semihost.h"

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
}

void rvbl_test_putc(int c, void *p)
{
    rvbl_uart_ns16550_data_write(&rvbl_uart_ns16550_instance_default, c);
}