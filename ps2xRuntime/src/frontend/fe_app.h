#pragma once

#include <string>

namespace frontend
{
    struct FeConfig
    {
        std::string title;
        std::string exeDir;
        std::string defaultElf;
        int width = 1024;
        int height = 640;
    };

    enum class FeAction
    {
        Boot,
        Quit
    };

    FeAction run(const FeConfig &cfg, std::string &bootElfOut);
}
