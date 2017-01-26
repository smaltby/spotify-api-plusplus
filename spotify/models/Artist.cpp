#include "Artist.h"

Artist::Artist(nlohmann::json artistJson)
{
    for (auto it = artistJson["external_urls"].begin(); it != artistJson["external_urls"].end(); ++it)
        externalUrls[it.key()] = it.value();
    followers = std::shared_ptr<Followers>(new Followers(artistJson["followers"]));
    for(std::string genre : artistJson["genres"])
        genres.push_back(genre);
    href = artistJson["href"];
    id = artistJson["id"];
    for(nlohmann::json json : artistJson["images"])
        images.push_back(std::shared_ptr<Image>(new Image(json)));
    name = artistJson["name"];
    popularity = artistJson["popularity"];
    type = artistJson["type"];
    uri = artistJson["uri"];
}

std::map<std::string, std::string> Artist::GetExternalUrls()
{
    return externalUrls;
}

std::shared_ptr<Followers> Artist::GetFollowers()
{
    return followers;
}

std::vector<std::string> Artist::GetGenres()
{
    return genres;
}

std::string Artist::GetHref()
{
    return href;
}

std::string Artist::GetId()
{
    return id;
}

std::vector<std::shared_ptr<Image>> Artist::GetImages()
{
    return images;
}


std::string Artist::GetName()
{
    return name;
}

int Artist::GetPopularity()
{
    return popularity;
}

std::string Artist::GetType()
{
    return type;
}

std::string Artist::GetUri()
{
    return uri;
}
