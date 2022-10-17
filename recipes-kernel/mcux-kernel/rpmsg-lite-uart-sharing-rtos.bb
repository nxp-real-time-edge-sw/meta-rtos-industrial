# Copyright 2022 NXP

include mcux-example.inc

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
    file://0001-add-srtm-uart-service.patch;patchdir=core \
    file://0001-add-demo-rpmsg_lite_uart_sharing_rtos.patch;patchdir=examples \
"

MCUX_EXAMPLE_DIR = "examples/${RTOS-INDUSTRIAL-BOARD}/multicore_examples/rpmsg_lite_uart_sharing_rtos"