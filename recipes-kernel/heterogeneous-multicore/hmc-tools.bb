# Copyright 2023 NXP

require mcux-sdk-src.inc
require hmc.inc

do_package_qa[noexec] = "1"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"

do_compile() {
    cd ${S}/heterogeneous-multicore/tools
    oe_runmake
}

do_install:append () {
    install -d ${D}${bindir}
    install -p ${S}/heterogeneous-multicore/tools/ram_console_dump ${D}${bindir}
}

FILES:${PN} += "${bindir}"
