#include "afs_archive.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <vector>

namespace
{

namespace fs = std::filesystem;

constexpr char kAfsMagic[4] = {'A', 'F', 'S', 0};
constexpr char kIdxMagic[8] = {'D', 'B', 'Z', 'A', 'F', 'S', '0', '1'};

enum Type : uint32_t
{
    T_OTHER = 0,
    T_MODEL = 1,
    T_ANIM = 2,
    T_EFF = 3,
    T_PAK1 = 4,
    T_PAK3 = 5,
    T_Q1 = 6,
    T_S12C = 7,
    T_R19 = 8,
    T_GS = 9,
    T_PAK2 = 10,
};

uint32_t classify(const uint8_t *head, uint32_t avail)
{
    if (avail < 8)
        return T_OTHER;
    uint32_t w0, w1;
    std::memcpy(&w0, head, 4);
    std::memcpy(&w1, head + 4, 4);
    if (w0 == 0xFC && w1 == 0x400) return T_MODEL;
    if (w0 == 0x1B8 && w1 == 0x700) return T_ANIM;
    if (w0 == 0x6 && w1 == 0x40) return T_EFF;
    if (w0 == 0x1 && w1 == 0x40) return T_PAK1;
    if (w0 == 0x3 && w1 == 0x40) return T_PAK3;
    if (w0 == 0x1 && w1 == 0x8) return T_Q1;
    if (w0 == 0x12C && w1 == 0x4C0) return T_S12C;
    if (w0 == 0x19 && w1 == 0x80) return T_R19;
    if (w0 == 0x435347) return T_GS;
    if (w0 == 0x2 && w1 == 0x40) return T_PAK2;
    return T_OTHER;
}

struct Entry
{
    uint32_t off = 0;
    uint32_t size = 0;
    uint32_t type = 0;
};

struct Slot
{
    Entry en;
    uint32_t slotBytes = 0;
};

bool readFile(const fs::path &p, std::vector<uint8_t> &out)
{
    std::FILE *f = std::fopen(p.string().c_str(), "rb");
    if (!f)
        return false;
    std::fseek(f, 0, SEEK_END);
    long sz = std::ftell(f);
    std::fseek(f, 0, SEEK_SET);
    if (sz < 0)
    {
        std::fclose(f);
        return false;
    }
    out.resize(static_cast<size_t>(sz));
    if (sz > 0 && std::fread(out.data(), 1, static_cast<size_t>(sz), f) != static_cast<size_t>(sz))
    {
        std::fclose(f);
        return false;
    }
    std::fclose(f);
    return true;
}

bool parseAfs(const fs::path &p, std::vector<Entry> &entries)
{
    std::vector<uint8_t> data;
    if (!readFile(p, data))
        return false;
    if (data.size() < 8)
        return false;
    uint32_t magic = 0;
    std::memcpy(&magic, data.data(), 4);
    if (std::memcmp(&magic, kAfsMagic, 4) != 0)
        return false;
    uint32_t count = 0;
    std::memcpy(&count, data.data() + 4, 4);
    if (data.size() < 8ull + count * 8ull)
        return false;

    entries.clear();
    entries.reserve(count);
    for (uint32_t i = 0; i < count; ++i)
    {
        uint32_t off, sz;
        std::memcpy(&off, data.data() + 8 + i * 8, 4);
        std::memcpy(&sz, data.data() + 8 + i * 8 + 4, 4);
        uint32_t type = T_OTHER;
        if (static_cast<uint64_t>(off) + 8 <= data.size())
            type = classify(data.data() + off, std::min<uint32_t>(sz, 8));
        entries.push_back({off, sz, type});
    }
    return true;
}

std::vector<Slot> computeSlots(const std::vector<Entry> &rows, uint32_t afsBytes,
                               uint32_t &outDataStart)
{
    std::vector<Slot> slots;
    outDataStart = afsBytes;
    for (const auto &en : rows)
        if (en.size > 0 && en.off < outDataStart)
            outDataStart = en.off;
    for (const auto &en : rows)
    {
        if (en.size == 0) // skip sentinel / empty rows
            continue;
        uint32_t nextOff = afsBytes;
        for (const auto &o : rows)
            if (o.off > en.off && o.off < nextOff)
                nextOff = o.off;
        if (en.off >= nextOff)
            nextOff = std::min<uint32_t>(en.off + en.size, afsBytes);
        if (en.off > afsBytes)
            continue;
        slots.push_back({en, nextOff - en.off});
    }
    std::sort(slots.begin(), slots.end(),
              [](const Slot &a, const Slot &b) { return a.en.off < b.en.off; });
    return slots;
}

void writeU32(std::vector<uint8_t> &out, uint32_t v)
{
    out.push_back(static_cast<uint8_t>(v));
    out.push_back(static_cast<uint8_t>(v >> 8));
    out.push_back(static_cast<uint8_t>(v >> 16));
    out.push_back(static_cast<uint8_t>(v >> 24));
}

} // namespace

AfsConvertResult convertAfsToFolder(const std::string &afsPath, const std::string &outDir,
                                    const std::function<void(const std::string &)> &onStatus,
                                    const std::function<void(uint64_t, uint64_t)> &onProgress)
{
    using namespace std::literals;

    auto fail = [](std::string msg) { return AfsConvertResult{false, std::move(msg)}; };

    const fs::path src(afsPath);
    const fs::path base = src.filename().stem();

    std::vector<Entry> entries;
    if (!parseAfs(src, entries))
        return fail("cannot read " + src.string() + " as an AFS container");

    std::error_code ec;
    fs::path dir = fs::path(outDir) / base.string();
    fs::create_directories(dir, ec);
    if (ec)
        return fail("cannot create " + dir.string());
    if (onStatus)
        onStatus("reading " + base.string() + " index");

    std::vector<uint8_t> afs;
    if (!readFile(src, afs))
        return fail("cannot read " + src.string());
    if (afs.size() > UINT32_MAX)
        return fail(src.string() + " too large for the index");
    const uint32_t afsBytes = static_cast<uint32_t>(afs.size());

    uint32_t dataStart = 0;
    std::vector<Slot> slots = computeSlots(entries, afsBytes, dataStart);
    const uint64_t total = 2ull * afsBytes;
    uint64_t done = 0;

    // Slot files: exact physical slices [off, nextOff), padding preserved.
    if (onStatus)
        onStatus("extracting " + base.string() + " entries (" +
                 std::to_string(slots.size()) + " slots)");
    for (size_t i = 0; i < slots.size(); ++i)
    {
        const Slot &s = slots[i];
        if (static_cast<uint64_t>(s.en.off) + s.slotBytes > afs.size())
            return fail("entry out of range in " + src.string());
        char name[32];
        std::snprintf(name, sizeof(name), "%06zu", i);
        std::FILE *f = std::fopen((dir / name).string().c_str(), "wb");
        if (!f)
            return fail("cannot write " + (dir / name).string());
        const size_t written = std::fwrite(afs.data() + s.en.off, 1, s.slotBytes, f);
        std::fclose(f);
        if (written != s.slotBytes)
            return fail("short write " + (dir / name).string());
        done += s.slotBytes;
        if (onProgress)
            onProgress(done, total);
    }

    // Index blob + slot table (idx v2), byte-exact reassembly contract.
    std::vector<uint8_t> idx;
    idx.insert(idx.end(), kIdxMagic, kIdxMagic + 8);
    writeU32(idx, 2u);
    writeU32(idx, static_cast<uint32_t>(slots.size()));
    writeU32(idx, afsBytes);
    writeU32(idx, dataStart);
    for (const auto &s : slots)
    {
        writeU32(idx, s.en.off);
        writeU32(idx, s.en.size);
        writeU32(idx, s.slotBytes);
        writeU32(idx, s.en.type);
    }
    idx.insert(idx.end(), afs.begin(), afs.begin() + dataStart);

    const fs::path idxPath = fs::path(outDir) / (base.string() + ".idx");
    {
        std::FILE *f = std::fopen(idxPath.string().c_str(), "wb");
        if (!f)
            return fail("cannot write " + idxPath.string());
        const bool ok = std::fwrite(idx.data(), 1, idx.size(), f) == idx.size();
        std::fclose(f);
        if (!ok)
            return fail("short write " + idxPath.string());
    }

    // Byte-for-byte verification before the caller drops the source .AFS.
    if (onStatus)
        onStatus("verifying " + base.string());
    for (size_t i = 0; i < slots.size(); ++i)
    {
        const Slot &s = slots[i];
        char name[32];
        std::snprintf(name, sizeof(name), "%06zu", i);
        std::vector<uint8_t> got;
        if (!readFile(dir / name, got) || got.size() != s.slotBytes ||
            std::memcmp(got.data(), afs.data() + s.en.off, s.slotBytes) != 0)
            return fail("verification mismatch at slot " + std::to_string(i) + " of " +
                        src.string());
        done += s.slotBytes;
        if (onProgress)
            onProgress(done, total);
    }

    return AfsConvertResult{true, std::string()};
}