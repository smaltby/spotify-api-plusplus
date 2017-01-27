#include "TrackSimple.h"

TrackSimple::TrackSimple(nlohmann::json trackJson)
{
    for(nlohmann::json json : trackJson["artists"])
        artists.push_back(std::shared_ptr<ArtistSimple>(new ArtistSimple(json)));
    for(std::string market : trackJson["available_markets"])
        availableMarkets.push_back(market);
    discNumber = trackJson["disc_number"];
    durationMs = trackJson["duration_ms"];
    isExplicit = trackJson["explicit"];
    for (auto it = trackJson["external_urls"].begin(); it != trackJson["external_urls"].end(); ++it)
        externalUrls[it.key()] = it.value();
    href = trackJson["href"];
    id = trackJson["id"];
    /* is_playable and linked_from, although in the API, don't seem to exist in any of the JSON being returned */
    //isPlayable = trackJson["is_playable"];
    //linkedFrom = std::shared_ptr<TrackLink>(new TrackLink(trackJson["linked_from"]));
    name = trackJson["name"];
    if(!trackJson["preview_url"].is_null())
        previewUrl = trackJson["preview_url"];
    trackNumber = trackJson["track_number"];
    type = trackJson["type"];
    uri = trackJson["uri"];
}

std::vector<std::shared_ptr<ArtistSimple>> TrackSimple::GetArtists()
{
    return artists;
}

std::vector<std::string> TrackSimple::GetAvailableMarkets()
{
    return availableMarkets;
}

int TrackSimple::GetDiscNumber()
{
    return discNumber;
}

int TrackSimple::GetDurationMs()
{
    return durationMs;
}

bool TrackSimple::IsExplicit()
{
    return isExplicit;
}

std::map<std::string, std::string> TrackSimple::GetExternalUrls()
{
    return externalUrls;
}

std::string TrackSimple::GetHref()
{
    return href;
}

std::string TrackSimple::GetId()
{
    return id;
}

bool TrackSimple::IsPlayable()
{
    return isPlayable;
}

std::shared_ptr<TrackLink> TrackSimple::GetLinkedFrom()
{
    return linkedFrom;
}

std::string TrackSimple::GetName()
{
    return name;
}

std::string TrackSimple::GetPreviewUrl()
{
    return previewUrl;
}

int TrackSimple::GetTrackNumber()
{
    return trackNumber;
}

std::string TrackSimple::GetType()
{
    return type;
}

std::string TrackSimple::GetUri()
{
    return uri;
}