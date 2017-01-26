#include "TrackLink.h"

TrackLink::TrackLink(nlohmann::json trackJson)
{
    for (auto it = trackJson["external_urls"].begin(); it != trackJson["external_urls"].end(); ++it)
        externalUrls[it.key()] = it.value();
    href = trackJson["href"];
    id = trackJson["id"];
    type = trackJson["type"];
    uri = trackJson["uri"];
}

std::map<std::string, std::string> TrackLink::GetExternalUrls()
{
    return externalUrls;
}

std::string TrackLink::GetHref()
{
    return href;
}

std::string TrackLink::GetId()
{
    return id;
}

std::string TrackLink::GetType()
{
    return type;
}

std::string TrackLink::GetUri()
{
    return uri;
}
