#pragma once

// [video] Video-tab status: the facts the overlay (and the launcher, from the last [vstatus] log line)
// show as green/yellow/red dots. Kept in its own header so the overlay does not drag heavy includes.
//
//   Ok       = what the settings asked for is what is running
//   Fallback = it is running, but downgraded: a different renderer, a clamped monitor/resolution, or a
//              change that only applies on restart
//   Fail     = unavailable / did not come up

namespace ps2x
{
    enum class VideoState : int { Ok = 0, Fallback = 1, Fail = 2 };

    struct VideoStatus
    {
        // Renderer actually presenting, and how it relates to the configured one.
        const char *rendererName = "?";
        const char *rendererConfigured = "?";
        VideoState renderer = VideoState::Fail;

        // Monitor: index in use, how many exist, and its human-readable name.
        int monitorIndex = 0;
        int monitorCount = 0;
        int monitorRequested = 0;
        const char *monitorName = "?";
        int monitorWidth = 0, monitorHeight = 0, monitorRefresh = 0;
        VideoState monitor = VideoState::Fail;

        // Window / resolution.
        int winW = 0, winH = 0;
        int resRequestedW = 0, resRequestedH = 0;
        VideoState resolution = VideoState::Fail;

        // Internal render scale ("upscale").
        int scaleRequested = 1, scaleActive = 1;
        bool scaleNeedsRestart = false;
        VideoState upscale = VideoState::Fail;
    };

    // Filled by the runtime at init and whenever a display setting changes.
    VideoStatus GetVideoStatus();
}
