# Copyright 2023 NXP

include hmc-example-aarch64.inc

# TODO: add evkmimx8mm_ca53.conf in conf/machine?
HMC_EXAMPLE_DIR = "heterogeneous-multicore/apps/virtio_net_backend/freertos/boards/${RTOS-INDUSTRIAL-BOARD}_ca53"
