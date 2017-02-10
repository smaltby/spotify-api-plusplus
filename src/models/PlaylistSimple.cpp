#include "PlaylistSimple.h"

PlaylistSimple::PlaylistSimple(nlohmann::json playlistJson)
{
    isCollaborative = playlistJson["collaborative"];
    for (auto it = playlistJson["external_urls"].begin(); it != playlistJson["external_urls"].end(); ++it)
        externalUrls[it.key()] = it.value();
    href = playlistJson["href"];
    id = playlistJson["id"];
    for(nlohmann::json json : playlistJson["images"])
        images.push_back(std::shared_ptr<Image>(new Image(json)));
    name = playlistJson["name"];
    owner = std::shared_ptr<UserPublic>(new UserPublic(playlistJson["owner"]));
    if(playlistJson["public"].is_null())
        isPublic = false;
    else
        isPublic = playlistJson["public"];
    snapshotId = playlistJson["snapshot_id"];
    tracks = Pager<PlaylistTrack>(playlistJson["tracks"]);
    type = playlistJson["type"];
    uri = playlistJson["uri"];
}

bool PlaylistSimple::IsCollaborative() const
{
    return isCollaborative;
}

std::map<std::string, std::string> PlaylistSimple::GetExternalUrls() const
{
    return externalUrls;
}

std::string PlaylistSimple::GetHref() const
{
    return href;
}

std::string PlaylistSimple::GetId() const
{
    return id;
}

std::vector<std::shared_ptr<Image>> PlaylistSimple::GetImages() const
{
    return images;
}

std::string PlaylistSimple::GetName() const
{
    return name;
}

std::shared_ptr<UserPublic> PlaylistSimple::GetOwner() const
{
    return owner;
}

bool PlaylistSimple::IsPublic() const
{
    return isPublic;
}

std::string PlaylistSimple::GetSnapshotId() const
{
    return snapshotId;
}

Pager<PlaylistTrack> PlaylistSimple::GetTracks() const
{
    return tracks;
}

std::string PlaylistSimple::GetType() const
{
    return type;
}

std::string PlaylistSimple::GetUri() const
{
    return uri;
}