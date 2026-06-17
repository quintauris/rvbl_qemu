/*
 * Copyright 2026 Quintauris GmbH
 * Licensed under the Apache License, Version 2.0 (the "License").
 * https://www.apache.org/licenses/LICENSE-2.0
 */

INCLUDE memory.GNU.ld
REGION_ALIAS("ROM", rom0)
REGION_ALIAS("FLASH", flash0)
REGION_ALIAS("RAM", ram0)
ENTRY(_start)
INCLUDE sections.ld
