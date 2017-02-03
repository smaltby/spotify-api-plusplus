#ifndef SPOTIFY_PLUSPLUS_IMAGE_H
#define SPOTIFY_PLUSPLUS_IMAGE_H

#include <string>
#include "utils/json.h"


class Image
{
public:
    Image(nlohmann::json imageJson);

    int GetHeight();
    std::string GetUrl();
    int GetWidth();

private:
    int height;
    std::string url;
    int width;
};


#endif
