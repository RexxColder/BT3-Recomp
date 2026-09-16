#include "runtime/ps2_host_audio.h"
#include "ps2_host_backend.h"

#if defined(PS2X_HAVE_SDL2)
#include "ps2_host_sdl.h"
#endif

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <unordered_map>
#include <vector>

namespace ps2x_audio
{
    namespace
    {
        Backend s_backend = Backend::Raylib;
        bool s_ready = false;
        uint32_t s_nextHandle = 1;

        Backend pickBackend()
        {
#if defined(PS2X_HAVE_SDL2)
            if (const char *v = std::getenv("PS2X_HOSTAUDIO"))
            {
                if (std::strcmp(v, "raylib") == 0) return Backend::Raylib;
                if (std::strcmp(v, "sdl2") == 0) return Backend::Sdl2;
            }
            return Backend::Sdl2;
#else
            return Backend::Raylib;
#endif
        }

        // ---- raylib backend ---------------------------------------------------------------
        namespace rl
        {
#if !defined(PLATFORM_VITA)
            std::unordered_map<Stream, AudioStream> s_streams;
            std::unordered_map<Sound, ::Sound> s_sounds;
#endif

            bool init()
            {
#if defined(PLATFORM_VITA)
                return false;   // raylib vita does not support audio
#else
                InitAudioDevice();
                return IsAudioDeviceReady();
#endif
            }

            void shutdown()
            {
#if !defined(PLATFORM_VITA)
                for (auto &e : s_sounds) { StopSound(e.second); UnloadSound(e.second); }
                s_sounds.clear();
                for (auto &e : s_streams) { StopAudioStream(e.second); UnloadAudioStream(e.second); }
                s_streams.clear();
                if (IsAudioDeviceReady()) CloseAudioDevice();
#endif
            }

#if !defined(PLATFORM_VITA)
            Stream openStream(uint32_t rate, uint32_t ch, uint32_t chunk)
            {
                // raylib refills in fixed-size sub-buffers; pin the size so a feed of exactly one
                // chunk fills a whole one (a partial fill is heard as pause/unpause stutter).
                SetAudioStreamBufferSizeDefault(static_cast<int>(chunk));
                const Stream h = s_nextHandle++;
                s_streams[h] = LoadAudioStream(rate, 16, ch);
                return h;
            }
            AudioStream *stream(Stream h)
            {
                auto it = s_streams.find(h);
                return it == s_streams.end() ? nullptr : &it->second;
            }
            ::Sound *sound(Sound h)
            {
                auto it = s_sounds.find(h);
                return it == s_sounds.end() ? nullptr : &it->second;
            }
#endif
        } // namespace rl

        // ---- SDL2 backend -----------------------------------------------------------------
        // One SDL audio device (float stereo at whatever rate it offers) and a mixer callback.
        // Each stream/sound owns an SDL_AudioStream, which does the int16->float, mono->stereo
        // and rate conversion; the callback pulls converted audio from every playing one and
        // sums it. All bookkeeping is done under SDL_LockAudioDevice, which also excludes the
        // callback, so no second mutex.
#if defined(PS2X_HAVE_SDL2)
        namespace sdl
        {
            struct SStream
            {
                SDL_AudioStream *cvt = nullptr;
                uint32_t rate = 0, channels = 0, chunk = 0, depth = 2;
                double queuedIn = 0.0;   // input frames handed over and not yet pulled by the device
                bool playing = false;
                // [snddiag] device callbacks that found this stream short (silence went out).
                uint32_t underruns = 0, underrunFrames = 0, reported = 0;
                bool lastGotFull = false;
            };
            // [snddiag] PS2X_SNDDIAG=1: report every underrun from the feed side (never printf
            // on the device thread), with the time since the device opened.
            bool s_diag = false;
            Uint64 s_t0 = 0;
            double nowS() { return double(SDL_GetPerformanceCounter() - s_t0) / double(SDL_GetPerformanceFrequency()); }
            struct SSound
            {
                SDL_AudioStream *cvt = nullptr;
            };
            std::unordered_map<Stream, SStream> s_streams;
            std::unordered_map<Sound, SSound> s_sounds;
            SDL_AudioDeviceID s_dev = 0;
            uint32_t s_devRate = 48000;
            std::vector<float> s_tmp;

            // Returns device frames actually mixed.
            int mix(float *out, int frames, SDL_AudioStream *cvt, double *queuedIn, uint32_t inRate)
            {
                const int bytes = frames * 2 * int(sizeof(float));
                if (int(s_tmp.size()) < frames * 2) s_tmp.resize(size_t(frames) * 2);
                const int got = SDL_AudioStreamGet(cvt, s_tmp.data(), bytes);
                const int n = got > 0 ? got / int(sizeof(float)) : 0;
                for (int i = 0; i < n; ++i) out[i] += s_tmp[size_t(i)];
                if (queuedIn)
                {
                    *queuedIn -= double(n / 2) * double(inRate) / double(s_devRate);
                    // Dry: the resampler keeps a few frames it will not emit until flushed, so
                    // the running estimate never quite reaches zero on its own. Snap it.
                    if (*queuedIn < 0.0 || (n / 2 < frames && SDL_AudioStreamAvailable(cvt) == 0))
                        *queuedIn = 0.0;
                }
                return n / 2;
            }

            void SDLCALL callback(void *, Uint8 *buf, int len)
            {
                float *out = reinterpret_cast<float *>(buf);
                const int frames = len / int(2 * sizeof(float));
                std::memset(buf, 0, size_t(len));
                for (auto &e : s_streams)
                    if (e.second.playing)
                    {
                        // An idle stream is silence by design; count the moment it RUNS dry (a
                        // short pull, or the first empty one after audio), not every idle callback.
                        const int got = mix(out, frames, e.second.cvt, &e.second.queuedIn, e.second.rate);
                        if (got < frames && (got > 0 || e.second.lastGotFull))
                        {
                            ++e.second.underruns;
                            e.second.underrunFrames += uint32_t(frames - got);
                        }
                        e.second.lastGotFull = got >= frames;
                    }
                for (auto &e : s_sounds)
                    mix(out, frames, e.second.cvt, nullptr, 0);
                for (int i = 0; i < frames * 2; ++i) out[i] = std::clamp(out[i], -1.0f, 1.0f);
            }

            bool init()
            {
                SDL_SetHint(SDL_HINT_NO_SIGNAL_HANDLERS, "1");
                SDL_SetMainReady();
                if (SDL_InitSubSystem(SDL_INIT_AUDIO) != 0)
                {
                    std::fprintf(stderr, "[hostaudio] SDL_InitSubSystem(AUDIO) failed: %s -- falling back to raylib\n",
                                 SDL_GetError());
                    return false;
                }
                SDL_AudioSpec want{}, have{};
                want.freq = 48000;
                want.format = AUDIO_F32SYS;
                want.channels = 2;
                // Device period. 512 frames at 48 kHz = 10.7 ms, the same latency class as
                // miniaudio's default under raylib. PS2X_SDLAUDIO_SAMPLES overrides (power of 2).
                want.samples = 512;
                if (const char *v = std::getenv("PS2X_SDLAUDIO_SAMPLES"))
                {
                    const long n = std::strtol(v, nullptr, 10);
                    if (n >= 64 && n <= 8192) want.samples = static_cast<Uint16>(n);
                }
                want.callback = callback;
                s_dev = SDL_OpenAudioDevice(nullptr, 0, &want, &have, SDL_AUDIO_ALLOW_FREQUENCY_CHANGE);
                if (s_dev == 0)
                {
                    std::fprintf(stderr, "[hostaudio] SDL_OpenAudioDevice failed: %s -- falling back to raylib\n",
                                 SDL_GetError());
                    SDL_QuitSubSystem(SDL_INIT_AUDIO);
                    return false;
                }
                s_devRate = static_cast<uint32_t>(have.freq);
                s_diag = [](){ const char *v = std::getenv("PS2X_SNDDIAG"); return v && v[0] && v[0] != '0'; }();
                s_t0 = SDL_GetPerformanceCounter();
                std::fprintf(stderr, "[hostaudio] SDL2 %d.%d.%d audio: driver=%s rate=%u period=%u frames (PS2X_HOSTAUDIO=raylib restores miniaudio)\n",
                             SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL,
                             SDL_GetCurrentAudioDriver() ? SDL_GetCurrentAudioDriver() : "?", s_devRate, unsigned(have.samples));
                SDL_PauseAudioDevice(s_dev, 0);
                return true;
            }

            void shutdown()
            {
                if (!s_dev) return;
                SDL_CloseAudioDevice(s_dev);   // stops the callback first
                for (auto &e : s_streams) SDL_FreeAudioStream(e.second.cvt);
                for (auto &e : s_sounds) SDL_FreeAudioStream(e.second.cvt);
                s_streams.clear();
                s_sounds.clear();
                s_dev = 0;
                SDL_QuitSubSystem(SDL_INIT_AUDIO);
            }

            struct Lock
            {
                Lock() { SDL_LockAudioDevice(s_dev); }
                ~Lock() { SDL_UnlockAudioDevice(s_dev); }
            };

            Stream openStream(uint32_t rate, uint32_t ch, uint32_t chunk, uint32_t depth)
            {
                if (rate == 0 || ch == 0 || ch > 2) return 0;
                if (depth < 2) depth = 2;
                SDL_AudioStream *cvt = SDL_NewAudioStream(AUDIO_S16SYS, static_cast<Uint8>(ch), int(rate),
                                                          AUDIO_F32SYS, 2, int(s_devRate));
                if (!cvt)
                {
                    std::fprintf(stderr, "[hostaudio] SDL_NewAudioStream(%u Hz, %u ch) failed: %s\n", rate, ch, SDL_GetError());
                    return 0;
                }
                const Stream h = s_nextHandle++;
                Lock lk;
                SStream s;
                s.cvt = cvt; s.rate = rate; s.channels = ch; s.chunk = chunk; s.depth = depth;
                s_streams[h] = s;
                return h;
            }

            void closeStream(Stream h)
            {
                SDL_AudioStream *cvt = nullptr;
                {
                    Lock lk;
                    auto it = s_streams.find(h);
                    if (it == s_streams.end()) return;
                    cvt = it->second.cvt;
                    s_streams.erase(it);
                }
                SDL_FreeAudioStream(cvt);
            }

            void setPlayingDiag(Stream h, bool on, double queued);
            void setPlaying(Stream h, bool on)
            {
                double queued = 0.0;
                {
                    Lock lk;
                    auto it = s_streams.find(h);
                    if (it == s_streams.end()) return;
                    queued = it->second.queuedIn;
                    it->second.playing = on;
                    if (!on)
                    {
                        SDL_AudioStreamClear(it->second.cvt);
                        it->second.queuedIn = 0.0;
                    }
                }
                setPlayingDiag(h, on, queued);
            }

            bool processed(Stream h)
            {
                bool ok = false; uint32_t under = 0, underFrames = 0; double queued = 0.0;
                {
                    Lock lk;
                    auto it = s_streams.find(h);
                    if (it == s_streams.end()) return false;
                    // `depth` sub-buffers of `chunk`: one is free once at most depth-1 chunks are
                    // still queued. The slack absorbs the resampler's rounding so a drained chunk
                    // reads as drained.
                    SStream &s = it->second;
                    ok = s.queuedIn <= double(s.chunk) * double(s.depth - 1) + double(s.chunk) / 64.0;
                    queued = s.queuedIn;
                    // [snddiag] polled every frame while a stream is started: report underruns as
                    // they happen instead of at the next feed.
                    if (s_diag && s.playing && s.underruns != s.reported)
                    {
                        under = s.underruns; underFrames = s.underrunFrames; s.reported = s.underruns;
                    }
                }
                if (under)
                    std::fprintf(stderr, "[snddiag] t=%.3fs stream=%u underrun #%u (%u silent device frames total) queued=%.0f\n",
                                 nowS(), h, under, underFrames, queued);
                return ok;
            }

            void update(Stream h, const int16_t *frames, uint32_t frameCount)
            {
                uint32_t under = 0, underFrames = 0; double queued = 0.0;
                {
                    Lock lk;
                    auto it = s_streams.find(h);
                    if (it == s_streams.end()) return;
                    SStream &s = it->second;
                    queued = s.queuedIn;
                    SDL_AudioStreamPut(s.cvt, frames, int(frameCount * s.channels * sizeof(int16_t)));
                    s.queuedIn += double(frameCount);
                    if (s_diag && s.underruns != s.reported)
                    {
                        under = s.underruns; underFrames = s.underrunFrames; s.reported = s.underruns;
                    }
                }
                if (under)
                    std::fprintf(stderr, "[snddiag] t=%.3fs stream=%u UNDERRUN #%u (%u device frames of silence so far); queued before this feed=%.0f in-frames\n",
                                 nowS(), h, under, underFrames, queued);
            }

            void setPlayingDiag(Stream h, bool on, double queued)
            {
                if (s_diag)
                    std::fprintf(stderr, "[snddiag] t=%.3fs stream=%u %s (queued=%.0f in-frames)\n", nowS(), h,
                                 on ? "PLAY" : "STOP", queued);
            }

            Sound playSound(const int16_t *pcm, size_t count, uint32_t rate, float pitch, float volume)
            {
                if (!pcm || count == 0 || rate == 0) return 0;
                // Pitch is a playback-rate change: declare the source at rate*pitch and let the
                // converter resample it to the device.
                const int srcRate = std::max(1000, std::min(384000, int(std::lround(double(rate) * double(pitch > 0.0f ? pitch : 1.0f)))));
                SDL_AudioStream *cvt = SDL_NewAudioStream(AUDIO_S16SYS, 1, srcRate, AUDIO_F32SYS, 2, int(s_devRate));
                if (!cvt) return 0;
                if (volume < 0.999f || volume > 1.001f)
                {
                    std::vector<int16_t> scaled(pcm, pcm + count);
                    for (auto &v : scaled) v = static_cast<int16_t>(std::clamp(float(v) * volume, -32768.0f, 32767.0f));
                    SDL_AudioStreamPut(cvt, scaled.data(), int(count * sizeof(int16_t)));
                }
                else
                    SDL_AudioStreamPut(cvt, pcm, int(count * sizeof(int16_t)));
                SDL_AudioStreamFlush(cvt);   // one-shot: push the resampler's tail out too
                const Sound h = s_nextHandle++;
                if (s_diag)
                    std::fprintf(stderr, "[snddiag] t=%.3fs sound=%u one-shot %zu samples @%u Hz pitch=%.3f vol=%.2f\n",
                                 nowS(), h, count, rate, double(pitch), double(volume));
                Lock lk;
                s_sounds[h] = SSound{cvt};
                return h;
            }

            bool soundPlaying(Sound h)
            {
                Lock lk;
                auto it = s_sounds.find(h);
                return it != s_sounds.end() && SDL_AudioStreamAvailable(it->second.cvt) > 0;
            }

            void stopSound(Sound h)
            {
                SDL_AudioStream *cvt = nullptr;
                {
                    Lock lk;
                    auto it = s_sounds.find(h);
                    if (it == s_sounds.end()) return;
                    cvt = it->second.cvt;
                    s_sounds.erase(it);
                }
                SDL_FreeAudioStream(cvt);
            }
        } // namespace sdl
#endif
    } // namespace

    Backend backend() { return s_backend; }
    const char *backendName() { return s_backend == Backend::Sdl2 ? "sdl2" : "raylib"; }

    bool init()
    {
        if (s_ready) return true;
        s_backend = pickBackend();
#if defined(PS2X_HAVE_SDL2)
        if (s_backend == Backend::Sdl2)
        {
            s_ready = sdl::init();
            if (!s_ready) s_backend = Backend::Raylib;
        }
#endif
        if (s_backend == Backend::Raylib)
            s_ready = rl::init();
        return s_ready;
    }

    void shutdown()
    {
        if (!s_ready) return;
#if defined(PS2X_HAVE_SDL2)
        if (s_backend == Backend::Sdl2) { sdl::shutdown(); s_ready = false; return; }
#endif
        rl::shutdown();
        s_ready = false;
    }

    bool ready() { return s_ready; }

    bool supportsDepth()
    {
#if defined(PS2X_HAVE_SDL2)
        return s_ready && s_backend == Backend::Sdl2;
#else
        return false;
#endif
    }

    Stream openStream(uint32_t sampleRate, uint32_t channels, uint32_t chunkFrames, uint32_t depth)
    {
        if (!s_ready) return 0;
#if defined(PS2X_HAVE_SDL2)
        if (s_backend == Backend::Sdl2) return sdl::openStream(sampleRate, channels, chunkFrames, depth);
#endif
        (void)depth;   // raylib: always two sub-buffers
#if !defined(PLATFORM_VITA)
        return rl::openStream(sampleRate, channels, chunkFrames);
#else
        return 0;
#endif
    }

    void closeStream(Stream s)
    {
        if (!s) return;
#if defined(PS2X_HAVE_SDL2)
        if (s_backend == Backend::Sdl2) { sdl::closeStream(s); return; }
#endif
#if !defined(PLATFORM_VITA)
        if (AudioStream *a = rl::stream(s))
        {
            StopAudioStream(*a);
            UnloadAudioStream(*a);
            rl::s_streams.erase(s);
        }
#endif
    }

    void playStream(Stream s)
    {
#if defined(PS2X_HAVE_SDL2)
        if (s_backend == Backend::Sdl2) { sdl::setPlaying(s, true); return; }
#endif
#if !defined(PLATFORM_VITA)
        if (AudioStream *a = rl::stream(s)) PlayAudioStream(*a);
#endif
    }

    void stopStream(Stream s)
    {
#if defined(PS2X_HAVE_SDL2)
        if (s_backend == Backend::Sdl2) { sdl::setPlaying(s, false); return; }
#endif
#if !defined(PLATFORM_VITA)
        if (AudioStream *a = rl::stream(s)) StopAudioStream(*a);
#endif
    }

    bool streamProcessed(Stream s)
    {
#if defined(PS2X_HAVE_SDL2)
        if (s_backend == Backend::Sdl2) return sdl::processed(s);
#endif
#if !defined(PLATFORM_VITA)
        if (AudioStream *a = rl::stream(s)) return IsAudioStreamProcessed(*a);
#endif
        return false;
    }

    void updateStream(Stream s, const int16_t *frames, uint32_t frameCount)
    {
        if (!frames || frameCount == 0) return;
#if defined(PS2X_HAVE_SDL2)
        if (s_backend == Backend::Sdl2) { sdl::update(s, frames, frameCount); return; }
#endif
#if !defined(PLATFORM_VITA)
        if (AudioStream *a = rl::stream(s)) UpdateAudioStream(*a, frames, static_cast<int>(frameCount));
#endif
    }

    Sound playSound(const int16_t *pcm, size_t sampleCount, uint32_t sampleRate, float pitch, float volume)
    {
        if (!s_ready || !pcm || sampleCount == 0) return 0;
#if defined(PS2X_HAVE_SDL2)
        if (s_backend == Backend::Sdl2) return sdl::playSound(pcm, sampleCount, sampleRate, pitch, volume);
#endif
#if !defined(PLATFORM_VITA)
        // LoadSoundFromWave copies the samples, so the Wave can point straight at the caller's PCM.
        Wave wave{};
        wave.frameCount = static_cast<unsigned int>(sampleCount);
        wave.sampleRate = sampleRate;
        wave.sampleSize = 16;
        wave.channels = 1;
        wave.data = const_cast<int16_t *>(pcm);
        ::Sound snd = LoadSoundFromWave(wave);
        if (snd.frameCount == 0) return 0;
        SetSoundPitch(snd, pitch);
        SetSoundVolume(snd, volume);
        const Sound h = s_nextHandle++;
        rl::s_sounds[h] = snd;
        PlaySound(snd);
        return h;
#else
        return 0;
#endif
    }

    bool soundPlaying(Sound s)
    {
#if defined(PS2X_HAVE_SDL2)
        if (s_backend == Backend::Sdl2) return sdl::soundPlaying(s);
#endif
#if !defined(PLATFORM_VITA)
        if (::Sound *snd = rl::sound(s)) return IsSoundPlaying(*snd);
#endif
        return false;
    }

    void stopSound(Sound s)
    {
        if (!s) return;
#if defined(PS2X_HAVE_SDL2)
        if (s_backend == Backend::Sdl2) { sdl::stopSound(s); return; }
#endif
#if !defined(PLATFORM_VITA)
        if (::Sound *snd = rl::sound(s))
        {
            StopSound(*snd);
            UnloadSound(*snd);
            rl::s_sounds.erase(s);
        }
#endif
    }
}
