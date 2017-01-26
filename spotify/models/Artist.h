#ifndef SPOTIFY_PLUSPLUS_ARTIST_H
#define SPOTIFY_PLUSPLUS_ARTIST_H

#include <string>
#include <map>
#include <memory>
#include <vector>
#include "Followers.h"
#include "Image.h"
#include <spotify/utils/json.h>


class Artist
{
public:
    Artist(nlohmann::json artistJson);

    std::map<std::string, std::string> GetExternalUrls();
    std::shared_ptr<Followers> GetFollowers();
    std::vector<std::string> GetGenres();
    std::string GetHref();
    std::string GetId();
    std::vector<std::shared_ptr<Image>> GetImages();
    std::string GetName();
    int GetPopularity();
    std::string GetType();
    std::string GetUri();

private:
    std::map<std::string, std::string> externalUrls;
    std::shared_ptr<Followers> followers;
    std::vector<std::string> genres;
    std::string href;
    std::string id;
    std::vector<std::shared_ptr<Image>> images;
    std::string name;
    int popularity;
    std::string type;
    std::string uri;
};

#endif
