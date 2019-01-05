#pragma once

#include "command.h"

class EventCommand : public ICommand
{
  public:
    std::array<const char*, 19> m_Hints = {
        "__showfps",
        "__reload_world",
        "ply.invulnerable",
        "ply.vulnerable",
        "ply.unlimitedammo.enable",
        "ply.unlimitedammo.disable",
        "ply.ammo.givemax",
        "ply.pause",
        "ply.unpause",
        "ply.vehicle.burn",
        "ply.jesus.enable",
        "ply.jesus.disable",
        "ply.bavarium.upgrade.enable",
        "ply.bavarium.upgrade.disable",
        "ply.lacrima.forcefield.enable",
        "ply.lacrima.forcefield.disable",
        "debug.vehicle.incrementtint",
        "vocals.rico.enable",
        "vocals.rico.disable",
    };

    virtual const char* GetCommand() override
    {
        return "event";
    }

    virtual bool Handler(const std::string& arguments) override
    {
        if (arguments == "load_game" || arguments == "new_game" || arguments == "continue_game") {
            return false;
        }

        hk::func_call<void>(0x14328A590, arguments.c_str(), nullptr);
        return true;
    }

    virtual std::vector<std::string> GetHints(const std::string& arguments) override
    {
        std::vector<std::string> result;
        std::copy_if(m_Hints.begin(), m_Hints.end(), std::back_inserter(result),
                     [&](const std::string& item) { return item.find(arguments) != std::string::npos; });

        return result;
    }
};
