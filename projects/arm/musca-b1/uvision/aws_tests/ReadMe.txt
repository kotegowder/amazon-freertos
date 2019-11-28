This demo is a work based on:
    1. Amazon FreeRTOS
       commit: 74875b1d2
    2. TF-M (Trusted Firmware M) - https://git.trustedfirmware.org/trusted-firmware-m.git/)
       commit: 85fef5d

Introduction of the test project:
    1. The demo has only one user task which is dedicated for PKCS#11 libray test.
    2. The PKCS#11 library's implementation is based on TF-M which is an implementation of PSA.

How to build:
    1. Software requirements
       a. Please follow the TF-M software requiremnts:
          https://git.trustedfirmware.org/trusted-firmware-m.git/tree/docs/user_guides/tfm_sw_requirement.rst
          to set up build environment
       b. Keil µVision V5.25.2.0 or above
       Note: if you are using CMSIS V5.5.0, git-lfs is required to get the CMSIS_5 large size binaries by git-lfs pull
    2. Download TF-M code
       Make sure it's in the same directory with the Amazon FreeRTOS.
       For example, if the Amazon FreeRTOS is in workspace/Amazon-FreeRTOS-TF-M/Amazon-FreeRTOS
       Then TF-M should be in workspace/Amazon-FreeRTOS-TF-M/trusted-firmware-m
    3. Build TF-M for Musca B1 platform
       a. cd trusted-firmware-m
       b. mkdir build
       c. cd build
       d. build for Library model:
		  cmake -G"Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D CRYPTO_ENGINE_BUF_SIZE=0x8000 -D TFM_NS_CLIENT_IDENTIFICATION=OFF -DTARGET_PLATFORM=MUSCA_B1 -DCOMPILER=ARMCLANG ../
          build for IPC model:
		  cmake -G"Unix Makefiles" -DPROJ_CONFIG=`readlink -f ../configs/ConfigCoreIPCTfmLevel2.cmake` -D CMAKE_BUILD_TYPE=Debug -D CRYPTO_ENGINE_BUF_SIZE=0x8000 -D TFM_NS_CLIENT_IDENTIFICATION=OFF -DTARGET_PLATFORM=MUSCA_B1 -DCOMPILER=ARMCLANG ../
       e. cmake --build ./ -- install
       You can find detailed instructions from:
       https://git.trustedfirmware.org/trusted-firmware-m.git/tree/docs/user_guides/tfm_build_instruction.rst
    4. Build the test project
       Open the Keil project of the test and build. Note that two configurable targets are contained in the project: Library Model and IPC Model(by default)
       The default build is for TF-M IPC model.
       If you want to build for IPC model:
           a. Build TFM in IPC model.
           b. Select target as IPC Model.
           c. Rebuild the project.
       If you want to build for Library Model:
           a. Build TFM in Library model.
           b. Select target as Library Model.
           c. Rebuild the project.
       In both models, the output image is rtos_tfm_MUSCA_B1.hex.

How to debug:
    The default configuration of the project supports debug by CMSIS-DAP ARMv8-M Debugger which is part of Musca-b1. Just click the debug button to start debugging.

How to run the test on Musca-B1 board:
    Download the image(rtos_tfm_MUSCA_B1.hex) to Musca-B1 board following the
    "Execute TF-M example and regression tests on Musca test chip boards" section
    in https://git.trustedfirmware.org/trusted-firmware-m.git/tree/docs/user_guides/tfm_user_guide.rst.

*Copyright (c) 2019, Arm Limited. All rights reserved.*
