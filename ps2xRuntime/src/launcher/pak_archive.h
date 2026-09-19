#pragma once
// [pakunpack] Unpack one Dragon Ball: BT3/Sparking .pak container into folders.
//
// Ported from HiroTex/SpikeSoft (GPL-3.0) `SpikeSoft.ZLib/Common/PAK.cs`:
//   header = FileCount (int32@0) + FilePointers[FileCount] (int32@4+i*4) + EOF (int32@4+count*4)
//   sub-file i = bytes [FilePointers[i], FilePointers[i+1])  (EOF for the last one)
// Sub-file names come from the community name DB <nameListDir>/paklist.txt
// (SpikeSoft resources, GPL-3.0); entries without a match fall back to
// "<NN>_<detected type>". Output layout mirrors the AFS converter:
//   <outDir>/<stem>/<name>          per-subfile slices (inter-file padding dropped)
//   <outDir>/<stem>/#info.idx       SpikeSoft-compatible header for repacking
// The source .pak is left in place (the runtime still serves it as a blob).

#include <cstdint>
#include <functional>
#include <string>

struct PakConvertResult
{
    bool ok = false;
    std::string error;
};

PakConvertResult convertPakToFolder(
    const std::string &pakPath, const std::string &outDir,
    const std::function<void(const std::string &)> &onStatus = {},
    const std::function<void(uint64_t done, uint64_t total)> &onProgress = {},
    const std::string &nameListDir = {});

// True when the file looks like a PAK container (mirrors SpikeSoft AnalysePAK).
bool isPakContainer(const uint8_t *data, size_t size);
