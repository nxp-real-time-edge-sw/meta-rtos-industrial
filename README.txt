Building RTOS Industrial Example via bitbake recipes
==========================================

Prerequisites:
==============

This layer depends on:
    Yocto distro
        git://git.yoctoproject.org/poky

Download the layers

git clone -b hardknott git://git.yoctoproject.org/poky
git clone -b hardknott git://git.openembedded.org/meta-openembedded

Setup build environment

source poky/oe-init-build-env build-rtos-industrial

Modify local conf by adding:
    MACHINE = "evkbimxrt1050"
    DISTRO = "rtos-industrial"

Add layers

bitbake-layers add-layer ../meta-openembedded/meta-oe
bitbake-layers add-layer ../meta-rtos-industrial

Building Samples
===================================

You can build rtos-industrial examples. There are several sample recipes.
For example, to build the "hello world" sample:

    $ bitbake demo-hello-world