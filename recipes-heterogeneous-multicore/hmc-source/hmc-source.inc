# Auto-generated from generate-version-hmc-from-west.py

SRCREV_FORMAT = "hmc"

SRCREV_hmc ?= "d7c39d53814f7fbf1077b3afb78a28fe1e34ce65"
SRCREV_core ?= "ad9e632e7735a4a6196e250027d1ea0fb0d2e5bd"
SRCREV_mcuxsdk-manifests ?= "262a466ff0e4e84b3cf5965011154c7c6236ea63"
SRCREV_MCUX_CMSIS ?= "dfbb2d775b238b22dc1541c257c9ddc3b22ed4e3"
SRCREV_mcu-sdk-components ?= "c4fad92115c7d4e69bdcd07c690018398ab6a231"
SRCREV_mcux-devices-kinetis ?= "748c452a7afe87b30e3aa6460a172b7a0e0ae433"
SRCREV_mcux-devices-lpc ?= "68bb24aeed5cccc1e758b061f7ffe1ef1c3ae926"
SRCREV_mcux-devices-mcx ?= "5cd233f7bdebd6de33c200d2bf423fc7548d79b2"
SRCREV_mcux-devices-rt ?= "3664324bd1240a92e05a31301f6636a7a19f01d2"
SRCREV_mcux-devices-imx ?= "2338cdc3cb067aaf86286e60bf9ec1f77d628b12"
SRCREV_mcu-sdk-doc ?= "5a330c6c9d51b7e0c868c2eddf7a580e7b04f474"
SRCREV_mcu-sdk-examples ?= "c37c97ca4376ecab88eb415f3b3679e10dee1ab7"
SRCREV_lvgl ?= "0779788b76285538b25c7c6d80b1b6856dfeb2bf"
SRCREV_lwip ?= "85980ff48d8781414d7294bd42366b6b1a03591f"
SRCREV_mcux-sdk-middleware-multicore ?= "0942eac75827fe2b9fbb5ee601a5c30f1c372ba6"
SRCREV_rpmsg-lite ?= "86a3e0a1c0dca76d6db4f13af9b373456f8f0dc2"
SRCREV_soem ?= "53acd56dca133af3817a53d93e0928f5bbc8406e"
SRCREV_freertos-kernel ?= "d763040fc3ec9edcb8b51ff333884e86f5130aec"
SRCREV_els_pkc ?= "71d4a89c03fb32e618ee02c0cd54b3fc92736c96"
SRCREV_psa_crypto_driver ?= "1a93893f986db38cf2c8910f6138b634f0437a48"
SRCREV_cmsis ?= "512cc7e895e8491696b61f7ba8066b4a182569b8"
SRCREV_cmsis_6 ?= "30a859f44ef8ab4dc8f84b03ed586fd16ccf9d74"
SRCREV_libmetal ?= "66e084293b2a7ced5a73fbd247deddba8915883a"
SRCREV_hal_nxp ?= "2c2f28ac333e995d7279777409817c4b4f92c1ec"
SRCREV_open-amp ?= "5efe7974f9546582e99f5a842a816ea4b65f5227"
SRCREV_zephyr ?= "6d1e9c921564dbe1ba37d73563ffefdf43fd4b3b"

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
SRC_URI_SOEM ?= "git://github.com/nxp-real-time-edge-sw/soem;protocol=https"
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
    ${SRC_URI_HMC};branch=${HMC_BRANCH};name=hmc;destsuffix=heterogeneous-multicore \
    ${SRC_URI_CORE_WITH_BRANCH};name=core;destsuffix=mcuxsdk/mcuxsdk \
    ${SRC_URI_MCUXSDK_MANIFESTS_WITH_BRANCH};name=mcuxsdk-manifests;destsuffix=mcuxsdk/mcuxsdk-manifests \
    ${SRC_URI_MCUX_CMSIS_WITH_BRANCH};name=MCUX_CMSIS;destsuffix=mcuxsdk/mcuxsdk/arch/arm/CMSIS \
    ${SRC_URI_MCU_SDK_COMPONENTS_WITH_BRANCH};name=mcu-sdk-components;destsuffix=mcuxsdk/mcuxsdk/components \
    ${SRC_URI_MCUX_DEVICES_KINETIS_WITH_BRANCH};name=mcux-devices-kinetis;destsuffix=mcuxsdk/mcuxsdk/devices/Kinetis \
    ${SRC_URI_MCUX_DEVICES_LPC_WITH_BRANCH};name=mcux-devices-lpc;destsuffix=mcuxsdk/mcuxsdk/devices/LPC \
    ${SRC_URI_MCUX_DEVICES_MCX_WITH_BRANCH};name=mcux-devices-mcx;destsuffix=mcuxsdk/mcuxsdk/devices/MCX \
    ${SRC_URI_MCUX_DEVICES_RT_WITH_BRANCH};name=mcux-devices-rt;destsuffix=mcuxsdk/mcuxsdk/devices/RT \
    ${SRC_URI_MCUX_DEVICES_IMX_WITH_BRANCH};name=mcux-devices-imx;destsuffix=mcuxsdk/mcuxsdk/devices/i.MX \
    ${SRC_URI_MCU_SDK_DOC_WITH_BRANCH};name=mcu-sdk-doc;destsuffix=mcuxsdk/mcuxsdk/docs \
    ${SRC_URI_MCU_SDK_EXAMPLES_WITH_BRANCH};name=mcu-sdk-examples;destsuffix=mcuxsdk/mcuxsdk/examples \
    ${SRC_URI_LVGL_WITH_BRANCH};name=lvgl;destsuffix=mcuxsdk/mcuxsdk/middleware/lvgl \
    ${SRC_URI_LWIP_WITH_BRANCH};name=lwip;destsuffix=mcuxsdk/mcuxsdk/middleware/lwip \
    ${SRC_URI_MCUX_SDK_MIDDLEWARE_MULTICORE_WITH_BRANCH};name=mcux-sdk-middleware-multicore;destsuffix=mcuxsdk/mcuxsdk/middleware/multicore \
    ${SRC_URI_RPMSG_LITE_WITH_BRANCH};name=rpmsg-lite;destsuffix=mcuxsdk/mcuxsdk/middleware/multicore/rpmsg-lite \
    ${SRC_URI_SOEM_WITH_BRANCH};name=soem;destsuffix=mcuxsdk/mcuxsdk/middleware/soem \
    ${SRC_URI_FREERTOS_KERNEL_WITH_BRANCH};name=freertos-kernel;destsuffix=mcuxsdk/mcuxsdk/rtos/freertos/freertos-kernel \
    ${SRC_URI_ELS_PKC_WITH_BRANCH};name=els_pkc;destsuffix=zsdk/modules/crypto/els_pkc \
    ${SRC_URI_PSA_CRYPTO_DRIVER_WITH_BRANCH};name=psa_crypto_driver;destsuffix=zsdk/modules/crypto/psa_crypto_driver \
    ${SRC_URI_CMSIS_WITH_BRANCH};name=cmsis;destsuffix=zsdk/modules/hal/cmsis \
    ${SRC_URI_CMSIS_6_WITH_BRANCH};name=cmsis_6;destsuffix=zsdk/modules/hal/cmsis_6 \
    ${SRC_URI_LIBMETAL_WITH_BRANCH};name=libmetal;destsuffix=zsdk/modules/hal/libmetal \
    ${SRC_URI_HAL_NXP_WITH_BRANCH};name=hal_nxp;destsuffix=zsdk/modules/hal/nxp \
    ${SRC_URI_OPEN_AMP_WITH_BRANCH};name=open-amp;destsuffix=zsdk/modules/lib/open-amp \
    ${SRC_URI_ZEPHYR_WITH_BRANCH};name=zephyr;destsuffix=zsdk/zephyr \
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
PV = "3.5"
