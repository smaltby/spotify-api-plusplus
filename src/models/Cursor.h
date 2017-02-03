#ifndef SPOTIFY_PLUSPLUS_CURSOR_H
#define SPOTIFY_PLUSPLUS_CURSOR_H

#include <string>
#include "utils/json.h"

class Cursor
{
public:
    Cursor(nlohmann::json cursorJson);
    std::string GetAfter();

private:
    std::string after;
};


#endif
