#include "Album.h"
#include "Track.h"

Album::Album(nlohmann::json albumJson)
{
    albumType = albumJson["album_type"];
    for(nlohmann::json json : albumJson["artists"])
        artists.push_back(std::shared_ptr<Artist>(new Artist(json)));
    for(std::string market : albumJson["available_markets"])
        availableMarkets.push_back(market);
    for(nlohmann::json json : albumJson["copyrights"])
        copyrights.push_back(std::shared_ptr<Copyright>(new Copyright(json)));
    for (auto it = albumJson["external_ids"].begin(); it != albumJson["external_ids"].end(); ++it)
        externalIds[it.key()] = it.value();
    for (auto it = albumJson["external_urls"].begin(); it != albumJson["external_urls"].end(); ++it)
        externalUrls[it.key()] = it.value();
    for(std::string genre : albumJson["genres"])
        genres.push_back(genre);
    href = albumJson["href"];
    id = albumJson["id"];
    for(nlohmann::json json : albumJson["images"])
        images.push_back(std::shared_ptr<Image>(new Image(json)));
    name = albumJson["name"];
    popularity = albumJson["popularity"];
    releaseDate = albumJson["release_date"];
    releaseDatePrecision = albumJson["release_date_precision"];
    tracks = Pager<Track>(albumJson["tracks"]);
    type = albumJson["type"];
    uri = albumJson["uri"];
}

Album::~Album() = default;

std::string Album::GetAlbumType()
{
    return albumType;
}

std::vector<std::shared_ptr<Artist>> Album::GetArtists()
{
    return artists;
}

std::vector<std::string> Album::GetAvailableMarkets()
{
    return availableMarkets;
}

std::vector<std::shared_ptr<Copyright>> Album::GetCopyrights()
{
    return copyrights;
}

std::map<std::string, std::string> Album::GetExternalIds()
{
    return externalIds;
}

std::map<std::string, std::string> Album::GetExternalUrls()
{
    return externalUrls;
}

std::vector<std::string> Album::GetGenres()
{
    return genres;
}

std::string Album::GetHref()
{
    return href;
}

std::string Album::GetId()
{
    return id;
}

std::vector<std::shared_ptr<Image>> Album::GetImages()
{
    return images;
}


std::string Album::GetLabel()
{
    return label;
}

std::string Album::GetName()
{
    return name;
}

int Album::GetPopularity()
{
    return popularity;
}

std::string Album::GetReleaseDate()
{
    return releaseDate;
}

std::string Album::GetReleaseDatePrecision()
{
    return releaseDatePrecision;
}

Pager<Track> Album::GetTracks()
{
    return tracks;
}

std::string Album::GetType()
{
    return type;
}

std::string Album::GetUri()
{
    return uri;
}
