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
#include <spotify/utils/json.h>


class Playlist
{
public:
    Playlist(nlohmann::json playlistJson);
    
    bool IsCollaborative();
    std::string GetDescription();
    std::map<std::string, std::string> GetExternalUrls();
    std::shared_ptr<Followers> GetFollowers();
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
    std::string description;
    std::map<std::string, std::string> externalUrls;
    std::shared_ptr<Followers> followers;
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
