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

    for repo in \
        "${S}/mcuxsdk/mcuxsdk-manifests" \
        "${S}/zsdk/zephyr" \
        "${S}/zsdk/zsdk" ; do
        if [ -d "${repo}" ]; then
            # get current commit and update manifest-rev to point to it
            sha=$(git -C "${repo}" rev-parse --verify HEAD)
            if [ -n "${sha}" ]; then
                git -C "${repo}" update-ref refs/heads/manifest-rev "${sha}"
                bbnote "Set ${repo} refs/heads/manifest-rev -> ${sha}"
            else
                bbwarn "Could not determine HEAD for ${repo}"
            fi
        fi
    done

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
