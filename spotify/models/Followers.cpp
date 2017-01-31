#include "Followers.h"

Followers::Followers(nlohmann::json followersJson)
{
    /* href currently always null, as the Web API doesn't yet support it */
    if(!followersJson["href"].is_null())
        href = followersJson["href"];
    total = followersJson["total"];
}

std::string Followers::GetHref()
{
    return href;
}

int Followers::GetTotal()
{
    return total;
}
