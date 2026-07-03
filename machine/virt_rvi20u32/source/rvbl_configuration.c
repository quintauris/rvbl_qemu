/*
 * Copyright 2026 Quintauris GmbH
 * Licensed under the Apache License, Version 2.0 (the "License").
 * https://www.apache.org/licenses/LICENSE-2.0
 */

#include "rvbl/boot/rvbl_boot.h"

extern rvbl_pointer_t text_begin_flash, text_end_flash, text_begin_dram;
extern rvbl_pointer_t rodata_begin_flash, rodata_end_flash, rodata_begin_dram;
extern rvbl_pointer_t data_begin_flash, data_end_flash, data_begin_dram;
extern rvbl_pointer_t bss_begin, bss_end;

__attribute__((section(".rodata.start"))) const rvbl_boot_step boot_steps[] = {
    {.action = rvbl_boot_action_copy,
     .parameters = {.copy = {&text_begin_flash, &text_end_flash, &text_begin_dram}}},
    {.action = rvbl_boot_action_copy,
     .parameters = {.copy = {&rodata_begin_flash, &rodata_end_flash, &rodata_begin_dram}}},
    {.action = rvbl_boot_action_copy,
     .parameters = {.copy = {&data_begin_flash, &data_end_flash, &data_begin_dram}}},
    {.action = rvbl_boot_action_fill, .parameters = {.fill = {&bss_begin, &bss_end, 0}}},
    {.action = rvbl_boot_action_finish}
};
