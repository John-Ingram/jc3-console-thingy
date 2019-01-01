#pragma once

#include <string>

class ICommand
{
  public:
    virtual const char*              GetCommand() = 0;
    virtual void                     Initialize(){};
    virtual bool                     Handler(const std::string& arguments)  = 0;
    virtual std::vector<std::string> GetHints(const std::string& arguments) = 0;
};
