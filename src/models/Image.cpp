#include "Image.h"

Image::Image(nlohmann::json imageJson)
{
    height = imageJson["height"];
    url = imageJson["url"];
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