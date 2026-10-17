/* SPDX-License-Identifier: MPL-2.0
 * SPDX-FileCopyrightText: 2026 Thomas Legrand
 *
 * Linker script for STM32H563xI (2 MB flash, 640 KB SRAM), single image at the start of flash.
 * No heap: dynamic allocation traps (see startup.cpp). The main stack sits at the top of SRAM
 * and its bottom is enforced in hardware through MSPLIM.
 */

ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 2048K
    RAM   (rw)  : ORIGIN = 0x20000000, LENGTH = 640K
}

/* Explicit segments: flash is read + execute only, RAM is read + write only. */
PHDRS
{
    text PT_LOAD FLAGS(5);
    data PT_LOAD FLAGS(6);
    bss  PT_LOAD FLAGS(6);
}

STACK_SIZE = DEFINED(STACK_SIZE) ? STACK_SIZE : 0x400;

_estack = ORIGIN(RAM) + LENGTH(RAM);
_sstack = _estack - STACK_SIZE;

SECTIONS
{
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector))
        . = ALIGN(4);
    } > FLASH :text

    .text :
    {
        . = ALIGN(4);
        *(.text .text.*)
        *(.glue_7) *(.glue_7t)
        *(.eh_frame)
        KEEP(*(.init))
        KEEP(*(.fini))
        . = ALIGN(4);
    } > FLASH :text

    .rodata :
    {
        . = ALIGN(4);
        *(.rodata .rodata.*)
        . = ALIGN(4);
    } > FLASH :text

    .ARM.extab : { *(.ARM.extab* .gnu.linkonce.armextab.*) } > FLASH :text
    .ARM.exidx : { *(.ARM.exidx* .gnu.linkonce.armexidx.*) } > FLASH :text

    .preinit_array :
    {
        PROVIDE_HIDDEN(__preinit_array_start = .);
        KEEP(*(.preinit_array*))
        PROVIDE_HIDDEN(__preinit_array_end = .);
    } > FLASH :text

    .init_array :
    {
        PROVIDE_HIDDEN(__init_array_start = .);
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array*))
        PROVIDE_HIDDEN(__init_array_end = .);
    } > FLASH :text

    .fini_array :
    {
        PROVIDE_HIDDEN(__fini_array_start = .);
        KEEP(*(SORT(.fini_array.*)))
        KEEP(*(.fini_array*))
        PROVIDE_HIDDEN(__fini_array_end = .);
    } > FLASH :text

    _sidata = LOADADDR(.data);

    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data .data.*)
        . = ALIGN(4);
        _edata = .;
    } > RAM AT > FLASH :data

    .bss (NOLOAD) :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss .bss.*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;
    } > RAM :bss

    ASSERT(_ebss <= _sstack, "RAM overflow: .data + .bss collide with the main stack")

    .ARM.attributes 0 : { *(.ARM.attributes) }
}
