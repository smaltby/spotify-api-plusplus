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

std::vector<std::shared_ptr<ArtistSimple>> TrackSimple::GetArtists() const
{
    return artists;
}

std::vector<std::string> TrackSimple::GetAvailableMarkets() const
{
    return availableMarkets;
}

int TrackSimple::GetDiscNumber() const
{
    return discNumber;
}

int TrackSimple::GetDurationMs() const
{
    return durationMs;
}

bool TrackSimple::IsExplicit() const
{
    return isExplicit;
}

std::map<std::string, std::string> TrackSimple::GetExternalUrls() const
{
    return externalUrls;
}

std::string TrackSimple::GetHref() const
{
    return href;
}

std::string TrackSimple::GetId() const
{
    return id;
}

bool TrackSimple::IsPlayable() const
{
    return isPlayable;
}

std::shared_ptr<TrackLink> TrackSimple::GetLinkedFrom() const
{
    return linkedFrom;
}

std::string TrackSimple::GetName() const
{
    return name;
}

std::string TrackSimple::GetPreviewUrl() const
{
    return previewUrl;
}

int TrackSimple::GetTrackNumber() const
{
    return trackNumber;
}

std::string TrackSimple::GetType() const
{
    return type;
}

std::string TrackSimple::GetUri() const
{
    return uri;
}