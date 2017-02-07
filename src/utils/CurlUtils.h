#ifndef SPOTIFY_PLUSPLUS_CURLUTILS_H
#define SPOTIFY_PLUSPLUS_CURLUTILS_H

#include <curl/curl.h>
#include "json.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

CURL * SpotifyCurlInternal(std::string request, std::string endpoint, std::map<std::string, std::string> options, std::string authToken, std::string body)
{
    CURL * curl;

    curl = curl_easy_init ( ) ;
    if(!curl)
    {
        std::cerr << "Could not initiate cURL" << std::endl;
        return curl;
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
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, request.c_str());

    if(!authToken.empty())
    {
        std::string header = "Authorization: Bearer " + authToken;
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, header.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    }
    if(!body.empty())
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
    return curl;
}

nlohmann::json SpotifyGET(std::string endpoint, std::map<std::string, std::string> options, std::string authToken, std::string body = "")
{
    CURL * curl = SpotifyCurlInternal("GET", endpoint, options, authToken, body);

    std::string readBuffer;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    int rc = curl_easy_perform(curl);
    if (rc == CURLE_OK)
        return nlohmann::json::parse(readBuffer);
    else
        std::cerr << "cURL error: " << rc << std::endl;
    curl_easy_cleanup(curl);
}

void SpotifyPUT(std::string endpoint, std::map<std::string, std::string> options, std::string authToken, std::string body = "")
{
    CURL * curl = SpotifyCurlInternal("PUT", endpoint, options, authToken, body);

    int rc = curl_easy_perform(curl);
    if (rc != CURLE_OK)
        std::cerr << "cURL error: " << rc << std::endl;
    curl_easy_cleanup(curl);
}

void SpotifyDELETE(std::string endpoint, std::map<std::string, std::string> options, std::string authToken, std::string body = "")
{
    CURL * curl = SpotifyCurlInternal("DELETE", endpoint, options, authToken, body);

    int rc = curl_easy_perform(curl);
    if (rc != CURLE_OK)
        std::cerr << "cURL error: " << rc << std::endl;
    curl_easy_cleanup(curl);
}

void SpotifyPOST(std::string endpoint, std::map<std::string, std::string> options, std::string authToken, std::string body = "")
{
    CURL * curl = SpotifyCurlInternal("POST", endpoint, options, authToken, body);

    int rc = curl_easy_perform(curl);
    if (rc != CURLE_OK)
        std::cerr << "cURL error: " << rc << std::endl;
    curl_easy_cleanup(curl);
}

std::string VectorJoin(std::vector<std::string> vector)
{
    std::stringstream ss;
    for(size_t i = 0; i < vector.size(); ++i)
    {
        if(i != 0)
            ss << ",";
        ss << vector[i];
    }
    return ss.str();
}

#endif
