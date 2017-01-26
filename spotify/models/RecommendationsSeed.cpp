#include "RecommendationsSeed.h"

RecommendationsSeed::RecommendationsSeed(nlohmann::json reccomendationsJson)
{
    afterFilteringSize = reccomendationsJson["after_filtering_size"];
    afterRelinkingSize = reccomendationsJson["after_relinking_size"];
    href = reccomendationsJson["href"];
    id = reccomendationsJson["id"];
    initialPoolSize = reccomendationsJson["initialPoolSize"];
    type = reccomendationsJson["type"];
}

int RecommendationsSeed::GetAfterFilteringSize()
{
    return afterFilteringSize;
}

int RecommendationsSeed::GetAfterRelinkingSize()
{
    return afterRelinkingSize;
}

std::string RecommendationsSeed::GetHref()
{
    return href;
}

std::string RecommendationsSeed::GetId()
{
    return id;
}

int RecommendationsSeed::GetInitialPoolSize()
{
    return initialPoolSize;
}

std::string RecommendationsSeed::GetType()
{
    return type;
}
