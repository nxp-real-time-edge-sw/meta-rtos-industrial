# Copyright 2023 NXP

LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://heterogeneous-multicore/LICENSE.txt;md5=b1a3c7f4e16fc8aa105097dd385e900f"
NXP_REAL_TIME_EDGE_BASE="github.com/nxp-real-time-edge-sw"

SRC_URI += "${HETEROGENEOUS_MULTICORE_SRC};destsuffix=git/heterogeneous-multicore;name=heterogeneous-multicore"

SRCREV_FORMAT:append = "_heterogeneous-multicore"
SRCREV_heterogeneous-multicore = "196d2ad42b109d6e862acd296b3a38e3e80073c2"
