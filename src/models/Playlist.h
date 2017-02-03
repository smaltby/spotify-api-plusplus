#ifndef SPOTIFY_PLUSPLUS_PLAYLIST_H
#define SPOTIFY_PLUSPLUS_PLAYLIST_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Followers.h"
#include "Image.h"
#include "User.h"
#include "PlaylistTrack.h"
#include "Pager.h"
#include "PlaylistSimple.h"
#include "utils/json.h"


class Playlist : public PlaylistSimple
{
public:
    Playlist(nlohmann::json playlistJson);

    std::string GetDescription();
    std::shared_ptr<Followers> GetFollowers();

private:
    std::string description;
    std::shared_ptr<Followers> followers;
};


#endif
