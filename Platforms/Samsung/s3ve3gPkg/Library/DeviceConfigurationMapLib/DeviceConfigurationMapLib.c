#include <Library/BaseLib.h>
#include <Library/DeviceConfigurationMapLib.h>

STATIC
CONFIGURATION_DESCRIPTOR_EX
gDeviceConfigurationDescriptorEx[] = {
  {"EnableShell", 0x1},
  {"NumCpus", 4},
  {"NumActiveCores", 4},
  {"MaxCoreCnt", 4},

  /* Terminator */
  {"Terminator", 0xFFFFFFFF}
};

CONFIGURATION_DESCRIPTOR_EX
*GetDeviceConfigurationMap()
{
  return gDeviceConfigurationDescriptorEx;
}