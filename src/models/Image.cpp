#include "Image.h"

Image::Image(nlohmann::json imageJson)
{
    height = imageJson["height"];
    url = imageJson["url"];
    width = imageJson["width"];
}

int Image::GetHeight()
{
    return height;
}

std::string Image::GetUrl()
{
    return url;
}

int Image::GetWidth()
{
    return width;
}