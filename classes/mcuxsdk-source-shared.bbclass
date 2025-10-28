# Copyright 2025 NXP
# Class for recipes that use MCUXSDK shared source

# Depend on mcuxsdk-source to ensure source is available
DEPENDS:append = " mcuxsdk-source"

# Set source directory to shared location
MCUXSDK_SOURCE_DIR ?= "${TMPDIR}/work-shared/mcuxsdk/git"
S = "${MCUXSDK_SOURCE_DIR}"

# Skip fetch and unpack as source is provided by mcuxsdk-source
do_fetch[noexec] = "1"
do_unpack[noexec] = "1"

# Critical: Ensure all tasks that need source wait for mcusdk-source
do_populate_lic[depends] += "mcuxsdk-source:do_unpack"
do_configure[depends] += "mcuxsdk-source:do_configure"
do_compile[depends] += "mcuxsdk-source:do_configure"

# Verify source is ready before configure
do_configure[prefuncs] += "mcuxsdk_verify_source"

mcuxsdk_verify_source() {
    if [ ! -f "${S}/.mcuxsdk-source-ready" ]; then
        bbfatal "MCUXSDK source not ready. Please build mcuxsdk-source first."
    fi

    if [ ! -f "${S}/.west/config" ]; then
        bbfatal "MCUXSDK source not properly configured. Missing west config."
    fi

    bbnote "Using MCUXSDK source from: ${S}"
    if [ -f "${S}/.mcuxsdk-version" ]; then
        bbnote "MCUXSDK source revision: $(cat ${S}/.mcuxsdk-version)"
    fi
}

# Add task to show source status
do_showsource() {
    echo "MCUXSDK Source Location: ${S}"
    if [ -f "${S}/.mcuxsdk-revision" ]; then
        echo "Current Revision: $(cat ${S}/.mcuxsdk-revision)"
    fi
}

addtask showsource
do_showsource[nostamp] = "1"
