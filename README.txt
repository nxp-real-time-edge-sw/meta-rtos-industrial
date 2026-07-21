Building RTOS Industrial Example via bitbake recipes
====================================================

The meta-rtos-industrial is integrated into Real-time Edge and doesn't require
specific commands or settings to enable building the rtos application.
When building nxp-image-real-time-edge image, all examples defined in 
packagegroup-real-time-edge-rtos.bb are built and installed into "/examples"
folder.

More information at: https://www.nxp.com/docs/en/user-guide/RTEDGEYOCTOUG.pdf


Building example
================
Use the below commands to create nxp-image-real-time-edge image for the 
imx8mm-lpddr4-evk board.

    $ mkdir yocto-real-time-edge
    $ cd yocto-real-time-edge
    $ repo init -u https://github.com/nxp-real-time-edge-sw/yocto-real-time-edge.git \
          -b real-time-edge-wrynose -m real-time-edge-3.5.0.xml
    $ repo sync
    $ DISTRO=nxp-real-time-edge MACHINE=imx8mm-lpddr4-evk \
          source real-time-edge-setup-env.sh -b build-real-time-edge
    $ bitbake nxp-image-real-time-edge

To compile a specific example, use the following command:

    $ DISTRO=nxp-real-time-edge MACHINE=imx8mm-lpddr4-evk bitbake demo-hello-world

