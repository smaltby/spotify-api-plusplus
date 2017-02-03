#ifndef SPOTIFY_PLUSPLUS_TRACKLINK_H
#define SPOTIFY_PLUSPLUS_TRACKLINK_H

#include "utils/json.h"

class TrackLink
{
public:
    TrackLink(nlohmann::json trackJson);
    
    std::map<std::string, std::string> GetExternalUrls();
    std::string GetHref();
    std::string GetId();
    std::string GetType();
    std::string GetUri();

private:
    std::map<std::string, std::string> externalUrls;
    std::string href;
    std::string id;
    std::string type;
    std::string uri;
};


#endif
