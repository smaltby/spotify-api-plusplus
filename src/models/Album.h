#ifndef SPOTIFY_PLUSPLUS_ALBUM_H
#define SPOTIFY_PLUSPLUS_ALBUM_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "../utils/json.h"
#include "Pager.h"
#include "Copyright.h"
#include "Image.h"
#include "Artist.h"
#include "AlbumSimple.h"

class TrackSimple;

class Album : public AlbumSimple
{
public:
    Album(nlohmann::json albumJson);
    ~Album();

    std::vector<std::shared_ptr<Copyright>> GetCopyrights() const;
    std::map<std::string, std::string> GetExternalIds() const;
    std::vector<std::string> GetGenres() const;
    std::string GetLabel() const;
    int GetPopularity() const;
    std::string GetReleaseDate() const;
    std::string GetReleaseDatePrecision() const;
    Pager<TrackSimple> GetTracks() const;

private:

    std::vector<std::shared_ptr<Copyright>> copyrights;
    std::map<std::string, std::string> externalIds;
    std::vector<std::string> genres;
    std::string label;
    int popularity;
    std::string releaseDate;
    std::string releaseDatePrecision;
    Pager<TrackSimple> tracks;

};

#endif
