#pragma once

// [C] ImGui's platform glue on SDL2 (replacing rlImGui). See src/lib/ui_sdl.cpp for the event-ownership
// details: events are fed to ImGui from an SDL event WATCH, so raylib keeps receiving them.
//
//   UiSdlInit(window, glContext)  -- ImGui_ImplSDL2_InitForOpenGL + the watch; window is raylib's
//                                    GetWindowHandle() (an SDL_Window* on the SDL platform).
//   UiSdlNewFrame()               -- forward the platform frame (call before ImGui::NewFrame()).
//   UiSdlShutdown()               -- release the platform backend.
//
// The renderer side is unchanged: ImGui_ImplOpenGL3_* or ImGui_ImplDX11_*.

bool UiSdlInit(void *sdlWindow, void *glContext);
void UiSdlNewFrame();
void UiSdlShutdown();
