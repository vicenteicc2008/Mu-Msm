#include <PiPei.h>
#include <Library/IoLib.h>
#include <Library/PlatformPrePiLib.h>

VOID PlatformInitialize(VOID)
{
  MmioWrite32(0xFD901E14, 0x03200000);
  MmioWrite32(0xFD901E00 + 0x30, 0x000236FF);
  MmioWrite32(0xFD901E00 + 0x34, 0x03020001);
  MmioWrite32(0xFD901E00 + 0x24, 720*4);
  MmioWrite32(0xFD900600 + 0x18, (1 << (3)));
  MmioWrite32(0xfd900618,0x00000001);
  MmioWrite32(0xfd900718,0x00000001); 

}