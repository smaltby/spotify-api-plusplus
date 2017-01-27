#include "ArtistSimple.h"

ArtistSimple::ArtistSimple(nlohmann::json artistJson)
{
    for (auto it = artistJson["external_urls"].begin(); it != artistJson["external_urls"].end(); ++it)
        externalUrls[it.key()] = it.value();
    href = artistJson["href"];
    id = artistJson["id"];
    name = artistJson["name"];
    type = artistJson["type"];
    uri = artistJson["uri"];
}

std::map<std::string, std::string> ArtistSimple::GetExternalUrls()
{
    return externalUrls;
}

std::string ArtistSimple::GetHref()
{
    return href;
}

std::string ArtistSimple::GetId()
{
    return id;
}

std::string ArtistSimple::GetName()
{
    return name;
}

std::string ArtistSimple::GetType()
{
    return type;
}

std::string ArtistSimple::GetUri()
{
    return uri;
}