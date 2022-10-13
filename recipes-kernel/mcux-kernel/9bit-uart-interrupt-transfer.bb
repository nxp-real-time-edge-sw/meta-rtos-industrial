# Copyright 2022 NXP

include mcux-example.inc

MCUX_EXAMPLE_DIR = "examples/${RTOS-INDUSTRIAL-BOARD}/driver_examples/uart/9bit_interrupt_transfer/"

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
    file://0001-iuart-Add-9bit-support.patch;patchdir=core \
    file://0001-Uart-Add-9bit_uart_interrupt_transfer-example.patch;patchdir=examples \
"
