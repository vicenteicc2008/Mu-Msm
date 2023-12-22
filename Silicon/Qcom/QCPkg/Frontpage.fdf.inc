  INF MsGraphicsPkg/GopOverrideDxe/GopOverrideDxe.inf
  INF MsCorePkg/MuCryptoDxe/MuCryptoDxe.inf
  INF DfciPkg/SettingsManager/SettingsManagerDxe.inf
  INF MsGraphicsPkg/MsUiTheme/Dxe/MsUiThemeProtocol.inf
  INF MsGraphicsPkg/RenderingEngineDxe/RenderingEngineDxe.inf
  INF MsGraphicsPkg/DisplayEngineDxe/DisplayEngineDxe.inf
  INF OemPkg/BootMenu/BootMenu.inf
  INF QCPkg/FrontPage/FrontPage.inf
  INF PcBdsPkg/MsBootPolicy/MsBootPolicy.inf
  INF MdeModulePkg/Universal/BootManagerPolicyDxe/BootManagerPolicyDxe.inf
  INF DfciPkg/DfciManager/DfciManager.inf
  INF MsGraphicsPkg/OnScreenKeyboardDxe/OnScreenKeyboardDxe.inf
  INF MsGraphicsPkg/SimpleWindowManagerDxe/SimpleWindowManagerDxe.inf
  INF MsGraphicsPkg/MsEarlyGraphics/Dxe/MsEarlyGraphics.inf

  INF MsCorePkg/AcpiRGRT/AcpiRgrt.inf

  INF QCPkg/DfciMenu/DfciMenu.inf

  FILE FREEFORM = PCD(gOemPkgTokenSpaceGuid.PcdLogoFile) {
    SECTION RAW = QCPkg/Resources/BootLogo.bmp
    SECTION UI = "Logo"
  }

  FILE APPLICATION = PCD(gPcBdsPkgTokenSpaceGuid.PcdShellFile) {
    SECTION PE32 = $(OUTPUT_DIRECTORY)/$(TARGET)_$(TOOL_CHAIN_TAG)/ARM/Shell.efi
    SECTION UI = "Shell"
  }

  FILE FREEFORM = PCD(gQcomPkgTokenSpaceGuid.PcdNoBootOSFile) {
    SECTION RAW = QCPkg/Resources/NoBootOS.bmp
  }

  FILE FREEFORM = PCD(gOemPkgTokenSpaceGuid.PcdFrontPageLogoFile) {
    SECTION RAW = QCPkg/FrontPage/Resources/FrontpageLogo.bmp
  }

  FILE FREEFORM = PCD(gOemPkgTokenSpaceGuid.PcdLowBatteryFile) {
    SECTION RAW = QCPkg/Resources/LBAT.bmp
  }

  FILE FREEFORM = PCD(gOemPkgTokenSpaceGuid.PcdThermalFile) {
    SECTION RAW = QCPkg/Resources/THOT.bmp
  }

  FILE FREEFORM = PCD(gOemPkgTokenSpaceGuid.PcdVolumeUpIndicatorFile) {
    SECTION RAW = QCPkg/FrontPage/Resources/VolumeUp.bmp
  }

  FILE FREEFORM = PCD(gOemPkgTokenSpaceGuid.PcdFirmwareSettingsIndicatorFile) {
    SECTION RAW = QCPkg/FrontPage/Resources/FirmwareSettings.bmp
  }

  FILE FREEFORM = PCD(gOemPkgTokenSpaceGuid.PcdBootFailIndicatorFile) {
    SECTION RAW = QCPkg/FrontPage/Resources/NoBoot.bmp
  }
