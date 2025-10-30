# Copyright 2025 NXP
SUMMARY = "MCUX SDK Shared Source"
DESCRIPTION = "Downloads and configures all MCUX SDK source repositories for sharing among recipes"

require recipes-mcuxsdk/includes/mcuxsdk-version.inc
require mcuxsdk-source.inc

# Use work-shared directory
WORKDIR = "${TMPDIR}/work-shared/mcuxsdk"
S = "${WORKDIR}/git"

# Don't generate packages
inherit nopackages

# mcuxsdk-core patch
SRC_URI += " \
    file://0001-MCUX-83513-driver-iuart-Add-9-bit-mode-support.patch;patchdir=${S}/mcuxsdk \
"

do_configure() {
    if [ ! -d "${S}/.west" ]; then
        bbnote "Creating .west directory and config"
        mkdir -p "${S}/.west"

        cat << EOF > "${S}/.west/config"
[manifest]
path = manifests
file = west.yml
EOF
    else
        bbnote ".west directory already exists"
    fi

    # Create marker file to indicate source is ready
    touch ${S}/.mcuxsdk-source-ready

    # Save current revision for tracking
    echo "${PV}" > ${S}/.mcuxsdk-version
    bbnote "MCUX SDK source configured with revision: $(cat ${S}/.mcuxsdk-version)"
}

do_compile[noexec] = "1"
do_install[noexec] = "1"

# Deploy task to trigger build
do_deploy() {
    bbnote "MCUX SDK source ready at ${S}"
}
addtask deploy after do_configure
