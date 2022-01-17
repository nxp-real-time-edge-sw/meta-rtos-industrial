# Copyright 2022 NXP

require mcux-sdk-src.inc

IMAGE_NO_MANIFEST = "1"
INHIBIT_DEFAULT_DEPS = "1"

do_configure[noexec] = "1"
do_compile[noexec] = "1"

do_install () {
    kerneldir=${D}/usr/src/mcuxsdk
    install -d $kerneldir
    cp -r ${S}/* $kerneldir
}

PACKAGES = "${PN}"

FILES:${PN} = "/usr/src/mcuxsdk"

SYSROOT_DIRS += "/usr/src/mcuxsdk"