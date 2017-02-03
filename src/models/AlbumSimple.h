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
#include "utils/json.h"

class AlbumSimple
{
public:
    AlbumSimple(nlohmann::json albumJson);

    std::string GetAlbumType();
    std::vector<std::shared_ptr<ArtistSimple>> GetArtists();
    std::vector<std::string> GetAvailableMarkets();
    std::map<std::string, std::string> GetExternalUrls();
    std::string GetHref();
    std::string GetId();
    std::vector<std::shared_ptr<Image>> GetImages();
    std::string GetName();
    std::string GetType();
    std::string GetUri();

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
