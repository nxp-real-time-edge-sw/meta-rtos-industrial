# Copyright 2022-2023 NXP

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

# This file might be included from other places (like other layers) and not
# having an explicit path to the patches directory, will make bitbake fail to
# find the patch(es) in SRC_URI.
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

NXPMICRO_BASE = "github.com/nxp-mcuxpresso"

SRCREV_FORMAT = "mcux-sdk"

SRC_URI = "\
    git://${NXPMICRO_BASE}/mcux-sdk.git;protocol=https;nobranch=1;destsuffix=git/mcux-sdk;name=mcux-sdk \
    git://${NXPMICRO_BASE}/FreeRTOS-Kernel.git;protocol=https;nobranch=1;destsuffix=git/FreeRTOS-Kernel;name=FreeRTOS-Kernel \
    "

S = "${WORKDIR}/git"

# Default to a stable version
PREFERRED_VERSION_MCUX-SDK ??= "2.12.0"
require mcux-sdk-src-${PREFERRED_VERSION_MCUX-SDK}.inc

PACKAGES = "${PN}"
