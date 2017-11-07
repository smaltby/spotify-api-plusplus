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
#include "../utils/json.h"

class PlaylistSimple
{
public:
    PlaylistSimple(nlohmann::json playlistJson);

    bool IsCollaborative() const;
    std::map<std::string, std::string> GetExternalUrls() const;
    std::string GetHref() const;
    std::string GetId() const;
    std::vector<std::shared_ptr<Image>> GetImages() const;
    std::string GetName() const;
    std::shared_ptr<UserPublic> GetOwner() const;
    bool IsPublic() const;
    std::string GetSnapshotId() const;
    Pager<PlaylistTrack> GetTracks() const;
    std::string GetType() const;
    std::string GetUri() const;

private:
    bool isCollaborative;
    std::map<std::string, std::string> externalUrls;
    std::string href;
    std::string id;
    std::vector<std::shared_ptr<Image>> images;
    std::string name;
    std::shared_ptr<UserPublic> owner;
    bool isPublic;
    std::string snapshotId;
    Pager<PlaylistTrack> tracks;
    std::string type;
    std::string uri;
};


#endif
