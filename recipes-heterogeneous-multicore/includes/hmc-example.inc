# Copyright 2025 NXP

SUMMARY = "HMS Application"

require recipes-heterogeneous-multicore/includes/hmc-version.inc

inherit hmc-source-shared
inherit deploy

PACKAGE_ARCH = "${MACHINE_ARCH}"

do_package_qa[noexec] = "1"

# Toolchain
HMC_ARMGCC ?= "rtos-gcc-arm-none-eabi"
HMC_ARMGCC_DIR ?= "${WORKDIR}/recipe-sysroot-native${libexecdir}/${HMC_ARMGCC}"

HMC_ARMGCC_AARCH64 ?= "rtos-gcc-aarch64-none-elf"
HMC_ARMGCC_AARCH64_DIR ?= "${WORKDIR}/recipe-sysroot-native${libexecdir}/${HMC_ARMGCC_AARCH64}"

HMC_RTOS_TYPE ?= "freertos zephyr"

RTOS_ACORE_TYPE ?= ""
RTOS_MCORE_TYPE ?= ""
HMC_RTOS_CORE_TYPE ?= "${RTOS_ACORE_TYPE} ${RTOS_MCORE_TYPE}"

HMC_EXAMPLE_TARGET_TYPE ?= "release ddr_release"

HMC_EXAMPLE_NAME ?= "${PN}"

HMC_EXAMPLE_DIR ?= "${S}/heterogeneous-multicore/apps/${HMC_EXAMPLE_NAME}"
HMC_EXAMPLE_INSTALL_DIR ?= "examples/heterogeneous-multicore"

DEPENDS += " \
    ${HMC_ARMGCC}-native \
    ${HMC_ARMGCC_AARCH64}-native \
    west-native \
    python3-jsonschema-native \
    python3-pyelftools-native \
    python3-pykwalify-native \
    python3-pyyaml-native \
    dtc-native \
    ninja-native \
    cmake-native \
"

python () {
    d.delVar('CFLAGS')
    d.delVar('CXXFLAGS')
    d.delVar('LDFLAGS')
}

get_build_dir() {
    local rtos=$1
    local core=$2
    local toolchain=""

    case " ${RTOS_MCORE_TYPE} " in
        *" ${core} "*)
            toolchain="armgcc"
            ;;
    esac

    case " ${RTOS_ACORE_TYPE} " in
        *" ${core} "*)
            toolchain="armgcc_aarch64"
            ;;
    esac

    if [ -z "${toolchain}" ]; then
        bbwarn "Core ${core} not found in RTOS_MCORE_TYPE or RTOS_ACORE_TYPE"
        return 1
    fi

    echo "${HMC_EXAMPLE_DIR}/${rtos}/boards/${RTOS_INDUSTRIAL_BOARD}/${core}/${toolchain}"
}

compile_generic() {
    local rtos=$1
    local core=$2

    local build_dir=$(get_build_dir ${rtos} ${core})
    # Check if directory exists
    if [ -d "${build_dir}" ]; then
        cd ${build_dir}
        # Build targets
        for target in ${HMC_EXAMPLE_TARGET_TYPE}; do
            if [ -f "build_${target}.sh" ]; then
                bbnote "Building ${build_dir}"
                # Execute build script and check return value
                ./"build_${target}.sh"
                if [ $? -ne 0 ]; then
                    bbfatal "Failed to build ${HMC_EXAMPLE_NAME}/${core} with target: ${target}"
                fi
                    bbnote "Successfully built ${HMC_EXAMPLE_NAME}/${core} with target: ${target}"
            fi
        done
    else
        bbnote "Directory ${build_dir} does not exist, skipping..."
    fi
}

compile_cm() {
    # set environment for freertos
    export ARMGCC_DIR="${HMC_ARMGCC_DIR}"

    # set environment for zephyr
    export Zephyr_DIR="${S}/zephyr"
    export ZEPHYR_TOOLCHAIN_VARIANT="cross-compile"
    export CROSS_COMPILE="${HMC_ARMGCC_DIR}/bin/arm-none-eabi-"
    export CROSS_COMPILE_TOOLCHAIN_PATH="${HMC_ARMGCC_DIR}"

    # Loop through RTOS types
    for rtos in ${HMC_RTOS_TYPE}; do
        # Loop through core types
       for core in ${RTOS_MCORE_TYPE}; do
            compile_generic ${rtos} ${core}
        done
    done
}

compile_aarch64() {
    # set environment for freertos
    export ARMGCC_DIR="${HMC_ARMGCC_AARCH64_DIR}"

    # set environment for zephyr
    export Zephyr_DIR="${S}/zephyr"

    export ZEPHYR_TOOLCHAIN_VARIANT="cross-compile"
    export CROSS_COMPILE="${HMC_ARMGCC_AARCH64_DIR}/bin/aarch64-none-elf-"
    export CROSS_COMPILE_TOOLCHAIN_PATH="${HMC_ARMGCC_AARCH64_DIR}"

    # Loop through RTOS types
    for rtos in ${HMC_RTOS_TYPE}; do
        # Loop through core types
       for core in ${RTOS_ACORE_TYPE}; do
            compile_generic ${rtos} ${core}
        done
    done
}

do_compile() {
     # Check and compile for Cortex-A cores
    if [ -n "${RTOS_ACORE_TYPE}" ]; then
        compile_aarch64
    fi

    # Check and compile for Cortex-M cores
    if [ -n "${RTOS_MCORE_TYPE}" ]; then
        compile_cm
    fi
}

do_clean() {
    # Loop through RTOS types
    for rtos in ${HMC_RTOS_TYPE}; do
        # Loop through core types
       for core in ${HMC_RTOS_CORE_TYPE}; do
            local build_dir=$(get_build_dir ${rtos} ${core})
            # Check if directory exists
            if [ -d "${build_dir}" ]; then
                cd ${build_dir}
                ./clean.sh
            fi
        done
    done

    # Clean other work directories but not the shared source
    rm -f ${WORKDIR}/temp
    rm -f ${WORKDIR}/pseudo
    rm -rf ${WORKDIR}/image
    rm -rf ${WORKDIR}/deploy-*
    rm -rf ${WORKDIR}/package
    rm -rf ${WORKDIR}/packages-split
    rm -rf ${WORKDIR}/pkgdata
    rm -rf ${WORKDIR}/sstate-install-*
}

FILES:${PN} += " \
    /${HMC_EXAMPLE_INSTALL_DIR}/${PN}-freertos/* \
    /${HMC_EXAMPLE_INSTALL_DIR}/${PN}-zephyr/* \
"

do_install() {
    # Loop through RTOS types
    for rtos in ${HMC_RTOS_TYPE}; do
        # Loop through core types
       for core in ${HMC_RTOS_CORE_TYPE}; do
            local build_dir=$(get_build_dir ${rtos} ${core})
            # Check if directory exists
            bbnote "Installing files for ${rtos} in ${D}/${HMC_EXAMPLE_INSTALL_DIR}/${PN}-${rtos}"
            if [ -d "${build_dir}" ]; then
                install -d ${D}/${HMC_EXAMPLE_INSTALL_DIR}/${PN}-${rtos}

                cd ${build_dir}
                # Find all .elf and .bin files and copy with -L to dereference symlinks
                # find . \( -name "${HMC_EXAMPLE_NAME}_*.elf" -o -name "${HMC_EXAMPLE_NAME}_*.bin" \) -exec cp -L {} ${D}/${HMC_EXAMPLE_INSTALL_DIR}/${PN}-${rtos}/ \;
                for file in $(find . \( -name "${HMC_EXAMPLE_NAME}_*.elf" -o -name "${HMC_EXAMPLE_NAME}_*.bin" \)); do
                    install -m 0644 "$file" ${D}/${HMC_EXAMPLE_INSTALL_DIR}/${PN}-${rtos}/
                done
            fi
        done
    done
}

do_deploy() {
    # Loop through RTOS types
    for rtos in ${HMC_RTOS_TYPE}; do
        # Loop through core types
        for core in ${HMC_RTOS_CORE_TYPE}; do
            local build_dir=$(get_build_dir ${rtos} ${core})   # Check if directory exists
            if [ -d "${build_dir}" ]; then
                install -d ${DEPLOYDIR}/${HMC_EXAMPLE_INSTALL_DIR}/${PN}-${rtos}
                cd ${build_dir}
                # Find all .elf and .bin files and copy with -L to dereference symlinks
                # find . \( -name "${HMC_EXAMPLE_NAME}_*.elf" -o -name "${HMC_EXAMPLE_NAME}_*.bin" \) -exec cp -L {} ${DEPLOYDIR}/${HMC_EXAMPLE_INSTALL_DIR}/${PN}-${rtos}/ \;
                for file in $(find . \( -name "${HMC_EXAMPLE_NAME}_*.elf" -o -name "${HMC_EXAMPLE_NAME}_*.bin" \)); do
                    install -m 0644 "$file" ${DEPLOYDIR}/${HMC_EXAMPLE_INSTALL_DIR}/${PN}-${rtos}/
                done
            fi
        done
    done
}

addtask deploy after do_compile
