#include "PlaylistTrack.h"

PlaylistTrack::PlaylistTrack(nlohmann::json trackJson)
{
    addedAt = trackJson["added_at"];
    addedBy = std::shared_ptr<UserPublic>(new UserPublic(trackJson["added_by"]));
    isLocal = trackJson["is_local"];
    track =std::shared_ptr<Track>(new Track(trackJson["track"]));
}

std::string PlaylistTrack::GetAddedAt() const
{
    return addedAt;
}

std::shared_ptr<UserPublic> PlaylistTrack::GetAddedBy() const
{
    return addedBy;
}

bool PlaylistTrack::IsLocal() const
{
    return isLocal;
}

std::shared_ptr<Track> PlaylistTrack::GetTrack() const
{
    return track;
}

