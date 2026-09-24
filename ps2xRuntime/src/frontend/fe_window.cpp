#include "frontend/fe_window.h"

#include "lib/ps2_host_sdl.h"

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl2.h"

#include <algorithm>
#include <cstdio>

namespace
{
    const char *const kGlslVersion = "#version 330";
}

namespace frontend
{
    int monitorCount()
    {
        const int n = SDL_GetNumVideoDisplays();
        return n > 0 ? n : 0;
    }

    std::string monitorName(int index)
    {
        SDL_DisplayMode mode;
        if (SDL_GetDesktopDisplayMode(index, &mode) != 0)
            return "display " + std::to_string(index);
        const int w = mode.w > 0 ? mode.w : 0;
        const int h = mode.h > 0 ? mode.h : 0;
        if (w <= 0 || h <= 0)
            return "display " + std::to_string(index);
        return std::to_string(w) + "x" + std::to_string(h) + " @" + std::to_string(mode.refresh_rate) + "Hz";
    }

    FeWindow::~FeWindow()
    {
        shutdown();
    }

    bool FeWindow::open(const std::string &title, int width, int height)
    {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0)
        {
            std::fprintf(stderr, "[fe] SDL_Init failed: %s\n", SDL_GetError());
            return false;
        }
        m_sdlUp = true;

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

        // Never open bigger than the desktop, and never smaller than the layout can take.
        int drawW = width;
        int drawH = height;
        SDL_DisplayMode mode;
        if (SDL_GetDesktopDisplayMode(0, &mode) == 0 && mode.w > 0 && mode.h > 0)
        {
            drawW = std::min(drawW, (int)(mode.w * 0.90f));
            drawH = std::min(drawH, (int)(mode.h * 0.90f));
        }
        if (drawW < 800) drawW = 800;
        if (drawH < 520) drawH = 520;

        m_window = SDL_CreateWindow(title.c_str(),
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    drawW, drawH,
                                    SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
        if (!m_window)
        {
            std::fprintf(stderr, "[fe] SDL_CreateWindow failed: %s\n", SDL_GetError());
            return false;
        }
        SDL_SetWindowMinimumSize(m_window, 800, 520);

        m_gl = SDL_GL_CreateContext(m_window);
        if (!m_gl)
        {
            std::fprintf(stderr, "[fe] SDL_GL_CreateContext failed: %s\n", SDL_GetError());
            return false;
        }
        SDL_GL_MakeCurrent(m_window, m_gl);
        SDL_GL_SetSwapInterval(1);

        int display = SDL_GetWindowDisplayIndex(m_window);
        if (display < 0)
            display = 0;
        float ddpi = 96.0f, hdpi = 96.0f, vdpi = 96.0f;
        if (SDL_GetDisplayDPI(display, &ddpi, &hdpi, &vdpi) == 0 && ddpi > 1.0f)
        {
            m_dpiScale = ddpi / 96.0f;
            if (m_dpiScale < 1.0f) m_dpiScale = 1.0f;
            if (m_dpiScale > 2.0f) m_dpiScale = 2.0f;
        }

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO &io = ImGui::GetIO();
        io.IniFilename = nullptr;
        io.LogFilename = nullptr;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

        if (!ImGui_ImplSDL2_InitForOpenGL(m_window, m_gl))
        {
            std::fprintf(stderr, "[fe] ImGui_ImplSDL2_InitForOpenGL failed\n");
            ImGui::DestroyContext();
            return false;
        }
        if (!ImGui_ImplOpenGL3_Init(kGlslVersion))
        {
            std::fprintf(stderr, "[fe] ImGui_ImplOpenGL3_Init failed\n");
            ImGui_ImplSDL2_Shutdown();
            ImGui::DestroyContext();
            return false;
        }
        m_imguiUp = true;
        std::fprintf(stderr, "[fe] front-end window up (dpi scale %.2f)\n", m_dpiScale);
        return true;
    }

    void FeWindow::beginFrame()
    {
        SDL_Event ev;
        while (SDL_PollEvent(&ev))
        {
            if (ev.type == SDL_QUIT)
                m_closeRequested = true;
            ImGui_ImplSDL2_ProcessEvent(&ev);
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
    }

    void FeWindow::endFrame()
    {
        // The host window paints the whole viewport every frame, so the drawable is fully
        // overwritten and no explicit glClear is needed (the backend sets the viewport).
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(m_window);
    }

    void FeWindow::shutdown()
    {
        if (m_imguiUp)
        {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplSDL2_Shutdown();
            ImGui::DestroyContext();
            m_imguiUp = false;
        }
        if (m_gl)
        {
            SDL_GL_DeleteContext(m_gl);
            m_gl = nullptr;
        }
        if (m_window)
        {
            SDL_DestroyWindow(m_window);
            m_window = nullptr;
        }
        if (m_sdlUp)
        {
            // raylib's SDL platform calls SDL_Init itself when the emulator boots, so the
            // whole subsystem has to be handed back cleanly for that handoff.
            SDL_Quit();
            m_sdlUp = false;
        }
    }
}
