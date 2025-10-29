# Auto-generated from generate-version-hmc-from-west.py

SRCREV_FORMAT = "hmc"

SRCREV_hmc ?= "2ef30175fa9415a2c81e006df3cc561e0fb3122a"
SRCREV_core ?= "054a131cb31b19d9dd11ab5a153d28c9a8810022"
SRCREV_mcuxsdk-manifests ?= "f8062efa0f77bbc45a641fc87eacfb225b7bc7f1"
SRCREV_MCUX_CMSIS ?= "19a9390ee4acdb36407639d56d6eea392719a993"
SRCREV_mcu-sdk-components ?= "17697c082c7ecf91752428f7bc741aa00588b850"
SRCREV_mcux-devices-kinetis ?= "978c1f97060c884d548c68ac06836750426033e8"
SRCREV_mcux-devices-lpc ?= "fe228b87e081a1938f6211b4c60926a333ed93fb"
SRCREV_mcux-devices-mcx ?= "6bbddd36a6efe653c4633b064705dd9f30e32ac8"
SRCREV_mcux-devices-rt ?= "6b306e8feca475462e7fd4cd682440513f570bc4"
SRCREV_mcux-devices-imx ?= "6ebb1ec8b81214d9f7ea54a1b50d553c7d32dea3"
SRCREV_mcu-sdk-doc ?= "a2e0722879312c7385e90ac78f43a09d0fcd6fd3"
SRCREV_mcu-sdk-examples ?= "0f5d413acda59010d3cf580ecd6f0094c530e711"
SRCREV_lvgl ?= "660716558391a990389c11b263b9c4d1336ae0cb"
SRCREV_lwip ?= "fbc6c9b6a5908e52661a3c1bf2f0e05f2c16b360"
SRCREV_mcux-sdk-middleware-multicore ?= "9e52c5ffeb00ef0ae6f7397e12ed56cce1d9359a"
SRCREV_rpmsg-lite ?= "42a37572d84fbabb35455292b3a87244b10a877e"
SRCREV_soem ?= "53acd56dca133af3817a53d93e0928f5bbc8406e"
SRCREV_freertos-kernel ?= "59f4fcb9c8b9f625b88f2e58703cfd48692222fc"
SRCREV_els_pkc ?= "71d4a89c03fb32e618ee02c0cd54b3fc92736c96"
SRCREV_psa_crypto_driver ?= "1a93893f986db38cf2c8910f6138b634f0437a48"
SRCREV_cmsis ?= "512cc7e895e8491696b61f7ba8066b4a182569b8"
SRCREV_cmsis_6 ?= "30a859f44ef8ab4dc8f84b03ed586fd16ccf9d74"
SRCREV_libmetal ?= "91d38634d1882f0a2151966f8c5c230ce1c0de7b"
SRCREV_hal_nxp ?= "6c46b1bbe78e33c5450001308748ac593288e4c1"
SRCREV_open-amp ?= "c30a6d8b92fcebdb797fc1a7698e8729e250f637"
SRCREV_zephyr ?= "671df04da7c9e495bb85539b21b1bb002db2be27"

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
SRC_URI_LVGL ?= "git://github.com/nxp-mcuxpresso/lvgl;protocol=https"
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
SRC_URI_LVGL_WITH_BRANCH ?= "${SRC_URI_LVGL};nobranch=1"
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
    ${SRC_URI_LVGL_WITH_BRANCH};name=lvgl;destsuffix=git/mcuxsdk/mcuxsdk/middleware/lvgl \
    ${SRC_URI_LWIP_WITH_BRANCH};name=lwip;destsuffix=git/mcuxsdk/mcuxsdk/middleware/lwip \
    ${SRC_URI_MCUX_SDK_MIDDLEWARE_MULTICORE_WITH_BRANCH};name=mcux-sdk-middleware-multicore;destsuffix=git/mcuxsdk/mcuxsdk/middleware/multicore \
    ${SRC_URI_RPMSG_LITE_WITH_BRANCH};name=rpmsg-lite;destsuffix=git/mcuxsdk/mcuxsdk/middleware/multicore/rpmsg-lite \
    ${SRC_URI_SOEM_WITH_BRANCH};name=soem;destsuffix=git/mcuxsdk/mcuxsdk/middleware/soem \
    ${SRC_URI_FREERTOS_KERNEL_WITH_BRANCH};name=freertos-kernel;destsuffix=git/mcuxsdk/mcuxsdk/rtos/freertos/freertos-kernel \
    ${SRC_URI_ELS_PKC_WITH_BRANCH};name=els_pkc;destsuffix=git/zsdk/modules/crypto/els_pkc \
    ${SRC_URI_PSA_CRYPTO_DRIVER_WITH_BRANCH};name=psa_crypto_driver;destsuffix=git/zsdk/modules/crypto/psa_crypto_driver \
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
${S}/mcuxsdk/mcuxsdk/middleware/lvgl\;\
${S}/mcuxsdk/mcuxsdk/middleware/lwip\;\
${S}/mcuxsdk/mcuxsdk/middleware/multicore\;\
${S}/mcuxsdk/mcuxsdk/middleware/multicore/rpmsg-lite\;\
${S}/mcuxsdk/mcuxsdk/middleware/soem\;\
${S}/mcuxsdk/mcuxsdk/rtos/freertos/freertos-kernel\;\
${S}/zsdk/modules/crypto/els_pkc\;\
${S}/zsdk/modules/crypto/psa_crypto_driver\;\
${S}/zsdk/modules/hal/cmsis\;\
${S}/zsdk/modules/hal/cmsis_6\;\
${S}/zsdk/modules/hal/libmetal\;\
${S}/zsdk/modules/hal/nxp\;\
${S}/zsdk/modules/lib/open-amp\;\
${S}/zsdk/zephyr\;\
"

HMC_BRANCH ?= "main"
PV = "3.3"
