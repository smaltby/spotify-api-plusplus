#include "RecommendationsSeed.h"

RecommendationsSeed::RecommendationsSeed(nlohmann::json reccomendationsJson)
{
    afterFilteringSize = reccomendationsJson["afterFilteringSize"];
    afterRelinkingSize = reccomendationsJson["afterRelinkingSize"];
    href = reccomendationsJson["href"];
    id = reccomendationsJson["id"];
    initialPoolSize = reccomendationsJson["initialPoolSize"];
    type = reccomendationsJson["type"];
}

int RecommendationsSeed::GetAfterFilteringSize() const
{
    return afterFilteringSize;
}

int RecommendationsSeed::GetAfterRelinkingSize() const
{
    return afterRelinkingSize;
}

std::string RecommendationsSeed::GetHref() const
{
    return href;
}

std::string RecommendationsSeed::GetId() const
{
    return id;
}

int RecommendationsSeed::GetInitialPoolSize() const
{
    return initialPoolSize;
}

std::string RecommendationsSeed::GetType() const
{
    return type;
}
