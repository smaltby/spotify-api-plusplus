#ifndef SPOTIFY_PLUSPLUS_IMAGE_H
#define SPOTIFY_PLUSPLUS_IMAGE_H

#include <string>
#include "../utils/json.h"


class Image
{
public:
    Image(nlohmann::json imageJson);

    int GetHeight() const;
    std::string GetUrl() const;
    int GetWidth() const;

private:
    int height;
    std::string url;
    int width;
};


#endif
