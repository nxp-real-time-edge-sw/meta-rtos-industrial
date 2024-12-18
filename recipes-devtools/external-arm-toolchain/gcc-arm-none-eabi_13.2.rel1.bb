# Copyright 2024 NXP

require arm-binary-toolchain.inc

SUMMARY = "Baremetal GCC for ARM-R and ARM-M processors"
LICENSE = "GPL-3.0-with-GCC-exception & GPLv3"

LIC_FILES_CHKSUM:aarch64 = "file://share/doc/gcc/Copying.html;md5=402090210d41f07263e91f760d0d1ea3"
LIC_FILES_CHKSUM:x86-64 = "file://share/doc/gcc/Copying.html;md5=2a62a4d37ddad55da732679acd9edf03"

PROVIDES = "virtual/arm-none-eabi-gcc"

SRC_URI = "https://developer.arm.com/-/media/Files/downloads/gnu/${PV}/binrel/arm-gnu-toolchain-${PV}-${HOST_ARCH}-${BINNAME}.tar.xz;name=gcc-${HOST_ARCH}"
SRC_URI[gcc-aarch64.sha256sum] = "8fd8b4a0a8d44ab2e195ccfbeef42223dfb3ede29d80f14dcf2183c34b8d199a"
SRC_URI[gcc-x86_64.sha256sum] = "6cd1bbc1d9ae57312bcd169ae283153a9572bd6a8e4eeae2fedfbc33b115fdbb"

# The decompressed toolchain version string is changed to capitalized "Rel1"
S = "${WORKDIR}/arm-gnu-toolchain-13.2.Rel1-${HOST_ARCH}-${BINNAME}"

UPSTREAM_CHECK_URI = "https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/downloads"
UPSTREAM_CHECK_REGEX = "${BPN}-(?P<pver>.+)-${HOST_ARCH}-linux\.tar\.\w+"
