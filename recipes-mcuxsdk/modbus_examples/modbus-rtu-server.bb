# Copyright 2026 NXP

require recipes-mcuxsdk/includes/mcuxsdk-example.inc

MCUXSDK_EXAMPLE_NAME = "modbus_rtu_server"
MCUXSDK_EXAMPLE_DIR = "examples/modbus_examples/rtu/modbus_server"

MCUXSDK_CORE_IDS:mx943-nxp-bsp = "cm33_core1 cm7_core1"
