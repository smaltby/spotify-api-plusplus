#ifndef SPOTIFY_PLUSPLUS_ALBUMSIMPE_H
#define SPOTIFY_PLUSPLUS_ALBUMSIMPE_H

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "Pager.h"
#include "Copyright.h"
#include "Image.h"
#include "ArtistSimple.h"
#include "../utils/json.h"

class AlbumSimple
{
public:
    AlbumSimple(nlohmann::json albumJson);

    std::string GetAlbumType() const;
    std::vector<std::shared_ptr<ArtistSimple>> GetArtists() const;
    std::vector<std::string> GetAvailableMarkets() const;
    std::map<std::string, std::string> GetExternalUrls() const;
    std::string GetHref() const;
    std::string GetId() const;
    std::vector<std::shared_ptr<Image>> GetImages() const;
    std::string GetName() const;
    std::string GetType() const;
    std::string GetUri() const;

private:
    std::string albumType;
    std::vector<std::shared_ptr<ArtistSimple>> artists;
    std::vector<std::string> availableMarkets;
    std::map<std::string, std::string> externalUrls;
    std::string href;
    std::string id;
    std::vector<std::shared_ptr<Image>> images;
    std::string name;
    std::string type;
    std::string uri;
};


#endif
