# Copyright 2023 NXP

LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://heterogeneous-multicore/LICENSE.txt;md5=b1a3c7f4e16fc8aa105097dd385e900f"
DNIND_BASE = "git@bitbucket.sw.nxp.com/dnind"
HMC_BRANCH="release/rtedge-v2.5"

SRC_URI += "git://${DNIND_BASE}/heterogeneous-multicore.git;protocol=ssh;branch=${HMC_BRANCH};destsuffix=git/heterogeneous-multicore;name=heterogeneous-multicore"

SRCREV_FORMAT:append = "_heterogeneous-multicore"
SRCREV_heterogeneous-multicore = "${AUTOREV}"
