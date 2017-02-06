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

std::map<std::string, std::string> TrackLink::GetExternalUrls() const
{
    return externalUrls;
}

std::string TrackLink::GetHref() const
{
    return href;
}

std::string TrackLink::GetId() const
{
    return id;
}

std::string TrackLink::GetType() const
{
    return type;
}

std::string TrackLink::GetUri() const
{
    return uri;
}
