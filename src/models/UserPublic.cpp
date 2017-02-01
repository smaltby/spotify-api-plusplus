#include "UserPublic.h"

UserPublic::UserPublic(nlohmann::json userJson)
{
    if(!userJson["display_name"].is_null())
        displayName = userJson["display_name"];
    for (auto it = userJson["external_urls"].begin(); it != userJson["external_urls"].end(); ++it)
        externalUrls[it.key()] = it.value();
    followers = std::shared_ptr<Followers>(new Followers(userJson["followers"]));
    href = userJson["href"];
    id = userJson["id"];
    for(nlohmann::json json : userJson["images"])
        images.push_back(std::shared_ptr<Image>(new Image(json)));
    type = userJson["type"];
    uri = userJson["uri"];
}

std::string UserPublic::GetDisplayName()
{
    return displayName;
}

std::map<std::string, std::string> UserPublic::GetExternalUrls()
{
    return externalUrls;
}

std::shared_ptr<Followers> UserPublic::GetFollowers()
{
    return followers;
}

std::string UserPublic::GetHref()
{
    return href;
}

std::string UserPublic::GetId()
{
    return id;
}

std::vector<std::shared_ptr<Image>> UserPublic::GetImages()
{
    return images;
}

std::string UserPublic::GetType()
{
    return type;
}

std::string UserPublic::GetUri()
{
    return uri;
}