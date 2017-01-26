#include "Playlist.h"

Playlist::Playlist(nlohmann::json playlistJson)
{
    isCollaborative = playlistJson["collaborative "];
    description = playlistJson["description"];
    for (auto it = playlistJson["external_urls"].begin(); it != playlistJson["external_urls"].end(); ++it)
        externalUrls[it.key()] = it.value();
    followers = std::shared_ptr<Followers>(new Followers(playlistJson["followers"]));
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

bool Playlist::IsCollaborative()
{
    return isCollaborative;
}

std::string Playlist::GetDescription()
{
    return description;
}

std::map<std::string, std::string> Playlist::GetExternalUrls()
{
    return externalUrls;
}

std::shared_ptr<Followers> Playlist::GetFollowers()
{
    return followers;
}

std::string Playlist::GetHref()
{
    return href;
}

std::string Playlist::GetId()
{
    return id;
}

std::vector<std::shared_ptr<Image>> Playlist::GetImages()
{
    return images;
}

std::string Playlist::GetName()
{
    return name;
}

std::shared_ptr<User> Playlist::GetOwner()
{
    return owner;
}

bool Playlist::IsPublic()
{
    return isPublic;
}

std::string Playlist::GetSnapshotId()
{
    return snapshotId;
}

Pager<PlaylistTrack> Playlist::GetTracks()
{
    return tracks;
}

std::string Playlist::GetType()
{
    return type;
}

std::string Playlist::GetUri()
{
    return uri;
}
