# Copyright 2025 NXP
# SPDX-License-Identifier: Apache-2.0

SUMMARY = "Zephyr RTOS Project meta-tool"
HOMEPAGE = "https://github.com/zephyrproject-rtos/west"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=e3fc50a88d0a364313df4b21ef20c29e"

SRC_URI = "git://github.com/zephyrproject-rtos/west;protocol=https;branch=v1.5-branch"

PV = "v1.5.0"
SRCREV = "f0e657721f2e215470274d6f8c0464fa73fc9caf"

PROVIDES = "virtual/west"

S = "${WORKDIR}/git"

inherit python_setuptools_build_meta  python3native

DEPENDS += "\
    python3-native \
    python3-pip-native \
    python3-setuptools-native \
    python3-wheel-native \
"

RDEPENDS:${PN} = "\
    python3-core \
    python3-pyyaml \
    python3-pykwalify \
    python3-packaging \
    python3-pyparsing \
    python3-colorama \
"

BBCLASSEXTEND = "native nativesdk"

TOOLCHAIN_HOST_TASK:append = " nativesdk-west"

FILES:${PN} += "\
    ${bindir}/west \
    ${PYTHON_SITEPACKAGES_DIR}/west \
    ${PYTHON_SITEPACKAGES_DIR}/west-*.egg-info \
"
