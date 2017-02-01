#include "AlbumSimple.h"

AlbumSimple::AlbumSimple(nlohmann::json albumJson)
{
    albumType = albumJson["album_type"];
    for(nlohmann::json json : albumJson["artists"])
        artists.push_back(std::shared_ptr<ArtistSimple>(new ArtistSimple(json)));
    for(std::string market : albumJson["available_markets"])
        availableMarkets.push_back(market);
    for (auto it = albumJson["external_urls"].begin(); it != albumJson["external_urls"].end(); ++it)
        externalUrls[it.key()] = it.value();
    href = albumJson["href"];
    id = albumJson["id"];
    for(nlohmann::json json : albumJson["images"])
        images.push_back(std::shared_ptr<Image>(new Image(json)));
    name = albumJson["name"];
    type = albumJson["type"];
    uri = albumJson["uri"];
}

std::string AlbumSimple::GetAlbumType()
{
    return albumType;
}

std::vector<std::shared_ptr<ArtistSimple>> AlbumSimple::GetArtists()
{
    return artists;
}

std::vector<std::string> AlbumSimple::GetAvailableMarkets()
{
    return availableMarkets;
}

std::map<std::string, std::string> AlbumSimple::GetExternalUrls()
{
    return externalUrls;
}

std::string AlbumSimple::GetHref()
{
    return href;
}

std::string AlbumSimple::GetId()
{
    return id;
}

std::vector<std::shared_ptr<Image>> AlbumSimple::GetImages()
{
    return images;
}

std::string AlbumSimple::GetName()
{
    return name;
}

std::string AlbumSimple::GetType()
{
    return type;
}

std::string AlbumSimple::GetUri()
{
    return uri;
}
