#pragma once

#include "device.h"

#pragma pack(push, 1)
namespace jc::NGraphicsEngine
{
class CGraphicsEngine
{
  public:
    static CGraphicsEngine& instance()
    {
        return **(CGraphicsEngine**)0x142E2B6F0;
    }

  public:
    char       _pad[0xEB0];
    HDevice_t* m_device;
};
}; // namespace jc::NGraphicsEngine
#pragma pack(pop)
