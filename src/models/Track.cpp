#include "Track.h"
#include "AlbumSimple.h"

Track::Track(nlohmann::json trackJson) : TrackSimple::TrackSimple(trackJson)
{
    album = std::shared_ptr<AlbumSimple>(new AlbumSimple(trackJson["album"]));
    for (auto it = trackJson["external_ids"].begin(); it != trackJson["external_ids"].end(); ++it)
        externalIds[it.key()] = it.value();
    popularity = trackJson["popularity"];
}

Track::~Track() = default;

std::shared_ptr<AlbumSimple> Track::GetAlbum()
{
    return album;
}

std::map<std::string, std::string> Track::GetExternalIds()
{
    return externalIds;
}

int Track::GetPopularity()
{
    return popularity;
}
