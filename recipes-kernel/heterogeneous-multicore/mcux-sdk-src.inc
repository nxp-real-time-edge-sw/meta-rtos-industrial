# Copyright 2022-2024 NXP

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
    ${LWIP_SRC};destsuffix=git/middleware/lwip;name=lwip \
    ${SOEM_SRC};destsuffix=git/middleware/soem;name=soem \
    ${MCUX_SDK_MIDDLEWARE_MULTICORE_SRC};destsuffix=git/middleware/multicore;name=mcux-sdk-middleware-multicore \
    ${RPMSG_LITE_SRC};destsuffix=git/middleware/multicore/rpmsg_lite;name=rpmsg-lite \
    ${ZEPHYR_SRC};destsuffix=git/zephyr;name=zephyr \
    ${HAL_NXP_SRC};destsuffix=git/modules/hal/nxp;name=hal-nxp \
    ${OPEN_AMP_SRC};destsuffix=git/modules/lib/open-amp;name=open-amp \
    ${LIBMETAL_SRC};destsuffix=git/modules/hal/libmetal;name=libmetal \
"

SRCREV_mcux-sdk = "${MCUX_SDK_SRCREV}"
SRCREV_CMSIS = "${CMSIS_SRCREV}"
SRCREV_FreeRTOS-Kernel = "${FREERTOS_KERNEL_SRCREV}"
SRCREV_rpmsg-lite = "${RPMSG_LITE_SRCREV}"
SRCREV_lwip = "${LWIP_SRCREV}"
SRCREV_soem = "${SOEM_SRCREV}"
SRCREV_mcux-sdk-middleware-multicore = "${MCUX_SDK_MIDDLEWARE_MULTICORE_SRCREV}"
SRCREV_zephyr = "${ZEPHYR_SRCREV}"
SRCREV_hal-nxp = "${HAL_NXP_SRCREV}"
SRCREV_open-amp = "${OPEN_AMP_SRCREV}"
SRCREV_libmetal = "${LIBMETAL_SRCREV}"

S = "${WORKDIR}/git"

PACKAGES = "${PN}"
