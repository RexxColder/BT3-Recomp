#include "frontend/fe_pages.h"

#include "frontend/fe_hash.h"
#include "frontend/fe_ui.h"
#include "frontend/fe_window.h"

#include "imgui.h"

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
    constexpr const char *kExpectedDiscElfSha256 =
        "811188ba9b416500d921cd4d9514df0cbf42f3a41a99cf5aac5a3da37171bf99";

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
    void drawVideoPage(PageContext &ctx)
    {
        ps2x_settings::Settings &s = *ctx.settings;
        const std::filesystem::path dataDir = ctx.exeDir / "data";

        fe::sectionHeader("RENDERER");
        {
            static const char *const items[] = {"OpenGL (New)", "Software", "paraLLEl-GS (Vulkan)"};
            int count = 2;
#if defined(PS2X_HAVE_PGS)
            count = 3;
#endif
            int renderer = s.renderer;
            if (renderer < 0 || renderer >= count)
                renderer = 0;
            fe::comboRow("##renderer", &renderer, items, count, 260.0f);
            if (renderer != s.renderer)
                s.renderer = renderer;
        }
        fe::hint("OpenGL (New) es el motor grafico propio. El rasterizador por software va lento; "
                 "paraLLEl-GS necesita Vulkan. Se elige al iniciar el juego.");

        fe::sectionHeader("RESOLUCION");
        {
            int current = -1;
            for (int i = 0; i < kResolutionCount; ++i)
                if (s.windowW == kResolutionW[i] && s.windowH == kResolutionH[i])
                    current = i;
            const char *label = current >= 0 ? kResolutionLabels[current] : kCustomResolution;
            if (fe::comboRowStr("##res", &current, kResolutionLabels, kResolutionCount, label, 260.0f))
            {
                if (current >= 0)
                {
                    s.windowW = kResolutionW[current];
                    s.windowH = kResolutionH[current];
                }
            }
        }
        fe::hint("El FOV sigue la relacion de aspecto de la ventana. Se aplica al iniciar el juego.");

        fe::sectionHeader("ESCALA DE RENDER");
        {
            ImGui::RadioButton("1x", &s.renderScale, 1);
            ImGui::SameLine();
            ImGui::RadioButton("2x", &s.renderScale, 2);
            ImGui::SameLine();
            ImGui::RadioButton("3x", &s.renderScale, 3);
        }
        fe::hint("Es la resolucion interna: 720p=1x, 1080p=2x, 1440p+=3x.");

        fe::sectionHeader("MONITOR");
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
                ImGui::TextDisabled("No se pudo enumerar monitores");
            }
            else
            {
                int mon = s.monitor;
                fe::comboRow("##monitor", &mon, namePtrs.data(), (int)namePtrs.size(), 300.0f);
                if (mon >= 0 && mon < n)
                    s.monitor = mon;
            }
        }

        fe::sectionHeader("MODO DE VENTANA");
        {
            ImGui::RadioButton("Ventana", &s.windowMode, 0);
            ImGui::SameLine();
            ImGui::RadioButton("Borderless", &s.windowMode, 1);
            ImGui::SameLine();
            ImGui::RadioButton("Pantalla completa", &s.windowMode, 2);
        }
        fe::hint("Ventana y borderless usan la resolucion de arriba; pantalla completa toma la del monitor.");

        fe::sectionHeader("EFECTOS");
        {
            fe::toggleSwitch("Contorno cel (cel outline)", &s.outline);
            if (s.outline)
                fe::intSliderRow("Intensidad del contorno", &s.inkStrength, 100, 400, "%d %%");
            fe::hint("199% replica la linea de la consola. Mas bajo = tinta mas fina.");

            fe::toggleSwitch("Sombras de personajes", &s.shadows);

            fe::toggleSwitch("Desenfoque de profundidad (DoF)", &s.dofBlur);
            if (s.dofBlur)
                fe::intSliderRow("Alcance del DoF", &s.dofZFar, 20000, 800000, "%d k");

            fe::toggleSwitch("Resplandor (aura Kaioken)", &s.glow);
        }

        fe::sectionHeader("FILTRADO");
        {
            fe::toggleSwitch("Filtro bilinear", &s.bilinear);
            fe::toggleSwitch("Forzar filtrado (terreno suave)", &s.forceBilinear);
        }

        fe::sectionHeader("PACK DE TEXTURAS");
        {
            const PackStatus pack = scanTexturePack(dataDir);
            if (pack.files > 0)
            {
                char size[32];
                fe::formatBytes(pack.bytes, size, sizeof size);
                fe::statusRow("Estado", fe::okCol(), "instalado");
                char line[96];
                std::snprintf(line, sizeof line, "%u archivos, %s", pack.files, size);
                fe::statusRow("Contenido", fe::dbz(0.84f, 0.89f, 0.92f), line);
            }
            else
            {
                fe::statusRow("Estado", fe::warnCol(), "no instalado");
            }
            char path[512];
            std::snprintf(path, sizeof path, "%s", (dataDir / "Textures").string().c_str());
            fe::kv("Carpeta", path);

            fe::toggleSwitch("Activar reemplazo de texturas", &s.texPack);
            if (ImGui::Button("Instalar pack desde archivo..."))
                ctx.requestPackInstall = true;
            fe::hint("El pack se instala en la carpeta de arriba. El archivo se descomprime ahi; "
                     "la descarga ya no existe.");
        }

        fe::sectionHeader("OPCIONES");
        {
            fe::toggleSwitch("Video de intro 4K", &s.introVideo);
            static const char *const buttons[] = {"PS2 (botones originales)", "Xbox"};
            fe::comboRow("Estilo de botones", &s.buttonLayout, buttons, 2, 260.0f);
        }
        fe::hint("Se aplican al iniciar el juego.");

        fe::sectionHeader("SOLO EN EL JUEGO");
        fe::hint("Half texel, saltar post, VRAM obsoleta, widescreen, 60 fps y el HUD se ajustan "
                 "desde el overlay del juego (Shift+Tab), igual que siempre.");
    }

    void drawAudioPage(PageContext &ctx)
    {
        ps2x_settings::Settings &s = *ctx.settings;

        fe::sectionHeader("VOLUMENES");
        fe::sliderRow("General", &s.master, 0.0f, 1.0f, "%.2f");
        fe::sliderRow("Musica", &s.music, 0.0f, 1.0f, "%.2f");
        fe::sliderRow("Efectos", &s.sfx, 0.0f, 0.4f, "%.2f");
        fe::hint("El juego y el menu del Dragon Net comparten estos tres volumenes.");
    }

    void drawInputPage(PageContext &ctx)
    {
        ps2x_settings::Settings &s = *ctx.settings;

        fe::sectionHeader("MANDO");
        {
            int device = s.device;
            static const char *const items[] = {"Teclado (fallback)", "Mando 1", "Mando 2", "Mando 3",
                                                "Mando 4"};
            int count = 5;
            if (device < 0 || device >= count)
                device = 0;
            fe::comboRow("Dispositivo del jugador 1", &device, items, count, 300.0f);
            if (device != s.device)
                s.device = device;
            fe::hint("El juego lee el pad por SDL2. El teclado queda como respaldo automatico.");
        }
        fe::sliderRow("Zona muerta de los analogicos", &s.deadzone, 0.0f, 0.5f, "%.2f");

        fe::sectionHeader("OVERLAY");
        {
            fe::toggleSwitch("Overlay del juego (Shift+Tab)", &s.overlayEnabled);
            fe::kv("Boton del pad", s.overlayPadBtns.c_str());
            fe::kv("Teclas", s.overlayKeys.c_str());
            fe::hint("Se captura manteniendo 3s el boton o la combinacion, desde el overlay del juego.");
        }

        fe::sectionHeader("ASIGNAR CONTROLES");
        fe::hint("El editor completo de asignaciones (con captura de pulsaciones) se migra junto con "
                 "el resto del overlay; el juego ya guarda y restaura las suyas sin cambios.");
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

        fe::sectionHeader("NIVEL");
        {
            bool enabled = s.logLevel > 0;
            if (fe::toggleSwitch("Activar registro", &enabled))
                s.logLevel = enabled ? (s.logLevel > 0 ? s.logLevel : 1) : 0;

            int level = s.logLevel;
            if (fe::comboRow("Nivel", &level, kLevels, 4, 220.0f))
                s.logLevel = level;
        }

        fe::sectionHeader("DESCRIPCION");
        if (s.logLevel == 0)
            ImGui::TextColored(fe::gold(), "Registro desactivado");
        else
            ImGui::TextColored(fe::gold(), "Nivel %d", s.logLevel);
        fe::hint(kDescriptions[s.logLevel]);
        fe::hint(kLogNote);
    }

    void drawMiscPage(PageContext &ctx)
    {
        ps2x_settings::Settings &s = *ctx.settings;
        const std::filesystem::path dataDir = ctx.exeDir / "data";

        fe::sectionHeader("DATOS DEL JUEGO");
        {
            char size[32];
            fe::formatBytes(dirSize(dataDir), size, sizeof size);
            fe::kv("Tamano", size);

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
                if (ImGui::Button("Asistente de instalacion...", ImVec2(240.0f, 0.0f)))
                    ctx.requestInstallWizard = true;
            }
        }

        fe::sectionHeader("CACHE DE TEXTURAS");
        {
            fe::toggleSwitch("Activar cache de texturas", &s.texcache);
            fe::hint("Guarda cada textura ya resuelta (decodificacion PSMT y reemplazo del pack "
                     "aplicados) en un unico archivo. Las siguientes ejecuciones suben la cache "
                     "directo: sin busqueda de hash en VRAM, sin lookup del pack y sin decodificar "
                     "PNG/DDS. Se rehace sola cuando cambian el pack o el reemplazo de texturas.");

            std::error_code ec;
            const std::filesystem::path cache = dataDir / "texcache.bin";
            if (std::filesystem::is_regular_file(cache, ec))
            {
                char size[32];
                fe::formatBytes((unsigned long long)std::filesystem::file_size(cache, ec), size, sizeof size);
                fe::statusRow("Estado", fe::okCol(), size);
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
            fe::hint("Borrarla solo fuerza una reconstruccion en la proxima ejecucion; no toca el pack.");
        }
    }

    void drawAboutPage(PageContext &ctx)
    {
        fe::sectionHeader("ACERCA DE");
        ImGui::TextColored(fe::gold(), "Dragon Ball Z: Budokai Tenkaichi 3 Recompiled");
        ImGui::Separator();
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
                 "Russo One - tipografia (SIL Open Font License)");
    }
}
