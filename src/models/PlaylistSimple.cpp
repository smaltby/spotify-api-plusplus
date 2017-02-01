#include "PlaylistSimple.h"

PlaylistSimple::PlaylistSimple(nlohmann::json playlistJson)
{
    isCollaborative = playlistJson["collaborative "];
    for (auto it = playlistJson["external_urls"].begin(); it != playlistJson["external_urls"].end(); ++it)
        externalUrls[it.key()] = it.value();
    href = playlistJson["href"];
    id = playlistJson["id"];
    for(nlohmann::json json : playlistJson["images"])
        images.push_back(std::shared_ptr<Image>(new Image(json)));
    name = playlistJson["name"];
    owner = std::shared_ptr<User>(new User(playlistJson["owner"]));
    isPublic = playlistJson["public"];
    snapshotId = playlistJson["snapshot_id"];
    tracks = Pager<PlaylistTrack>(playlistJson["tracks"]);
    type = playlistJson["type"];
    uri = playlistJson["uri"];
}

bool PlaylistSimple::IsCollaborative()
{
    return isCollaborative;
}

std::map<std::string, std::string> PlaylistSimple::GetExternalUrls()
{
    return externalUrls;
}

std::string PlaylistSimple::GetHref()
{
    return href;
}

std::string PlaylistSimple::GetId()
{
    return id;
}

std::vector<std::shared_ptr<Image>> PlaylistSimple::GetImages()
{
    return images;
}

std::string PlaylistSimple::GetName()
{
    return name;
}

std::shared_ptr<User> PlaylistSimple::GetOwner()
{
    return owner;
}

bool PlaylistSimple::IsPublic()
{
    return isPublic;
}

std::string PlaylistSimple::GetSnapshotId()
{
    return snapshotId;
}

Pager<PlaylistTrack> PlaylistSimple::GetTracks()
{
    return tracks;
}

std::string PlaylistSimple::GetType()
{
    return type;
}

std::string PlaylistSimple::GetUri()
{
    return uri;
}