#include "pak_archive.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

namespace
{
namespace fs = std::filesystem;

uint32_t readU32(const uint8_t *p)
{
    uint32_t v;
    std::memcpy(&v, p, 4);
    return v;
}

bool readFile(const fs::path &p, std::vector<uint8_t> &out)
{
    std::FILE *f = std::fopen(p.string().c_str(), "rb");
    if (!f)
        return false;
    std::fseek(f, 0, SEEK_END);
    long sz = std::ftell(f);
    std::fseek(f, 0, SEEK_SET);
    if (sz < 0) { std::fclose(f); return false; }
    out.resize(static_cast<size_t>(sz));
    if (sz > 0 && std::fread(out.data(), 1, static_cast<size_t>(sz), f) != static_cast<size_t>(sz))
    {
        std::fclose(f);
        return false;
    }
    std::fclose(f);
    return true;
}

std::string sanitizeSegment(const std::string &in)
{
    std::string out;
    out.reserve(in.size());
    for (char c : in)
    {
        const unsigned char uc = static_cast<unsigned char>(c);
        if (uc < 0x20 || uc == 0x7F) continue;
        if (c == '/' || c == '\\' || c == ':' || c == '*' || c == '?' ||
            c == '"' || c == '<' || c == '>' || c == '|')
            out.push_back('_');
        else
            out.push_back(c);
    }
    while (!out.empty() && out.back() == ' ') out.pop_back();
    return out;
}

// Keeps the DB's own subdirectory layout ("ginyu_body_data/cv_lips_JP/..."), like
// SpikeSoft, while dropping empty/`.`/`..` segments as a traversal guard.
std::string sanitizeName(const std::string &in)
{
    std::string out;
    size_t i = 0;
    for (;;)
    {
        const size_t slash = in.find('/', i);
        const std::string seg = in.substr(i, slash == std::string::npos ? std::string::npos : slash - i);
        const std::string s = sanitizeSegment(seg);
        if (!s.empty() && s != "." && s != "..")
        {
            if (!out.empty()) out.push_back('/');
            out += s;
        }
        if (slash == std::string::npos) break;
        i = slash + 1;
    }
    return out;
}

std::string lower(std::string s)
{
    for (char &c : s) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return s;
}

// --- minimal sub-file type sniffing (mirrors SpikeSoft AnalysisMan) ----------
const char *magicName(const std::string &head)
{
    struct { const char *magic; const char *name; } kTable[] = {
        {"FOD", "config.fod"}, {"V000", ".v00"}, {"CMAn", "camera.cma"},
        {"LIPS", "cv_vic.lps"}, {"DBES", ".dbe"}, {"pmdl", ".pmdl"},
        {"mdl3", ".mdl3"}, {"EPCK", ".pck"},
    };
    for (const auto &e : kTable)
        if (head.find(e.magic) != std::string::npos)
            return e.name;
    return nullptr;
}

bool looksBPE(const uint8_t *d, size_t n)
{
    if (n < 8) return false;
    const uint32_t zsize = readU32(d + 4);
    size_t pad = 0;
    for (size_t i = n; i > 1; --i) { if (d[i - 1] != 0) break; ++pad; }
    if (zsize != n - 8 - pad) return false;
    return readU32(d) > zsize;
}

bool looksDBT(const uint8_t *d, size_t n)
{
    static const uint8_t kPattern[32] = {
        0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x10,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
    if (n < sizeof(kPattern)) return false;
    const size_t limit = n - sizeof(kPattern);
    for (size_t i = 0; i <= limit; ++i)
        if (std::memcmp(d + i, kPattern, sizeof(kPattern)) == 0)
            return true;
    return false;
}

std::string analyseType(const uint8_t *d, size_t n)
{
    if (n >= 2 && d[0] == 0xFF && d[1] == 0xFE) return "text.txt";
    if (n >= 16)
    {
        char head[17] = {};
        std::memcpy(head, d, 16);
        if (const char *m = magicName(head)) return m;
    }
    if (looksBPE(d, n)) return "compressed.z";
    if (isPakContainer(d, n)) return ".pak";
    if (looksDBT(d, n)) return "texture.dbt";
    return "unknown.bin";
}

// --- paklist.txt ------------------------------------------------------------
struct PakNameBlock
{
    std::string ident;
    int maxCount = 0;
    std::vector<std::string> extra;   // extra identifier words (id[3..])
    std::vector<std::string> names;   // exactly maxCount entries
};

// Reads the SpikeSoft/community pak name DB. Format:
//   # <ident> <maxCount> [extra1|extra2]
//   <maxCount name lines>
std::vector<PakNameBlock> loadPakList(const fs::path &path)
{
    std::vector<PakNameBlock> blocks;
    std::ifstream in(path, std::ios::binary);
    if (!in.is_open()) return blocks;
    std::string line;
    while (std::getline(in, line))
    {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        if (line.size() < 2 || line[0] != '#') continue;
        PakNameBlock b;
        std::string rest = line.substr(1);
        // ident maxCount [extra]
        size_t p = 0;
        auto nextTok = [&](std::string &tok) {
            while (p < rest.size() && rest[p] == ' ') ++p;
            const size_t s = p;
            while (p < rest.size() && rest[p] != ' ') ++p;
            tok = rest.substr(s, p - s);
        };
        std::string tok;
        nextTok(b.ident);
        nextTok(tok);
        b.maxCount = tok.empty() ? 0 : std::atoi(tok.c_str());
        // remaining tokens are extra identifiers ("a|b")
        while (p < rest.size())
        {
            nextTok(tok);
            if (tok.empty()) break;
            size_t s = 0;
            while (s <= tok.size())
            {
                const size_t bar = tok.find('|', s);
                const size_t end = bar == std::string::npos ? tok.size() : bar;
                if (end > s) b.extra.push_back(tok.substr(s, end - s));
                if (bar == std::string::npos) break;
                s = bar + 1;
            }
        }
        if (b.maxCount <= 0) continue;
        for (int i = 0; i < b.maxCount; ++i)
        {
            std::string n;
            if (!std::getline(in, n)) break;
            if (!n.empty() && n.back() == '\r') n.pop_back();
            b.names.push_back(n);
        }
        if (!b.names.empty()) blocks.push_back(std::move(b));
    }
    return blocks;
}

int levenshtein(const std::string &a, const std::string &b)
{
    std::vector<int> prev(b.size() + 1), cur(b.size() + 1);
    for (size_t j = 0; j <= b.size(); ++j) prev[j] = static_cast<int>(j);
    for (size_t i = 1; i <= a.size(); ++i)
    {
        cur[0] = static_cast<int>(i);
        for (size_t j = 1; j <= b.size(); ++j)
        {
            const int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
            cur[j] = std::min({prev[j] + 1, cur[j - 1] + 1, prev[j - 1] + cost});
        }
        prev = cur;
    }
    return prev[b.size()];
}

// Picks the name list for `stem` (mirrors PAK.FindFileListMatch, simplified).
std::vector<std::string> matchNames(const std::vector<PakNameBlock> &blocks,
                                    const std::string &stem, int count)
{
    const std::string s = lower(stem);
    // 1) exact file count among containment / wildcard matches.
    for (const auto &b : blocks)
    {
        const std::string id = lower(b.ident);
        if (id == "*" || s.find(id) != std::string::npos)
            if (b.maxCount == count)
                return b.names;
    }
    // 2) most-similar identifier (Levenshtein ratio >= 0.7), same count.
    int best = -1, bestDist = INT32_MAX;
    for (size_t i = 0; i < blocks.size(); ++i)
    {
        const auto &b = blocks[i];
        if (b.maxCount != count) continue;
        const int d = levenshtein(stem, b.ident);
        const int maxLen = static_cast<int>(std::max(stem.size(), b.ident.size()));
        if (maxLen == 0) continue;
        const double ratio = 1.0 - static_cast<double>(d) / maxLen;
        if (ratio >= 0.7 && d < bestDist) { bestDist = d; best = static_cast<int>(i); }
    }
    if (best >= 0) return blocks[best].names;
    // 3) a block with more names than the source's count, gated by extra identifiers.
    for (const auto &b : blocks)
    {
        if (b.maxCount <= count) continue;
        const std::string id = lower(b.ident);
        if (!(id == "*" || s.find(id) != std::string::npos)) continue;
        if (!b.extra.empty())
        {
            bool any = false;
            for (const auto &e : b.extra)
                if (stem.find(e) != std::string::npos) { any = true; break; }
            if (!any) continue;
        }
        std::vector<std::string> names(b.names.begin(), b.names.begin() + count);
        return names;
    }
    return {};
}

} // namespace

bool isPakContainer(const uint8_t *data, size_t size)
{
    if (!data || size < 8) return false;
    const uint32_t count = readU32(data);
    if (count < 1 || (count * 4ull + 4ull) >= size || count >= 32767u) return false;
    const uint32_t eof = readU32(data + count * 4u + 4u);
    return eof == size;
}

PakConvertResult convertPakToFolder(const std::string &pakPath, const std::string &outDir,
                                    const std::function<void(const std::string &)> &onStatus,
                                    const std::function<void(uint64_t, uint64_t)> &onProgress,
                                    const std::string &nameListDir)
{
    auto fail = [](std::string msg) { return PakConvertResult{false, std::move(msg)}; };

    std::vector<uint8_t> data;
    if (!readFile(fs::path(pakPath), data))
        return fail("cannot read " + pakPath);
    if (!isPakContainer(data.data(), data.size()))
        return fail(pakPath + " is not a PAK container");

    const uint32_t count = readU32(data.data());
    const uint32_t eof = readU32(data.data() + count * 4u + 4u);
    (void)eof;

    std::vector<uint32_t> ptr(count);
    for (uint32_t i = 0; i < count; ++i)
        ptr[i] = readU32(data.data() + 4u + i * 4u);

    std::vector<uint32_t> starts = ptr;
    std::vector<uint32_t> ends(count);
    for (uint32_t i = 0; i < count; ++i)
        ends[i] = (i + 1 < count) ? ptr[i + 1] : eof;

    const fs::path src(pakPath);
    const std::string stem = src.filename().stem().string();
    fs::path dir = fs::path(outDir) / stem;
    std::error_code ec;
    fs::create_directories(dir, ec);
    if (ec)
        return fail("cannot create " + dir.string());

    // Names: paklist.txt first, else "<NN>_<type>" from content sniffing.
    std::vector<PakNameBlock> blocks;
    if (!nameListDir.empty())
        blocks = loadPakList(fs::path(nameListDir) / "paklist.txt");
    std::vector<std::string> names = matchNames(blocks, stem, static_cast<int>(count));

    std::vector<std::string> fileNames(count);
    for (uint32_t i = 0; i < count; ++i)
    {
        std::string n;
        if (i < names.size())
        {
            n = names[i];
            // {fName} -> the pak's own stem, like SpikeSoft ReplaceDynamicNames.
            for (size_t p = n.find("{fName}"); p != std::string::npos; p = n.find("{fName}", p))
                n.replace(p, 7, stem);
        }
        n = sanitizeName(n);
        if (n.empty())
        {
            char b[32];
            if (ends[i] > starts[i] && starts[i] + 0u <= data.size())
            {
                const size_t len = std::min<size_t>(ends[i] - starts[i], 4096);
                std::snprintf(b, sizeof(b), "%02u_", i + 1);
                n = b + analyseType(data.data() + starts[i], len);
            }
            else
            {
                std::snprintf(b, sizeof(b), "%02u_dummy", i + 1);
                n = b;
            }
        }
        fileNames[i] = n;
    }

    uint64_t total = 0;
    for (uint32_t i = 0; i < count; ++i)
        if (ends[i] > starts[i]) total += ends[i] - starts[i];

    if (onStatus)
        onStatus("extracting " + stem + " (" + std::to_string(count) + " sub-files)");

    uint64_t done = 0;
    for (uint32_t i = 0; i < count; ++i)
    {
        if (ends[i] <= starts[i]) continue;
        if (ends[i] > data.size() || starts[i] > ends[i])
            return fail("sub-file out of range in " + pakPath);
        const fs::path outPath = dir / fileNames[i];
        fs::create_directories(outPath.parent_path(), ec);
        std::FILE *f = std::fopen(outPath.string().c_str(), "wb");
        if (!f)
            return fail("cannot write " + (dir / fileNames[i]).string());
        const size_t n = ends[i] - starts[i];
        const size_t w = std::fwrite(data.data() + starts[i], 1, n, f);
        std::fclose(f);
        if (w != n)
            return fail("short write " + (dir / fileNames[i]).string());
        done += n;
        if (onProgress) onProgress(done, total);
    }

    // SpikeSoft-compatible #info.idx (type, count, BPE flag, then the names) so the
    // folder can be repacked later by the same tooling.
    {
        std::ofstream idx((dir / "#info.idx").string());
        if (!idx.is_open())
            return fail("cannot write #info.idx in " + dir.string());
        idx << "PAK\n" << count << "\n0\n";
        for (uint32_t i = 0; i < count; ++i) idx << fileNames[i] << "\n";
    }

    return PakConvertResult{true, std::string()};
}
