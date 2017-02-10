#include "Image.h"

Image::Image(nlohmann::json imageJson)
{
    if(!imageJson["height"].is_null())
        height = imageJson["height"];
    url = imageJson["url"];
    if(!imageJson["width"].is_null())
        width = imageJson["width"];
}

int Image::GetHeight() const
{
    return height;
}

std::string Image::GetUrl() const
{
    return url;
}

int Image::GetWidth() const
{
    return width;
}