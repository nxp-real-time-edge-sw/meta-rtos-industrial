# Copyright 2022-2023 NXP

inherit cmake

python () {
    d.delVar('CFLAGS')
    d.delVar('CXXFLAGS')
    d.delVar('LDFLAGS')
}

# IMAGE_NO_MANIFEST = "1"

EXAMPLE_TYPES = "elf bin"
