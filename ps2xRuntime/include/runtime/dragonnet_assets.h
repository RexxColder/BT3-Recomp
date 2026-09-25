#pragma once
// [netmenu] The Dragon Net Menu art ships as one blob (games/bt3/dragonnet_assets.bin)
// instead of ~19 loose PNGs. The menu still asks for assets by name
// ("menu/ship.png", "buttons/ps/Equis.png"); this resolves the name inside the
// blob and hands back the bytes, so the page needs no unpack step in the install.
//
// Layout (little endian), written by tools/iop/dragonnet_assets.py:
//   magic 8 (b"DRAGONNET") | version u32 | count u32
//   per entry: u16 name_len, name, u32 offset, u32 size   (offset from file start)
//   payload

#include <cstdint>
#include <string>
#include <vector>

namespace dragonnet
{
    // Installs the blob as <cdRoot>/NETPLAY.BIN -- next to DBZP.BIN in the data
    // folder -- when only the build-time copy is present, and returns where the
    // art will be read from ("" when there is none). Idempotent.
    std::string ensureInstalled();

    // The PNG bytes for `name` (e.g. "menu/ship.png"), or an empty vector when the
    // blob is missing, unreadable, or has no such entry. `tried` receives the paths
    // that were looked at, for the one-shot diagnostic.
    std::vector<uint8_t> load(const std::string &name, std::vector<std::string> *tried = nullptr);

    // True once the blob has been found and parsed, so the page can say "no art"
    // instead of logging one missing line per file.
    bool available();
}
