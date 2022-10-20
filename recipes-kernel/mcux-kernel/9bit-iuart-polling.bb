# Copyright 2022 NXP

include mcux-example.inc

MCUX_EXAMPLE_DIR = "examples/${RTOS-INDUSTRIAL-BOARD}/driver_examples/uart/9bit_polling/"

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
    file://0001-iuart-Add-9bit-support.patch;patchdir=core \
    file://0001-Uart-Add-9bit_iuart_polling-example.patch;patchdir=examples \
"
