#ifndef SPOTIFY_PLUSPLUS_AUDIOFEATURES_H
#define SPOTIFY_PLUSPLUS_AUDIOFEATURES_H

#include <string>
#include "utils/json.h"

class AudioFeatures
{
public:
    AudioFeatures(nlohmann::json audioFeaturesJson);
    
    float GetAcousticness();
    std::string GetAnalysisUrl();
    float GetDanceability();
    int GetDurationMs();
    float GetEnergy();
    std::string GetId();
    float GetInstrumentalness();
    int GetKey();
    float GetLiveness();
    float GetLoudness();
    int GetMode();
    float GetSpeechiness();
    float GetTempo();
    int GetTimeSignature();
    std::string GetTrackHref();
    std::string GetType();
    std::string GetUri();
    float GetValence();

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
