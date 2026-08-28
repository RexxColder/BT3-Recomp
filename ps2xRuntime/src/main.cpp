#include "ps2_runtime.h"
#include "games_database.h"
#if !defined(PLATFORM_VITA)
#include "ps2_settings_overlay.h"
#endif

#ifdef _DEBUG
#include "ps2_log.h"
#endif

#include <iostream>
#include <string>
#include <filesystem>
#include <exception>
#include <algorithm>
#include <cstdlib>

namespace
{
    void setupTerminateLogger() // to help on release build crashs
    {
        std::set_terminate([]()
                           {
                               std::cerr << "[terminate] unhandled exception" << std::endl;
                               const std::exception_ptr ep = std::current_exception();
                               if (ep)
                               {
                                   try
                                   {
                                       std::rethrow_exception(ep);
                                   }
                                   catch (const std::system_error &e)
                                   {
                                       std::cerr << "[terminate] std::system_error code=" << e.code().value()
                                                 << " category=" << e.code().category().name()
                                                 << " message=" << e.what() << std::endl;
                                   }
                                   catch (const std::exception &e)
                                   {
                                       std::cerr << "[terminate] std::exception: " << e.what() << std::endl;
                                   }
                                   catch (...)
                                   {
                                       std::cerr << "[terminate] non-std exception" << std::endl;
                                   }
                               }
                               std::abort(); });
    }

    std::string normalizeGameId(const std::string &folderName)
    {
        std::string result = folderName;

        size_t underscore = result.find('_');
        if (underscore != std::string::npos)
            result[underscore] = '-';

        size_t dot = result.find('.');
        if (dot != std::string::npos)
            result.erase(dot, 1);

        std::ranges::transform(result, result.begin(), [](unsigned char character)
                               { return static_cast<char>(std::toupper(character)); });

        return result;
    }

    std::filesystem::path getExecutableDirectory()
    {
#if defined(__linux__)
        // Resolve the real executable location (portable dist), independent of cwd/argv.
        std::error_code ec;
        std::filesystem::path self = std::filesystem::read_symlink("/proc/self/exe", ec);
        if (!ec && !self.empty())
        {
            return self.parent_path().lexically_normal();
        }
#endif
        std::error_code ec2;
        const std::filesystem::path cwd = std::filesystem::current_path(ec2);
        return (ec2 ? std::filesystem::path(".") : cwd).lexically_normal();
    }

    std::filesystem::path getExecutablePath(int argc, char *argv[])
    {
        if (argc >= 2 && argv[1] && argv[1][0] != '\0')
        {
            std::cout << "Using argv boot path" << std::endl;
            return std::filesystem::path(argv[1]);
        }
        // Portable dist: auto-locate the guest ELF next to the executable in data/.
        const std::filesystem::path exeDir = getExecutableDirectory();
        const std::filesystem::path autoElf = exeDir / "data" / "SLUS_216.78";
        std::error_code ec;
        if (std::filesystem::is_regular_file(autoElf, ec) && !ec)
        {
            std::cout << "Using auto-located boot file: " << autoElf.string() << std::endl;
            return autoElf;
        }
#if defined(PS2X_DEFAULT_BOOT_ELF)
        std::cout << "Using default boot file" << std::endl;
        const std::filesystem::path configuredPath = std::filesystem::path(PS2X_DEFAULT_BOOT_ELF);
#if defined(PLATFORM_VITA)
        return configuredPath;
#endif
        if (configuredPath.is_absolute())
        {
            return configuredPath;
        }
        return (std::filesystem::current_path() / configuredPath).lexically_normal();
#else
        throw std::runtime_error("Unable to determine executable path. Pass the guest ELF as argv[1] or define PS2X_DEFAULT_BOOT_ELF.");
#endif
    }
}

int main(int argc, char *argv[])
{
    setupTerminateLogger();

    try
    {
        std::filesystem::path pathObj = getExecutablePath(argc, argv);

        std::string filePathStr = pathObj.string();
        std::string elfName = pathObj.filename().string();
        std::string normalizedId = normalizeGameId(elfName);

        std::string windowTitle = "Dragon Ball Budokai Tenkaichi 3";
        const char *gameName = getGameName(normalizedId);

#if !defined(PLATFORM_VITA)
        if (gameName && std::string(gameName) != "Unknown")
        {
            windowTitle = std::string(gameName) + " | " + elfName;
        }
        else
#endif
        {
            (void)gameName;
        }

        PS2Runtime runtime;

        // Performance defaults — only set if not already in environment
        auto setDefault = [](const char *key, const char *val) {
            if (!std::getenv(key))
                setenv(key, val, 1);
        };
        setDefault("PS2X_SKIPPOST", "1");
        setDefault("PS2X_SKIP_STALE_VRAM", "1");
        setDefault("PS2X_TEXCACHEMB", "256");
        setDefault("PS2X_TIMERMULT", "8");
        setDefault("PS2X_BT3_CDTICK", "1");
        setDefault("PS2X_SCHED", "1");
        setDefault("PS2X_GPU_DEPTH", "1");
        setDefault("PS2X_ASYNC_KICK", "1");
        setDefault("PS2X_BT3_SNDACK", "1");
#if !defined(PLATFORM_VITA)
        // --soft -> software rasterizer (manual debugging utility).
        const bool softGpu = std::any_of(argv, argv + argc, [](const char *a) {
            return a && std::string(a) == "--soft";
        });
        if (!softGpu)
        {
            setDefault("PS2X_GPU", "1");
        }
#endif

#if !defined(PLATFORM_VITA)
        PS2SettingsOverlay settingsOverlay;
        PS2SettingsOverlay::setConfigDirectory((getExecutableDirectory() / "savedata").string());
        settingsOverlay.preloadSettings();
        runtime.setDebugUiCallbacks(
            [](PS2Runtime &rt, void *userData)
            {
                (void)rt;
                static_cast<PS2SettingsOverlay *>(userData)->initialize();
            },
            [](PS2Runtime &rt, void *userData)
            {
                static_cast<PS2SettingsOverlay *>(userData)->draw(rt);
            },
            [](PS2Runtime &rt, void *userData)
            {
                (void)rt;
                static_cast<PS2SettingsOverlay *>(userData)->shutdown();
            },
            &settingsOverlay);
#endif
        if (!runtime.initialize(windowTitle.c_str()))
        {
            std::cerr << "Failed to initialize PS2 runtime" << std::endl;
            return 1;
        }

        if (!runtime.loadELF(filePathStr))
        {
            std::cerr << "Failed to load ELF file: " << filePathStr << std::endl;
            return 1;
        }

        runtime.run();

#ifdef _DEBUG
        ps2_log::print_saved_location();
#endif
        std::cout.flush();
        std::cerr.flush();
        std::_Exit(0);
    }
    catch (const std::exception &e)
    {
        std::cerr << "[main] fatal exception: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "[main] fatal exception: unknown" << std::endl;
    }

    std::cout.flush();
    std::cerr.flush();
    std::_Exit(1);
}
