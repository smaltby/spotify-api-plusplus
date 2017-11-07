#ifndef SPOTIFY_PLUSPLUS_RECOMMENDATIONSSEED_H
#define SPOTIFY_PLUSPLUS_RECOMMENDATIONSSEED_H

#include <string>
#include "../utils/json.h"

class RecommendationsSeed
{
public:
    RecommendationsSeed(nlohmann::json reccomendationsJson);

    int GetAfterFilteringSize() const;
    int GetAfterRelinkingSize() const;
    std::string GetHref() const;
    std::string GetId() const;
    int GetInitialPoolSize() const;
    std::string GetType() const;

private:
    int afterFilteringSize;
    int afterRelinkingSize;
    std::string href;
    std::string id;
    int initialPoolSize;
    std::string type;
};


#endif
