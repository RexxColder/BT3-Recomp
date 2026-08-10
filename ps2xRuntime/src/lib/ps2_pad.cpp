#include "runtime/ps2_pad.h"
#include "runtime/pad_config.h"
#include "ps2_host_backend.h"
#include <cstring>

namespace
{
    constexpr uint8_t kPadAnalogMarker = 0x73;
    constexpr uint8_t kPadStickCenter = 0x80;
}

bool PSPadBackend::readState(int port, int slot, uint8_t *data, size_t size)
{
    if (!data || size < 32)
    {
        return false;
    }

    std::memset(data, 0, 32);
    data[0] = 0x01;
    data[1] = kPadAnalogMarker;
    data[2] = 0xFF;
    data[3] = 0xFF;
    data[4] = data[5] = data[6] = data[7] = kPadStickCenter;

    // Per-player profile poll (port 0/1 x slot 0/1 -> players 0..3).
    const int player = ps2_stubs::padPlayerForPortSlot(port, slot);
    const ps2_stubs::PadPacket pkt = ps2_stubs::padPollPlayer(static_cast<size_t>(player));

    data[2] = static_cast<uint8_t>(pkt.buttons & 0xFFu);
    data[3] = static_cast<uint8_t>((pkt.buttons >> 8) & 0xFFu);
    data[4] = pkt.rx;
    data[5] = pkt.ry;
    data[6] = pkt.lx;
    data[7] = pkt.ly;
    return true;
}
