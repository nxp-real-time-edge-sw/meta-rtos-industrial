# Copyright 2022 NXP

include mcux-example.inc

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
    file://0001-rpmsg-lite-imx8mm-increase-vring-size-to-support-tot.patch;patchdir=middleware/multicore/rpmsg_lite \
    file://0001-imx8mmevk-str-echo-increase-rpmsg-buffer-to-8MB.patch;patchdir=examples \
"
MCUX_EXAMPLE_DIR = "examples/${RTOS-INDUSTRIAL-BOARD}/multicore_examples/rpmsg_lite_str_echo_rtos"
