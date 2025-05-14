# Copyright 2024-2025 NXP

require hmc-common.inc
require mcux-sdk-src.inc
require hmc.inc

inherit deploy
inherit python3native

do_configure[noexec] = "1"
# do_rootfs[noexec] = "1"
# do_package[noexec] = "1"
do_package_qa[noexec] = "1"
# do_packagedata[noexec] = "1"
# do_package_write_ipk[noexec] = "1"
# do_package_write_deb[noexec] = "1"
# do_package_write_rpm[noexec] = "1"

INHIBIT_DEFAULT_DEPS = "1"
# INHIBIT_SYSROOT_STRIP = "1"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"

DEPENDS = "rtos-gcc-aarch64-none-elf-native"
ARMGCC_DIR ?= "${WORKDIR}/recipe-sysroot-native${libexecdir}/rtos-gcc-aarch64-none-elf"

EXAMPLE_ARMGCC_DIR = "${S}/${HMC_EXAMPLE_DIR}/armgcc_aarch64"

EXAMPLE_INSTALL_DIR = "examples/heterogeneous-multicore"

do_compile() {
    export ARMGCC_DIR="${ARMGCC_DIR}"
    export Zephyr_DIR="${S}/zephyr"
    echo "Start to compile example with ${ARMGCC_DIR}"
    cd ${EXAMPLE_ARMGCC_DIR}

    chmod u+x *.sh
    ./clean.sh

    # build
    ./build_release.sh
}

FILES:${PN} += "/examples/*"

do_install () {
    install -d ${D}/${EXAMPLE_INSTALL_DIR}/${PN}

    for type in ${EXAMPLE_TYPES}; do
        cp ${EXAMPLE_ARMGCC_DIR}/${BUILD_DIR}/${BIN_NAME}.${type}  ${D}/${EXAMPLE_INSTALL_DIR}/${PN}
    done
}

do_deploy () {
    install -d ${DEPLOYDIR}/${EXAMPLE_INSTALL_DIR}/${PN}

    for type in ${EXAMPLE_TYPES}; do
        cp ${EXAMPLE_ARMGCC_DIR}/${BUILD_DIR}/${BIN_NAME}.${type}  ${DEPLOYDIR}/${EXAMPLE_INSTALL_DIR}/${PN}
    done
}

addtask deploy after do_compile

DEPENDS += "python3-packaging-native"
DEPENDS += "python3-pyelftools-native"
DEPENDS += "python3-pykwalify-native"
DEPENDS += "python3-pyyaml-native"
