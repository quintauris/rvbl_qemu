INCLUDE memory.GNU.ld
REGION_ALIAS("ROM", rom0)
REGION_ALIAS("FLASH", flash0)
REGION_ALIAS("RAM", ram0)
ENTRY(_start)
INCLUDE sections.ld
