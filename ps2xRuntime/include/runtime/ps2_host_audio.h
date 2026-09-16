#pragma once

#include <cstddef>
#include <cstdint>

// Host audio output: streaming PCM (BGM pair, voice/SE rings) and one-shot VAG samples.
//
// Two backends: raylib (miniaudio, what shipped until now) and SDL2 (our own mixer over an
// SDL audio device). PS2X_HOSTAUDIO=raylib|sdl2 picks at startup, default sdl2 when built in.
//
// The stream model is raylib's, because PS2AudioBackend's credit accounting was built on it:
// a stream owns TWO sub-buffers of `chunkFrames`; streamProcessed() says one of them is free,
// and updateStream() must then hand over exactly one whole chunk. The SDL backend reproduces
// that contract on top of a queue (processed <=> at most one chunk is still queued).
//
// Every call is render-thread only, like raylib's.
namespace ps2x_audio
{
    enum class Backend { Raylib, Sdl2 };
    Backend backend();
    const char *backendName();

    bool init();
    void shutdown();
    bool ready();

    using Stream = uint32_t;   // 0 = none
    // `depth` = number of sub-buffers (raylib has exactly 2 and ignores anything else; the SDL
    // backend honours it: processed <=> fewer than depth-1 chunks still queued). A finer chunk
    // with a deeper queue keeps the same audio in the device but tops it up in smaller steps,
    // which is what a producer paced by our queue level needs -- see the SE stream.
    bool supportsDepth();
    Stream openStream(uint32_t sampleRate, uint32_t channels, uint32_t chunkFrames, uint32_t depth = 2);
    void closeStream(Stream s);
    void playStream(Stream s);
    void stopStream(Stream s);
    bool streamProcessed(Stream s);
    // `frames` interleaved int16 frames of the stream's channel count; frameCount == chunkFrames.
    void updateStream(Stream s, const int16_t *frames, uint32_t frameCount);

    using Sound = uint32_t;    // 0 = none
    // Mono int16 PCM, played once at sampleRate*pitch. The PCM is copied.
    Sound playSound(const int16_t *pcm, size_t sampleCount, uint32_t sampleRate, float pitch, float volume);
    bool soundPlaying(Sound s);
    void stopSound(Sound s);   // stops and frees
}
