#ifndef SPOTIFY_PLUSPLUS_USERPUBLIC_H
#define SPOTIFY_PLUSPLUS_USERPUBLIC_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Followers.h"
#include "Image.h"
#include "utils/json.h"

class UserPublic
{
public:
    UserPublic(nlohmann::json userJson);

    std::string GetDisplayName();
    std::map<std::string, std::string> GetExternalUrls();
    std::shared_ptr<Followers> GetFollowers();
    std::string GetHref();
    std::string GetId();
    std::vector<std::shared_ptr<Image>> GetImages();
    std::string GetType();
    std::string GetUri();

private:
    std::string displayName;
    std::map<std::string, std::string> externalUrls;
    std::shared_ptr<Followers> followers;
    std::string href;
    std::string id;
    std::vector<std::shared_ptr<Image>> images;
    std::string type;
    std::string uri;
};


#endif
