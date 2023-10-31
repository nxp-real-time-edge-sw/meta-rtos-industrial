SUMMARY = "i.MX RT1180 EVK DSA switch application"
DESCRIPTION = "Binary image of DSA switch application running on CM33 core of i.MX RT1180 EVK"
LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = "file://COPYING-BSD-3;md5=7320a721656f5ec655c71bef0f22a3a8"

SRC_URI = "file://COPYING-BSD-3 \
           file://release \
           file://ram_release"

S = "${WORKDIR}"

inherit deploy

EXAMPLE_INSTALL_DIR = "examples/heterogeneous-multi-soc"

do_package_qa[noexec] = "1"

do_install() {
    install -d ${D}/${EXAMPLE_INSTALL_DIR}/${PN}/release
    install -d ${D}/${EXAMPLE_INSTALL_DIR}/${PN}/ram_release
    install -Dm 0755 ${WORKDIR}/release/* ${D}/${EXAMPLE_INSTALL_DIR}/${PN}/release
    install -Dm 0755 ${WORKDIR}/ram_release/* ${D}/${EXAMPLE_INSTALL_DIR}/${PN}/ram_release
}

do_deploy () {
    install -d ${DEPLOYDIR}/${EXAMPLE_INSTALL_DIR}/${PN}/release
    install -d ${DEPLOYDIR}/${EXAMPLE_INSTALL_DIR}/${PN}/ram_release
    install -Dm 0755 ${WORKDIR}/release/* ${DEPLOYDIR}/${EXAMPLE_INSTALL_DIR}/${PN}/release
    install -Dm 0755 ${WORKDIR}/ram_release/* ${DEPLOYDIR}/${EXAMPLE_INSTALL_DIR}/${PN}/ram_release
}

FILES:${PN} += "/examples/heterogeneous-multi-soc/dsa-switch-evkmimxrt1180-cm33/*"

addtask deploy after do_install
