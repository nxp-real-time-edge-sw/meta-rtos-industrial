# Copyright 2025 NXP

require recipes-heterogeneous-multicore/includes/hmc-example.inc

HMC_EXAMPLE_NAME = "rpmsg_str_echo"

HMC_EXAMPLE_TARGET_TYPE = "release_8m_buf"

FILES:${PN} += " \
    /${HMC_EXAMPLE_INSTALL_DIR}/rpmsg-str-echo-freertos/* \
    /${HMC_EXAMPLE_INSTALL_DIR}/rpmsg-str-echo-zephyr/* \
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
                for file in $(find . \( -name "${HMC_EXAMPLE_NAME}*_8m_buf.elf" -o -name "${HMC_EXAMPLE_NAME}*_8m_buf.bin" \)); do
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
                for file in $(find . \( -name "${HMC_EXAMPLE_NAME}*_8m_buf.elf" -o -name "${HMC_EXAMPLE_NAME}*_8m_buf.bin" \)); do
                    install -m 0644 "$file" ${DEPLOYDIR}/${HMC_EXAMPLE_INSTALL_DIR}/${PN}-${rtos}/
                done
            fi
        done
    done
}