# Copyright 2022 NXP

include mcux-example.inc
include mcux-sdk-soem.inc

MCUX_EXAMPLE_DIR = "examples/${RTOS-INDUSTRIAL-BOARD}/demo_apps/soem_gpio_pulse"

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
    file://0001-SOEM-add-soem_gpio_pulse-example-to-evkmimx8mp-platf.patch;patchdir=examples \
    file://0001-SOEM-add-soem_gpio_pulse-example-to-evkmimx8mm-platf.patch;patchdir=examples \
"
