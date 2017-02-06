#include "SavedTrack.h"

SavedTrack::SavedTrack(nlohmann::json trackJson)
{
    addedAt = trackJson["added_at"];
    track = std::shared_ptr<Track>(new Track(trackJson["track"]));
}

std::string SavedTrack::GetAddedAt() const
{
    return addedAt;
}

std::shared_ptr<Track> SavedTrack::GetTrack() const
{
    return track;
}

