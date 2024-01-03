#include <Library/BaseLib.h>
#include <Library/PlatformMemoryMapLib.h>

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
    /* Name               Address     Length      HobOption        ResourceAttribute    ArmAttributes
                                                          ResourceType          MemoryType */

    //------------- DDR Regions ------},
    {"DBI Dump",          0x00010000, 0x00011000, NoHob,  MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},
    {"HLOS 0",            0x00100000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
    {"UEFI FD",           0x00200000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, BsCode, WRITE_BACK},
    {"MPPark Code",       0x00300000, 0x00040000, AddMem, MEM_RES, UNCACHEABLE, RtCode, UNCACHED_UNBUFFERED},
    {"Reser. Uncached1",  0x00340000, 0x00040000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, UNCACHED_UNBUFFERED},
    {"FBPT Payload",      0x00380000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, UNCACHED_UNBUFFERED},
    {"DBG2",              0x00381000, 0x00004000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, UNCACHED_UNBUFFERED},
    {"Capsule Header",    0x00385000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, UNCACHED_UNBUFFERED},
    {"TPM Control Area",  0x00386000, 0x00003000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, UNCACHED_UNBUFFERED},
    {"UEFI Info Block",   0x00389000, 0x00001000, AddMem, SYS_MEM, SYS_MEM_CAP, RtData, UNCACHED_UNBUFFERED},
    {"Reser. Uncached0",  0x0038A000, 0x00076000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, UNCACHED_UNBUFFERED},
    {"Display Reserved",  0x03200000, 0x00800000, AddMem, MEM_RES, WRITE_THROUGH, MaxMem, WRITE_THROUGH},
    {"UEFI Stack",        0x00C00000, 0x00040000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {"CPU Vectors",       0x00C40000, 0x00010000, AddMem, SYS_MEM, SYS_MEM_CAP, BsCode, WRITE_BACK},
    {"Reser. Cached 0",   0x00C50000, 0x000B0000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {"HLOS 1",            0x00D00000, 0x07300000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
    {"PIL_REGION",        0x08000000, 0x07700000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE},
    {"TZ Apps",           0x0F700000, 0x00300000,          AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE},
    {"SMEM",              0x0FA00000, 0x00100000, AddMem, MEM_RES, UNCACHEABLE, Reserv, UNCACHED_UNBUFFERED},
    {"HLOS 2",            0x0FB00000, 0x00100000, AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
    {"NonRelocateable 0", 0x0FC00000, 0x00300000, AddMem, SYS_MEM, SYS_MEM_CAP, Reserv, NS_DEVICE},
    {"BGRT Logo",         0x0FF00000, 0x00300000, AddMem, SYS_MEM, SYS_MEM_CAP, BsData, WRITE_BACK},
    {"HLOS 5",            0x10200000, 0x4FE00000,           AddMem, SYS_MEM, SYS_MEM_CAP, Conv,   WRITE_BACK},
    //------------- Other Memory Regions ------
    {"IMEM Boot Base",    0xFE800000, 0x00004000, NoHob,  SYS_MEM, INITIALIZED, Conv,   NS_DEVICE},
    {"IMEM Cookie Base",  0xFC42B000, 0x00001000, AddDev, MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},
    {"IMEM Cookie Base2", 0xFE805000, 0x00001000, AddDev, MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},
    {"RPM CODE_DATARAM Dump 2", 0xFE805000, 0x00001000, HobOnlyNoCacheSetting, MMAP_IO, INITIALIZED, Conv,   NS_DEVICE},
    //------------- Register Regions ----------
    {"REG 1", 0xF9000000, 0x02000000, AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},
    {"REG 2", 0xFC400000, 0x00002000, AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},
    {"REG 3", 0xFC428000, 0x00008000, AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},
    {"REG 4", 0xFC4AB000, 0x00001000, AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},
    {"REG 5", 0xFC4C0000, 0x00040000, AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},
    {"REG 6", 0xFD400000, 0x00D00000, AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},
    {"REG 7", 0xFC4B8000, 0x00008000, AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},
    {"REG 8", 0xFC4A9000, 0x00008000, AddDev, MMAP_IO,  UNCACHEABLE, MmIO,   NS_DEVICE},

    /* Terminator for MMU */
    {"Terminator", 0, 0, 0, 0, 0, 0, 0}};

ARM_MEMORY_REGION_DESCRIPTOR_EX *GetPlatformMemoryMap()
{
    return gDeviceMemoryDescriptorEx;
}