#include "runtime/ps2_iop_module.h"

#include <cstdio>
#include <cstring>
#include <filesystem>

namespace ps2iop
{
namespace
{
    constexpr uint32_t PT_LOAD = 1;
    constexpr uint32_t PT_IOP = 0x70000080;

    uint16_t rdU16(const uint8_t *p) { return (uint16_t)(p[0] | (p[1] << 8)); }
    uint32_t rdU32(const uint8_t *p)
    { return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24); }

    bool readAll(const std::string &path, std::vector<uint8_t> &out)
    {
        std::FILE *f = std::fopen(path.c_str(), "rb");
        if (!f) return false;
        std::fseek(f, 0, SEEK_END);
        long sz = std::ftell(f);
        std::fseek(f, 0, SEEK_SET);
        if (sz < 0) { std::fclose(f); return false; }
        out.resize((size_t)sz);
        const bool ok = (sz == 0) || std::fread(out.data(), 1, (size_t)sz, f) == (size_t)sz;
        std::fclose(f);
        return ok;
    }
}

bool loadIrx(const std::string &path, Module &out)
{
    std::vector<uint8_t> d;
    if (!readAll(path, d)) return false;
    if (d.size() < 52 || std::memcmp(d.data(), "\x7f" "ELF", 4) != 0) return false;
    if (d[4] != 1 || d[5] != 1) return false;   // ELF32 little-endian

    out = Module{};
    out.name = std::filesystem::path(path).filename().string();
    out.entry = rdU32(d.data() + 24);
    const uint32_t phoff = rdU32(d.data() + 28);
    const uint16_t phentsize = rdU16(d.data() + 42);
    const uint16_t phnum = rdU16(d.data() + 44);

    uint32_t bestFilesz = 0;
    for (uint16_t i = 0; i < phnum; ++i)
    {
        const size_t off = phoff + (size_t)i * phentsize;
        if (off + 32 > d.size()) break;
        const uint32_t pType = rdU32(d.data() + off);
        const uint32_t pOffset = rdU32(d.data() + off + 4);
        const uint32_t pVaddr = rdU32(d.data() + off + 8);
        const uint32_t pFilesz = rdU32(d.data() + off + 16);
        const uint32_t pMemsz = rdU32(d.data() + off + 20);
        const uint32_t pFlags = rdU32(d.data() + off + 24);
        if (pType != PT_LOAD && pType != PT_IOP) continue;

        Segment s;
        s.vaddr = pVaddr; s.filesz = pFilesz; s.memsz = pMemsz; s.flags = pFlags;
        s.iopHeader = (pType == PT_IOP);
        if (pOffset + pFilesz <= d.size())
            s.data.assign(d.begin() + pOffset, d.begin() + pOffset + pFilesz);

        // NOTE: the IOP header segment (p_type 0x70000080) carries the module metadata, but its
        // layout is not a leading ASCII name; decode it when the R3000 runtime needs it. For now
        // moduleName stays empty and the loader exposes only segments + entry.

        // The main loadable segment (largest filesz) is the code+data image.
        if (pType == PT_LOAD && pFilesz > bestFilesz)
        {
            bestFilesz = pFilesz;
            out.textVaddr = pVaddr;
            out.textSize = pFilesz;
        }
        out.segments.push_back(std::move(s));
    }
    return !out.segments.empty();
}
}
