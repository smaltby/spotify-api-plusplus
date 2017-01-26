#include "User.h"

User::User(nlohmann::json userJson)
{
    birthdate = userJson["birthdate"];
    country = userJson["country"];
    displayName = userJson["display_name"];
    email = userJson["email"];
    for (auto it = userJson["external_urls"].begin(); it != userJson["external_urls"].end(); ++it)
        externalUrls[it.key()] = it.value();
    followers = std::shared_ptr<Followers>(new Followers(userJson["followers"]));
    href = userJson["href"];
    id = userJson["id"];
    for(nlohmann::json json : userJson["images"])
        images.push_back(std::shared_ptr<Image>(new Image(json)));
    product = userJson["product"];
    type = userJson["type"];
    uri = userJson["uri"];
}

std::string User::GetBirthdate()
{
    return birthdate;
}

std::string User::GetCountry()
{
    return country;
}

std::string User::GetDisplayName()
{
    return displayName;
}

std::string User::GetEmail()
{
    return email;
}

std::map<std::string, std::string> User::GetExternalUrls()
{
    return externalUrls;
}

std::shared_ptr<Followers> User::GetFollowers()
{
    return followers;
}

std::string User::GetHref()
{
    return href;
}

std::string User::GetId()
{
    return id;
}

std::vector<std::shared_ptr<Image>> User::GetImages()
{
    return images;
}

std::string User::GetProduct()
{
    return product;
}

std::string User::GetType()
{
    return type;
}

std::string User::GetUri()
{
    return uri;
}

