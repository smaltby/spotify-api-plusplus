#ifndef SPOTIFY_PLUSPLUS_PLAYLISTSIMPLE_H
#define SPOTIFY_PLUSPLUS_PLAYLISTSIMPLE_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Followers.h"
#include "Image.h"
#include "User.h"
#include "PlaylistTrack.h"
#include "Pager.h"
#include "utils/json.h"

class PlaylistSimple
{
public:
    PlaylistSimple(nlohmann::json playlistJson);

    bool IsCollaborative();
    std::map<std::string, std::string> GetExternalUrls();
    std::string GetHref();
    std::string GetId();
    std::vector<std::shared_ptr<Image>> GetImages();
    std::string GetName();
    std::shared_ptr<User> GetOwner();
    bool IsPublic();
    std::string GetSnapshotId();
    Pager<PlaylistTrack> GetTracks();
    std::string GetType();
    std::string GetUri();

private:
    bool isCollaborative;
    std::map<std::string, std::string> externalUrls;
    std::string href;
    std::string id;
    std::vector<std::shared_ptr<Image>> images;
    std::string name;
    std::shared_ptr<User> owner;
    bool isPublic;
    std::string snapshotId;
    Pager<PlaylistTrack> tracks;
    std::string type;
    std::string uri;
};


#endif
