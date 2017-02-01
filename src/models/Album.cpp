#include "Album.h"
#include "TrackSimple.h"

Album::Album(nlohmann::json albumJson) : AlbumSimple::AlbumSimple(albumJson)
{
    for(nlohmann::json json : albumJson["copyrights"])
        copyrights.push_back(std::shared_ptr<Copyright>(new Copyright(json)));
    for (auto it = albumJson["external_ids"].begin(); it != albumJson["external_ids"].end(); ++it)
        externalIds[it.key()] = it.value();
    for(std::string genre : albumJson["genres"])
        genres.push_back(genre);
    popularity = albumJson["popularity"];
    releaseDate = albumJson["release_date"];
    releaseDatePrecision = albumJson["release_date_precision"];
    tracks = Pager<TrackSimple>(albumJson["tracks"]);
}

Album::~Album() = default;

std::vector<std::shared_ptr<Copyright>> Album::GetCopyrights()
{
    return copyrights;
}

std::map<std::string, std::string> Album::GetExternalIds()
{
    return externalIds;
}

std::vector<std::string> Album::GetGenres()
{
    return genres;
}

std::string Album::GetLabel()
{
    return label;
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

Pager<TrackSimple> Album::GetTracks()
{
    return tracks;
}
