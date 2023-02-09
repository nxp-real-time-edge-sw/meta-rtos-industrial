# Copyright 2023 NXP

LICENSE = "BSD-3-Clause & Apache-2.0"
LIC_FILES_CHKSUM = " \
    file://heterogeneous-multicore/LICENSES/COPYING-BSD-3;md5=b1a3c7f4e16fc8aa105097dd385e900f \
    file://heterogeneous-multicore/LICENSES/COPYING-Apache.txt;md5=f562198c0123d3829f9a8dab92f09e92 \
    "
DNIND_BASE = "git@bitbucket.sw.nxp.com/dnind"
HMC_BRANCH="master"

SRC_URI += "git://${DNIND_BASE}/heterogeneous-multicore.git;protocol=ssh;branch=${HMC_BRANCH};destsuffix=git/heterogeneous-multicore;name=heterogeneous-multicore"

SRCREV_FORMAT:append = "_heterogeneous-multicore"
SRCREV_heterogeneous-multicore = "${AUTOREV}"
