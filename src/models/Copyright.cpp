#include "Copyright.h"

Copyright::Copyright(nlohmann::json copyrightJson)
{
    text = copyrightJson["text"];
    type = copyrightJson["type"];
}

std::string Copyright::GetText() const
{
    return text;
}

std::string Copyright::GetType() const
{
    return type;
}
