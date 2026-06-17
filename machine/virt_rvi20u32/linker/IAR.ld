/*
 * Copyright 2026 Quintauris GmbH
 * Licensed under the Apache License, Version 2.0 (the "License").
 * https://www.apache.org/licenses/LICENSE-2.0
 */

build for rom;

define exported symbol _link_file_version_2 = 1;
define symbol STACK_SIZE = 4096;
define symbol HEAP_SIZE = 4096;
define memory Mem with size = 4G;

include "memory.IAR.ld";
include "sections.ld";

place at start of rom0 { section .text.start, section .rodata.start };
place in flash0 { block ROM_CONTENT };
place in ram0 { block RAM_CONTENT, block GP_STACK, block SP_STACK, block IR_STACK, block HEAP };
