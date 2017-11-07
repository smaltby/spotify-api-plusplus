#ifndef SPOTIFY_PLUSPLUS_CURLUTILS_H
#define SPOTIFY_PLUSPLUS_CURLUTILS_H

#include <curl/curl.h>
#include "../models/Error.h"
#include "json.h"
#include "CurlException.h"
#include "SpotifyException.h"

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

nlohmann::json SpotifyCurlInternal(std::string request, std::string endpoint, std::map<std::string, std::string> options, std::string authToken, std::string body)
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
    url = ReplaceAll(url, " ", "%20");

    std::string readBuffer;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

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

    int rc = curl_easy_perform(curl);
    if (rc != CURLE_OK)
        throw CurlException(rc);

    long statusCode = 0;
    curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &statusCode);
    if(statusCode < 200 || statusCode > 204)
        throw SpotifyException(Error(nlohmann::json::parse(readBuffer)["error"]));

    curl_easy_cleanup(curl);
    if(readBuffer.empty())
        return nlohmann::json();
    return nlohmann::json::parse(readBuffer);
}

nlohmann::json SpotifyGET(std::string endpoint, std::map<std::string, std::string> options, std::string authToken, std::string body = "")
{
    return SpotifyCurlInternal("GET", endpoint, options, authToken, body);
}

nlohmann::json SpotifyPUT(std::string endpoint, std::map<std::string, std::string> options, std::string authToken, std::string body = "")
{
   return SpotifyCurlInternal("PUT", endpoint, options, authToken, body);
}

nlohmann::json SpotifyDELETE(std::string endpoint, std::map<std::string, std::string> options, std::string authToken, std::string body = "")
{
    return SpotifyCurlInternal("DELETE", endpoint, options, authToken, body);
}

nlohmann::json SpotifyPOST(std::string endpoint, std::map<std::string, std::string> options, std::string authToken, std::string body = "")
{
    return SpotifyCurlInternal("POST", endpoint, options, authToken, body);
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
