# Copyright 2022 NXP

SUMMARY = "Real-time Edge RTOS industrial examples"

LICENSE = "MIT"

IMAGE_INSTALL_append = " \
    demo-hello-world \
    driver-gpio-led-output \
    freertos-hello \
"
