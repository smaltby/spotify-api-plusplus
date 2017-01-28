#include <iostream>
#include "SpotifyService.h"

SpotifyService::SpotifyService()
{
    curl_global_init( CURL_GLOBAL_ALL );
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::shared_ptr<Album> SpotifyService::GetAlbum(std::string id)
{
    CURL * curl;
    CURLcode result;
    std::string readBuffer;

    curl = curl_easy_init ( ) ;
    if(!curl)
    {
        return std::unique_ptr<Album>(new Album(nullptr));
    }

    curl_easy_setopt(curl, CURLOPT_URL, "https://api.spotify.com/v1/albums/6JWc4iAiJ9FjyK0B59ABb4");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);  // Can't authenticate the certificate, so disable authentication.
    int rc = curl_easy_perform(curl);
    if (rc == CURLE_OK)
    {
        nlohmann::json json = nlohmann::json::parse(readBuffer);
        return std::shared_ptr<Album>(new Album(json));
    } else
    {
        std::cerr << "cURL error: " << rc << std::endl;
    }

}