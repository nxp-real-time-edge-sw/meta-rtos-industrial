# Copyright 2024 NXP

include hmc-example-aarch64-zephyr.inc

HMC_EXAMPLE_DIR = "heterogeneous-multicore/apps/hello_world/zephyr/boards/${RTOS-INDUSTRIAL-BOARD-CA}"

BUILD_DIR = "build_*/zephyr/"
BIN_NAME = "hello_world_*"
