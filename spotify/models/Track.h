#ifndef SPOTIFY_PLUSPLUS_TRACK_H
#define SPOTIFY_PLUSPLUS_TRACK_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "TrackLink.h"
#include "Artist.h"
#include "TrackSimple.h"
#include <spotify/utils/json.h>

class Album;

class Track : public TrackSimple
{
public:
    Track(nlohmann::json trackJson);
    ~Track();

    std::shared_ptr<Album> GetAlbum();
    std::map<std::string, std::string> GetExternalIds();
    int GetPopularity();

private:
    std::shared_ptr<Album> album;
    std::map<std::string, std::string> externalIds;
    int popularity;
};

#endif
