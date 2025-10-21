# Auto-generated from generate-version-hmc-from-west.py

SRCREV_FORMAT = "hmc"

SRCREV_hmc ?= "7c0ea7362987f6933781785d2962de047629d465"
SRCREV_core ?= "62eb76eb657605fdc9d850bfd2310cdf0de6a0b4"
SRCREV_mcuxsdk-manifests ?= "686abea9abe797e4a9446d5415901db95ff11b34"
SRCREV_MCUX_CMSIS ?= "389527cf99d80051dcf747d83b484e62d9c8128b"
SRCREV_mcu-sdk-components ?= "80a9d96ebf169290649a78ecdbdc230e22c7649c"
SRCREV_mcux-devices-kinetis ?= "f64e02dfe58c464c2110b1552ed9c1521d4871e3"
SRCREV_mcux-devices-lpc ?= "14eea8ab86f5522b0dc9e4c9bc56817ee35b312e"
SRCREV_mcux-devices-mcx ?= "cb21024505166d9b78dce33b71345db9f55d9643"
SRCREV_mcux-devices-rt ?= "57a58f6951e2d44f2e7a7f665d9de1a86d40c640"
SRCREV_mcux-devices-imx ?= "cb564892ff6f2200e067446b06c57145ceeb69bf"
SRCREV_mcu-sdk-doc ?= "862c3464b4b678d5834fc14ed0d491c184fdf52c"
SRCREV_mcu-sdk-examples ?= "962df7f187857fb9544f97e3161151853739f4f1"
SRCREV_lwip ?= "68d1f9f864a4b419e1a14fdb1e4388502d3b651d"
SRCREV_mcux-sdk-middleware-multicore ?= "6efff30b68c60a7a7c06bbad08ab8422e69fd79b"
SRCREV_rpmsg-lite ?= "c50e006d016d7614db1422ed7f330dad253cdcad"
SRCREV_soem ?= "4824f5c236127571fd0834eaeae4ccc152688fce"
SRCREV_freertos-kernel ?= "72ef44a2d0f4a4ed79b3d535ee1b7adeda6c423e"
SRCREV_els_pkc ?= "71d4a89c03fb32e618ee02c0cd54b3fc92736c96"
SRCREV_psa_crypto_driver ?= "1a93893f986db38cf2c8910f6138b634f0437a48"
SRCREV_cmsis ?= "512cc7e895e8491696b61f7ba8066b4a182569b8"
SRCREV_cmsis_6 ?= "30a859f44ef8ab4dc8f84b03ed586fd16ccf9d74"
SRCREV_libmetal ?= "91d38634d1882f0a2151966f8c5c230ce1c0de7b"
SRCREV_hal_nxp ?= "6c46b1bbe78e33c5450001308748ac593288e4c1"
SRCREV_open-amp ?= "c30a6d8b92fcebdb797fc1a7698e8729e250f637"
SRCREV_zephyr ?= "e7422607616c69717408bf78be261cf96ba20927"

SRC_URI_HMC ?= "git://github.com/nxp-real-time-edge-sw/heterogeneous-multicore.git;protocol=https"
SRC_URI_CORE ?= "git://github.com/nxp-mcuxpresso/mcuxsdk-core;protocol=https"
SRC_URI_MCUXSDK_MANIFESTS ?= "git://github.com/nxp-mcuxpresso/mcuxsdk-manifests;protocol=https"
SRC_URI_MCUX_CMSIS ?= "git://github.com/nxp-mcuxpresso/mcu-sdk-cmsis;protocol=https"
SRC_URI_MCU_SDK_COMPONENTS ?= "git://github.com/nxp-mcuxpresso/mcux-component;protocol=https"
SRC_URI_MCUX_DEVICES_KINETIS ?= "git://github.com/nxp-mcuxpresso/mcux-devices-kinetis;protocol=https"
SRC_URI_MCUX_DEVICES_LPC ?= "git://github.com/nxp-mcuxpresso/mcux-devices-lpc;protocol=https"
SRC_URI_MCUX_DEVICES_MCX ?= "git://github.com/nxp-mcuxpresso/mcux-devices-mcx;protocol=https"
SRC_URI_MCUX_DEVICES_RT ?= "git://github.com/nxp-mcuxpresso/mcux-devices-rt;protocol=https"
SRC_URI_MCUX_DEVICES_IMX ?= "git://github.com/nxp-mcuxpresso/mcux-devices-imx;protocol=https"
SRC_URI_MCU_SDK_DOC ?= "git://github.com/nxp-mcuxpresso/mcuxsdk-doc;protocol=https"
SRC_URI_MCU_SDK_EXAMPLES ?= "git://github.com/nxp-mcuxpresso/mcuxsdk-examples;protocol=https"
SRC_URI_LWIP ?= "git://github.com/nxp-mcuxpresso/lwip;protocol=https"
SRC_URI_MCUX_SDK_MIDDLEWARE_MULTICORE ?= "git://github.com/nxp-mcuxpresso/mcuxsdk-middleware-multicore;protocol=https"
SRC_URI_RPMSG_LITE ?= "git://github.com/nxp-mcuxpresso/rpmsg-lite;protocol=https"
SRC_URI_SOEM ?= "git://github.com/nxp-mcuxpresso/soem;protocol=https"
SRC_URI_FREERTOS_KERNEL ?= "git://github.com/nxp-mcuxpresso/freertos-kernel;protocol=https"
SRC_URI_ELS_PKC ?= "git://github.com/NXP/els_pkc;protocol=https"
SRC_URI_PSA_CRYPTO_DRIVER ?= "git://github.com/NXP/psa_crypto_driver;protocol=https"
SRC_URI_CMSIS ?= "git://github.com/zephyrproject-rtos/cmsis;protocol=https"
SRC_URI_CMSIS_6 ?= "git://github.com/zephyrproject-rtos/CMSIS_6;protocol=https"
SRC_URI_LIBMETAL ?= "git://github.com/zephyrproject-rtos/libmetal;protocol=https"
SRC_URI_HAL_NXP ?= "git://github.com/nxp-zephyr/hal_nxp;protocol=https"
SRC_URI_OPEN_AMP ?= "git://github.com/zephyrproject-rtos/open-amp;protocol=https"
SRC_URI_ZEPHYR ?= "git://github.com/nxp-zephyr/zephyr;protocol=https"

SRC_URI_CORE_WITH_BRANCH ?= "${SRC_URI_CORE};nobranch=1"
SRC_URI_MCUXSDK_MANIFESTS_WITH_BRANCH ?= "${SRC_URI_MCUXSDK_MANIFESTS};nobranch=1"
SRC_URI_MCUX_CMSIS_WITH_BRANCH ?= "${SRC_URI_MCUX_CMSIS};nobranch=1"
SRC_URI_MCU_SDK_COMPONENTS_WITH_BRANCH ?= "${SRC_URI_MCU_SDK_COMPONENTS};nobranch=1"
SRC_URI_MCUX_DEVICES_KINETIS_WITH_BRANCH ?= "${SRC_URI_MCUX_DEVICES_KINETIS};nobranch=1"
SRC_URI_MCUX_DEVICES_LPC_WITH_BRANCH ?= "${SRC_URI_MCUX_DEVICES_LPC};nobranch=1"
SRC_URI_MCUX_DEVICES_MCX_WITH_BRANCH ?= "${SRC_URI_MCUX_DEVICES_MCX};nobranch=1"
SRC_URI_MCUX_DEVICES_RT_WITH_BRANCH ?= "${SRC_URI_MCUX_DEVICES_RT};nobranch=1"
SRC_URI_MCUX_DEVICES_IMX_WITH_BRANCH ?= "${SRC_URI_MCUX_DEVICES_IMX};nobranch=1"
SRC_URI_MCU_SDK_DOC_WITH_BRANCH ?= "${SRC_URI_MCU_SDK_DOC};nobranch=1"
SRC_URI_MCU_SDK_EXAMPLES_WITH_BRANCH ?= "${SRC_URI_MCU_SDK_EXAMPLES};nobranch=1"
SRC_URI_LWIP_WITH_BRANCH ?= "${SRC_URI_LWIP};nobranch=1"
SRC_URI_MCUX_SDK_MIDDLEWARE_MULTICORE_WITH_BRANCH ?= "${SRC_URI_MCUX_SDK_MIDDLEWARE_MULTICORE};nobranch=1"
SRC_URI_RPMSG_LITE_WITH_BRANCH ?= "${SRC_URI_RPMSG_LITE};nobranch=1"
SRC_URI_SOEM_WITH_BRANCH ?= "${SRC_URI_SOEM};nobranch=1"
SRC_URI_FREERTOS_KERNEL_WITH_BRANCH ?= "${SRC_URI_FREERTOS_KERNEL};nobranch=1"
SRC_URI_ELS_PKC_WITH_BRANCH ?= "${SRC_URI_ELS_PKC};nobranch=1"
SRC_URI_PSA_CRYPTO_DRIVER_WITH_BRANCH ?= "${SRC_URI_PSA_CRYPTO_DRIVER};nobranch=1"
SRC_URI_CMSIS_WITH_BRANCH ?= "${SRC_URI_CMSIS};nobranch=1"
SRC_URI_CMSIS_6_WITH_BRANCH ?= "${SRC_URI_CMSIS_6};nobranch=1"
SRC_URI_LIBMETAL_WITH_BRANCH ?= "${SRC_URI_LIBMETAL};nobranch=1"
SRC_URI_HAL_NXP_WITH_BRANCH ?= "${SRC_URI_HAL_NXP};nobranch=1"
SRC_URI_OPEN_AMP_WITH_BRANCH ?= "${SRC_URI_OPEN_AMP};nobranch=1"
SRC_URI_ZEPHYR_WITH_BRANCH ?= "${SRC_URI_ZEPHYR};nobranch=1"

SRC_URI = "\
    ${SRC_URI_HMC};branch=${HMC_BRANCH};name=hmc;destsuffix=git/heterogeneous-multicore \
    ${SRC_URI_CORE_WITH_BRANCH};name=core;destsuffix=git/mcuxsdk/mcuxsdk \
    ${SRC_URI_MCUXSDK_MANIFESTS_WITH_BRANCH};name=mcuxsdk-manifests;destsuffix=git/mcuxsdk/mcuxsdk-manifests \
    ${SRC_URI_MCUX_CMSIS_WITH_BRANCH};name=MCUX_CMSIS;destsuffix=git/mcuxsdk/mcuxsdk/arch/arm/CMSIS \
    ${SRC_URI_MCU_SDK_COMPONENTS_WITH_BRANCH};name=mcu-sdk-components;destsuffix=git/mcuxsdk/mcuxsdk/components \
    ${SRC_URI_MCUX_DEVICES_KINETIS_WITH_BRANCH};name=mcux-devices-kinetis;destsuffix=git/mcuxsdk/mcuxsdk/devices/Kinetis \
    ${SRC_URI_MCUX_DEVICES_LPC_WITH_BRANCH};name=mcux-devices-lpc;destsuffix=git/mcuxsdk/mcuxsdk/devices/LPC \
    ${SRC_URI_MCUX_DEVICES_MCX_WITH_BRANCH};name=mcux-devices-mcx;destsuffix=git/mcuxsdk/mcuxsdk/devices/MCX \
    ${SRC_URI_MCUX_DEVICES_RT_WITH_BRANCH};name=mcux-devices-rt;destsuffix=git/mcuxsdk/mcuxsdk/devices/RT \
    ${SRC_URI_MCUX_DEVICES_IMX_WITH_BRANCH};name=mcux-devices-imx;destsuffix=git/mcuxsdk/mcuxsdk/devices/i.MX \
    ${SRC_URI_MCU_SDK_DOC_WITH_BRANCH};name=mcu-sdk-doc;destsuffix=git/mcuxsdk/mcuxsdk/docs \
    ${SRC_URI_MCU_SDK_EXAMPLES_WITH_BRANCH};name=mcu-sdk-examples;destsuffix=git/mcuxsdk/mcuxsdk/examples \
    ${SRC_URI_LWIP_WITH_BRANCH};name=lwip;destsuffix=git/mcuxsdk/mcuxsdk/middleware/lwip \
    ${SRC_URI_MCUX_SDK_MIDDLEWARE_MULTICORE_WITH_BRANCH};name=mcux-sdk-middleware-multicore;destsuffix=git/mcuxsdk/mcuxsdk/middleware/multicore \
    ${SRC_URI_RPMSG_LITE_WITH_BRANCH};name=rpmsg-lite;destsuffix=git/mcuxsdk/mcuxsdk/middleware/multicore/rpmsg-lite \
    ${SRC_URI_SOEM_WITH_BRANCH};name=soem;destsuffix=git/mcuxsdk/mcuxsdk/middleware/soem \
    ${SRC_URI_FREERTOS_KERNEL_WITH_BRANCH};name=freertos-kernel;destsuffix=git/mcuxsdk/mcuxsdk/rtos/freertos/freertos-kernel \
    ${SRC_URI_ELS_PKC_WITH_BRANCH};name=els_pkc;destsuffix=git/modules/crypto/els_pkc \
    ${SRC_URI_PSA_CRYPTO_DRIVER_WITH_BRANCH};name=psa_crypto_driver;destsuffix=git/modules/crypto/psa_crypto_driver \
    ${SRC_URI_CMSIS_WITH_BRANCH};name=cmsis;destsuffix=git/zsdk/modules/hal/cmsis \
    ${SRC_URI_CMSIS_6_WITH_BRANCH};name=cmsis_6;destsuffix=git/zsdk/modules/hal/cmsis_6 \
    ${SRC_URI_LIBMETAL_WITH_BRANCH};name=libmetal;destsuffix=git/zsdk/modules/hal/libmetal \
    ${SRC_URI_HAL_NXP_WITH_BRANCH};name=hal_nxp;destsuffix=git/zsdk/modules/hal/nxp \
    ${SRC_URI_OPEN_AMP_WITH_BRANCH};name=open-amp;destsuffix=git/zsdk/modules/lib/open-amp \
    ${SRC_URI_ZEPHYR_WITH_BRANCH};name=zephyr;destsuffix=git/zsdk/zephyr \
"

HMC_MODULES = "\
${S}/mcuxsdk/mcuxsdk\;\
${S}/mcuxsdk/mcuxsdk-manifests\;\
${S}/mcuxsdk/mcuxsdk/arch/arm/CMSIS\;\
${S}/mcuxsdk/mcuxsdk/components\;\
${S}/mcuxsdk/mcuxsdk/devices/Kinetis\;\
${S}/mcuxsdk/mcuxsdk/devices/LPC\;\
${S}/mcuxsdk/mcuxsdk/devices/MCX\;\
${S}/mcuxsdk/mcuxsdk/devices/RT\;\
${S}/mcuxsdk/mcuxsdk/devices/i.MX\;\
${S}/mcuxsdk/mcuxsdk/docs\;\
${S}/mcuxsdk/mcuxsdk/examples\;\
${S}/mcuxsdk/mcuxsdk/middleware/lwip\;\
${S}/mcuxsdk/mcuxsdk/middleware/multicore\;\
${S}/mcuxsdk/mcuxsdk/middleware/multicore/rpmsg-lite\;\
${S}/mcuxsdk/mcuxsdk/middleware/soem\;\
${S}/mcuxsdk/mcuxsdk/rtos/freertos/freertos-kernel\;\
${S}/modules/crypto/els_pkc\;\
${S}/modules/crypto/psa_crypto_driver\;\
${S}/zsdk/modules/hal/cmsis\;\
${S}/zsdk/modules/hal/cmsis_6\;\
${S}/zsdk/modules/hal/libmetal\;\
${S}/zsdk/modules/hal/nxp\;\
${S}/zsdk/modules/lib/open-amp\;\
${S}/zsdk/zephyr\;\
"

HMC_BRANCH ?= "main"
PV = "3.3"
