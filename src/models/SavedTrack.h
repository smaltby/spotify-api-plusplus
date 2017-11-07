#ifndef SPOTIFY_PLUSPLUS_SAVEDTRACK_H
#define SPOTIFY_PLUSPLUS_SAVEDTRACK_H

#include <string>
#include <memory>
#include "Track.h"
#include "../utils/json.h"


class SavedTrack
{
public:
    SavedTrack(nlohmann::json trackJson);

    std::string GetAddedAt() const;
    std::shared_ptr<Track> GetTrack() const;

private:
    std::string addedAt;
    std::shared_ptr<Track> track;
};


#endif
