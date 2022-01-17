# Copyright 2022 NXP

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

# This file might be included from other places (like other layers) and not
# having an explicit path to the patches directory, will make bitbake fail to
# find the patch(es) in SRC_URI.
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

NXPMICRO_BASE = "github.com/NXPmicro"

SRCREV_FORMAT = "mcux-sdk"

SRC_URI = "\
    git://${NXPMICRO_BASE}/mcux-sdk.git;protocol=https;nobranch=1;destsuffix=git/core;name=mcux-sdk \
    git://${NXPMICRO_BASE}/mcux-sdk-examples.git;protocol=https;nobranch=1;destsuffix=git/examples;name=mcux-sdk-examples \
    git://${NXPMICRO_BASE}/FreeRTOS-Kernel.git;protocol=https;nobranch=1;destsuffix=git/rtos/freertos/freertos_kernel;name=FreeRTOS-Kernel \
    git://${NXPMICRO_BASE}/mcux-sdk-middleware-sdmmc.git;protocol=https;nobranch=1;destsuffix=git/middleware/sdmmc;name=mcux-sdk-middleware-sdmmc \
    git://${NXPMICRO_BASE}/mcux-sdk-middleware-multicore.git;protocol=https;nobranch=1;destsuffix=git/middleware/multicore;name=mcux-sdk-middleware-multicore \
    git://${NXPMICRO_BASE}/rpmsg-lite.git;protocol=https;nobranch=1;destsuffix=git/middleware/multicore/rpmsg_lite;name=rpmsg-lite \
    git://github.com/EmbeddedRPC/erpc;protocol=https;nobranch=1;destsuffix=git/middleware/multicore/erpc;name=erpc \
    git://${NXPMICRO_BASE}/mcux-soc-svd.git;protocol=https;nobranch=1;destsuffix=git/svd;name=mcux-soc-svd \
    git://bitbucket.sw.nxp.com/dnind/soem.git;protocol=ssh;nobranch=1;destsuffix=git/core/components/SOEM;name=SOEM \
    "

S = "${WORKDIR}/git"

# Default to a stable version
PREFERRED_VERSION_MCUX-SDK ??= "2.10.0"
require mcux-sdk-src-${PREFERRED_VERSION_MCUX-SDK}.inc

PACKAGES = "${PN}"
