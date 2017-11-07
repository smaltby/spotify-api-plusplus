#ifndef SPOTIFY_PLUSPLUS_TRACKLINK_H
#define SPOTIFY_PLUSPLUS_TRACKLINK_H

#include "../utils/json.h"

class TrackLink
{
public:
    TrackLink(nlohmann::json trackJson);
    
    std::map<std::string, std::string> GetExternalUrls() const;
    std::string GetHref() const;
    std::string GetId() const;
    std::string GetType() const;
    std::string GetUri() const;

private:
    std::map<std::string, std::string> externalUrls;
    std::string href;
    std::string id;
    std::string type;
    std::string uri;
};


#endif
