## @file
#
#  Copyright (c) 2011-2015, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2016, Intel Corporation. All rights reserved.
#  Copyright (c) 2018 - 2019, Bingxing Wang. All rights reserved.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
#
##

# SoC Defines
[Defines]
  USE_PHYSICAL_TIMER = 0

[BuildOptions.common]
  *_*_ARM_CC_FLAGS = -march=armv7-a+crypto+rcpc

[PcdsFixedAtBuild.common]
  gArmTokenSpaceGuid.PcdArmArchTimerFreqInHz|19200000
  gArmTokenSpaceGuid.PcdArmArchTimerSecIntrNum|2
  gArmTokenSpaceGuid.PcdArmArchTimerIntrNum|3
  gArmTokenSpaceGuid.PcdArmArchTimerVirtIntrNum|4
  gArmTokenSpaceGuid.PcdArmArchTimerHypIntrNum|1
  gArmTokenSpaceGuid.PcdGicDistributorBase|0xf9000000
  gArmTokenSpaceGuid.PcdGicRedistributorsBase|0xf9002000
  gArmTokenSpaceGuid.PcdGicInterruptInterfaceBase|0xf9000000

  gEfiMdeModulePkgTokenSpaceGuid.PcdAcpiDefaultOemRevision|0x00008226
  gEmbeddedTokenSpaceGuid.PcdInterruptBaseAddress|0xf9000000

  gQcomPkgTokenSpaceGuid.PcdSmbiosProcessorModel|"Snapdragon (TM) 400 @ 1.40 GHz"
  gQcomPkgTokenSpaceGuid.PcdSmbiosProcessorRetailModel|"MSM8226"

  gArmPlatformTokenSpaceGuid.PcdCoreCount|4
  gArmPlatformTokenSpaceGuid.PcdClusterCount|1

[LibraryClasses.common]
  PlatformPeiLib|Msm8226Pkg/Library/PlatformPeiLib/PlatformPeiLib.inf
  PlatformPrePiLib|Msm8226Pkg/Library/PlatformPrePiLib/PlatformPrePiLib.inf
  HwResetSystemLib|ArmPkg/Library/ArmSmcPsciResetSystemLib/ArmSmcPsciResetSystemLib.inf
  ResetSystemLib|ArmPkg/Library/ArmSmcPsciResetSystemLib/ArmSmcPsciResetSystemLib.inf

[Components.common]

!include QCPkg/QcomPkg.dsc.inc
