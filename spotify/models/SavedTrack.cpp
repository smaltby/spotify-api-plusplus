#include "SavedTrack.h"

SavedTrack::SavedTrack(nlohmann::json trackJson)
{
    addedAt = trackJson["added_at"];
    track = std::shared_ptr<Track>(new Track(trackJson["track"]));
}

std::string SavedTrack::GetAddedAt()
{
    return addedAt;
}

std::shared_ptr<Track> SavedTrack::GetTrack()
{
    return track;
}

