# Copyright 2022 NXP

FILESEXTRAPATHS:prepend := "${THISDIR}/mcux-sdk-soem:"


SRC_URI += " \
    file://0001-Enet-enable-Enet-and-SOEM-for-MIMX8ML.patch;patchdir=core \
"
