#ifndef SPOTIFY_PLUSPLUS_PLAYLISTTRACK_H
#define SPOTIFY_PLUSPLUS_PLAYLISTTRACK_H

#include <string>
#include <memory>
#include "User.h"
#include "Track.h"
#include "utils/json.h"

class PlaylistTrack
{
public:
    PlaylistTrack(nlohmann::json trackJson);

    std::string GetAddedAt();
    std::shared_ptr<User> GetAddedBy();
    bool IsLocal();
    std::shared_ptr<Track> GetTrack();

private:
    std::string addedAt;
    std::shared_ptr<User> addedBy;
    bool isLocal;
    std::shared_ptr<Track> track;
};


#endif
