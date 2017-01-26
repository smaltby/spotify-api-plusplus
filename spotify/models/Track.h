#ifndef SPOTIFY_PLUSPLUS_TRACK_H
#define SPOTIFY_PLUSPLUS_TRACK_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "TrackLink.h"
#include "Artist.h"
#include <spotify/utils/json.h>

class Album;

class Track
{
public:
    Track(nlohmann::json trackJson);
    ~Track();

    std::shared_ptr<Album> GetAlbum();
    std::vector<std::shared_ptr<Artist>> GetArtists();
    std::vector<std::string> GetAvailableMarkets();
    int GetDiscNumber();
    int GetDurationMs();
    bool IsExplicit();
    std::map<std::string, std::string> GetExternalIds();
    std::map<std::string, std::string> GetExternalUrls();
    std::string GetHref();
    std::string GetId();
    bool IsPlayable();
    std::shared_ptr<TrackLink> GetLinkedFrom();
    std::string GetName();
    int GetPopularity();
    std::string GetPreviewUrl();
    int GetTrackNumber();
    std::string GetType();
    std::string GetUri();

private:
    std::shared_ptr<Album> album;
    std::vector<std::shared_ptr<Artist>> artists;
    std::vector<std::string> availableMarkets;
    int discNumber;
    int durationMs;
    bool isExplicit;
    std::map<std::string, std::string> externalIds;
    std::map<std::string, std::string> externalUrls;
    std::string href;
    std::string id;
    bool isPlayable;
    std::shared_ptr<TrackLink> linkedFrom;
    std::string name;
    int popularity;
    std::string previewUrl;
    int trackNumber;
    std::string type;
    std::string uri;
};

#endif
