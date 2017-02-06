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

float AudioFeatures::GetAcousticness() const
{
    return acousticness;
}

std::string AudioFeatures::GetAnalysisUrl() const
{
    return analysisUrl;
}

float AudioFeatures::GetDanceability() const
{
    return danceability;
}

int AudioFeatures::GetDurationMs() const
{
    return durationMs;
}

float AudioFeatures::GetEnergy() const
{
    return energy;
}

std::string AudioFeatures::GetId() const
{
    return id;
}

float AudioFeatures::GetInstrumentalness() const
{
    return instrumentalness;
}

int AudioFeatures::GetKey() const
{
    return key;
}

float AudioFeatures::GetLiveness() const
{
    return liveness;
}

float AudioFeatures::GetLoudness() const
{
    return loudness;
}

int AudioFeatures::GetMode() const
{
    return mode;
}

float AudioFeatures::GetSpeechiness() const
{
    return speechiness;
}

float AudioFeatures::GetTempo() const
{
    return tempo;
}

int AudioFeatures::GetTimeSignature() const
{
    return timeSignature;
}

std::string AudioFeatures::GetTrackHref() const
{
    return trackHref;
}

std::string AudioFeatures::GetType() const
{
    return type;
}

std::string AudioFeatures::GetUri() const
{
    return uri;
}

float AudioFeatures::GetValence() const
{
    return valence;
}
