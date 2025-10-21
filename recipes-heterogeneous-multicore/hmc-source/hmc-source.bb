# Recipe dedicated to downloading and managing source code
SUMMARY = "HMS Shared Source"
DESCRIPTION = "Downloads and configures all HMS source repositories for sharing among recipes"

require recipes-heterogeneous-multicore/includes/hmc-version.inc
require hmc-source.inc

# Use work-shared directory
WORKDIR = "${TMPDIR}/work-shared/hmc-source"
S = "${WORKDIR}/git"

# Don't generate packages
inherit nopackages

do_configure() {
    # Configure west
    if [ ! -f "${S}/.west/config" ]; then
        mkdir -p "${S}/.west"
        cat << EOF > "${S}/.west/config"
[manifest]
path = heterogeneous-multicore
file = west.yml
group-filter = +bifrost

[commands]
allow_extensions = true
EOF
    fi

    # Update manifest-rev to track latest commits
    bbnote "Updating manifest-rev references"

    if [ -d "${S}/mcuxsdk/mcuxsdk-manifests" ]; then
        cd ${S}/mcuxsdk/mcuxsdk-manifests
        git update-ref refs/heads/manifest-rev origin/feature/heterogeneous_multicore
    fi

    if [ -d "${S}/zsdk/zephyr" ]; then
        cd ${S}/zsdk/zephyr
        git update-ref refs/heads/manifest-rev origin/main
    fi

    if [ -d "${S}/zsdk/zsdk" ]; then
        cd ${S}/zsdk/zsdk
        git update-ref refs/heads/manifest-rev origin/main
    fi

    # Create marker file to indicate source is ready
    touch ${S}/.hmc-source-ready

    # Save current version for tracking
    echo "${PV}" > ${S}/.hmc-version
    bbnote "HMS source configured with version: $(cat ${S}/.hmc-version)"
}

do_compile[noexec] = "1"
do_install[noexec] = "1"

# Deploy task to trigger build
do_deploy() {
    bbnote "HMS source ready at ${S}"
}
addtask deploy after do_configure
