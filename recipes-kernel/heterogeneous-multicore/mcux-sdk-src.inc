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

SRCREV_mcux-sdk = "6f07efa02e9a449e98971e032ec8a480c693a17c"
SRCREV_CMSIS = "43707031e8a26930a14b4c63be877d30661b3d82"
SRCREV_FreeRTOS-Kernel = "2236f887ee773c267515b17d023c77e305efb0f1"

S = "${WORKDIR}/git"

PACKAGES = "${PN}"
