#include <Library/BaseLib.h>
#include <Library/PlatformMemoryMapLib.h>

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
    /* Name               Address     Length      HobOption        ResourceAttribute    ArmAttributes
                                                          ResourceType          MemoryType */

    //------------- DDR Regions ------},
    {0x00010000, 0x00011000, "DBI Dump",         NoHob,  MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},
    {0x00100000, 0x00100000, "HLOS 0",           AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
    {0x00200000, 0x00100000, "UEFI FD",          AddMem, SYS_MEM, SYS_MEM_CAP, BsCode, WRITE_BACK},
    {0x00300000, 0x00040000, "MPPark Code",      AddMem, MEM_RES, UNCACHEABLE, RtCode, UNCACHED_UNBUFFERED},
    {0x00340000, 0x00040000, "Reser. Uncached1", AddMem, SYS_MEM, SYS_MEM_CAP, BsData, UNCACHED_UNBUFFERED},
    {0x00380000, 0x00001000, "FBPT Payload",     AddMem, SYS_MEM, SYS_MEM_CAP, RtData, UNCACHED_UNBUFFERED},
    {0x00381000, 0x00004000, "DBG2",             AddMem, SYS_MEM, SYS_MEM_CAP, RtData, UNCACHED_UNBUFFERED},
    {0x00385000, 0x00001000, "Capsule Header",   AddMem, SYS_MEM, SYS_MEM_CAP, RtData, UNCACHED_UNBUFFERED},
    {0x00386000, 0x00003000, "TPM Control Area", AddMem, SYS_MEM, SYS_MEM_CAP, RtData, UNCACHED_UNBUFFERED},
    {0x00389000, 0x00001000, "UEFI Info Block",  AddMem, SYS_MEM, SYS_MEM_CAP, RtData, UNCACHED_UNBUFFERED},
    {0x0038A000, 0x00076000, "Reser. Uncached0", AddMem, SYS_MEM, SYS_MEM_CAP, BsData, UNCACHED_UNBUFFERED},
    {0x00400000, 0x00800000, "Display Reserved", AddMem, MEM_RES, WRITE_THROUGH, MaxMem, WRITE_THROUGH},
    {0x00C00000, 0x00040000, "UEFI Stack",       AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {0x00C40000, 0x00010000, "CPU Vectors",      AddMem, SYS_MEM, SYS_MEM_CAP, BsCode, WRITE_BACK},
    {0x00C50000, 0x000B0000, "Reser. Cached 0",  AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {0x00D00000, 0x07300000, "HLOS 1",           AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
    {0x08000000, 0x07700000, "PIL_REGION",       AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE},
    {0x0F700000, 0x00300000, "TZ Apps",          AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE},
    {0x0FA00000, 0x00100000, "SMEM",             AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED},
    {0x0FB00000, 0x00100000, "HLOS 2",           AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
    {0x0FC00000, 0x00300000, "NonRelocateable 0",AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE},
    {0x0FF00000, 0x00300000, "BGRT Logo",        AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {0x10200000, 0x4FE00000, "HLOS 5",           AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
    //------------- Other Memory Regions ------
    {0xFE800000, 0x00004000, "IMEM Boot Base",   NoHob,  SYS_MEM, INITIALIZED, Conv,   NS_DEVICE},
    {0xFC42B000, 0x00001000, "IMEM Cookie Base", AddDev, MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},
    {0xFE805000, 0x00001000, "IMEM Cookie Base2",AddDev, MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},
    {0xFE805000, 0x00001000, "RPM CODE_DATARAM Dump 2", HobOnlyNoCacheSetting, MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},
    //------------- Register Regions ----------
    {0xF9000000, 0x02000000, "REG 1",           AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},
    {0xFC400000, 0x00002000, "REG 2",           AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},
    {0xFC428000, 0x00008000, "REG 3",           AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},
    {0xFC4AB000, 0x00001000, "REG 4",           AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},
    {0xFC4C0000, 0x00040000, "REG 5",           AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},
    {0xFD400000, 0x00D00000, "REG 6",           AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},
    {0xFC4B8000, 0x00008000, "REG 7",           AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},
    {0xFC4A9000, 0x00008000, "REG 8",           AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},

    /* Terminator for MMU */
    {"Terminator", 0, 0, 0, 0, 0, 0, 0}};

ARM_MEMORY_REGION_DESCRIPTOR_EX *GetPlatformMemoryMap()
{
    return gDeviceMemoryDescriptorEx;
}