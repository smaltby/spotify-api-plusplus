#ifndef SPOTIFY_PLUSPLUS_SPOTIFYSERVICE_H
#define SPOTIFY_PLUSPLUS_SPOTIFYSERVICE_H

#include <string>
#include "models/Track.h"
#include "models/AudioFeatures.h"
#include "models/Playlist.h"
#include "models/Category.h"
#include "models/CursorPager.h"
#include "models/SavedTrack.h"
#include "models/SavedAlbum.h"
#include "models/Recommendations.h"
#include "models/Album.h"
#include "models/PlayHistoryObject.h"
#include "models/Device.h"
#include "models/CurrentlyPlayingContext.h"
#include "models/CurrentlyPlayingTrack.h"

typedef std::map<std::string, std::string> options_t;
class SpotifyAPI
{
public:
    SpotifyAPI();

    void setAuthToken(std::string authToken);

    std::shared_ptr<Album> GetAlbum(std::string albumId, options_t options = options_t());

    std::vector<std::shared_ptr<Album>> GetAlbums(std::vector<std::string> albumIds, options_t options = options_t());

    Pager<TrackSimple> GetAlbumTracks(std::string albumId, options_t options = options_t());

    std::shared_ptr<Artist> GetArtist(std::string artistId, options_t options = options_t());

    std::vector<std::shared_ptr<Artist>> GetArtists(std::vector<std::string> artistIds, options_t options = options_t());

    Pager<AlbumSimple> GetArtistAlbums(std::string artistId, options_t options = options_t());

    std::vector<std::shared_ptr<Track>> GetArtistTopTracks(std::string artistId, std::string country, options_t options = options_t());

    std::vector<std::shared_ptr<Artist>> GetArtistRelatedArtists(std::string artistId, options_t options = options_t());

    std::shared_ptr<AudioFeatures> GetAudioFeatures(std::string trackId, options_t options = options_t());

    std::vector<std::shared_ptr<AudioFeatures>> GetAudioFeatures(std::vector<std::string> trackIds, options_t options = options_t());

    Pager<PlaylistSimple> GetFeaturedPlaylists(options_t options = options_t());

    Pager<AlbumSimple> GetNewReleases(options_t options = options_t());

    Pager<Category> GetCategories(options_t options = options_t());

    std::shared_ptr<Category> GetCategory(std::string categoryId, options_t options = options_t());

    Pager<PlaylistSimple> GetCategoryPlaylists(std::string categoryId, options_t options = options_t());

    std::shared_ptr<User> GetMe(options_t options = options_t());

    CursorPager<Artist> GetMyFollowedArtists(options_t options = options_t());

    void FollowArtist(std::string artistId, options_t options = options_t());

    void FollowUser(std::string userId, options_t options = options_t());

    void UnfollowArtist(std::string artistId, options_t options = options_t());

    void UnfollowUser(std::string userId, options_t options = options_t());

    bool CheckFollowingArtist(std::string artistId, options_t options = options_t());

    bool CheckFollowingUser(std::string userId, options_t options = options_t());

    void FollowPlaylist(std::string ownerId, std::string playlistId, options_t options = options_t());

    void UnfollowPlaylist(std::string ownerId, std::string playlistId, options_t options = options_t());

    void SaveTracks(std::vector<std::string> trackIds, options_t options = options_t());

    Pager<SavedTrack> GetMySavedTracks(options_t options = options_t());

    void RemoveSavedTracks(std::vector<std::string> trackIds, options_t options = options_t());

    bool CheckSavedTracks(std::vector<std::string> trackIds, options_t options = options_t());

    void SaveAlbums(std::vector<std::string> albumIds, options_t options = options_t());

    Pager<SavedAlbum> GetMySavedAlbums(options_t options = options_t());

    void RemoveSavedAlbums(std::vector<std::string> albumIds, options_t options = options_t());

    bool CheckSavedAlbums(std::vector<std::string> albumIds, options_t options = options_t());

    Pager<Artist> GetMyTopArtists(options_t options = options_t());

    Pager<Track> GetMyTopTracks(options_t options = options_t());

    Recommendations GetRecommendations(options_t options = options_t());

    Pager<AlbumSimple> SearchAlbums(std::string query, options_t options = options_t());

    Pager<Artist> SearchArtists(std::string query, options_t options = options_t());

    Pager<PlaylistSimple> SearchPlaylists(std::string query, options_t options = options_t());

    Pager<Track> SearchTracks(std::string query, options_t options = options_t());

    std::shared_ptr<Track> GetTrack(std::string trackId, options_t options = options_t());

    std::vector<std::shared_ptr<Track>> GetTracks(std::vector<std::string> trackIds, options_t options = options_t());

    std::shared_ptr<UserPublic> GetUser(std::string userId, options_t options = options_t());

    Pager<PlaylistSimple> GetUserPlaylists(std::string userId, options_t options = options_t());

    Pager<PlaylistSimple> GetMyPlaylists(options_t options = options_t());

    std::shared_ptr<Playlist> GetPlaylist(std::string userId, std::string playlistId, options_t options = options_t());

    Pager<PlaylistTrack> GetPlaylistTracks(std::string userId, std::string playlistId, options_t options = options_t());

    std::shared_ptr<Playlist> CreatePlaylist(std::string userId, std::string name, options_t options = options_t());

    void EditPlaylist(std::string userId, std::string playlistId, options_t options = options_t());

    void AddTracksToPlaylist(std::string userId, std::string playlistId, std::vector<std::string> trackUris, options_t options = options_t());

    void RemoveTracksFromPlaylist(std::string userId, std::string playlistId, std::vector<std::string> trackUris, std::string snapshotId = "");

    void RemoveTracksFromPlaylist(std::string userId, std::string playlistId, std::map<std::string, std::vector<int>> trackUrisToPositions, std::string snapshotId = "");

    void RemoveTracksFromPlaylist(std::string userId, std::string playlistId, std::vector<int> positions, std::string snapshotId);

    void ReorderPlaylistTracks(std::string userId, std::string playlistId, int rangeStart, int insertBefore, options_t options = options_t());

    void ReplacePlaylistTracks(std::string userId, std::string playlistId, std::vector<std::string> trackUris, options_t options = options_t());

    bool CheckUserFollowingPlaylist(std::string userId, std::string playlistId, std::vector<std::string> userIds, options_t options = options_t());

    void UploadCustomPlaylistCover(std::string userId, std::string playlistId, std::string contentType, std::string image, options_t options = options_t());

    CursorPager<PlayHistoryObject> GetMyRecentlyPlayed(options_t options = options_t());

    std::vector<std::shared_ptr<Device>> GetMyDevices(options_t options = options_t());

    std::shared_ptr<CurrentlyPlayingContext> GetMyCurrentPlayback(options_t options = options_t());

    std::shared_ptr<CurrentlyPlayingTrack> GetMyCurrentPlayingTrack(options_t options = options_t());

    void TransferMyPlayback(std::string deviceId, options_t options = options_t());

    void Resume(options_t options = options_t());

    void Pause(options_t options = options_t());

    void SkipToNext(options_t options = options_t());

    void SkipToPrevious(options_t options = options_t());

    void SetRepeat(std::string state, options_t options = options_t());

    void SetVolume(int volumePercent, options_t options = options_t());

    void ToggleShuffle(bool state, options_t options = options_t());

private:
    std::string authToken;
};


#endif
