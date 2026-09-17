#include "gfx/image_io.h"

#include "gfx/gl/GlApi.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_NO_STDIO          // we do the fopen ourselves: keeps the TU free of stdio surprises
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <cstdio>
#include <cstring>

namespace ps2x::gfx
{
    bool GsDecodeImageRGBA8(const char *path, std::vector<uint8_t> &rgba, int &w, int &h)
    {
        FILE *f = std::fopen(path, "rb");
        if (!f) return false;
        std::fseek(f, 0, SEEK_END);
        const long n = std::ftell(f);
        std::fseek(f, 0, SEEK_SET);
        if (n <= 0) { std::fclose(f); return false; }
        std::vector<uint8_t> bytes((size_t)n);
        const size_t got = std::fread(bytes.data(), 1, (size_t)n, f);
        std::fclose(f);
        if (got != (size_t)n) return false;

        int comp = 0;
        stbi_uc *px = stbi_load_from_memory(bytes.data(), (int)bytes.size(), &w, &h, &comp, 4);
        if (!px) return false;
        rgba.assign(px, px + (size_t)w * (size_t)h * 4u);
        stbi_image_free(px);
        return true;
    }

    static void writeCb(void *ctx, void *data, int size)
    {
        std::fwrite(data, 1, (size_t)size, static_cast<FILE *>(ctx));
    }

    bool GsWritePngRGBA8(const char *path, const uint8_t *rgba, int w, int h)
    {
        if (!rgba || w <= 0 || h <= 0) return false;
        FILE *f = std::fopen(path, "wb");
        if (!f) return false;
        const int ok = stbi_write_png_to_func(writeCb, f, w, h, 4, rgba, w * 4);
        std::fclose(f);
        return ok != 0;
    }

    bool GsReadTextureRGBA8(unsigned glTexture, int w, int h, std::vector<uint8_t> &out)
    {
        if (!glTexture || w <= 0 || h <= 0 || !ps2xgl::Ready()) return false;
        unsigned fbo = 0;
        ps2xgl::glGenFramebuffers(1, &fbo);
        ps2xgl::glBindFramebuffer(ps2xgl::GL_FRAMEBUFFER, fbo);
        ps2xgl::glFramebufferTexture2D(ps2xgl::GL_FRAMEBUFFER, ps2xgl::GL_COLOR_ATTACHMENT0,
                                       ps2xgl::GL_TEXTURE_2D, glTexture, 0);
        if (ps2xgl::glCheckFramebufferStatus(ps2xgl::GL_FRAMEBUFFER) != ps2xgl::GL_FRAMEBUFFER_COMPLETE)
        { ps2xgl::glBindFramebuffer(ps2xgl::GL_FRAMEBUFFER, 0); ps2xgl::glDeleteFramebuffers(1, &fbo); return false; }
        std::vector<uint8_t> tmp((size_t)w * (size_t)h * 4u);
        ps2xgl::glPixelStorei(ps2xgl::GL_PACK_ALIGNMENT, 1);
        ps2xgl::glReadPixels(0, 0, w, h, ps2xgl::GL_RGBA, ps2xgl::GL_UNSIGNED_BYTE, tmp.data());
        ps2xgl::glBindFramebuffer(ps2xgl::GL_FRAMEBUFFER, 0);
        ps2xgl::glDeleteFramebuffers(1, &fbo);
        // NOTE: deliberately NOT flipped -- raylib's LoadImageFromTexture (rlReadTexturePixels)
        // returns the raw bottom-up GL data, and the callers already flip when they need to.
        out.swap(tmp);
        return true;
    }
}
