# Copyright 2023-2024 NXP

require mcux-sdk-src.inc
require hmc.inc

do_package_qa[noexec] = "1"
INHIBIT_PACKAGE_STRIP = "1"
INHIBIT_PACKAGE_DEBUG_SPLIT = "1"

do_compile() {
    cd ${S}/heterogeneous-multicore/tools/ram_console
    oe_runmake
    cd ${S}/heterogeneous-multicore/tools/rpmsg_perf
    oe_runmake
}

do_install:append () {
    install -d ${D}${bindir}
    install -p ${S}/heterogeneous-multicore/tools/ram_console/ram_console_dump ${D}${bindir}
    install -p ${S}/heterogeneous-multicore/tools/rpmsg_perf/rpmsg_perf ${D}${bindir}
    install -p ${S}/heterogeneous-multicore/tools/virtio_perf/vt_test.sh ${D}${bindir}
    install -p ${S}/heterogeneous-multicore/tools/rt_setup/real_time_setup.sh ${D}${bindir}
}

FILES:${PN} += "${bindir}"
