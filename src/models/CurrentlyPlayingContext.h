#ifndef SPOTIFY_API_PLUSPLUS_CURRENTLYPLAYINGCONTEXT_H
#define SPOTIFY_API_PLUSPLUS_CURRENTLYPLAYINGCONTEXT_H

#include "Context.h"
#include "Device.h"
#include "Track.h"
#include "../utils/json.h"

class CurrentlyPlayingContext
{
public:
    CurrentlyPlayingContext(nlohmann::json currentlyPlayingJson);

    Device GetDevice() const;
    std::string GetRepeatState() const;
    bool GetShuffleState() const;
    Context GetContext() const;
    int GetTimestamp() const;
    int GetProgressMs() const;
    bool IsPlaying() const;
    Track GetItem() const;

private:
    Device device;
    std::string repeatState;
    bool shuffleState;
    Context context;
    int timestamp;
    int progressMs;
    bool isPlaying;
    Track item;
};


#endif
