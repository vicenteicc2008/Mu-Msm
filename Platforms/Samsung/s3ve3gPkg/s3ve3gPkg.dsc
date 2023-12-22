## @file
#
#  Copyright (c) 2011-2015, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.
#  Copyright (c) 2018 - 2019, Bingxing Wang. All rights reserved.
#  Copyright (c) 2022, Xilin Wu. All rights reserved.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = s3ve3g
  PLATFORM_GUID                  = 630d1379-7d3f-4511-a6f9-578abbc07518
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/s3ve3gPkg-$(ARCH)
  SUPPORTED_ARCHITECTURES        = ARM
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = s3ve3gPkg/s3ve3gPkg.fdf

[LibraryClasses.common]
  PlatformMemoryMapLib|s3ve3gPkg/Library/PlatformMemoryMapLib/PlatformMemoryMapLib.inf

[PcdsFixedAtBuild.common]
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x00000000    # Starting address
  gArmTokenSpaceGuid.PcdSystemMemorySize|0x60000000    # 1.5 GB Size

  gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareVendor|L"vice2008"

  gArmTokenSpaceGuid.PcdCpuVectorBaseAddress|0x00C40000

  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|0x00C00000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|0x00040000

  # SmBios
  gQcomPkgTokenSpaceGuid.PcdSmbiosSystemVendor|"Samsung"
  gQcomPkgTokenSpaceGuid.PcdSmbiosSystemModel|"Galaxy S3 Neo"
  gQcomPkgTokenSpaceGuid.PcdSmbiosSystemRetailModel|"s3ve3gds"
  gQcomPkgTokenSpaceGuid.PcdSmbiosSystemRetailSku|"Galaxy_S3_Neo_s3ve3gds"
  gQcomPkgTokenSpaceGuid.PcdSmbiosBoardModel|"Galaxy S3 Neo"

  # Simple FrameBuffer
  gQcomPkgTokenSpaceGuid.PcdMipiFrameBufferWidth|720
  gQcomPkgTokenSpaceGuid.PcdMipiFrameBufferHeight|1280
  gQcomPkgTokenSpaceGuid.PcdMipiFrameBufferPixelBpp|32

[PcdsDynamicDefault.common]
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|720
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|1280
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|720
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|1280
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutColumn|37
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutRow|160
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutColumn|37
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutRow|160

!include Msm8226Pkg/Msm8226.dsc.inc
