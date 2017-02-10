#include "Followers.h"

Followers::Followers(nlohmann::json followersJson)
{
    /* href currently always null, as the Web API doesn't yet support it */
    if(!followersJson["href"].is_null())
        href = followersJson["href"];
    if(followersJson["total"].is_null())
        total = 0;
    else
        total = followersJson["total"];
}

std::string Followers::GetHref() const
{
    return href;
}

int Followers::GetTotal() const
{
    return total;
}
