#ifndef SPOTIFY_PLUSPLUS_TRACKSIMPLE_H
#define SPOTIFY_PLUSPLUS_TRACKSIMPLE_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "TrackLink.h"
#include "Artist.h"
#include "utils/json.h"

class TrackSimple
{
public:
    TrackSimple(nlohmann::json trackJson);

    std::vector<std::shared_ptr<ArtistSimple>> GetArtists();
    std::vector<std::string> GetAvailableMarkets();
    int GetDiscNumber();
    int GetDurationMs();
    bool IsExplicit();
    std::map<std::string, std::string> GetExternalUrls();
    std::string GetHref();
    std::string GetId();
    bool IsPlayable();
    std::shared_ptr<TrackLink> GetLinkedFrom();
    std::string GetName();
    std::string GetPreviewUrl();
    int GetTrackNumber();
    std::string GetType();
    std::string GetUri();

private:
    std::vector<std::shared_ptr<ArtistSimple>> artists;
    std::vector<std::string> availableMarkets;
    int discNumber;
    int durationMs;
    bool isExplicit;
    std::map<std::string, std::string> externalUrls;
    std::string href;
    std::string id;
    bool isPlayable;
    std::shared_ptr<TrackLink> linkedFrom;
    std::string name;
    std::string previewUrl;
    int trackNumber;
    std::string type;
    std::string uri;
};


#endif
