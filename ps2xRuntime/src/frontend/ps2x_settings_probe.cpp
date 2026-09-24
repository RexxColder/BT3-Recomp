#include "runtime/ps2x_settings.h"

#include <cstdio>
#include <filesystem>
#include <fstream>
#include <string>
#include <system_error>
#include <vector>

namespace
{
    int g_fail = 0;

    void check(bool ok, const char *what)
    {
        if (!ok)
        {
            std::printf("  FAIL  %s\n", what);
            ++g_fail;
        }
        else
        {
            std::printf("  ok    %s\n", what);
        }
    }

    std::string readAll(const std::string &path)
    {
        std::ifstream f(path, std::ios::binary);
        return std::string((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    }

    void writeAll(const std::string &path, const std::string &text)
    {
        std::ofstream f(path, std::ios::trunc);
        f << text;
    }

    const char *const kRoot = "ps2x_settings_probe_tmp";
}

int main()
{
    const std::string dir = kRoot;
    std::error_code ec;
    std::filesystem::remove_all(dir, ec);
    std::filesystem::create_directories(dir, ec);

    const std::string tomlPath = ps2x_settings::configPath(dir);

    std::printf("[1] primera carga sin archivos: escribe los defaults\n");
    ps2x_settings::Settings s;
    const bool existed = ps2x_settings::load(s, dir);
    check(!existed, "load() reporta que no habia archivo");
    check(std::filesystem::exists(tomlPath), "settings.toml creado");
    check(s.master == 1.0f && s.music == 1.0f, "defaults de audio");
    check(s.renderer == ps2x_settings::kRendererOpenGL, "renderer por defecto en Windows");

    std::printf("[2] round-trip de valores no default\n");
    {
        ps2x_settings::Settings w;
        ps2x_settings::load(w, dir);
        w.master = 0.75f;
        w.music = 0.30f;
        w.sfx = 0.20f;
        w.renderer = ps2x_settings::kRendererSoftware;
        w.outline = true;
        w.inkStrength = 250;
        w.inkColor = 0xFF8800u;
        w.renderScale = 3;
        w.windowMode = 2;
        w.monitor = 1;
        w.fps60 = true;
        w.hudLayout = 2;
        w.hudOffR = -7;
        w.device = 3;
        w.deadzone = 0.25f;
        w.overlayEnabled = false;
        w.overlayPadBtns = "12,14,16";
        w.overlayKeys = "340,258,262";
        w.logLevel = 3;
        w.dumpGamepad = true;
        w.texPack = true;
        w.introVideo = false;
        w.buttonLayout = 0;
        w.texcache = false;
        check(ps2x_settings::save(w, dir), "save()");

        ps2x_settings::Settings r;
        check(ps2x_settings::load(r, dir), "load() del archivo escrito");
        check(r.master == 0.75f && r.music == 0.30f && r.sfx == 0.20f, "audio");
        check(r.renderer == ps2x_settings::kRendererSoftware, "renderer");
        check(r.outline && r.inkStrength == 250 && r.inkColor == 0xFF8800u, "ink");
        check(r.renderScale == 3 && r.windowMode == 2 && r.monitor == 1, "escala/modo/monitor");
        check(r.fps60 && r.texPack && !r.introVideo && r.buttonLayout == 0 && !r.texcache, "flags de video");
        check(r.hudLayout == 2 && r.hudOffR == -7, "hud");
        check(r.device == 3 && r.deadzone == 0.25f && !r.overlayEnabled, "mandos");
        check(r.overlayPadBtns == "12,14,16" && r.overlayKeys == "340,258,262", "hotkeys");
        check(r.logLevel == 3 && r.dumpGamepad, "logging");
    }

    std::printf("[3] clamps: un archivo a mano con valores fuera de rango\n");
    {
        writeAll(tomlPath,
                 "[audio]\nmaster_volume = 9.0\nmusic_volume = -3.0\nsfx_volume = 5.0\n\n"
                 "[video]\nrenderer = \"d3d11\"\nink_strength = 9999\nink_width = 1\n"
                 "render_scale = 77\ndof_zfar = 5\n\n"
                 "[controllers]\ndevice = 9999\ndeadzone = 7.5\n\n"
                 "[logging]\nlog_level = 42\n");
        ps2x_settings::Settings c;
        check(ps2x_settings::load(c, dir), "load() del archivo con garbage");
        check(c.master == 1.0f && c.music == 0.0f && c.sfx == 0.4f, "audio clamp 0..1 / sfx 0..0.4");
        check(c.renderer == ps2x_settings::kRendererOpenGL, "d3d11 -> opengl (retirado)");
        check(c.inkStrength == 400 && c.inkWidth == 25, "ink clamp 100..400 / 25..100");
        check(c.renderScale == 4 && c.dofZFar == 20000, "render_scale 1..4 / dof_zfar 20000..");
        check(c.device == 100 && c.deadzone == 0.5f, "device 0..100 / deadzone 0..0.5");
        check(c.logLevel == 3, "log_level 0..3");
    }

    std::printf("[4] migracion del INI 0.x\n");
    {
        std::filesystem::remove(tomlPath, ec);
        writeAll((std::filesystem::path(dir) / "bt3_settings.ini").string(),
                 "[video]\ngpu_renderer = 0\ntexture_pack = 1\nink_strength = 300\n"
                 "[audio]\nmaster_volume = 0.5\n"
                 "[logging]\nlog_level = 2\n");
        ps2x_settings::Settings m;
        const bool ok = ps2x_settings::load(m, dir);
        check(ok, "migracion reportada");
        check(std::filesystem::exists(tomlPath), "settings.toml creado tras migrar");
        check(!std::filesystem::exists((std::filesystem::path(dir) / "bt3_settings.ini")),
              "el INI viejo se borra");
        check(m.master == 0.5f, "master_volume migrado");
        check(m.texPack && m.inkStrength == 300, "video migrado");
        check(m.logLevel == 2, "logging migrado");
        check(m.renderer == ps2x_settings::kRendererSoftware, "gpu_renderer=0 -> software");

        std::printf("[4b] en el INI viejo manda 'renderer' sobre 'gpu_renderer'\n");
        std::filesystem::remove(tomlPath, ec);
        writeAll((std::filesystem::path(dir) / "bt3_settings.ini").string(),
                 "[video]\nrenderer = \"opengl\"\ngpu_renderer = 0\n");
        ps2x_settings::Settings p;
        ps2x_settings::load(p, dir);
        check(p.renderer == ps2x_settings::kRendererOpenGL, "renderer explicito gana");
    }

    std::printf("[5] el archivo resultante\n");
    std::printf("----------------------------------------\n%s\n", readAll(tomlPath).c_str());
    std::printf("----------------------------------------\n");

    std::filesystem::remove_all(dir, ec);

    std::printf("%s (%d fallos)\n", g_fail ? "PROBE FALLIDO" : "PROBE OK", g_fail);
    return g_fail ? 1 : 0;
}
