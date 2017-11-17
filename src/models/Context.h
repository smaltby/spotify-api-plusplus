#ifndef SPOTIFY_API_PLUSPLUS_CONTEXT_H
#define SPOTIFY_API_PLUSPLUS_CONTEXT_H

#include "../utils/json.h"

class Context
{
public:
    Context(nlohmann::json contextJson);

    std::string GetUri() const;
    std::string GetHref() const;
    std::map<std::string, std::string> GetExternalUrls() const;
    std::string GetType() const;

private:
    std::string uri;
    std::string href;
    std::map<std::string, std::string> externalUrls;
    std::string type;
};


#endif
