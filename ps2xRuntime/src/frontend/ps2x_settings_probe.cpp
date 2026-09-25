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
#if defined(_WIN32)
    check(s.renderer == ps2x_settings::kRendererOpenGL, "renderer por defecto en Windows");
#else
    check(s.renderer == ps2x_settings::kRendererParallelGS, "renderer por defecto fuera de Windows");
#endif

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

    std::printf("[5] el overlay reescribe el archivo entero: lo que no modela debe sobrevivir\n");
    {
        // This is the shape of PS2SettingsOverlay::saveSettings(): seed from disk, overwrite only
        // the keys the overlay owns, serialize the lot. Default-constructing instead silently reset
        // every key the overlay has no field for, which is how the shell lost its window size and
        // the menu theme un-muted itself at the end of a session.
        writeAll(tomlPath,
                 "[video]\ngpu = \"NVIDIA GeForce RTX 4070\"\nink_strength = 300\nink_width = 60\n"
                 "ink_color = \"#1a2b3c\"\nrender_scale = 3\n\n"
                 "[frontend]\nwidth = 1600\nheight = 900\nmusic_muted = true\n");
        ps2x_settings::Settings out;
        check(ps2x_settings::loadFromFile(out, tomlPath), "loadFromFile() lee sin escribir");

        // Only what the overlay actually edits.
        out.renderScale = 2;
        out.inkStrength = 275;
        out.inkWidth = 55;
        check(ps2x_settings::saveToFile(out, tomlPath), "saveToFile() del overlay");

        ps2x_settings::Settings back;
        check(ps2x_settings::load(back, dir), "relectura");
        check(back.renderScale == 2, "la clave editada por el overlay se aplica");
        check(back.inkStrength == 275 && back.inkWidth == 55, "las claves ink del overlay se aplican");
        check(back.gpu == "NVIDIA GeForce RTX 4070", "video.gpu sobrevive (el overlay no lo modela)");
        check(back.feWidth == 1600 && back.feHeight == 900, "[frontend] width/height sobreviven");
        check(back.musicMuted, "[frontend] music_muted sobrevive");

        // loadFromFile() on a missing file must not create one, or the overlay would write defaults
        // over a user's file just by saving once.
        const std::string gone = (std::filesystem::path(dir) / "nada.toml").string();
        ps2x_settings::Settings untouched;
        check(!ps2x_settings::loadFromFile(untouched, gone), "loadFromFile() falla si no hay archivo");
        check(!std::filesystem::exists(gone), "loadFromFile() no crea el archivo");
        check(untouched.feWidth == 800 && untouched.musicMuted == false, "y deja el struct intacto");
    }

    std::printf("[6] un override de env no se persiste en el archivo\n");
    {
        // The file says glow = false and the user runs one session with PS2X_GLOW=1. The overlay
        // must not write the env's value back, or the experiment outlives the variable.
        ps2x_settings::Settings fromFile;
        writeAll(tomlPath, "[video]\nglow = false\nrender_scale = 2\nink_strength = 250\n\n"
                           "[logging]\nlog_level = 2\n");
        check(ps2x_settings::loadFromFile(fromFile, tomlPath), "lectura del archivo");

        ps2x_settings::Settings live;
        live.glow = true;              // what PS2X_GLOW=1 did to the running config
        live.renderScale = 3;          // the user also changed this one, in the overlay
        live.inkStrength = 275;
        live.logLevel = 2;

        ps2x_settings::Settings out = fromFile;
        ps2x_settings::applyOverlayValues(out, live, ps2x_settings::kLockGlow);
        check(!out.glow, "la clave con override de env conserva el valor del archivo");
        check(out.renderScale == 3, "una clave SIN override de env si se escribe");
        check(out.inkStrength == 275, "ink_strength se escribe cuando no esta bloqueado");
        check(out.logLevel == 2, "las claves que el overlay no modela no se tocan aqui");

        // And the full round-trip through the file, to prove it survives serialization.
        check(ps2x_settings::saveToFile(out, tomlPath), "saveToFile()");
        ps2x_settings::Settings back;
        check(ps2x_settings::load(back, dir), "relectura");
        check(!back.glow, "glow = false sigue en el archivo despues del round-trip");
        check(back.renderScale == 3, "render_scale = 3 llego al archivo");

        // The renderer case: this build cannot do parallel-gs, so it runs OpenGL, but the file must
        // keep saying parallel-gs for the build that can.
        ps2x_settings::Settings r;
        ps2x_settings::Settings rlive;
        r.renderer = ps2x_settings::kRendererParallelGS;
        rlive.renderer = ps2x_settings::kRendererOpenGL;   // the fallback this build applied
        ps2x_settings::applyOverlayValues(r, rlive, ps2x_settings::kLockRenderer);
        check(r.renderer == ps2x_settings::kRendererParallelGS, "el fallback de build no se persiste");

        // Without the lock it does persist, which is what makes a retired renderer a real migration.
        ps2x_settings::Settings d;
        d.renderer = ps2x_settings::kRendererD3D11;
        ps2x_settings::applyOverlayValues(d, rlive, 0);
        check(d.renderer == ps2x_settings::kRendererOpenGL, "sin lock, el valor del overlay se escribe");
    }

    std::printf("[7] el flag del medidor de rendimiento sobrevive un round-trip\n");
    {
        ps2x_settings::Settings w;
        w.showPerf = true;
        check(ps2x_settings::save(w, dir), "save() con show_perf");
        ps2x_settings::Settings r;
        check(ps2x_settings::load(r, dir), "load()");
        check(r.showPerf, "video.show_perf se guardo y se leyo");

        // It is not env-guarded, so the overlay must always be able to write it -- if someone later
        // gives it an EnvLock bit and forgets the mask, the value would silently stop persisting.
        ps2x_settings::Settings seeded;
        check(ps2x_settings::loadFromFile(seeded, ps2x_settings::configPath(dir)), "loadFromFile()");
        ps2x_settings::Settings live;
        live.showPerf = false;
        ps2x_settings::applyOverlayValues(seeded, live, 0);
        check(!seeded.showPerf, "el overlay puede apagar show_perf (sin EnvLock)");

        // And it has to be in operator==, or the front-end's "unsaved changes" test never fires and
        // the toggle is a lie: the box moves, the file never changes.
        ps2x_settings::Settings a, b;
        a.showPerf = true; b.showPerf = false;
        check(!(a == b), "show_perf participa en operator==");
    }

    std::printf("[8] el archivo resultante\n");
    std::printf("----------------------------------------\n%s\n", readAll(tomlPath).c_str());
    std::printf("----------------------------------------\n");

    std::filesystem::remove_all(dir, ec);

    std::printf("%s (%d fallos)\n", g_fail ? "PROBE FALLIDO" : "PROBE OK", g_fail);
    return g_fail ? 1 : 0;
}
