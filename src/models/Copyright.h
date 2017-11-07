#ifndef SPOTIFY_PLUSPLUS_COPYRIGHT_H
#define SPOTIFY_PLUSPLUS_COPYRIGHT_H

#include <string>
#include "../utils/json.h"

class Copyright
{
public:
    Copyright(nlohmann::json copyrightJson);

    std::string GetText() const;
    std::string GetType() const;

private:
    std::string text;
    std::string type;
};


#endif
