# Copyright 2024 NXP

include hmc-example-aarch64-zephyr.inc

HMC_EXAMPLE_DIR = "heterogeneous-multicore/apps/rt_latency/zephyr/boards/${RTOS-INDUSTRIAL-BOARD-CA}"

BUILD_DIR = "build/zephyr/"
BIN_NAME = "rt_latency_*"
