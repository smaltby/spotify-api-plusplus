#ifndef SPOTIFY_PLUSPLUS_TRACK_H
#define SPOTIFY_PLUSPLUS_TRACK_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "TrackLink.h"
#include "Artist.h"
#include "TrackSimple.h"
#include "../utils/json.h"

class AlbumSimple;

class Track : public TrackSimple
{
public:
    Track(nlohmann::json trackJson);
    ~Track();

    std::shared_ptr<AlbumSimple> GetAlbum() const;
    std::map<std::string, std::string> GetExternalIds() const;
    int GetPopularity() const;

private:
    std::shared_ptr<AlbumSimple> album;
    std::map<std::string, std::string> externalIds;
    int popularity;
};

#endif
