#ifndef SPOTIFY_PLUSPLUS_RECOMMENDATIONSSEED_H
#define SPOTIFY_PLUSPLUS_RECOMMENDATIONSSEED_H

#include <string>
#include "utils/json.h"

class RecommendationsSeed
{
public:
    RecommendationsSeed(nlohmann::json reccomendationsJson);

    int GetAfterFilteringSize();
    int GetAfterRelinkingSize();
    std::string GetHref();
    std::string GetId();
    int GetInitialPoolSize();
    std::string GetType();

private:
    int afterFilteringSize;
    int afterRelinkingSize;
    std::string href;
    std::string id;
    int initialPoolSize;
    std::string type;
};


#endif
