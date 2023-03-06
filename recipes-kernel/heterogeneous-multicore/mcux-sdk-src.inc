# Copyright 2022-2023 NXP

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

# This file might be included from other places (like other layers) and not
# having an explicit path to the patches directory, will make bitbake fail to
# find the patch(es) in SRC_URI.
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

DNIND_BASE = "git@bitbucket.sw.nxp.com/dnind"
NXPMICRO_BASE = "github.com/NXPmicro"
MCUX_SDK_BRANCH = "feature/heterogeneous_multicore"
FREERTOS_BRANCH = "feature/aarch64_support"

SRCREV_FORMAT = "mcux-sdk"

SRC_URI = "\
    git://${DNIND_BASE}/mcux-sdk.git;protocol=ssh;branch=${MCUX_SDK_BRANCH};destsuffix=git/mcux-sdk;name=mcux-sdk \
    git://${DNIND_BASE}/FreeRTOS-Kernel.git;protocol=ssh;branch=${FREERTOS_BRANCH};destsuffix=git/FreeRTOS-Kernel;name=FreeRTOS-Kernel \
    "

S = "${WORKDIR}/git"

# Default to a stable version
PREFERRED_VERSION_MCUX-SDK ??= "2.12.0"
require mcux-sdk-src-${PREFERRED_VERSION_MCUX-SDK}.inc

PACKAGES = "${PN}"
