#ifndef SPOTIFY_PLUSPLUS_ALBUM_H
#define SPOTIFY_PLUSPLUS_ALBUM_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "Pager.h"
#include "Copyright.h"
#include "Image.h"
#include "Artist.h"
#include <spotify/utils/json.h>

class Track;

class Album
{
public:
    Album(nlohmann::json albumJson);
    ~Album();

    std::string GetAlbumType();
    std::vector<std::shared_ptr<Artist>> GetArtists();
    std::vector<std::string> GetAvailableMarkets();
    std::vector<std::shared_ptr<Copyright>> GetCopyrights();
    std::map<std::string, std::string> GetExternalIds();
    std::map<std::string, std::string> GetExternalUrls();
    std::vector<std::string> GetGenres();
    std::string GetHref();
    std::string GetId();
    std::vector<std::shared_ptr<Image>> GetImages();
    std::string GetLabel();
    std::string GetName();
    int GetPopularity();
    std::string GetReleaseDate();
    std::string GetReleaseDatePrecision();
    Pager<Track> GetTracks();
    std::string GetType();
    std::string GetUri();

private:
    std::string albumType;
    std::vector<std::shared_ptr<Artist>> artists;
    std::vector<std::string> availableMarkets;
    std::vector<std::shared_ptr<Copyright>> copyrights;
    std::map<std::string, std::string> externalIds;
    std::map<std::string, std::string> externalUrls;
    std::vector<std::string> genres;
    std::string href;
    std::string id;
    std::vector<std::shared_ptr<Image>> images;
    std::string label;
    std::string name;
    int popularity;
    std::string releaseDate;
    std::string releaseDatePrecision;
    Pager<Track> tracks;
    std::string type;
    std::string uri;
};

#endif
