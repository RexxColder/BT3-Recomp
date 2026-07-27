#pragma once

#include <cstdint>

namespace ps2_iop_dbcman
{
    void reset();

    bool handleDbcManRpc(uint8_t *rdram,
                         uint32_t sid,
                         uint32_t rpcNum,
                         uint32_t sendBufAddr,
                         uint32_t sendSize,
                         uint32_t recvBufAddr,
                         uint32_t recvSize,
                         uint32_t &resultPtr);
}
