#include "Playlist.h"

Playlist::Playlist(nlohmann::json playlistJson) : PlaylistSimple::PlaylistSimple(playlistJson)
{
    if(!playlistJson["description"].is_null())
        description = playlistJson["description"];
    followers = std::shared_ptr<Followers>(new Followers(playlistJson["followers"]));
}

std::string Playlist::GetDescription() const
{
    return description;
}

std::shared_ptr<Followers> Playlist::GetFollowers() const
{
    return followers;
}