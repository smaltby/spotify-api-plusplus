#include <iostream>
#include "SpotifyAPI.h"
#include <curl/curl.h>
#include <utils/CurlUtils.h>

SpotifyAPI::SpotifyAPI()
{
    curl_global_init( CURL_GLOBAL_ALL );
}

void SpotifyAPI::setAuthToken(std::string authToken)
{
    this->authToken = authToken;
}

std::shared_ptr<Album> SpotifyAPI::GetAlbum(std::string albumId, options_t options)
{
    return std::shared_ptr<Album>(new Album(SpotifyGET("/v1/albums/" + albumId, options, authToken)));
}

std::vector<std::shared_ptr<Album>> SpotifyAPI::GetAlbums(std::vector<std::string> albumIds, options_t options)
{
    std::vector<std::shared_ptr<Album>> albums;
    for(std::string albumId : albumIds)
        albums.push_back(GetAlbum(albumId, options));
    return albums;
}

Pager<TrackSimple> SpotifyAPI::GetAlbumTracks(std::string albumId, options_t options)
{
    return Pager<TrackSimple>(SpotifyGET("/v1/albums/" + albumId + "/tracks", options, authToken));
}

std::shared_ptr<Artist> SpotifyAPI::GetArtist(std::string artistId, options_t options)
{
    return std::shared_ptr<Artist>(new Artist(SpotifyGET("/v1/artists/" + artistId, options, authToken)));
}

std::vector<std::shared_ptr<Artist>> SpotifyAPI::GetArtists(std::vector<std::string> artistIds, options_t options)
{
    std::vector<std::shared_ptr<Artist>> artists;
    for(std::string artistId : artistIds)
        artists.push_back(GetArtist(artistId));
    return artists;
}

Pager<AlbumSimple> SpotifyAPI::GetArtistAlbums(std::string artistId, options_t options)
{
    return Pager<AlbumSimple>(SpotifyGET("/v1/artists/" + artistId + "/albums", options, authToken));
}

std::vector<std::shared_ptr<Track>> SpotifyAPI::GetArtistTopTracks(std::string artistId, std::string country, options_t options)
{
    std::vector<std::shared_ptr<Track>> tracks;
    options["country"] = country;
    nlohmann::json json = SpotifyGET("/v1/artists/" + artistId + "/top-tracks", options, authToken);
    for(nlohmann::json trackJson : json["tracks"])
    {
        tracks.push_back(std::shared_ptr<Track>(new Track(trackJson)));
    }
    return tracks;
}

std::vector<std::shared_ptr<Artist>> SpotifyAPI::GetArtistRelatedArtists(std::string artistId, options_t options)
{
    std::vector<std::shared_ptr<Artist>> artists;
    nlohmann::json json = SpotifyGET("/v1/artists/" + artistId + "/related-artists", options, authToken);
    for(nlohmann::json artistJson : json["artists"])
        artists.push_back(std::shared_ptr<Artist>(new Artist(artistJson)));
    return artists;
}

std::shared_ptr<AudioFeatures> SpotifyAPI::GetAudioFeatures(std::string trackId, options_t options)
{
    return std::shared_ptr<AudioFeatures>(new AudioFeatures(SpotifyGET("/v1/audio-features/" + trackId, options, authToken)));
}

std::vector<std::shared_ptr<AudioFeatures>> SpotifyAPI::GetAudioFeatures(std::vector<std::string> trackIds, options_t options)
{
    std::vector<std::shared_ptr<AudioFeatures>> audioFeatures;
    for(std::string trackId : trackIds)
        audioFeatures.push_back(GetAudioFeatures(trackId, options));
    return audioFeatures;
}

Pager<Playlist> SpotifyAPI::GetFeaturedPlaylists(options_t options)
{
    return Pager<Playlist>(SpotifyGET("/v1/browse/featured-playlists", options, authToken));
}

Pager<AlbumSimple> SpotifyAPI::GetNewReleases(options_t options)
{
    return Pager<AlbumSimple>(SpotifyGET("/v1/browse/new-releases", options, authToken));
}

Pager<Category> SpotifyAPI::GetCategories(options_t options)
{
    return Pager<Category>(SpotifyGET("/v1/browse/categories", options, authToken));
}

std::shared_ptr<Category> SpotifyAPI::GetCategory(std::string categoryId, options_t options)
{
    return std::shared_ptr<Category>(new Category(SpotifyGET("/v1/browse/categories/" + categoryId, options, authToken)));
}

Pager<PlaylistSimple> SpotifyAPI::GetCategoryPlaylists(std::string categoryId, options_t options)
{
    return Pager<PlaylistSimple>(SpotifyGET("/v1/browse/categories/" + categoryId + "/playlists", options, authToken));
}

std::shared_ptr<User> SpotifyAPI::GetMe(options_t options)
{
    return std::shared_ptr<User>(new User(SpotifyGET("/v1/me", options, authToken)));
}

CursorPager<Artist> SpotifyAPI::GetMyFollowedArtists(options_t options)
{
    return CursorPager<Artist>(SpotifyGET("/v1/me/following", options, authToken));
}

void SpotifyAPI::FollowArtist(std::string artistId, options_t options)
{
    options["type"] = "artist";
    options["ids"] = artistId;
    SpotifyPUT("/v1/me/following", options, authToken);
}