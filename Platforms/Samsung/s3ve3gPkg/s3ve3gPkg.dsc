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
  PLATFORM_NAME                  = <Device Codename>
  PLATFORM_GUID                  = <GUID>
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/<Device Codename>Pkg-$(ARCH)
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = DEBUG|RELEASE
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = <Device Codename>Pkg/<Device Codename>.fdf
  # Set this to 1 if your Device has a RGB Display (Newer Devices have BGR instead of RGB)
  DISPLAY_USES_RGBA              = 0
  USE_DISPLAYDXE                 = 0
  # Set this to 1 If your Device is A/B Device
  AB_SLOT_SUPPORT                = 0
  USE_UART                       = 0

  # If your SoC has multimple variants define the Number here
  # If not don't add this Define
  SOC_TYPE                       = 2

# If your SoC has multimple variants keep this Build Option
# If not don't add "-DSOC_TYPE=$(SOC_TYPE)" to the Build Options.
[BuildOptions.common]
  *_*_*_CC_FLAGS = -DSOC_TYPE=$(SOC_TYPE) -DDISPLAY_USES_RGBA=$(DISPLAY_USES_RGBA)

[LibraryClasses.common]
  PlatformMemoryMapLib|<Device Codename>Pkg/Library/PlatformMemoryMapLib/PlatformMemoryMapLib.inf

[PcdsFixedAtBuild.common]
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x00000000    # Starting address
  gArmTokenSpaceGuid.PcdSystemMemorySize|0x60000000    # <RAM Size> GB Size

  gEfiMdeModulePkgTokenSpaceGuid.PcdFirmwareVendor|L"vice2008"

  gArmTokenSpaceGuid.PcdCpuVectorBaseAddress|<CPU Vector Base Address>

  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|<UEFI Stack Base Address>
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|<UEFI Stack Size>

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

!include Msm8226Pkg/Msm8226Pkg.dsc.inc