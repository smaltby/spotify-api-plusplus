#ifndef SPOTIFY_PLUSPLUS_RECCOMENDATIONS_H
#define SPOTIFY_PLUSPLUS_RECCOMENDATIONS_H

#include <vector>
#include <memory>
#include "RecommendationsSeed.h"
#include "Track.h"
#include "../utils/json.h"

class Recommendations
{
public:
    Recommendations(nlohmann::json reccomendationsJson);

    std::vector<std::shared_ptr<RecommendationsSeed>> GetSeeds() const;
    std::vector<std::shared_ptr<Track>> GetTracks() const;

private:
    std::vector<std::shared_ptr<RecommendationsSeed>> seeds;
    std::vector<std::shared_ptr<Track>> tracks;
};


#endif
