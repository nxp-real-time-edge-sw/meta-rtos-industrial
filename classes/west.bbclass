# west.bbclass - Support for building MCUXSDK, HMC applications with west
#
# This class provides support for building applications using
# the west meta-tool.

inherit python3native

# Add west and Zephyr build dependencies
DEPENDS += " \
    west-native \
    cmake-native \
    ninja-native \
    dtc-native \
    python3-pyelftools-native \
    python3-pyyaml-native \
    python3-pykwalify-native \
    python3-jsonschema-native \
    python3-jinja2-native \
    python3-packaging-native \
"
