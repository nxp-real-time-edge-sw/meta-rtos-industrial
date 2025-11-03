# Copyright 2025 NXP

SUMMARY = "MCUX SDK Application"

include recipes-mcuxsdk/includes/mcuxsdk-version.inc

inherit mcuxsdk-source-shared
inherit west deploy

PACKAGE_ARCH = "${MACHINE_ARCH}"

do_package_qa[noexec] = "1"

B = "${WORKDIR}/build"

# Toolchain
MCUXSDK_ARMGCC ?= "rtos-gcc-arm-none-eabi"
MCUXSDK_ARMGCC_DIR ?= "${WORKDIR}/recipe-sysroot-native${libexecdir}/${MCUXSDK_ARMGCC}"

MCUXSDK_DIR ?= "${S}/mcuxsdk"
MCUXSDK_BUILD_DIR ?= "${B}"

MCUXSDK_EXAMPLE_NAME ?= ""
MCUXSDK_EXAMPLE_DIR ?= ""
MCUXSDK_EXAMPLE_BIN_TYPE ?= "elf bin"
MCUXSDK_EXAMPLE_INSTALL_DIR ?= "examples/mcuxsdk"
MCUXSDK_EXAMPLE_TARGET ?= "release"

MCUXSDK_BOARD_NAME ?= "${RTOS_INDUSTRIAL_BOARD}"

MCUXSDK_CORE_IDS ?= "${RTOS_MCORE_TYPE}"
MCUXSDK_TOOLCHAIN ?="armgcc"

DEPENDS:append = " \
    ${MCUXSDK_ARMGCC}-native \
"

python () {
    d.delVar('CFLAGS')
    d.delVar('CXXFLAGS')
    d.delVar('LDFLAGS')
}

do_compile() {
    export ARMGCC_DIR="${MCUXSDK_ARMGCC_DIR}"

    cd ${MCUXSDK_DIR}

    if [ -z "${MCUXSDK_EXAMPLE_NAME}" ]; then
        bbfatal "MCUXSDK_EXAMPLE_NAME is not defined"
    fi

    if [ -z "${MCUXSDK_EXAMPLE_DIR}" ]; then
        bbfatal "MCUXSDK_EXAMPLE_DIR is not defined"
    fi

    for core_id in ${MCUXSDK_CORE_IDS}; do
        MCUX_EXAMPLE_BIN_NAME="${MCUXSDK_EXAMPLE_NAME}_${core_id}"
        BUILD_DIR="${MCUXSDK_BUILD_DIR}/${MCUX_EXAMPLE_BIN_NAME}"

        bbnote "========================================="
        bbnote "Building ${MCUX_EXAMPLE_BIN_NAME}"
        bbnote "========================================="
        bbnote "Application: ${MCUXSDK_EXAMPLE_NAME}"
        bbnote "Board: ${MCUXSDK_BOARD_NAME}"
        bbnote "Build Dir: ${MCUXSDK_EXAMPLE_DIR}"
        bbnote "Config: ${MCUXSDK_EXAMPLE_TARGET}"
        bbnote "Toolchain: ${MCUXSDK_TOOLCHAIN}"

        WEST_CMD="west build ${MCUXSDK_EXAMPLE_DIR} \
            -p always \
            -b ${MCUXSDK_BOARD_NAME} \
            -d ${BUILD_DIR} \
            --config ${MCUXSDK_EXAMPLE_TARGET} \
            --toolchain ${MCUXSDK_TOOLCHAIN} \
            -Dcore_id=${core_id} \
        "

        bbnote "Executing command:"
        bbnote "${WEST_CMD}"

        if ! eval ${WEST_CMD}; then
            bbfatal "west build failed for core_id=${core_id}"
        fi

        bbnote "Successfully built for core_id=${core_id}"

    done
}

FILES:${PN} += "/${MCUXSDK_EXAMPLE_INSTALL_DIR}/${PN}/*"

do_install() {
    if [ -d "${MCUXSDK_BUILD_DIR}" ]; then
        install -d ${D}/${MCUXSDK_EXAMPLE_INSTALL_DIR}/${PN}

        cd ${MCUXSDK_BUILD_DIR}

        for file in $(find . \( -name "${MCUXSDK_EXAMPLE_NAME}_*.elf" -o -name "${MCUXSDK_EXAMPLE_NAME}_*.bin" \)); do
            install -m 0644 "$file" ${D}/${MCUXSDK_EXAMPLE_INSTALL_DIR}/${PN}/
        done
    fi
}

do_deploy () {
    if [ -d "${MCUXSDK_BUILD_DIR}" ]; then
        install -d ${DEPLOYDIR}/${MCUXSDK_EXAMPLE_INSTALL_DIR}/${PN}

        cd ${MCUXSDK_BUILD_DIR}

        for file in $(find . \( -name "${MCUXSDK_EXAMPLE_NAME}_*.elf" -o -name "${MCUXSDK_EXAMPLE_NAME}_*.bin" \)); do
            install -m 0644 "$file" ${DEPLOYDIR}/${MCUXSDK_EXAMPLE_INSTALL_DIR}/${PN}/
        done
    fi
}

addtask deploy after do_compile
