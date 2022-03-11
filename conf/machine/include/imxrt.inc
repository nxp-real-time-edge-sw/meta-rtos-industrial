#@TYPE: Machine
#@NAME: iMXRT

#@DESCRIPTION: Machine configuration for NXP Semiconductor iMXRT SoC.

# require conf/machine/include/arm/armv7m/tune-cortexm7.inc
#require conf/machine/include/tune-cortex-m0.inc
require conf/machine/include/tune-cortexm4.inc

MACHINEOVERRIDES =. "imxrt:"

# TUNE_FEATURES = "armv7m cortexm7"
TUNE_FEATURES = "armv7m cortexm4"
# TUNE_FEATURES = "armv6m cortexm0"

ARCH:imxrt = "arm"

# TUNE_ARCH = "arm"
# TARGET_SYS = "arm-none-eabi"
# TARGET_ARCH = "arm"

RTOS-INDUSTRIAL-BOARD ?= "${MACHINE}"

EXAMPLE_TARGET_TYPE ?= " \
    release \
    flexspi_nor_release \
    flexspi_nor_sdram_release \
    sdram_release \
"
