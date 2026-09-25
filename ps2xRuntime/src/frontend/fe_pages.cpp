#include "frontend/fe_pages.h"

#include "frontend/fe_gpu.h"
#include "frontend/fe_hash.h"
#include "frontend/fe_hw.h"
#include "frontend/fe_iso9660.h"
#include "frontend/fe_music.h"
#include "frontend/fe_ui.h"
#include "frontend/fe_window.h"

#include "imgui.h"
#include "raylib.h"
#include "runtime/pad_config.h"
#include "runtime/ps2_host_pad.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <system_error>
#include <vector>

namespace
{
    constexpr const char *const kResolutionLabels[] = {
        "1024 x 768", "1280 x 720", "1360 x 768", "1366 x 768", "1440 x 900",
        "1600 x 900", "1920 x 1080", "2560 x 1440", "3440 x 1440", "3840 x 2160"
    };
    constexpr int kResolutionW[] = {1024, 1280, 1360, 1366, 1440, 1600, 1920, 2560, 3440, 3840};
    constexpr int kResolutionH[] = {768, 720, 768, 768, 900, 900, 1080, 1440, 1440, 2160};
    constexpr int kResolutionCount = 10;
    const char *const kCustomResolution = "Personalizado";

    // SLUS_216.78 (US) -- must stay in sync with games/bt3/setup.py.
    // The expected boot-ELF digest lives in fe_iso9660.h next to the code that verifies the
// dump: one constant, so the status page and the wizard cannot disagree.
using DiscVerify::kExpectedDiscElfSha256;

    enum class DataState
    {
        Missing,
        Corrupt,
        Valid
    };

    unsigned long long dirSize(const std::filesystem::path &root, int maxDepth = 6)
    {
        std::error_code ec;
        unsigned long long total = 0;
        if (!std::filesystem::is_directory(root, ec))
            return 0;
        std::filesystem::recursive_directory_iterator it(root, ec), end;
        for (; it != end && !ec; it.increment(ec))
        {
            if (it->is_directory(ec))
            {
                if (std::distance(it->path().begin(), it->path().end()) > maxDepth)
                    it.disable_recursion_pending();
                continue;
            }
            const std::uintmax_t sz = it->file_size(ec);
            if (!ec)
                total += (unsigned long long)sz;
        }
        return total;
    }

    DataState verifyInstalledData(const std::filesystem::path &dataDir)
    {
        const std::filesystem::path boot = dataDir / "SLUS_216.78";
        std::error_code ec;
        if (!std::filesystem::exists(boot, ec))
            return DataState::Missing;
        bool hashed = false;
        const std::string got = fe::sha256Hex(boot, hashed);
        if (!hashed)
            return DataState::Corrupt;
        return got == kExpectedDiscElfSha256 ? DataState::Valid : DataState::Corrupt;
    }

    struct PackStatus
    {
        unsigned files = 0;
        unsigned long long bytes = 0;
    };

    PackStatus scanTexturePack(const std::filesystem::path &dataDir)
    {
        PackStatus st;
        std::error_code ec;
        const std::filesystem::path root = dataDir / "Textures";
        if (!std::filesystem::is_directory(root, ec))
            return st;
        for (std::filesystem::recursive_directory_iterator it(root, ec), end;
             it != end && !ec; it.increment(ec))
        {
            if (!it->is_regular_file(ec))
                continue;
            ++st.files;
            const std::uintmax_t sz = it->file_size(ec);
            if (!ec)
                st.bytes += (unsigned long long)sz;
        }
        return st;
    }
}

namespace frontend
{
    // Video: the settings you almost always want (renderer, GPU, resolution, scale, monitor,
    // window mode) stay open and unboxed; the rest is grouped into collapsible sections and
    // the "only in game" note is a plain line instead of a section.
    static const char *const kVideoSections[] = {
        "EFECTOS Y FILTRADO", "PACK Y OPCIONES", "RECOMENDADO"
    };

    // The game window's GL context is created by SDL with no adapter argument, so on Windows the
    // only lever the OS exposes is the per-app graphics preference. That makes this a
    // launch-time choice: it is written the moment it changes and lands on the next game start.
    static void drawGpuRow(ps2x_settings::Settings &s)
    {
        static std::vector<gpu::Adapter> list;
        static std::vector<std::string> names;
        static std::vector<const char *> ptrs;
        static std::string lastError;
        static bool listed = false;
        if (!listed)
        {
            listed = true;
            list = gpu::adapters(gpu::currentRenderer());
            for (const gpu::Adapter &a : list)
                std::fprintf(stderr, "[fe] gpu: %s (%llu MB)%s%s\n", a.name.c_str(),
                             static_cast<unsigned long long>(a.vramMB), a.software ? " software" : "",
                             a.active ? " ACTIVA" : "");
            // WARP and the other software adapters are not a choice: picking one would run the
            // game on the CPU rasterizer. They stay in the log, out of the dropdown.
            list.erase(std::remove_if(list.begin(), list.end(),
                                      [](const gpu::Adapter &a) { return a.software; }),
                       list.end());
        }
        if (list.empty())
        {
            if (!gpu::supported())
            {
                fe::rowLabel("GPU");
                ImGui::TextDisabled("Seleccion de GPU disponible solo en Windows");
            }
            return;
        }

        names.clear();
        ptrs.clear();
        names.push_back("Automatica (decide Windows)");
        ptrs.push_back(names.back().c_str());
        int current = 0;
        for (std::size_t i = 0; i < list.size(); ++i)
        {
            char buf[320];
            std::snprintf(buf, sizeof buf, "%s  (%llu GB)%s", list[i].name.c_str(),
                          static_cast<unsigned long long>((list[i].vramMB + 512) / 1024),
                          list[i].active ? "   <-- ACTIVA" : "");
            names.push_back(buf);
            ptrs.push_back(names.back().c_str());
            if (!s.gpu.empty() && list[i].name == s.gpu)
                current = static_cast<int>(i) + 1;
        }

        if (list.size() == 1)
        {
            // One adapter is not a choice; name it and move on.
            fe::rowLabel("GPU");
            ImGui::Text("%s", names[1].c_str());
            if (s.gpu.empty() && list[0].active)
                s.gpu = list[0].name;
            return;
        }

        if (fe::comboRowStr("GPU", &current, ptrs.data(), static_cast<int>(ptrs.size()),
                            names[current].c_str()))
        {
            s.gpu = current == 0 ? std::string() : list[current - 1].name;
            std::string err;
            lastError = gpu::applyPreference(s.gpu, &err) ? std::string() : err;
        }
        if (!lastError.empty())
            ImGui::TextColored(fe::warnCol(), "%s", lastError.c_str());
        else if (current > 0 && !list[current - 1].active)
            ImGui::TextDisabled("Se aplica al reiniciar el juego");
    }

    // Write a detected recommendation into the settings the shell owns. The texture pack is only
    // switched on when one is actually installed, so a recommendation never points at files
    // that are not there.
    static void applyRecommendation(ps2x_settings::Settings &s, const hw::Recommendation &r,
                                    const std::filesystem::path &dataDir)
    {
        std::error_code ec;
        const std::filesystem::path packDir = dataDir / "Textures";
        const bool packThere =
            std::filesystem::is_directory(packDir, ec) &&
            std::filesystem::directory_iterator(packDir, ec) != std::filesystem::directory_iterator();

        s.renderScale = r.renderScale;
        // widescreen is not touched here: it is fixed, so a recommendation has no say over it.
        s.texPack = r.texPackFull && packThere;
        s.fps60 = r.fps60;
        s.windowMode = r.windowMode;
        s.fullscreen = r.windowMode == 2;
        if (r.windowMode != 2)
        {
            int w = 0, h = 0;
            if (frontend::monitorSize(s.monitor, &w, &h))
            {
                s.windowW = w;
                s.windowH = h;
            }
        }
    }

    void drawVideoPage(PageContext &ctx)
    {
        ps2x_settings::Settings &s = *ctx.settings;
        const std::filesystem::path dataDir = ctx.exeDir / "data";

        // --- fixed, always visible ---
        {
            static const char *const items[] = {"OpenGL (New)", "Software", "paraLLEl-GS (Vulkan)"};
            int count = 2;
#if defined(PS2X_HAVE_PGS)
            count = 3;
#endif
            int renderer = s.renderer;
            if (renderer < 0 || renderer >= count)
                renderer = 0;
            fe::comboRow("Motor grafico", &renderer, items, count);
            if (renderer != s.renderer)
                s.renderer = renderer;
        }
        {
            const int n = frontend::monitorCount();
            static std::vector<std::string> names;
            static std::vector<const char *> namePtrs;
            names.clear();
            namePtrs.clear();
            for (int i = 0; i < n; ++i)
            {
                names.push_back(std::to_string(i) + ": " + frontend::monitorName(i));
                namePtrs.push_back(names.back().c_str());
            }
            if (namePtrs.empty())
            {
                fe::rowLabel("Monitor");
                ImGui::TextDisabled("No se pudo enumerar monitores");
            }
            else
            {
                int mon = s.monitor;
                fe::comboRow("Monitor", &mon, namePtrs.data(), (int)namePtrs.size());
                if (mon >= 0 && mon < n)
                    s.monitor = mon;
            }
        }
        {
            fe::rowLabel("Modo de ventana");
            ImGui::RadioButton("Ventana", &s.windowMode, 0);
            ImGui::SameLine();
            ImGui::RadioButton("Borderless", &s.windowMode, 1);
            ImGui::SameLine();
            ImGui::RadioButton("Pantalla completa", &s.windowMode, 2);
        }

        {
            int current = -1;
            for (int i = 0; i < kResolutionCount; ++i)
                if (s.windowW == kResolutionW[i] && s.windowH == kResolutionH[i])
                    current = i;
            const char *label = current >= 0 ? kResolutionLabels[current] : kCustomResolution;
            if (fe::comboRowStr("Resolucion", &current, kResolutionLabels, kResolutionCount, label))
            {
                if (current >= 0)
                {
                    s.windowW = kResolutionW[current];
                    s.windowH = kResolutionH[current];
                }
            }
        }
        {
            fe::rowLabel("Escala de render");
            ImGui::RadioButton("1x", &s.renderScale, 1);
            ImGui::SameLine();
            ImGui::RadioButton("2x", &s.renderScale, 2);
            ImGui::SameLine();
            ImGui::RadioButton("3x", &s.renderScale, 3);
        }
        drawGpuRow(s);

        if (fe::beginSection("EFECTOS Y FILTRADO", false,
                             "El contorno de cel a 199% replica la linea de la consola; mas bajo, "
                             "tinta mas fina. El DoF y el resplandor (aura Kaioken) tambien se "
                             "activan aqui."))
        {
            fe::toggleSwitch("Contorno cel (cel outline)", &s.outline);
            if (s.outline)
                fe::intSliderRow("Intensidad del contorno", &s.inkStrength, 100, 400, "%d %%");
            fe::toggleSwitch("Sombras de personajes", &s.shadows);
            fe::toggleSwitch("Desenfoque de profundidad (DoF)", &s.dofBlur);
            if (s.dofBlur)
                fe::intSliderRow("Alcance del DoF", &s.dofZFar, 20000, 800000, "%d k");
            fe::toggleSwitch("Resplandor (aura Kaioken)", &s.glow);
            fe::toggleSwitch("Filtro bilinear", &s.bilinear);
            fe::toggleSwitch("Forzar filtrado (terreno suave)", &s.forceBilinear);
        }

        if (fe::beginSection("PACK Y OPCIONES", false,
                             "El pack se instala en la carpeta de arriba: el archivo se descomprime "
                             "ahi. La descarga automatica ya no existe. Las opciones se aplican al "
                             "iniciar el juego."))
        {
            const PackStatus pack = scanTexturePack(dataDir);
            if (pack.files > 0)
            {
                char size[32];
                fe::formatBytes(pack.bytes, size, sizeof size);
                fe::statusRow("Pack", fe::okCol(), "instalado");
                char line[96];
                std::snprintf(line, sizeof line, "%u archivos, %s", pack.files, size);
                fe::statusRow("Contenido", fe::dbz(0.84f, 0.89f, 0.92f), line);
            }
            else
            {
                fe::statusRow("Pack", fe::warnCol(), "no instalado");
            }
            char path[512];
            std::snprintf(path, sizeof path, "%s", (dataDir / "Textures").string().c_str());
            fe::kv("Carpeta", path);

            fe::toggleSwitch("Activar reemplazo de texturas", &s.texPack);
            fe::rowLabel("Instalar");
            if (ImGui::Button("Instalar pack desde archivo..."))
                ctx.requestPackInstall = true;
            fe::toggleSwitch("Video de intro 4K", &s.introVideo);
            static const char *const buttons[] = {"PS2 (botones originales)", "Xbox"};
            fe::comboRow("Estilo de botones", &s.buttonLayout, buttons, 2);
        }

        if (fe::beginSection("RECOMENDADO", false,
                             "Detecta tu CPU, RAM y GPU y mide un banco de pruebas de un solo "
                             "hilo para decidir el nivel. Aplicar escribe la escala de render, "
                             "el pack de texturas, los 60 fps y el modo de ventana."))
        {
            static hw::Recommendation rec;
            static std::string recText;
            static bool haveRec = false;
            static bool applied = false;
            if (fe::primaryButton("DETECTAR", ImVec2(120.0f, 28.0f)))
            {
                rec = hw::recommend(hw::detect(), hw::benchSingleThreadR());
                char buf[256];
                std::snprintf(buf, sizeof buf,
                              "%s  -  %dx render, pack %s, %d fps, %s",
                              rec.tierName.c_str(), rec.renderScale,
                              rec.texPackFull ? "4K" : "lite", rec.fps60 ? 60 : 30,
                              rec.windowMode == 2 ? "pantalla completa"
                                                  : rec.windowMode == 1 ? "borderless" : "ventana");
                recText = buf;
                haveRec = true;
                applied = false;
            }
            ImGui::SameLine(0.0f, 10.0f);
            if (fe::primaryButton("APLICAR", ImVec2(120.0f, 28.0f)) && haveRec)
            {
                applyRecommendation(s, rec, dataDir);
                applied = true;
            }
            if (!recText.empty())
            {
                ImGui::TextWrapped("%s", recText.c_str());
                if (applied)
                    ImGui::TextColored(fe::okCol(), "Aplicado. Guardalo para que sobreviva al cierre.");
                else if (haveRec)
                    ImGui::TextDisabled("Aplica los valores de arriba a los ajustes de esta pagina.");
            }
        }

        ctx.footerHint = "Half texel, saltar post, VRAM obsoleta, widescreen, 60 fps y el HUD se "
                         "cambian en caliente desde el overlay del juego (Shift+Tab).";
    }

    void drawAudioPage(PageContext &ctx)
    {
        ps2x_settings::Settings &s = *ctx.settings;

    if (fe::beginSection("VOLUMENES", true,
                         "El juego y el menu del Dragon Net comparten estos tres volumenes."))
    {
        fe::sliderRow("General", &s.master, 0.0f, 1.0f, "%.2f");
        fe::sliderRow("Musica", &s.music, 0.0f, 1.0f, "%.2f");
        fe::sliderRow("Efectos", &s.sfx, 0.0f, 0.4f, "%.2f");
    }

    // The menu theme is a local file, not part of the project, so muting it is a shell setting
    // and not one of the game's own volume sliders. It applies on the spot instead of waiting
    // for the session to end, which is why it is written out immediately.
    {
        bool muted = s.musicMuted;
        if (fe::toggleSwitch("Silenciar la musica del menu", &muted) && muted != s.musicMuted)
        {
            s.musicMuted = muted;
            music::setMuted(muted);
            if (ps2x_settings::save(s, ctx.configDir.string()))
                std::fprintf(stderr, "[fe] menu theme %s\n", muted ? "muted" : "unmuted");
        }
        if (music::trackName().empty())
            fe::hintPending("No hay ninguna pista. Poner un music.flac en "
                            "assets/music/ la activa.");
    }
    }

    // Live pad tester: reads the same host pad layer the game polls, so what lights up here is
    // exactly what the game will see. Button and axis indices are raylib's GAMEPAD_* values,
    // which is the convention pad_pN.conf persists.
    void drawPadTester(int player, ps2_stubs::PadConfig &pads)
    {
        ps2x_pad::update();

        // Which physical pad is the selected player bound to?
        const ps2_stubs::PadPlayerConfig cfg = pads.snapshot((size_t)player);
        int slot = -1;
        if (cfg.device.kind == ps2_stubs::PadDeviceKind::Gamepad)
            slot = cfg.device.gamepad;

        // Fall back to the first real controller so "Automatico" is still testable.
        if (slot < 0)
        {
            for (int i = 0; i < ps2x_pad::kMaxSlots; ++i)
                if (ps2x_pad::isController(i))
                {
                    slot = i;
                    break;
                }
        }

        if (slot < 0 || !ps2x_pad::available(slot))
        {
            fe::hintPending("No hay ningun mando conectado. Conecta uno y el probador se enciende "
                            "solo; mientras tanto el juego usara el teclado.");
            return;
        }

        fe::kv("Mando fisico", ps2x_pad::name(slot) ? ps2x_pad::name(slot) : "(sin nombre)");
        fe::kv("Asignado a", cfg.device.kind == ps2_stubs::PadDeviceKind::Gamepad
                                 ? "este mando, fijo"
                                 : (cfg.device.kind == ps2_stubs::PadDeviceKind::Keyboard
                                        ? "solo teclado"
                                        : "automatico (primer mando)"));

        const float f = fe::unit();
        ImDrawList *dl = ImGui::GetWindowDrawList();
        const ImVec2 org = ImGui::GetCursorScreenPos();

        const ImU32 off = ImGui::GetColorU32(fe::dbz(0.13f, 0.15f, 0.17f));
        const ImU32 on = ImGui::GetColorU32(fe::okCol());
        const ImU32 edge = ImGui::GetColorU32(fe::dbz(0.28f, 0.32f, 0.35f));
        const ImU32 dim = ImGui::GetColorU32(fe::dbz(0.55f, 0.60f, 0.63f));

        // The tester is laid out across the whole content width: d-pad, face buttons and the two
        // analog boxes spread out so they nearly reach the right edge, all the same size, and the
        // shoulder row on its own line underneath. Dummy() reserves both rows plus the captions,
        // so the hint below never collides with the drawing.
        const float f2 = f;
        const float u = f2 * 1.5f;          // one button
        const float block = u * 3.0f;      // d-pad and analog boxes are all 3u square
        const float W = ImGui::GetContentRegionAvail().x;
        // Inset from the content edges so nothing sits flush against the border.
        const float m = f2 * 0.7f;
        const float inner = W - m * 2.0f;
        const float top = f2 * 0.9f;
        const float capY = top + block + f2 * 0.25f;
        const float row2Y = capY + f2 * 2.0f;
        ImGui::Dummy(ImVec2(0.0f, row2Y + f2 * 1.2f));

        auto pad = [&](float x, float y, float w, float h, bool pressed, const char *label) {
            const ImVec2 a(org.x + x, org.y + y);
            const ImVec2 b(a.x + w, a.y + h);
            dl->AddRectFilled(a, b, pressed ? on : off, 3.0f);
            dl->AddRect(a, b, pressed ? on : edge, 3.0f, 0, pressed ? 1.5f : 1.0f);
            if (label && *label)
            {
                const ImVec2 t = ImGui::CalcTextSize(label);
                dl->AddText(ImGui::GetFont(), f * 0.8f,
                            ImVec2(a.x + (w - t.x) * 0.5f, a.y + (h - f * 0.8f) * 0.5f),
                            ImGui::GetColorU32(pressed ? fe::dbz(0.02f, 0.06f, 0.03f)
                                                       : fe::dbz(0.70f, 0.74f, 0.76f)),
                            label);
            }
        };

        // D-pad: a plus sign.
        const float dpx = m;
        pad(dpx + u, top, u, u, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_LEFT_FACE_UP), "^");
        pad(dpx, top + u, u, u, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_LEFT_FACE_LEFT), "<");
        pad(dpx + u * 2.0f, top + u, u, u, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_LEFT_FACE_RIGHT), ">");
        pad(dpx + u, top + u * 2.0f, u, u, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_LEFT_FACE_DOWN), "v");
        dl->AddText(ImGui::GetFont(), f2 * 0.8f, ImVec2(org.x + dpx, org.y + capY), dim, "CRUCETA");

        // Face buttons in a diamond, PS2 names.
        const float fx = m + inner * 0.20f;
        pad(fx + u, top, u, u, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_RIGHT_FACE_UP), "TRI");
        pad(fx, top + u, u, u, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_RIGHT_FACE_LEFT), "CUAD");
        pad(fx + u * 2.0f, top + u, u, u, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT), "CIR");
        pad(fx + u, top + u * 2.0f, u, u, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_RIGHT_FACE_DOWN), "CRU");
        dl->AddText(ImGui::GetFont(), f2 * 0.8f, ImVec2(org.x + fx, org.y + capY), dim, "BOTONES");

        // Analogs: same 3u square, live dot, caption and value underneath.
        auto analog = [&](float x, int axisX, int axisY, bool clicked, const char *name) {
            const ImVec2 a(org.x + x, org.y + top);
            const ImVec2 b(a.x + block, a.y + block);
            dl->AddRectFilled(a, b, off, 3.0f);
            dl->AddRect(a, b, clicked ? on : edge, 3.0f, 0, clicked ? 1.5f : 1.0f);
            const float vx = ps2x_pad::axis(slot, axisX);
            const float vy = ps2x_pad::axis(slot, axisY);
            dl->AddCircleFilled(ImVec2((a.x + b.x) * 0.5f + vx * (b.x - a.x) * 0.40f,
                                       (a.y + b.y) * 0.5f + vy * (b.y - a.y) * 0.40f),
                                  f2 * 0.30f, on);
            dl->AddText(ImGui::GetFont(), f2 * 0.8f, ImVec2(a.x, org.y + capY), dim, name);
            char buf[48];
            std::snprintf(buf, sizeof(buf), "%.2f / %.2f", vx, vy);
            dl->AddText(ImGui::GetFont(), f2 * 0.8f, ImVec2(a.x, org.y + capY + f2 * 0.95f),
                        ImGui::GetColorU32(fe::dbz(0.45f, 0.50f, 0.53f)), buf);
        };
        analog(m + inner * 0.50f, GAMEPAD_AXIS_LEFT_X, GAMEPAD_AXIS_LEFT_Y,
               ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_LEFT_THUMB), "STICK IZQ (L3)");
        analog(m + inner * 0.80f, GAMEPAD_AXIS_RIGHT_X, GAMEPAD_AXIS_RIGHT_Y,
               ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_RIGHT_THUMB), "STICK DER (R3)");

        // Shoulder row: L1/L2 hard left, SEL/PS/STA centred, R2/R1 hard right.
        const float bw = u * 1.6f;
        const float bh = f2 * 0.9f;
        const float step = bw + f2 * 0.5f;
        pad(m, row2Y, bw, bh, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_LEFT_TRIGGER_1), "L1");
        pad(m + step, row2Y, bw, bh, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_LEFT_TRIGGER_2), "L2");

        const float cgap = bw * 0.25f;
        const float clusterW = bw * 3.0f + cgap * 2.0f;
        const float cx = m + (inner - clusterW) * 0.5f;
        pad(cx, row2Y, bw, bh, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_MIDDLE_LEFT), "SEL");
        pad(cx + bw + cgap, row2Y, bw, bh, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_MIDDLE), "PS");
        pad(cx + (bw + cgap) * 2.0f, row2Y, bw, bh, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_MIDDLE_RIGHT), "STA");

        pad(m + inner - bw * 2.0f - step, row2Y, bw, bh, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_RIGHT_TRIGGER_2), "R2");
        pad(m + inner - bw, row2Y, bw, bh, ps2x_pad::buttonDown(slot, GAMEPAD_BUTTON_RIGHT_TRIGGER_1), "R1");
    }

    void drawInputPage(PageContext &ctx)
    {
        ps2x_settings::Settings &s = *ctx.settings;
        ps2_stubs::PadConfig &pads = ps2_stubs::PadConfig::instance();
        static int player = 0;
        if (player < 0 || (size_t)player >= ps2_stubs::PadConfig::kPlayerCount)
            player = 0;

        fe::sectionHeader("MANDO");
        {
            // The runtime has always had two per-player profiles (savedata/pad_p1.conf and
            // pad_p2.conf); the front-end only exposed P1. Editing them here goes through the
            // same PadConfig the game polls, so what you set is what it reads.
            static const char *const kPlayers[] = {"Jugador 1", "Jugador 2"};
            fe::comboRow("Jugador", &player, kPlayers, (int)ps2_stubs::PadConfig::kPlayerCount);

            const ps2_stubs::PadPlayerConfig cur = pads.snapshot((size_t)player);

            // The list is the pads actually plugged in, by their real names, so nobody has to
            // guess which physical pad is "Mando 2".
            ps2x_pad::update();
            static std::vector<std::string> devNames;
            static std::vector<const char *> devPtrs;
            static std::vector<int> devSlots;
            devNames.clear();
            devPtrs.clear();
            devSlots.clear();
            devNames.emplace_back("Automatico (primer mando)");
            devNames.emplace_back("Teclado");
            for (int i = 0; i < ps2x_pad::kMaxSlots; ++i)
            {
                if (!ps2x_pad::isController(i))
                    continue;
                const char *n = ps2x_pad::name(i);
                devNames.emplace_back(n && *n ? n : ("Mando " + std::to_string(i + 1)));
                devSlots.push_back(i);
            }
            for (size_t i = 0; i < devNames.size(); ++i)
                devPtrs.push_back(devNames[i].c_str());

            int chosen = 0;
            if (cur.device.kind == ps2_stubs::PadDeviceKind::Keyboard)
                chosen = 1;
            else if (cur.device.kind == ps2_stubs::PadDeviceKind::Gamepad)
            {
                for (size_t i = 0; i < devSlots.size(); ++i)
                    if (devSlots[i] == cur.device.gamepad)
                        chosen = (int)i + 2;
            }

            int pick = chosen;
            fe::comboRow("Dispositivo", &pick, devPtrs.data(), (int)devPtrs.size());
            if (pick != chosen)
            {
                ps2_stubs::PadDevice dev;
                if (pick == 1)
                {
                    dev.kind = ps2_stubs::PadDeviceKind::Keyboard;
                }
                else if (pick >= 2 && (size_t)(pick - 2) < devSlots.size())
                {
                    dev.kind = ps2_stubs::PadDeviceKind::Gamepad;
                    dev.gamepad = devSlots[pick - 2];
                }
                else
                {
                    dev.kind = ps2_stubs::PadDeviceKind::None;
                    dev.gamepad = -1;
                }
                pads.setDevice((size_t)player, dev);
                pads.save();
            }
            fe::kv("Perfil", pads.playerConfigPath((size_t)player).c_str());
            fe::sliderRow("Zona muerta de los analogicos", &s.deadzone, 0.0f, 0.5f, "%.2f");
        }

        fe::sectionHeader("PROBAR MANDO");
        drawPadTester(player, pads);

        ctx.footerHint = "ASIGNAR CONTROLES: se edita desde el overlay del juego (Shift+Tab).";
    }

    void drawLoggingPage(PageContext &ctx)
    {
        ps2x_settings::Settings &s = *ctx.settings;

        static const char *const kLevels[] = {"OFF", "Equilibrado", "Detallado", "Depuracion"};
        static const char *const kDescriptions[4] = {
            "Todo silencioso. No se escriben logs y el juego corre sin coste extra.",
            "Perfil + mclog + eventos del planificador: paradas al arrancar, tormentas de guardado y "
            "tirones de cadencia. Recomendado para jugar.",
            "Anade draws de GPU por frame, trafico de tarjeta de memoria, estado de voces de audio y "
            "eventos del pad. Para cazar un fallo concreto.",
            "Todo lo que el runtime puede emitir (recompilador por opcode, JIT de VU1, recorridos del "
            "heap del juego y volcados de VRVR crudos). Muy lento: solo para diagnostico de fallos."
        };
        static const char *const kLogNote =
            "Los logs van a logs/bt3.log junto al ejecutable. El nivel coincide con el overlay del "
            "juego (Shift+Tab).";

        if (fe::beginSection("NIVEL", true, kLogNote))
        {
            bool enabled = s.logLevel > 0;
            if (fe::toggleSwitch("Activar registro", &enabled))
                s.logLevel = enabled ? (s.logLevel > 0 ? s.logLevel : 1) : 0;

            int level = s.logLevel;
            if (fe::comboRow("Nivel", &level, kLevels, 4))
                s.logLevel = level;
            fe::rowLabel("Estado");
            if (s.logLevel == 0)
                ImGui::TextColored(fe::gold(), "Registro desactivado");
            else
                ImGui::TextColored(fe::gold(), "Nivel %d", s.logLevel);
            fe::hint(kDescriptions[s.logLevel]);
        }
    }

    void drawMiscPage(PageContext &ctx)
    {
        ps2x_settings::Settings &s = *ctx.settings;
        const std::filesystem::path dataDir = ctx.exeDir / "data";

        if (fe::beginSection("DATOS DEL JUEGO", true,
                             "El asistente extrae el ELF y los recursos de tu propia ISO. El "
                             "tamano y el estado se comprueban contra el hash del arranque."))
        {
            fe::rowLabel("Tamano");
            {
                char size[32];
                fe::formatBytes(dirSize(dataDir), size, sizeof size);
                ImGui::TextDisabled("%s", size);
            }

            if (ctx.dataState < 0)
            {
                ctx.dataState = (int)verifyInstalledData(dataDir);
                std::fprintf(stderr, "[fe] data state: %s\n",
                             ctx.dataState == (int)DataState::Valid ? "valid"
                             : ctx.dataState == (int)DataState::Corrupt ? "corrupt"
                                                                        : "missing");
            }
            switch ((DataState)ctx.dataState)
            {
            case DataState::Valid:
                fe::statusRow("Estado", fe::okCol(), "instalado y validado");
                break;
            case DataState::Corrupt:
                fe::statusRow("Estado", fe::badCol(), "corrupto: reinstalar");
                break;
            case DataState::Missing:
                fe::statusRow("Estado", fe::badCol(), "falta");
                break;
            }

            char path[512];
            std::snprintf(path, sizeof path, "%s", dataDir.string().c_str());
            fe::kv("Carpeta", path);

            fe::toggleSwitch("Modo reinstalar", &ctx.reinstallMode);
            if (ctx.reinstallMode)
            {
                fe::rowLabel("Asistente");
                if (ImGui::Button("Instalar datos del juego...", ImVec2(240.0f, 0.0f)))
                    ctx.requestInstallWizard = true;
            }
        }

        if (fe::beginSection("CACHE DE TEXTURAS", false,
                             "Guarda cada textura ya resuelta (decodificacion PSMT y reemplazo del "
                             "pack aplicados) en un unico archivo. Las siguientes ejecuciones suben la "
                             "cache directo: sin busqueda de hash en VRAM, sin lookup del pack y sin "
                             "decodificar PNG/DDS. Se rehace sola cuando cambian el pack o el "
                             "reemplazo. Borrarla solo fuerza la reconstruccion; no toca el pack."))
        {
            fe::toggleSwitch("Activar cache de texturas", &s.texcache);

            std::error_code ec;
            const std::filesystem::path cache = dataDir / "texcache.bin";
            if (std::filesystem::is_regular_file(cache, ec))
            {
                char size[32];
                fe::formatBytes((unsigned long long)std::filesystem::file_size(cache, ec), size, sizeof size);
                fe::statusRow("Estado", fe::okCol(), size);
                fe::rowLabel("Borrar");
                if (ImGui::Button("Borrar cache de texturas"))
                {
                    std::filesystem::remove(cache, ec);
                    std::filesystem::remove(std::filesystem::path(cache.string() + ".tmp"), ec);
                }
            }
            else
            {
                fe::statusRow("Estado", fe::warnCol(), "todavia no construida (se llena al jugar)");
            }
        }

        // The overlay shortcut belongs with the other runtime switches, not with the pad.
        if (fe::beginSection("OVERLAY DEL JUEGO", false,
                             "Atajo para abrir y cerrar el menu de ajustes dentro de la partida. "
                             "Los botones y teclas se capturan mantendo pulsado el boton o la "
                             "combinacion durante 3 s, desde el propio overlay del juego."))
        {
            fe::toggleSwitch("Overlay del juego (Shift+Tab)", &s.overlayEnabled);
            fe::kv("Boton del pad", s.overlayPadBtns.c_str());
            fe::kv("Teclas", s.overlayKeys.c_str());
        }
    }

    void drawAboutPage(PageContext &ctx)
    {
        // All fixed: the page is short and there is nothing to fold away.
        fe::sectionHeader("ACERCA DE");
        fe::rowLabel("Juego");
        ImGui::TextColored(fe::gold(), "Dragon Ball Z: Budokai Tenkaichi 3 Recompiled");
        fe::hint("Recompilacion estatica del juego de PS2: el codigo MIPS del disco se traduce a "
                 "C++ y corre de forma nativa, con el hardware de PS2 emulado en el proceso host.");

        fe::sectionHeader("COMPONENTES");
        fe::kv("Interfaz", "ImGui + SDL2 (dentro del runtime)");
        fe::kv("Grafico", "OpenGL 3.3 / paraLLEl-GS (Vulkan)");
        fe::kv("Video", "FFmpeg");
        fe::kv("Audio", "motor SE/ADX del propio juego");
        fe::kv("Mando", "SDL2 gamecontroller");

    fe::sectionHeader("CREDITOS");
    fe::hint("PS2Recomp (ran-j) - recompilador estatico (GPL-3.0)\n"
    "paraLLEl-GS (Arntzen-Software) - backend de GS (LGPL-3.0-or-later)\n"
    "BT3-Recomp (z3xox) - este proyecto\n"
    "ViveTheModder - listas de archivos AFS NTSC-U (Apache-2.0)\n"
    "Russo One - tipografia (SIL Open Font License)\n"
    "Musica del menu: pista 08 \"Shine\" de la banda sonora de Dragon Ball Z: Budokai Tenkaichi 3 "
    "(2007). El audio es material con derechos de autor y NO se distribuye con el proyecto: "
    "ponela como assets/music/music.flac y el front-end la reproduce desde ahi.");
    }
}
