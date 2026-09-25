#include "runtime/dragonnet_assets.h"

#include "ps2_runtime.h"                      // PS2Runtime::getIoPaths, used by getConfiguredCdRoot
#include "Kernel/Syscalls/Helpers/Path.h"     // getConfiguredCdRoot()

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <string>

namespace dragonnet
{
namespace
{
    constexpr char kMagic[] = "DRAGONNET";
    constexpr size_t kMagicLen = sizeof(kMagic) - 1;   // 9
    constexpr uint32_t kVersion = 1;
    constexpr const char *kInstalledName = "NETPLAY.BIN";
    constexpr const char *kSourceName = "dragonnet_assets.bin";

    struct Entry
    {
        std::string name;
        uint32_t offset = 0;
        uint32_t size = 0;
    };

    struct Blob
    {
        bool ok = false;
        std::vector<uint8_t> bytes;
        std::vector<Entry> entries;
    };

    uint16_t rdU16(const uint8_t *p) { return (uint16_t)(p[0] | (p[1] << 8)); }
    uint32_t rdU32(const uint8_t *p)
    { return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24); }

    std::vector<uint8_t> readAll(const std::filesystem::path &path)
    {
        std::vector<uint8_t> out;
        std::FILE *f = std::fopen(path.string().c_str(), "rb");
        if (!f) return out;
        std::fseek(f, 0, SEEK_END);
        const long sz = std::ftell(f);
        std::fseek(f, 0, SEEK_SET);
        if (sz > 0)
        {
            out.resize((size_t)sz);
            if (std::fread(out.data(), 1, (size_t)sz, f) != (size_t)sz) out.clear();
        }
        std::fclose(f);
        return out;
    }

    // Where the art lives once installed, and the build-time copy it comes from.
    std::filesystem::path installedPath()
    {
        const std::filesystem::path cd = getConfiguredCdRoot();
        return cd.empty() ? std::filesystem::path() : cd / kInstalledName;
    }

    // No GetModuleFileName here on purpose: windows.h collides with raylib's Rectangle in
    // the unity build. The CD root is <exe>/data in every layout this project ships, so its
    // parent is the executable's directory, and that is also where CMake stages the blob.
    std::filesystem::path exeDir()
    {
        const std::filesystem::path cd = getConfiguredCdRoot();
        if (cd.empty() || !cd.has_parent_path()) return {};
        return cd.parent_path();
    }

    std::vector<std::filesystem::path> candidates()
    {
        std::vector<std::filesystem::path> out;
        if (const char *env = std::getenv("PS2X_DRAGONNET_ASSETS"); env && env[0])
            out.emplace_back(env);
        if (const std::filesystem::path p = installedPath(); !p.empty())
            out.push_back(p);
        if (const std::filesystem::path d = getConfiguredCdRoot(); !d.empty())
            out.push_back(d / kSourceName);
        if (const std::filesystem::path d = exeDir(); !d.empty())
            out.push_back(d / kSourceName);
        std::error_code ec;
        if (const std::filesystem::path cwd = std::filesystem::current_path(ec); !ec)
            out.push_back(cwd / kSourceName);
        return out;
    }

    const Blob &blob()
    {
        static const Blob b = [] {
            Blob r;
            for (const auto &p : candidates())
            {
                std::vector<uint8_t> data = readAll(p);
                if (data.empty()) continue;
                if (data.size() < kMagicLen + 8 || std::memcmp(data.data(), kMagic, kMagicLen) != 0)
                {
                    std::fprintf(stderr, "[netmenu-assets] %s is not a DragonNet blob\n", p.string().c_str());
                    continue;
                }
                uint32_t version = 0, count = 0;
                std::memcpy(&version, data.data() + kMagicLen, 4);
                std::memcpy(&count, data.data() + kMagicLen + 4, 4);
                if (version != kVersion)
                {
                    std::fprintf(stderr, "[netmenu-assets] %s: unsupported version %u\n", p.string().c_str(), version);
                    continue;
                }
                size_t pos = kMagicLen + 8;
                bool sane = true;
                for (uint32_t i = 0; i < count && sane; ++i)
                {
                    if (pos + 2 > data.size()) { sane = false; break; }
                    const uint16_t nlen = rdU16(data.data() + pos);
                    pos += 2;
                    if (pos + nlen + 8 > data.size()) { sane = false; break; }
                    Entry e;
                    e.name.assign((const char *)data.data() + pos, nlen);
                    pos += nlen;
                    e.offset = rdU32(data.data() + pos);
                    e.size = rdU32(data.data() + pos + 4);
                    pos += 8;
                    if ((size_t)e.offset + e.size > data.size()) { sane = false; break; }
                    r.entries.push_back(std::move(e));
                }
                if (!sane || r.entries.empty())
                {
                    std::fprintf(stderr, "[netmenu-assets] %s: index is malformed (%u entries)\n",
                                 p.string().c_str(), count);
                    r.entries.clear();
                    continue;
                }
                r.bytes = std::move(data);
                r.ok = true;
                std::fprintf(stderr, "[netmenu-assets] %s: %u entries\n", p.string().c_str(), count);
                break;
            }
            return r;
        }();
        return b;
    }
}

bool available()
{
    ensureInstalled();   // the install has to happen before the blob is cached
    return blob().ok;
}

std::string ensureInstalled()
{
    // Already there (or the only copy is the installed one): nothing to do.
    const std::filesystem::path dst = installedPath();
    std::error_code ec;
    if (!dst.empty() && std::filesystem::exists(dst, ec))
        return dst.string();

    // Find the build-time copy and put it next to DBZP.BIN, so the art ends up in
    // the game data folder instead of depending on the runner's own directory.
    for (const auto &p : candidates())
    {
        if (p.empty() || p == dst) continue;
        if (!std::filesystem::is_regular_file(p, ec)) continue;
        if (dst.empty()) return {};
        std::filesystem::create_directories(dst.parent_path(), ec);
        ec.clear();
        if (std::filesystem::copy_file(p, dst, std::filesystem::copy_options::overwrite_existing, ec))
        {
            std::fprintf(stderr, "[netmenu-assets] installed %s -> %s\n", p.string().c_str(), dst.string().c_str());
            return dst.string();
        }
        std::fprintf(stderr, "[netmenu-assets] cannot install %s: %s\n", dst.string().c_str(), ec.message().c_str());
        return {};
    }
    return {};
}

std::vector<uint8_t> load(const std::string &name, std::vector<std::string> *tried)
{
    ensureInstalled();
    const Blob &b = blob();
    for (const Entry &e : b.entries)
        if (e.name == name)
            return std::vector<uint8_t>(b.bytes.begin() + e.offset, b.bytes.begin() + e.offset + e.size);
    if (tried)
        for (const auto &p : candidates()) tried->push_back(p.string());
    return {};
}
}
