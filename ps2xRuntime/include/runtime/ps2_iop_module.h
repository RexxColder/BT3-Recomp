#pragma once
// [iop] IRX (IOP module) loader.
//
// IOP modules shipped in the game data (data/IRX/*.IRX) are plain ELF32 little-endian
// MIPS images with an extra IOP-specific segment (p_type 0x70000080) that carries the
// module header. This parses the ELF into loadable segments + the entry point so the
// runtime can (a) map the module and (b) dispatch to R3000-recompiled functions.

#include <cstdint>
#include <string>
#include <vector>

namespace ps2iop
{
    struct Segment
    {
        uint32_t vaddr = 0;
        uint32_t filesz = 0;
        uint32_t memsz = 0;
        uint32_t flags = 0;
        bool iopHeader = false;          // p_type 0x70000080
        std::vector<uint8_t> data;       // filesz bytes from the image
    };

    struct Reloc
    {
        uint32_t offset = 0;   // r_offset
        uint32_t symbol = 0;   // r_info >> 8
        uint8_t type = 0;      // r_info & 0xff (R_MIPS_26=4, R_MIPS_HI16=5, R_MIPS_LO16=6, R_MIPS_32=2)
    };

    struct Module
    {
        std::string name;                // basename of the file
        std::string moduleName;          // name from the IOP header (34-byte .iopmod)
        uint32_t entry = 0;              // IOP header entry (== e_entry)
        uint32_t gp = 0;                 // IOP header global pointer
        uint32_t hdrText = 0, hdrData = 0, hdrBss = 0;   // IOP header sizes
        std::vector<Segment> segments;   // PT_LOAD (+ IOP header)
        uint32_t textVaddr = 0, textSize = 0;   // the main loadable segment
        std::vector<Reloc> relocs;       // .rel.text / .rel.data
    };

    bool loadIrx(const std::string &path, Module &out);
}
