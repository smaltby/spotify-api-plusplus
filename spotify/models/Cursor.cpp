#include "Cursor.h"

Cursor::Cursor(nlohmann::json cursorJson)
{
    after = cursorJson["after"];
}

std::string Cursor::GetAfter()
{
    return after;
}