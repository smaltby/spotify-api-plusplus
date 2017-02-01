#include "AudioFeatures.h"

AudioFeatures::AudioFeatures(nlohmann::json audioFeaturesJson)
{
    acousticness = audioFeaturesJson["acousticness"];
    analysisUrl = audioFeaturesJson["analysis_url"];
    danceability = audioFeaturesJson["danceability"];
    durationMs = audioFeaturesJson["duration_ms"];
    energy = audioFeaturesJson["energy"];
    id = audioFeaturesJson["id"];
    instrumentalness = audioFeaturesJson["instrumentalness"];
    key = audioFeaturesJson["key"];
    liveness = audioFeaturesJson["liveness"];
    loudness = audioFeaturesJson["loudness"];
    mode = audioFeaturesJson["mode"];
    speechiness = audioFeaturesJson["speechiness"];
    tempo = audioFeaturesJson["tempo"];
    timeSignature = audioFeaturesJson["time_signature"];
    trackHref = audioFeaturesJson["track_href"];
    type = audioFeaturesJson["type"];
    uri = audioFeaturesJson["uri"];
    valence = audioFeaturesJson["valence"];
}

float AudioFeatures::GetAcousticness()
{
    return acousticness;
}

std::string AudioFeatures::GetAnalysisUrl()
{
    return analysisUrl;
}

float AudioFeatures::GetDanceability()
{
    return danceability;
}

int AudioFeatures::GetDurationMs()
{
    return durationMs;
}

float AudioFeatures::GetEnergy()
{
    return energy;
}

std::string AudioFeatures::GetId()
{
    return id;
}

float AudioFeatures::GetInstrumentalness()
{
    return instrumentalness;
}

int AudioFeatures::GetKey()
{
    return key;
}

float AudioFeatures::GetLiveness()
{
    return liveness;
}

float AudioFeatures::GetLoudness()
{
    return loudness;
}

int AudioFeatures::GetMode()
{
    return mode;
}

float AudioFeatures::GetSpeechiness()
{
    return speechiness;
}

float AudioFeatures::GetTempo()
{
    return tempo;
}

int AudioFeatures::GetTimeSignature()
{
    return timeSignature;
}

std::string AudioFeatures::GetTrackHref()
{
    return trackHref;
}

std::string AudioFeatures::GetType()
{
    return type;
}

std::string AudioFeatures::GetUri()
{
    return uri;
}

float AudioFeatures::GetValence()
{
    return valence;
}
