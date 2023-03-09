# Copyright 2023 NXP

LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://heterogeneous-multicore/LICENSE.txt;md5=b1a3c7f4e16fc8aa105097dd385e900f"
NXP_REAL_TIME_EDGE_BASE="github.com/nxp-real-time-edge-sw"

SRC_URI += "git://${NXP_REAL_TIME_EDGE_BASE}/heterogeneous-multicore.git;protocol=https;nobranch=1;destsuffix=git/heterogeneous-multicore;name=heterogeneous-multicore"

SRCREV_FORMAT:append = "_heterogeneous-multicore"
SRCREV_heterogeneous-multicore = "fe7e5c1a932e38712ae5da167958aab8b43ae883"
