#ifndef SPOTIFY_PLUSPLUS_AUDIOFEATURES_H
#define SPOTIFY_PLUSPLUS_AUDIOFEATURES_H

#include <string>
#include "../utils/json.h"

class AudioFeatures
{
public:
    AudioFeatures(nlohmann::json audioFeaturesJson);
    
    float GetAcousticness() const;
    std::string GetAnalysisUrl() const;
    float GetDanceability() const;
    int GetDurationMs() const;
    float GetEnergy() const;
    std::string GetId() const;
    float GetInstrumentalness() const;
    int GetKey() const;
    float GetLiveness() const;
    float GetLoudness() const;
    int GetMode() const;
    float GetSpeechiness() const;
    float GetTempo() const;
    int GetTimeSignature() const;
    std::string GetTrackHref() const;
    std::string GetType() const;
    std::string GetUri() const;
    float GetValence() const;

private:
    float acousticness;
    std::string analysisUrl;
    float danceability;
    int durationMs;
    float energy;
    std::string id;
    float instrumentalness;
    int key;
    float liveness;
    float loudness;
    int mode;
    float speechiness;
    float tempo;
    int timeSignature;
    std::string trackHref;
    std::string type;
    std::string uri;
    float valence;
};


#endif
