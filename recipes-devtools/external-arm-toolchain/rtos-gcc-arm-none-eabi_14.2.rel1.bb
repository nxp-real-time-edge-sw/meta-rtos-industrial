# Copyright 2024-2025 NXP

require arm-binary-toolchain.inc

SUMMARY = "Baremetal GCC for ARM-R and ARM-M processors"
LICENSE = "GPL-3.0-with-GCC-exception & GPLv3"

LIC_FILES_CHKSUM:aarch64 = "file://share/doc/gcc/Copying.html;md5=402090210d41f07263e91f760d0d1ea3"
LIC_FILES_CHKSUM:x86-64 = "file://share/doc/gcc/Copying.html;md5=b58b1e79cb685387c684bf647c848b82"

PROVIDES = "rtos-gcc-arm-none-eabi"

SRC_URI = "https://developer.arm.com/-/media/Files/downloads/gnu/${PV}/binrel/arm-gnu-toolchain-${PV}-${HOST_ARCH}-${BINNAME}.tar.xz;name=gcc-${HOST_ARCH}"
SRC_URI[gcc-aarch64.sha256sum] = "87330bab085dd8749d4ed0ad633674b9dc48b237b61069e3b481abd364d0a684"
SRC_URI[gcc-x86_64.sha256sum] = "62a63b981fe391a9cbad7ef51b17e49aeaa3e7b0d029b36ca1e9c3b2a9b78823"

S = "${WORKDIR}/arm-gnu-toolchain-${PV}-${HOST_ARCH}-${BINNAME}"

UPSTREAM_CHECK_URI = "https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/downloads"
UPSTREAM_CHECK_REGEX = "${BPN}-(?P<pver>.+)-${HOST_ARCH}-linux\.tar\.\w+"
