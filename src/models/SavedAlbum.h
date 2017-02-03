#ifndef SPOTIFY_PLUSPLUS_SAVEDALBUM_H
#define SPOTIFY_PLUSPLUS_SAVEDALBUM_H

#include <string>
#include "Album.h"
#include "utils/json.h"

class SavedAlbum
{
public:
    SavedAlbum(nlohmann::json albumJson);

    std::string GetAddedAt();
    std::shared_ptr<Album> GetAlbum();

private:
    std::string addedAt;
    std::shared_ptr<Album> album;
};


#endif
