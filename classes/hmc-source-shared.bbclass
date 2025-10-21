# Copyright 2025 NXP
# Class for recipes that use HMS shared source

# Depend on hmc-source to ensure source is available
DEPENDS:append = " hmc-source"

# Set source directory to shared location
HMS_SOURCE_DIR ?= "${TMPDIR}/work-shared/hmc-source/git"
S = "${HMS_SOURCE_DIR}"

# Skip fetch and unpack as source is provided by hmc-source
do_fetch[noexec] = "1"
do_unpack[noexec] = "1"

# Verify source is ready before configure
do_configure[prefuncs] += "hmc_verify_source"

hmc_verify_source() {
    if [ ! -f "${S}/.hmc-source-ready" ]; then
        bbfatal "HMS source not ready. Please build hmc-source first."
    fi

    if [ ! -f "${S}/.west/config" ]; then
        bbfatal "HMS source not properly configured. Missing west config."
    fi

    bbnote "Using HMS source from: ${S}"
    if [ -f "${S}/.hmc-revision" ]; then
        bbnote "HMS source revision: $(cat ${S}/.hmc-revision)"
    fi
}

# Add task to show source status
do_showsource() {
    echo "HMS Source Location: ${S}"
    if [ -f "${S}/.hmc-revision" ]; then
        echo "Current Revision: $(cat ${S}/.hmc-revision)"
    fi

    CURRENT_DIR=$(pwd)
    echo "Repositories:"
    for repo in heterogeneous-multicore mcuxsdk/mcuxsdk-manifests zsdk/zephyr zsdk/zsdk; do
        if [ -d "${S}/${repo}/.git" ]; then
            echo "  ${repo}:"
            cd "${S}/${repo}"
            echo "    Branch: $(git branch --show-current)"
            echo "    Commit: $(git rev-parse --short HEAD)"
        fi
    done
    cd "${CURRENT_DIR}"
}

addtask showsource
do_showsource[nostamp] = "1"
