#include "Copyright.h"

Copyright::Copyright(nlohmann::json copyrightJson)
{
    text = copyrightJson["text"];
    type = copyrightJson["type"];
}

std::string Copyright::GetText()
{
    return text;
}

std::string Copyright::GetType()
{
    return type;
}
