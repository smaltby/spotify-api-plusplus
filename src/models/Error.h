#ifndef SPOTIFY_PLUSPLUS_ERROR_H
#define SPOTIFY_PLUSPLUS_ERROR_H

#include <string>
#include "utils/json.h"

class Error
{
public:
    Error(nlohmann::json pagerJson);

    int GetStatus();
    std::string GetMessage();

private:
    int status;
    std::string message;
};


#endif
