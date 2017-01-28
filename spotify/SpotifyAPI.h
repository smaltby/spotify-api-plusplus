#ifndef SPOTIFY_PLUSPLUS_SPOTIFYSERVICE_H
#define SPOTIFY_PLUSPLUS_SPOTIFYSERVICE_H

#include <string>
#include <curl/curl.h>
#include <spotify/models/Track.h>
#include <spotify/models/AudioFeatures.h>
#include <spotify/models/Playlist.h>
#include <spotify/models/Category.h>
#include <spotify/models/CursorPager.h>
#include <spotify/models/SavedTrack.h>
#include <spotify/models/SavedAlbum.h>
#include <spotify/models/Recommendations.h>
#include "utils/json.h"
#include "models/Album.h"

class SpotifyAPI
{
public:
    SpotifyAPI();

    std::shared_ptr<Album> GetAlbum(std::string albumId);

    std::vector<std::shared_ptr<Album>> GetAlbums(std::vector<std::string> albumIds);

    Pager<TrackSimple> GetAlbumTracks(std::string albumId);

    std::shared_ptr<Artist> GetArtist(std::string artistId);

    std::vector<std::shared_ptr<Artist>> GetArtists(std::vector<std::string> artistIds);

    Pager<AlbumSimple> GetArtistAlbums(std::string artistId);

    std::vector<std::shared_ptr<Track>> GetArtistTopTracks(std::string artistId);

    std::vector<std::shared_ptr<Artist>> GetArtistRelatedArtists(std::string artistId);

    std::shared_ptr<AudioFeatures> GetAudioFeatures(std::string trackId);

    std::vector<std::shared_ptr<AudioFeatures>> GetAudioFeatures(std::vector<std::string> trackIds);

    Pager<Playlist> GetFeaturedPlaylists();

    Pager<AlbumSimple> GetNewReleases();

    Pager<Category> GetCategories();

    std::shared_ptr<Category> GetCategory(std::string categoryId);

    Pager<PlaylistSimple> GetCategoryPlaylists(std::string categoryId);

    std::shared_ptr<User> GetMe();

    CursorPager<Artist> GetMyFollowedArtists();

    void FollowArtist(std::string artistId);

    void FollowUser(std::string userId);

    void UnfollowArtist(std::string artistId);

    void UnfollowUser(std::string userId);

    bool CheckFollowingArtist(std::string artistId);

    bool CheckFollowingUser(std::string userId);

    void FollowPlaylist(std::string ownerId, std::string playlistId);

    void UnfollowPlaylist(std::string ownerId, std::string playlistId);

    void SaveTracks(std::vector<std::string> trackIds);

    Pager<SavedTrack> GetMySavedTracks();

    void RemoveSavedTracks(std::vector<std::string> trackIds);

    bool CheckSavedTracks(std::vector<std::string> trackIds);

    void SaveAlbums(std::vector<std::string> albumIds);

    Pager<SavedAlbum> GetMySavedAlbums();

    void RemoveSavedAlbums(std::vector<std::string> albumIds);

    bool CheckSavedAlbums(std::vector<std::string> albumIds);

    Pager<Artist> GetMyTopArtists();

    Pager<Track> GetMyTopTracks();

    Recommendations GetRecommendations();

    Pager<AlbumSimple> SearchAlbums(std::string query);

    Pager<Artist> SearchArtists(std::string query);

    Pager<PlaylistSimple> SearchPlaylists(std::string query);

    Pager<Track> SearchTracks(std::string query);

    std::shared_ptr<Track> GetTrack(std::string trackId);

    std::vector<std::shared_ptr<Track>> GetTracks(std::vector<std::string> trackIds);

    std::shared_ptr<UserPublic> GetUser(std::string userId);

    Pager<PlaylistSimple> GetUserPlaylists(std::string userId);

    Pager<PlaylistSimple> GetMyPlaylists();

    std::shared_ptr<Playlist> GetPlaylist(std::string userId, std::string playlistId);

    Pager<PlaylistTrack> GetPlaylistTracks(std::string userId, std::string playlistId);

    void CreatePlaylist(std::string userId);

    void EditPlaylist(std::string userId, std::string playlistId);

    void AddTracksToPlaylist(std::string userId, std::string playlistId);

    void RemoveTracksFromPlaylist(std::string userId, std::string playlistId);

    void ReorderPlaylistTracks(std::string userId, std::string playlistId);

    void ReplacePlaylistTracks(std::string userId, std::string playlistId);

    bool CheckUserFollowingPlaylist(std::string userId, std::string playlistId);
};


#endif
