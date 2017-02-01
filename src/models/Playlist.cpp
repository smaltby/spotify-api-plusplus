#include "Playlist.h"

Playlist::Playlist(nlohmann::json playlistJson) : PlaylistSimple::PlaylistSimple(playlistJson)
{
    description = playlistJson["description"];
    followers = std::shared_ptr<Followers>(new Followers(playlistJson["followers"]));
}

std::string Playlist::GetDescription()
{
    return description;
}

std::shared_ptr<Followers> Playlist::GetFollowers()
{
    return followers;
}