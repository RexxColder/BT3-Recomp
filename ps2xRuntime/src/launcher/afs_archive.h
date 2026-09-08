#pragma once

#include <cstdint>
#include <functional>
#include <string>

struct AfsConvertResult
{
    bool ok = false;
    std::string error;
};

// Extracts one Dragon Ball: BT3 AFS container (PZS3US*.AFS) into the physical
// slot layout that the runtime serves from folders:
//   <outDir>/<stem>/000000, 000001, ...   slot files (exact disk slices)
//   <outDir>/<stem>.idx                   v2 index (blob + slot table)
// After dumping it re-reads every slot file and byte-compares it against the
// source so the caller can safely drop the .AFS afterwards.
//
// onStatus receives a short human-readable stage ("reading index...",
// "extracting entries...", "verifying..."); onProgress receives accumulated
// done/total bytes where total == 2 * fileSize (one pass to write the slots,
// one pass to verify them), or no progress row written when serializing.
AfsConvertResult convertAfsToFolder(
    const std::string &afsPath, const std::string &outDir,
    const std::function<void(const std::string &)> &onStatus = {},
    const std::function<void(uint64_t done, uint64_t total)> &onProgress = {});