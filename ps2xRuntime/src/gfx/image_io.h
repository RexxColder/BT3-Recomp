#pragma once

// [altGL] A4: our own CPU-side image IO, to replace raylib's LoadImage / ExportImage /
// LoadImageFromTexture (stb_image + stb_image_write, which raylib already vendors). Kept separate
// from gfx::gl so it works with or without a GL context, and thread-safe (no raylib state).

#include <cstdint>
#include <string>
#include <vector>

namespace ps2x::gfx
{
    // Decode a file to tightly packed RGBA8 (top-down). Returns false on failure.
    bool GsDecodeImageRGBA8(const char *path, std::vector<uint8_t> &rgba, int &w, int &h);

    // Write tightly packed RGBA8 as a PNG. Returns false on failure.
    bool GsWritePngRGBA8(const char *path, const uint8_t *rgba, int w, int h);

    // Read back a GL texture (RGBA8, top-down) into `out`. Needs a current GL context.
    bool GsReadTextureRGBA8(unsigned glTexture, int w, int h, std::vector<uint8_t> &out);
}
