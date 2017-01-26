#ifndef SPOTIFY_PLUSPLUS_USER_H
#define SPOTIFY_PLUSPLUS_USER_H

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Followers.h"
#include "Image.h"
#include <spotify/utils/json.h>


class User
{
public:
    User(nlohmann::json userJson);

    std::string GetBirthdate();
    std::string GetCountry();
    std::string GetDisplayName();
    std::string GetEmail();
    std::map<std::string, std::string> GetExternalUrls();
    std::shared_ptr<Followers> GetFollowers();
    std::string GetHref();
    std::string GetId();
    std::vector<std::shared_ptr<Image>> GetImages();
    std::string GetProduct();
    std::string GetType();
    std::string GetUri();

private:
    std::string birthdate;
    std::string country;
    std::string displayName;
    std::string email;
    std::map<std::string, std::string> externalUrls;
    std::shared_ptr<Followers> followers;
    std::string href;
    std::string id;
    std::vector<std::shared_ptr<Image>> images;
    std::string product;
    std::string type;
    std::string uri;
};


#endif
