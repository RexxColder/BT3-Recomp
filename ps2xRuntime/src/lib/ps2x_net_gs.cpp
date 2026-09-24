// [netmenu] F3 GS-level screen control.
//
// While the net entry owns the screen we "destroy" the retail Duel menu underneath: a full-screen
// BLACK quad is drawn through the SAME immediate-mode path the game's GS replay uses (rlgl), so the
// Duel's assets/UI are covered and only our own screen shows. Runs on the render thread from the
// debug-UI draw callback, before the ImGui frame. The BGM comes from the conditional AFS serve.
//
// Compiled into ps2EntryRunner only.
#include "runtime/ps2x_net_menu.h"

#include "gfx/bt3gl_api.h"

#include <cstdio>

namespace
{
    void rect(float x, float y, float w, float h, unsigned char r, unsigned char g, unsigned char b,
              unsigned char a)
    {
        bt3rlBegin(BT3RL_QUADS);
        bt3rlColor4ub(r, g, b, a);
        bt3rlTexCoord2f(0.0f, 0.0f); bt3rlVertex2f(x, y);
        bt3rlTexCoord2f(1.0f, 0.0f); bt3rlVertex2f(x + w, y);
        bt3rlTexCoord2f(1.0f, 1.0f); bt3rlVertex2f(x + w, y + h);
        bt3rlTexCoord2f(0.0f, 1.0f); bt3rlVertex2f(x, y + h);
        bt3rlEnd();
    }
}

namespace ps2x_net_gs
{
    void draw()
    {
        // The GS background black covers the retail screen. Entry uses the normal fade (fadeLevel),
        // the EXIT switches to a TOTAL black with no fade (blackLevel handles both).
        const float black = ps2x_net_menu::blackLevel();
        if (black <= 0.0f) return;
        if (!ps2x_net_menu::hosted() && !ps2x_net_menu::isActive()) return;

        // The rlgl immediate path here is in WINDOW pixels (no GS mvp on our injection), so cover
        // the whole window, not the 640x448 logical space.
        // IMPORTANT: flush the pending raylib 2D batch (our menu's Draw*) first. Mixing an immediate
        // rlBegin/rlEnd with queued batched geometry left the previous texture (the font atlas)
        // bound, so this quad sampled the atlas -- the glyph grid all over the screen.
        bt3rlDrawRenderBatchActive();
        bt3rlSetTexture(0);
        rect(0.0f, 0.0f, (float)bt3GetScreenWidth(), (float)bt3GetScreenHeight(),
             0, 0, 0, (unsigned char)(black * 255.0f + 0.5f));
    }
}
