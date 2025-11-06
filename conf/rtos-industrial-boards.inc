# Copyright 2025 NXP

# board name
RTOS_INDUSTRIAL_BOARD ?= ""
RTOS_INDUSTRIAL_BOARD:mx8mm-nxp-bsp = "evkmimx8mm"
# RTOS_INDUSTRIAL_BOARD:mx8mn-nxp-bsp = "evkmimx8mn"
RTOS_INDUSTRIAL_BOARD:mx8mp-nxp-bsp = "evkmimx8mp"
# RTOS_INDUSTRIAL_BOARD:mx8mq-nxp-bsp = "evkmimx8mq"
RTOS_INDUSTRIAL_BOARD:imx93evk = "mcimx93evk"
RTOS_INDUSTRIAL_BOARD:imx93-9x9-lpddr4-qsb = "mcimx93qsb"
RTOS_INDUSTRIAL_BOARD:imx93-14x14-lpddr4x-evk = "mcimx93autoevk"
RTOS_INDUSTRIAL_BOARD:imx95-15x15-lpddr4x-evk = "imx95lp4xevk15"
RTOS_INDUSTRIAL_BOARD:imx95-19x19-lpddr5-evk = "imx95lpd5evk19"
RTOS_INDUSTRIAL_BOARD:imx91-9x9-lpddr4-qsb = "mcimx91qsb"
RTOS_INDUSTRIAL_BOARD:imx91-11x11-lpddr4-evk = "mcimx91evk"
RTOS_INDUSTRIAL_BOARD:mx943-nxp-bsp = "imx943evk"

# Core types
RTOS_ACORE_TYPE ?= ""
RTOS_ACORE_TYPE:mx8mm-nxp-bsp = "ca53"
RTOS_ACORE_TYPE:mx8mp-nxp-bsp = "ca53"
RTOS_ACORE_TYPE:mx91-nxp-bsp = "ca55"
RTOS_ACORE_TYPE:mx93-nxp-bsp = "ca55"
RTOS_ACORE_TYPE:mx943-nxp-bsp = "ca55"
RTOS_ACORE_TYPE:mx95-nxp-bsp = "ca55"

RTOS_MCORE_TYPE ?= ""
RTOS_MCORE_TYPE:mx8mm-nxp-bsp = "cm4"
RTOS_MCORE_TYPE:mx8mn-nxp-bsp = "cm7"
RTOS_MCORE_TYPE:mx8mp-nxp-bsp = "cm7"
RTOS_MCORE_TYPE:mx93-nxp-bsp = "cm33"
RTOS_MCORE_TYPE:mx95-nxp-bsp = "cm7"
RTOS_MCORE_TYPE:mx943-nxp-bsp = "cm33_core1 cm7_core0 cm7_core1"