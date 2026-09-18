#pragma once

// [altGL] A4: our own CPU-side image IO, to replace raylib's LoadImage / ExportImage /
// LoadImageFromTexture (stb_image + stb_image_write, which raylib already vendors). Kept separate
// from gfx::gl so it works with or without a GL context, and thread-safe (no raylib state).

#include <cstdint>
#include <string>
#include <vector>

struct Color;   // raylib's colour struct (values only; no raylib functions are used)

namespace ps2x::gfx
{
    // [A4.3] A CPU-side RGBA8 image (same field surface our readback shim already uses:
    // buf/data/width/height/format), replacing raylib's Image for the procedural scratch/mask
    // images the renderer builds with GenImageColor + ImageDrawPixel.
    struct GsImage
    {
        std::vector<unsigned char> buf;
        unsigned char *data = nullptr;
        int width = 0, height = 0, format = 4 /*PIXELFORMAT_UNCOMPRESSED_R8G8B8A8*/;
    };

    GsImage GsImageMake(int w, int h, const Color &c);
    void GsImageSetPx(GsImage &im, int x, int y, const Color &c);
    bool GsImageValid(const GsImage &im);

    // Decode a file to tightly packed RGBA8 (top-down). Returns false on failure.
    bool GsDecodeImageRGBA8(const char *path, std::vector<uint8_t> &rgba, int &w, int &h);

    // Write tightly packed RGBA8 as a PNG. Returns false on failure.
    bool GsWritePngRGBA8(const char *path, const uint8_t *rgba, int w, int h);

    // Read back a GL texture (RGBA8, raw bottom-up like raylib's LoadImageFromTexture) into
    // `out`. Needs a current GL context.
    bool GsReadTextureRGBA8(unsigned glTexture, int w, int h, std::vector<uint8_t> &out);
}
