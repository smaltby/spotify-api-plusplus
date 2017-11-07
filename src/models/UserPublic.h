#ifndef SPOTIFY_PLUSPLUS_USERPUBLIC_H
#define SPOTIFY_PLUSPLUS_USERPUBLIC_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Followers.h"
#include "Image.h"
#include "../utils/json.h"

class UserPublic
{
public:
    UserPublic(nlohmann::json userJson);

    std::string GetDisplayName() const;
    std::map<std::string, std::string> GetExternalUrls() const;
    std::shared_ptr<Followers> GetFollowers() const;
    std::string GetHref() const;
    std::string GetId() const;
    std::vector<std::shared_ptr<Image>> GetImages() const;
    std::string GetType() const;
    std::string GetUri() const;

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
