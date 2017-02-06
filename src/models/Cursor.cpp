#include "Cursor.h"

Cursor::Cursor(nlohmann::json cursorJson)
{
    if(!cursorJson["after"].is_null())
        after = cursorJson["after"];
}

std::string Cursor::GetAfter() const
{
    return after;
}