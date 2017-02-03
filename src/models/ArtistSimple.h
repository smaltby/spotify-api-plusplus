#ifndef SPOTIFY_PLUSPLUS_ARTISTSIMPLE_H
#define SPOTIFY_PLUSPLUS_ARTISTSIMPLE_H

#include <string>
#include <map>
#include <memory>
#include <vector>
#include "Followers.h"
#include "Image.h"
#include "utils/json.h"

class ArtistSimple
{
public:
    ArtistSimple(nlohmann::json artistJson);

    std::map<std::string, std::string> GetExternalUrls();
    std::string GetHref();
    std::string GetId();
    std::string GetName();
    std::string GetType();
    std::string GetUri();

private:
    std::map<std::string, std::string> externalUrls;
    std::string href;
    std::string id;
    std::string name;
    std::string type;
    std::string uri;
};


#endif
