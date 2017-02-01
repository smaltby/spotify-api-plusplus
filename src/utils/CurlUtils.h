#ifndef SPOTIFY_PLUSPLUS_CURLUTILS_H
#define SPOTIFY_PLUSPLUS_CURLUTILS_H

#include <curl/curl.h>
#include "json.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

nlohmann::json SpotifyCurlInternal(std::string request, std::string endpoint, std::map<std::string, std::string> options, std::string authToken)
{
    CURL * curl;
    std::string readBuffer;

    curl = curl_easy_init ( ) ;
    if(!curl)
    {
        std::cerr << "Could not initiate cURL" << std::endl;
        return nlohmann::json();
    }

    std::string url = "https://api.spotify.com" + endpoint;
    if(!options.empty())
    {
        url += "?";
        for(auto option : options)
        {
            url += option.first + "=" + option.second + '&';
        }
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);  // Can't authenticate the certificate, so disable authentication.
    if(request == "PUT")
    {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
    } else if(request == "GET")
    {
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    }

    if(!authToken.empty())
    {
        std::string header = "Authorization: Bearer " + authToken;
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, header.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    }

    int rc = curl_easy_perform(curl);
    if (rc == CURLE_OK)
    {
        curl_easy_cleanup(curl);
        if(request == "GET")
            return nlohmann::json::parse(readBuffer);
    }
    std::cerr << "cURL error: " << rc << std::endl;
    return nlohmann::json();
}

nlohmann::json SpotifyGET(std::string endpoint, std::map<std::string, std::string> options, std::string authToken)
{
    return SpotifyCurlInternal("GET", endpoint, options, authToken);
}

void SpotifyPUT(std::string endpoint, std::map<std::string, std::string> options, std::string authToken)
{
    SpotifyCurlInternal("PUT", endpoint, options, authToken);
}

#endif
