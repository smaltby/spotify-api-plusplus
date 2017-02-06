#include "Recommendations.h"

Recommendations::Recommendations(nlohmann::json reccomendationsJson)
{
    for(nlohmann::json json : reccomendationsJson["seeds"])
        seeds.push_back(std::shared_ptr<RecommendationsSeed>(new RecommendationsSeed(json)));
    for(nlohmann::json json : reccomendationsJson["tracks"])
        tracks.push_back(std::shared_ptr<Track>(new Track(json)));
}

std::vector<std::shared_ptr<RecommendationsSeed>> Recommendations::GetSeeds() const
{
    return seeds;
}

std::vector<std::shared_ptr<Track>> Recommendations::GetTracks() const
{
    return tracks;
}
