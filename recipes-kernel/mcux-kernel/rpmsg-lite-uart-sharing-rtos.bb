# Copyright 2022 NXP

include mcux-example.inc

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
    file://0001-add-srtm-uart-service.patch;patchdir=core \
    file://0001-move-structure-to-header-files-for-rpmsg_lite.patch;patchdir=middleware/multicore/rpmsg_lite \
    file://0001-add-demo-rpmsg_lite_uart_sharing_rtos.patch;patchdir=examples \
"

MCUX_EXAMPLE_DIR = "examples/${RTOS-INDUSTRIAL-BOARD}/multicore_examples/rpmsg_lite_uart_sharing_rtos"