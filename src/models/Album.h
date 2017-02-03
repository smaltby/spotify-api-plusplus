#ifndef SPOTIFY_PLUSPLUS_ALBUM_H
#define SPOTIFY_PLUSPLUS_ALBUM_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "utils/json.h"
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

    std::vector<std::shared_ptr<Copyright>> GetCopyrights();
    std::map<std::string, std::string> GetExternalIds();
    std::vector<std::string> GetGenres();
    std::string GetLabel();
    int GetPopularity();
    std::string GetReleaseDate();
    std::string GetReleaseDatePrecision();
    Pager<TrackSimple> GetTracks();

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
