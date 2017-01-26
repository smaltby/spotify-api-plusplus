#ifndef SPOTIFY_PLUSPLUS_SPOTIFYSERVICE_H
#define SPOTIFY_PLUSPLUS_SPOTIFYSERVICE_H

#include <string>
#include <curl/curl.h>
#include "utils/json.h"
#include "models/Album.h"

class SpotifyService
{
public:
    SpotifyService();

    std::shared_ptr<Album> GetAlbum(std::string id);
};


#endif
