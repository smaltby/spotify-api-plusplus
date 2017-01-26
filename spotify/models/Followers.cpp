#include "Followers.h"

Followers::Followers(nlohmann::json followersJson)
{
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
