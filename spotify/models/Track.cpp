#include "Track.h"
#include "Album.h"

Track::Track(nlohmann::json trackJson)
{
    album = std::shared_ptr<Album>(new Album(trackJson["album"]));
    for(nlohmann::json json : trackJson["artists"])
        artists.push_back(std::shared_ptr<Artist>(new Artist(json)));
    for(std::string market : trackJson["available_markets"])
        availableMarkets.push_back(market);
    discNumber = trackJson["disc_number"];
    durationMs = trackJson["duration_ms"];
    isExplicit = trackJson["explicit"];
    for (auto it = trackJson["external_ids"].begin(); it != trackJson["external_ids"].end(); ++it)
        externalIds[it.key()] = it.value();
    for (auto it = trackJson["external_urls"].begin(); it != trackJson["external_urls"].end(); ++it)
        externalUrls[it.key()] = it.value();
    href = trackJson["href"];
    id = trackJson["id"];
    isPlayable = trackJson["playable"];
    linkedFrom = std::shared_ptr<TrackLink>(new TrackLink(trackJson["linked_from"]));
    name = trackJson["name"];
    popularity = trackJson["popularity"];
    previewUrl = trackJson["preview_url"];
    trackNumber = trackJson["track_number"];
    type = trackJson["type"];
    uri = trackJson["uri"];
}

Track::~Track() = default;

std::shared_ptr<Album> Track::GetAlbum()
{
    return album;
}

std::vector<std::shared_ptr<Artist>> Track::GetArtists()
{
    return artists;
}

std::vector<std::string> Track::GetAvailableMarkets()
{
    return availableMarkets;
}

int Track::GetDiscNumber()
{
    return discNumber;
}

int Track::GetDurationMs()
{
    return durationMs;
}

bool Track::IsExplicit()
{
    return isExplicit;
}

std::map<std::string, std::string> Track::GetExternalIds()
{
    return externalIds;
}

std::map<std::string, std::string> Track::GetExternalUrls()
{
    return externalUrls;
}

std::string Track::GetHref()
{
    return href;
}

std::string Track::GetId()
{
    return id;
}

bool Track::IsPlayable()
{
    return isPlayable;
}

std::shared_ptr<TrackLink> Track::GetLinkedFrom()
{
    return linkedFrom;
}

std::string Track::GetName()
{
    return name;
}

int Track::GetPopularity()
{
    return popularity;
}

std::string Track::GetPreviewUrl()
{
    return previewUrl;
}

int Track::GetTrackNumber()
{
    return trackNumber;
}

std::string Track::GetType()
{
    return type;
}

std::string Track::GetUri()
{
    return uri;
}

