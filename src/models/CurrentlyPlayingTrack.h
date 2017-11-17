#ifndef SPOTIFY_API_PLUSPLUS_CURRENTLYPLAYINGTRACK_H
#define SPOTIFY_API_PLUSPLUS_CURRENTLYPLAYINGTRACK_H

#include "Context.h"
#include "Track.h"
#include "../utils/json.h"

class CurrentlyPlayingTrack
{
public:
    CurrentlyPlayingTrack(nlohmann::json currentlyPlayingJson);

    Context GetContext() const;
    int GetTimestamp() const;
    int GetProgressMs() const;
    bool IsPlaying() const;
    Track GetItem() const;

private:
    Context context;
    int timestamp;
    int progressMs;
    bool isPlaying;
    Track item;
};


#endif
