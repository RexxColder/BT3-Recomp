#pragma once

// [B] Platform-neutral video injection (the FMV override). The decoder side lives in
// ps2_fmv_override.cpp (ffmpeg, already neutral); this module owns the UPLOAD + DRAW of a decoded
// frame through gfx, so the injection no longer depends on raylib (LoadTextureFromImage /
// UpdateTexture / DrawTexturePro) and works on every backend (GL now, D3D11 next, SDL2 later).
//
// A backend only has to implement VideoBlit; the facade below drives it.

#include <cstdint>

namespace ps2x::gfx
{
    struct VideoFrame
    {
        const uint8_t *rgba = nullptr;
        int w = 0, h = 0;
        uint64_t gen = 0;     // changes when `rgba` holds a new frame
        float alpha = 1.0f;   // fade tint
    };

    // What a video backend must provide. Implementations own their GPU resources.
    class VideoBlit
    {
    public:
        virtual ~VideoBlit() = default;
        // Create/replace the video texture as needed. Returns false if unavailable.
        virtual bool Ensure(int w, int h) = 0;
        // Upload a new frame (RGBA8, w*h*4).
        virtual void UploadFrame(const void *rgba, uint64_t gen) = 0;
        // Draw the video quad over the window (x0..x1, y0..y1 in top-left screen pixels).
        virtual void Draw(float x0, float y0, float x1, float y1, float alpha) = 0;
        virtual void Release() = 0;
    };

    // The GL backend (uses the shared gfx::gl context + the blit shader). Returns nullptr when no
    // GL context is up.
    VideoBlit *CreateGlVideoBlit();

    // Facade used by the runtime.
    //   Prepare(): upload the frame (no draw) so the caller can draw it LATER, on top of the
    //     frame the game already presented (the injected video must sit above the (black) FMV).
    //   DrawOnTop(): draw the last prepared frame over the window.
    //   Draw(): Prepare + Draw in one call (kept for callers that draw immediately).
    bool VideoOverlayPrepare(VideoBlit *blit, const VideoFrame &f);
    void VideoOverlayDrawOnTop(VideoBlit *blit, int screenW, int screenH, int frameW, int frameH,
                               float alpha, bool stretch);
    bool VideoOverlayDraw(VideoBlit *blit, const VideoFrame &f, int screenW, int screenH, bool stretch = false);
}
