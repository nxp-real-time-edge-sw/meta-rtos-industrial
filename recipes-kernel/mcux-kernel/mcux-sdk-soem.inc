# Copyright 2022 NXP

FILESEXTRAPATHS:prepend := "${THISDIR}/mcux-sdk-soem:"


SRC_URI += " \
    file://0001-Enet-enable-Enet-and-SOEM-for-MIMX8ML.patch;patchdir=core \
    file://0001-MIMX8MM6-add-clock-definitions-for-ENET.patch;patchdir=core \
    file://0002-MIMX8MM6-clock-Add-Enet-IPG-clock-support.patch;patchdir=core \
    file://0003-devices-MIMX8MM6-add-enet-mdio-and-phy.patch;patchdir=core \
    file://0004-Enet-enable-SOEM-for-MIMX8MM.patch;patchdir=core \
"
