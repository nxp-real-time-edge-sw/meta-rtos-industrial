# Copyright 2022 NXP

include mcux-example.inc
include mcux-sdk-soem.inc

MCUX_EXAMPLE_DIR = "examples/${RTOS-INDUSTRIAL-BOARD}/rtos_examples/freertos_soem_gpio_pulse"

FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
    file://0001-SOEM-add-freertos_soem_gpio_pulse-example-to-evkmimx.patch;patchdir=examples \
    file://0002-SOEM-add-freertos_soem_gpio_pulse-example-to-evkmimx.patch;patchdir=examples \
    file://0001-SOEM-Remalloc-netc-buf-to-non-cached-partition.patch;patchdir=examples \
"
