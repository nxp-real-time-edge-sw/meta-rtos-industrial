# Copyright 2022-2023 NXP

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/Apache-2.0;md5=89aea4e17d99a7cacdbeed46a0096b10"

# This file might be included from other places (like other layers) and not
# having an explicit path to the patches directory, will make bitbake fail to
# find the patch(es) in SRC_URI.
FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRCREV_FORMAT = "mcux-sdk"

SRC_URI = "\
    ${MCUX_SDK_SRC};destsuffix=git/core;name=mcux-sdk \
    ${MCUX_SDK_EXAMPLES_SRC};destsuffix=git/examples;name=mcux-sdk-examples \
    ${CMSIS_SRC};destsuffix=git/core/CMSIS;name=CMSIS \
    ${FREERTOS_KERNEL_SRC};destsuffix=git/rtos/freertos/freertos_kernel;name=FreeRTOS-Kernel \
    ${MCUX_SDK_MIDDLEWARE_MULTICORE_SRC};destsuffix=git/middleware/multicore;name=mcux-sdk-middleware-multicore \
    ${RPMSG_LITE_SRC};destsuffix=git/middleware/multicore/rpmsg_lite;name=rpmsg-lite \
    ${SOEM_SRC};destsuffix=git/core/components/SOEM;name=SOEM \
    git://${NXPMICRO_BASE}/mcux-sdk-middleware-sdmmc.git;protocol=https;nobranch=1;destsuffix=git/middleware/sdmmc;name=mcux-sdk-middleware-sdmmc \
    git://github.com/EmbeddedRPC/erpc;protocol=https;nobranch=1;destsuffix=git/middleware/multicore/erpc;name=erpc \
    git://${NXPMICRO_BASE}/mcux-soc-svd.git;protocol=https;nobranch=1;destsuffix=git/svd;name=mcux-soc-svd \
    git://${NXPMICRO_BASE}/fatfs.git;protocol=https;nobranch=1;destsuffix=git/middleware/fatfs;name=fatfs \
    git://${NXPMICRO_BASE}/mcux-sdk-middleware-eiq.git;protocol=https;nobranch=1;destsuffix=git/middleware/eiq;name=mcux-sdk-middleware-eiq \
    git://${NXPMICRO_BASE}/mcux-sdk-middleware-deepviewrt.git;protocol=https;nobranch=1;destsuffix=git/middleware/eiq/deepviewrt;name=mcux-sdk-middleware-deepviewrt \
    git://${NXPMICRO_BASE}/mcux-sdk-middleware-glow.git;protocol=https;nobranch=1;destsuffix=git/middleware/eiq/glow;name=mcux-sdk-middleware-glow \
    git://${NXPMICRO_BASE}/mcux-sdk-middleware-tensorflow.git;protocol=https;nobranch=1;destsuffix=git/middleware/eiq/tensorflow-lite;name=mcux-sdk-middleware-tensorflow \
    git://${NXPMICRO_BASE}/mcux-sdk-middleware-usb.git;protocol=https;nobranch=1;destsuffix=git/middleware/usb;name=mcux-sdk-middleware-usb \
    git://${NXPMICRO_BASE}/mcux-sdk-middleware-edgefast-bluetooth.git;protocol=https;nobranch=1;destsuffix=git/middleware/edgefase_bluetooth;name=mcux-sdk-middleware-edgefast-bluetooth \
    git://${NXP_BASE}/mcux-sdk-middleware-ethermind.git;protocol=https;nobranch=1;destsuffix=git/middleware/wireless/ethermind;name=mcux-sdk-middleware-ethermind \
    git://${NXP_BASE}/azure-rtos.git;protocol=https;nobranch=1;destsuffix=git/rtos/azure-rtos;name=azure-rtos \
    git://${NXP_BASE}/threadx.git;protocol=https;nobranch=1;destsuffix=git/rtos/azure-rtos/threadx;name=threadx \
    git://${NXP_BASE}/filex.git;protocol=https;nobranch=1;destsuffix=git/rtos/azure-rtos/filex;name=filex \
    git://${NXP_BASE}/levelx.git;protocol=https;nobranch=1;destsuffix=git/rtos/azure-rtos/levelx;name=levelx \
    git://${NXP_BASE}/netxduo.git;protocol=https;nobranch=1;destsuffix=git/rtos/azure-rtos/netduo;name=netxduo \
    git://${NXP_BASE}/usbx.git;protocol=https;nobranch=1;destsuffix=git/rtos/azure-rtos/usbx;name=usbx \
    git://${NXP_BASE}/guix.git;protocol=https;nobranch=1;destsuffix=git/rtos/azure-rtos/guix;name=guix \
    git://${NXPMICRO_BASE}/mbedtls.git;protocol=https;nobranch=1;destsuffix=git/middleware/mbedtls;name=mbedtls \
    git://${NXP_BASE}/wifi_nxp.git;protocol=https;nobranch=1;destsuffix=git/middleware/wifi_nxp;name=wifi-nxp \
    git://${NXPMICRO_BASE}/lwip.git;protocol=https;nobranch=1;destsuffix=git/middleware/lwip;name=lwip \
    git://${NXPMICRO_BASE}/littlefs.git;protocol=https;nobranch=1;destsuffix=git/middleware/littlefs;name=littlefs \
    git://${NXPMICRO_BASE}/maestro.git;protocol=https;nobranch=1;destsuffix=git/middleware/maestro;name=maestro \
    git://${NXP_ZEPHYR_BASE}/mcuboot.git;protocol=https;nobranch=1;destsuffix=git/middleware/mcuboot_opensource;name=mcuboot \
    git://${NXPMICRO_BASE}/EAP.git;protocol=https;nobranch=1;destsuffix=git/middleware/EAP;name=EAP \
    git://${NXPMICRO_BASE}/vit.git;protocol=https;nobranch=1;destsuffix=git/middleware/vit;name=vit \
    git://${NXPMICRO_BASE}/VoiceSeeker.git;protocol=https;nobranch=1;destsuffix=git/middleware/voice_seeker;name=VoiceSeeker \
"

S = "${WORKDIR}/git"

# Default to a stable version
PREFERRED_VERSION_MCUX-SDK ??= "2.13.1"
require mcux-sdk-src-${PREFERRED_VERSION_MCUX-SDK}.inc

PACKAGES = "${PN}"
