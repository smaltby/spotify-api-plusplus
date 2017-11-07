#ifndef SPOTIFY_PLUSPLUS_TRACKSIMPLE_H
#define SPOTIFY_PLUSPLUS_TRACKSIMPLE_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "TrackLink.h"
#include "Artist.h"
#include "../utils/json.h"

class TrackSimple
{
public:
    TrackSimple(nlohmann::json trackJson);

    std::vector<std::shared_ptr<ArtistSimple>> GetArtists() const;
    std::vector<std::string> GetAvailableMarkets() const;
    int GetDiscNumber() const;
    int GetDurationMs() const;
    bool IsExplicit() const;
    std::map<std::string, std::string> GetExternalUrls() const;
    std::string GetHref() const;
    std::string GetId() const;
    bool IsPlayable() const;
    std::shared_ptr<TrackLink> GetLinkedFrom() const;
    std::string GetName() const;
    std::string GetPreviewUrl() const;
    int GetTrackNumber() const;
    std::string GetType() const;
    std::string GetUri() const;

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
