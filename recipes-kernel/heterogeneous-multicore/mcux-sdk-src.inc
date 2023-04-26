# Copyright 2022-2023 NXP

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

# This file might be included from other places (like other layers) and not
# having an explicit path to the patches directory, will make bitbake fail to
# find the patch(es) in SRC_URI.
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRCREV_FORMAT = "mcux-sdk"

SRC_URI = " \
    ${MCUX_SDK_SRC};destsuffix=git/mcux-sdk;name=mcux-sdk \
    ${CMSIS_SRC};destsuffix=git/mcux-sdk/CMSIS;name=CMSIS \
    ${FREERTOS_KERNEL_SRC};destsuffix=git/FreeRTOS-Kernel;name=FreeRTOS-Kernel \
"

SRCREV_mcux-sdk = "${AUTOREV}"
SRCREV_CMSIS = "${AUTOREV}"
SRCREV_FreeRTOS-Kernel = "${AUTOREV}"

S = "${WORKDIR}/git"

PACKAGES = "${PN}"
