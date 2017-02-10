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

Pager<PlaylistSimple> SpotifyAPI::GetFeaturedPlaylists(options_t options)
{
    // TODO Add access to message variable
    return Pager<PlaylistSimple>(SpotifyGET("/v1/browse/featured-playlists", options, authToken)["playlists"]);
}

Pager<AlbumSimple> SpotifyAPI::GetNewReleases(options_t options)
{
    return Pager<AlbumSimple>(SpotifyGET("/v1/browse/new-releases", options, authToken)["albums"]);
}

Pager<Category> SpotifyAPI::GetCategories(options_t options)
{
    return Pager<Category>(SpotifyGET("/v1/browse/categories", options, authToken)["categories"]);
}

std::shared_ptr<Category> SpotifyAPI::GetCategory(std::string categoryId, options_t options)
{
    return std::shared_ptr<Category>(new Category(SpotifyGET("/v1/browse/categories/" + categoryId, options, authToken)));
}

Pager<PlaylistSimple> SpotifyAPI::GetCategoryPlaylists(std::string categoryId, options_t options)
{
    return Pager<PlaylistSimple>(SpotifyGET("/v1/browse/categories/" + categoryId + "/playlists", options, authToken)["playlists"]);
}

std::shared_ptr<User> SpotifyAPI::GetMe(options_t options)
{
    return std::shared_ptr<User>(new User(SpotifyGET("/v1/me", options, authToken)));
}

CursorPager<Artist> SpotifyAPI::GetMyFollowedArtists(options_t options)
{
    options["type"] = "artist";
    return CursorPager<Artist>(SpotifyGET("/v1/me/following", options, authToken)["artists"]);
}

void SpotifyAPI::FollowArtist(std::string artistId, options_t options)
{
    options["type"] = "artist";
    options["ids"] = artistId;
    SpotifyPUT("/v1/me/following", options, authToken);
}

void SpotifyAPI::FollowUser(std::string userId, options_t options)
{
    options["type"] = "user";
    options["ids"] = userId;
    SpotifyPUT("/v1/me/following", options, authToken);
}

void SpotifyAPI::UnfollowArtist(std::string artistId, options_t options)
{
    options["type"] = "artist";
    options["ids"] = artistId;
    SpotifyDELETE("/v1/me/following", options, authToken);
}

void SpotifyAPI::UnfollowUser(std::string userId, options_t options)
{
    options["type"] = "user";
    options["ids"] = userId;
    SpotifyDELETE("/v1/me/following", options, authToken);
}

bool SpotifyAPI::CheckFollowingArtist(std::string artistId, options_t options)
{
    options["type"] = "artist";
    options["ids"] = artistId;
    return SpotifyGET("/v1/me/following/contains", options, authToken);
}

bool SpotifyAPI::CheckFollowingUser(std::string userId, options_t options)
{
    options["type"] = "user";
    options["ids"] = userId;
    return SpotifyGET("/v1/me/following/contains", options, authToken)[0];
}

void SpotifyAPI::FollowPlaylist(std::string ownerId, std::string playlistId, options_t options)
{
    SpotifyPUT("/v1/users/" + ownerId + "/playlists/" + playlistId + "/followers", options, authToken);
}

void SpotifyAPI::UnfollowPlaylist(std::string ownerId, std::string playlistId, options_t options)
{
    SpotifyDELETE("/v1/users/" + ownerId + "/playlists/" + playlistId + "/followers", options, authToken);
}

void SpotifyAPI::SaveTracks(std::vector<std::string> trackIds, options_t options)
{
    options["ids"] = VectorJoin(trackIds);
    SpotifyPUT("/v1/me/tracks", options, authToken);
}

Pager<SavedTrack> SpotifyAPI::GetMySavedTracks(options_t options)
{
    return Pager<SavedTrack>(SpotifyGET("/v1/me/tracks", options, authToken));
}

void SpotifyAPI::RemoveSavedTracks(std::vector<std::string> trackIds, options_t options)
{
    options["ids"] = VectorJoin(trackIds);
    SpotifyDELETE("/v1/me/tracks", options, authToken);
}

bool SpotifyAPI::CheckSavedTracks(std::vector<std::string> trackIds, options_t options)
{
    options["ids"] = VectorJoin(trackIds);
    return SpotifyGET("/v1/me/tracks/contains", options, authToken)[0];
}

void SpotifyAPI::SaveAlbums(std::vector<std::string> albumIds, options_t options)
{
    options["ids"] = VectorJoin(albumIds);
    SpotifyPUT("/v1/me/albums", options, authToken);
}

Pager<SavedAlbum> SpotifyAPI::GetMySavedAlbums(options_t options)
{
    return Pager<SavedAlbum>(SpotifyGET("/v1/me/albums", options, authToken));
}

void SpotifyAPI::RemoveSavedAlbums(std::vector<std::string> albumIds, options_t options)
{
    options["ids"] = VectorJoin(albumIds);
    SpotifyDELETE("/v1/me/albums", options, authToken);
}

bool SpotifyAPI::CheckSavedAlbums(std::vector<std::string> albumIds, options_t options)
{
    options["ids"] = VectorJoin(albumIds);
    return SpotifyGET("/v1/me/albums/contains", options, authToken)[0];
}

Pager<Artist> SpotifyAPI::GetMyTopArtists(options_t options)
{
    return Pager<Artist>(SpotifyGET("/v1/me/top/artists", options, authToken));
}

Pager<Track> SpotifyAPI::GetMyTopTracks(options_t options)
{
    return Pager<Track>(SpotifyGET("/v1/me/top/tracks", options, authToken));
}

Recommendations SpotifyAPI::GetRecommendations(options_t options)
{
    return Recommendations(SpotifyGET("/v1/recommendations", options, authToken));
}

Pager<AlbumSimple> SpotifyAPI::SearchAlbums(std::string query, options_t options)
{
    options["type"] = "album";
    options["q"] = query;
    return Pager<AlbumSimple>(SpotifyGET("/v1/search", options, authToken));
}

Pager<Artist> SpotifyAPI::SearchArtists(std::string query, options_t options)
{
    options["type"] = "artist";
    options["q"] = query;
    return Pager<Artist>(SpotifyGET("/v1/search", options, authToken));
}

Pager<PlaylistSimple> SpotifyAPI::SearchPlaylists(std::string query, options_t options)
{
    options["type"] = "playlist";
    options["q"] = query;
    return Pager<PlaylistSimple>(SpotifyGET("/v1/search", options, authToken));
}

Pager<Track> SpotifyAPI::SearchTracks(std::string query, options_t options)
{
    options["type"] = "track";
    options["q"] = query;
    return Pager<Track>(SpotifyGET("/v1/search", options, authToken));
}

std::shared_ptr<Track> SpotifyAPI::GetTrack(std::string trackId, options_t options)
{
    return std::shared_ptr<Track>(new Track(SpotifyGET("/v1/tracks/" + trackId, options, authToken)));
}

std::vector<std::shared_ptr<Track>> SpotifyAPI::GetTracks(std::vector<std::string> trackIds, options_t options)
{
    std::vector<std::shared_ptr<Track>> tracks;
    for(std::string trackId : trackIds)
        tracks.push_back(GetTrack(trackId, options));
    return tracks;
}

std::shared_ptr<UserPublic> SpotifyAPI::GetUser(std::string userId, options_t options)
{
    return std::shared_ptr<UserPublic>(new UserPublic(SpotifyGET("/v1/users/" + userId, options, authToken)));
}

Pager<PlaylistSimple> SpotifyAPI::GetUserPlaylists(std::string userId, options_t options)
{
    return Pager<PlaylistSimple>(SpotifyGET("/v1/users/" + userId + "/playlists", options, authToken));
}

Pager<PlaylistSimple> SpotifyAPI::GetMyPlaylists(options_t options)
{
    return Pager<PlaylistSimple>(SpotifyGET("/v1/me/playlists", options, authToken));
}

std::shared_ptr<Playlist> SpotifyAPI::GetPlaylist(std::string userId, std::string playlistId, options_t options)
{
    return std::shared_ptr<Playlist>(new Playlist(SpotifyGET("/v1/users/" + userId + "/playlists/" + playlistId, options, authToken)));
}

Pager<PlaylistTrack> SpotifyAPI::GetPlaylistTracks(std::string userId, std::string playlistId, options_t options)
{
    return Pager<PlaylistTrack>(SpotifyGET("/v1/users/" + userId + "/playlists/" + playlistId + "/tracks", options, authToken));
}

void SpotifyAPI::CreatePlaylist(std::string userId, std::string name, options_t options)
{
    nlohmann::json bodyJson;
    bodyJson["name"] = name;
    for(auto option : options)
        bodyJson[option.first] = option.second;

    SpotifyPOST("/v1/users/" + userId + "/playlists", options_t(), authToken, bodyJson);
}

void SpotifyAPI::EditPlaylist(std::string userId, std::string playlistId, options_t options)
{
    nlohmann::json bodyJson;
    for(auto option : options)
        bodyJson[option.first] = option.second;

    SpotifyPUT("/v1/users/" + userId + "/playlists/" + playlistId, options_t(), authToken, bodyJson);
}

void SpotifyAPI::AddTracksToPlaylist(std::string userId, std::string playlistId, std::vector<std::string> trackUris,
                                     options_t options)
{
    options["uris"] = VectorJoin(trackUris);
    SpotifyPOST("/v1/users/" + userId + "/playlists/" + playlistId + "/tracks", options, authToken);
}

void SpotifyAPI::RemoveTracksFromPlaylist(std::string userId, std::string playlistId, std::vector<std::string> trackIds, std::string snapshotId)
{
    nlohmann::json bodyJson;
    for(std::string trackId : trackIds)
    {
        nlohmann::json uriJson;
        uriJson["uri"] = trackId;
        bodyJson["tracks"].push_back(uriJson);
    }
    if(!snapshotId.empty())
        bodyJson["snapshot_id"] = snapshotId;

    SpotifyDELETE("/v1/users/" + userId + "/playlists/" + playlistId + "/tracks", options_t(), authToken, bodyJson);
}

void SpotifyAPI::RemoveTracksFromPlaylist(std::string userId, std::string playlistId,
                                          std::map<std::string, std::vector<int>> trackUrisToPositions,
                                          std::string snapshotId)
{
    nlohmann::json bodyJson;
    for(auto trackIdToPositions : trackUrisToPositions)
    {
        nlohmann::json uriJson;
        uriJson["uri"] = trackIdToPositions.first;
        for(int position : trackIdToPositions.second)
            uriJson["positions"].push_back(position);
        bodyJson["tracks"].push_back(uriJson);
    }
    if(!snapshotId.empty())
        bodyJson["snapshot_id"] = snapshotId;

    SpotifyDELETE("/v1/users/" + userId + "/playlists/" + playlistId + "/tracks", options_t(), authToken, bodyJson);
}

void SpotifyAPI::RemoveTracksFromPlaylist(std::string userId, std::string playlistId, std::vector<int> positions,
                                          std::string snapshotId)
{
    nlohmann::json bodyJson;
    for(int position : positions)
        bodyJson["positions"].push_back(position);
    bodyJson["snapshot_id"] = snapshotId;

    SpotifyDELETE("/v1/users/" + userId + "/playlists/" + playlistId + "/tracks", options_t(), authToken, bodyJson);
}

void SpotifyAPI::ReorderPlaylistTracks(std::string userId, std::string playlistId, int rangeStart, int insertBefore,
                                       options_t options)
{
    nlohmann::json bodyJson;
    bodyJson["range_start"] = rangeStart;
    bodyJson["insert_before"] = insertBefore;
    for(auto option : options)
        bodyJson[option.first] = option.second;

    SpotifyPUT("/v1/users/" + userId + "/playlists/" + playlistId + "/tracks", options_t(), authToken, bodyJson);
}

void SpotifyAPI::ReplacePlaylistTracks(std::string userId, std::string playlistId, std::vector<std::string> trackUris,
                                       options_t options)
{
    options["uris"] = VectorJoin(trackUris);
    SpotifyPUT("/v1/users/" + userId + "/playlists/" + playlistId + "/tracks", options, authToken);
}

bool SpotifyAPI::CheckUserFollowingPlaylist(std::string userId, std::string playlistId, std::vector<std::string> userIds,
                                       options_t options)
{
    options["ids"] = VectorJoin(userIds);
    return SpotifyGET("/v1/users/" + userId + "/playlists/" + playlistId + "/followers/contains", options, authToken)[0];
}

