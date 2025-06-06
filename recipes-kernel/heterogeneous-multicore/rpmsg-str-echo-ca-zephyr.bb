# Copyright 2025 NXP

include hmc-example-aarch64-zephyr.inc

HMC_EXAMPLE_DIR = "heterogeneous-multicore/apps/rpmsg_str_echo/zephyr/boards/${RTOS-INDUSTRIAL-BOARD-CA}"

BUILD_DIR = "build_*/zephyr/"
BIN_NAME = "rpmsg_str_echo_*"
