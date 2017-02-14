#include <SpotifyAPI.h>
#include <gtest/gtest.h>
#include <fstream>
#include <gmock/gmock.h>
#include <curl/curl.h>
#include <utils/CurlUtils.h>

class TestEndpoints : public ::testing::Test
{
protected:
    static SpotifyAPI sharedApi;
    SpotifyAPI api;
    virtual void SetUp()
    {
        api = TestEndpoints::sharedApi;
    }

    static void SetUpTestCase()
    {
        sharedApi = SpotifyAPI();

        std::string refreshToken = GetStringFromFile("../refresh_token.txt");
        std::string clientId = GetStringFromFile("../client_id.txt");
        std::string clientSecret = GetStringFromFile("../client_secret.txt");

        CURL * curl;
        curl = curl_easy_init ( ) ;
        if(!curl)
        {
            std::cerr << "Could not initiate cURL" << std::endl;
            return;
        }

        std::string readBuffer;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        curl_easy_setopt(curl, CURLOPT_URL, "https://accounts.spotify.com/api/token");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);  // Can't authenticate the certificate, so disable authentication.
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
        std::string postData = "grant_type=refresh_token&refresh_token="+refreshToken+"&client_id=" + clientId + "&client_secret="+clientSecret;
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());

        int rc = curl_easy_perform(curl);
        if (rc != CURLE_OK)
        {
            std::cerr << "cURL error: " << rc << std::endl;
            return;
        }
        curl_easy_cleanup(curl);

        nlohmann::json json = nlohmann::json::parse(readBuffer);
        std::string accessToken = json["access_token"];

        sharedApi.setAuthToken(accessToken);
    }

private:
    static std::string GetStringFromFile(std::string fileName)
    {
        std::stringstream buffer;
        std::ifstream file(fileName);
        buffer << file.rdbuf();
        file.close();
        return buffer.str();
    }
};
SpotifyAPI TestEndpoints::sharedApi;

TEST_F(TestEndpoints, GetAlbumTest)
{
    std::shared_ptr<Album> album = api.GetAlbum("0sNOF9WDwhWunNAHPD3Baj");
    ASSERT_STREQ(album->GetName().c_str(), "She's So Unusual");
}

TEST_F(TestEndpoints, GetAlbumsTest)
{
    std::vector<std::shared_ptr<Album>> albums = api.GetAlbums({"41MnTivkwTO3UUJ8DrqEJJ", "6JWc4iAiJ9FjyK0B59ABb4", "6UXCm6bOO4gFlDQZV5yL37"});
    ASSERT_THAT(albums, testing::ElementsAre(testing::Property(&std::shared_ptr<Album>::operator*, testing::Property(&Album::GetName, testing::StrEq("The Best Of Keane (Deluxe Edition)"))),
                                             testing::Property(&std::shared_ptr<Album>::operator*, testing::Property(&Album::GetName, testing::StrEq("Strangeland"))),
                                             testing::Property(&std::shared_ptr<Album>::operator*, testing::Property(&Album::GetName, testing::StrEq("Night Train")))
    ));
}

TEST_F(TestEndpoints, GetAlbumTracksTest)
{
    Pager<TrackSimple> tracks = api.GetAlbumTracks("6akEvsycLGftJxYudPjmqK");
    ASSERT_STREQ(tracks.GetItems()[0].GetName().c_str(), "All I Want");
    ASSERT_EQ(tracks.GetTotal(), 11);
}

TEST_F(TestEndpoints, GetArtistTest)
{
    std::shared_ptr<Artist> artist = api.GetArtist("0OdUWJ0sBjDrqHygGUXeCF");
    ASSERT_STREQ(artist->GetName().c_str(), "Band of Horses");
}

TEST_F(TestEndpoints, GetArtistsTest)
{
    std::vector<std::shared_ptr<Artist>> artists = api.GetArtists({"0oSGxfWSnnOXhD2fKuz2Gy", "3dBVyJ7JuOMt4GE9607Qin"});
    ASSERT_THAT(artists, testing::ElementsAre(testing::Property(&std::shared_ptr<Artist>::operator*, testing::Property(&Artist::GetName, testing::StrEq("David Bowie"))),
                                             testing::Property(&std::shared_ptr<Artist>::operator*, testing::Property(&Artist::GetName, testing::StrEq("T. Rex")))
    ));
}

TEST_F(TestEndpoints, GetArtistAlbumsTest)
{
    Pager<AlbumSimple> albums = api.GetArtistAlbums("1vCWHaC5f2uS3yhpwWbIA6");
    ASSERT_THAT(albums.GetItems(), testing::Contains(testing::Property(&AlbumSimple::GetName, testing::StrEq("Taste The Feeling (Avicii Vs. Conrad Sewell)"))));
}

TEST_F(TestEndpoints, GetArtistTopTracksTest)
{
    std::vector<std::shared_ptr<Track>> tracks = api.GetArtistTopTracks("43ZHCT0cAZBISjO8DG9PnE", "US");
    //An artist's top tracks change over time, so we can't test specific tracks.
    //If the function doesn't return an error, and 10 tracks are returned, the function is probably working as intended
    ASSERT_EQ(tracks.size(), 10);
}

TEST_F(TestEndpoints, GetArtistRelatedArtistsTest)
{
    std::vector<std::shared_ptr<Artist>> artists = api.GetArtistRelatedArtists("43ZHCT0cAZBISjO8DG9PnE");
    //Similar to the above test, related artists change, so just test the number of artists returned
    ASSERT_EQ(artists.size(), 20);
}

TEST_F(TestEndpoints, GetAudioFeaturesTest)
{
    std::shared_ptr<AudioFeatures> features = api.GetAudioFeatures("06AKEBrKUckW0KREUWRnvT");
    ASSERT_FLOAT_EQ(features->GetDanceability(), 0.735);
    ASSERT_EQ(features->GetDurationMs(), 255349);
}

TEST_F(TestEndpoints, GetAudioFeaturesTest2)
{
    std::vector<std::shared_ptr<AudioFeatures>> features = api.GetAudioFeatures((std::vector<std::string>) {"06AKEBrKUckW0KREUWRnvT", "2NRANZE9UCmPAS5XVbXL40"});
    ASSERT_EQ(features[0]->GetDurationMs(), 255349);
    ASSERT_EQ(features[1]->GetDurationMs(), 187800);
}

TEST_F(TestEndpoints, GetFeaturedPlaylistsTest)
{
    Pager<PlaylistSimple> playlists = api.GetFeaturedPlaylists();
    ASSERT_EQ(playlists.GetLimit(), 20);
}

TEST_F(TestEndpoints, GetNewReleasesTest)
{
    Pager<AlbumSimple> albums = api.GetNewReleases();
    ASSERT_EQ(albums.GetLimit(), 20);
}

TEST_F(TestEndpoints, GetCategoriesTest)
{
    Pager<Category> categories = api.GetCategories();
    ASSERT_EQ(categories.GetLimit(), 20);
}

TEST_F(TestEndpoints, GetCategoryTest)
{
    std::shared_ptr<Category> category = api.GetCategory("party");
    ASSERT_STREQ(category->GetName().c_str(), "Party");
}

TEST_F(TestEndpoints, GetCategoryPlaylistsTest)
{
    Pager<PlaylistSimple> playlists = api.GetCategoryPlaylists("party");
    ASSERT_EQ(playlists.GetLimit(), 20);
}

TEST_F(TestEndpoints, GetMeTest)
{
    std::shared_ptr<User> me = api.GetMe();
    ASSERT_STREQ(me->GetType().c_str(), "user");
}

TEST_F(TestEndpoints, MyFollowedArtistsTest)
{
    // Follow Band of Horses and check to make sure that MyFollowedArtists contains it
    api.FollowArtist("0OdUWJ0sBjDrqHygGUXeCF");
    std::vector<Artist> followed = api.GetMyFollowedArtists().GetItems();
    ASSERT_THAT(followed, testing::Contains(testing::Property(&Artist::GetName, testing::StrEq("Band of Horses"))));
    ASSERT_TRUE(api.CheckFollowingArtist("0OdUWJ0sBjDrqHygGUXeCF"));

    // Unfollow Band of Horses and check to make sure that MyFollowedArtists no longer contains it
    api.UnfollowArtist("0OdUWJ0sBjDrqHygGUXeCF");
    followed = api.GetMyFollowedArtists().GetItems();
    ASSERT_THAT(followed, testing::Not(testing::Contains(testing::Property(&Artist::GetName, testing::StrEq("Band of Horses")))));
    ASSERT_FALSE(api.CheckFollowingArtist("0OdUWJ0sBjDrqHygGUXeCF"));
}

TEST_F(TestEndpoints, MyFollowedUsersTest)
{
    api.FollowUser("exampleuser01");
    ASSERT_TRUE(api.CheckFollowingUser("exampleuser01"));

    api.UnfollowUser("exampleuser01");
    ASSERT_FALSE(api.CheckFollowingUser("exampleuser01"));
}

TEST_F(TestEndpoints, MyFollowedPlaylistsTest)
{
    api.FollowPlaylist("jmperezperez", "2v3iNvBX8Ay1Gt2uXtUKUT");
    ASSERT_TRUE(api.CheckUserFollowingPlaylist("jmperezperez", "2v3iNvBX8Ay1Gt2uXtUKUT", {api.GetMe()->GetId()}));

    api.UnfollowPlaylist("jmperezperez", "2v3iNvBX8Ay1Gt2uXtUKUT");
    ASSERT_FALSE(api.CheckUserFollowingPlaylist("jmperezperez", "2v3iNvBX8Ay1Gt2uXtUKUT", {api.GetMe()->GetId()}));
}

TEST_F(TestEndpoints, MySavedTracksTest)
{
    api.SaveTracks({"3n3Ppam7vgaVa1iaRUc9Lp"});
    Pager<SavedTrack> tracks = api.GetMySavedTracks();
    ASSERT_THAT(tracks.GetItems(), testing::Contains(testing::Property(&SavedTrack::GetTrack,
                                                     testing::Property(&std::shared_ptr<Track>::operator*,
                                                     testing::Property(&Track::GetName, testing::StrEq("Mr. Brightside"))))));
    ASSERT_TRUE(api.CheckSavedTracks({"3n3Ppam7vgaVa1iaRUc9Lp"}));

    api.RemoveSavedTracks({"3n3Ppam7vgaVa1iaRUc9Lp"});
    tracks = api.GetMySavedTracks();
    ASSERT_THAT(tracks.GetItems(), testing::Not(testing::Contains(testing::Property(&SavedTrack::GetTrack,
                                                     testing::Property(&std::shared_ptr<Track>::operator*,
                                                     testing::Property(&Track::GetName, testing::StrEq("Mr. Brightside")))))));
    ASSERT_FALSE(api.CheckSavedTracks({"3n3Ppam7vgaVa1iaRUc9Lp"}));
}

TEST_F(TestEndpoints, MySavedAlbumsTest)
{
    api.SaveAlbums({"0sNOF9WDwhWunNAHPD3Baj"});
    Pager<SavedAlbum> albums = api.GetMySavedAlbums();
    ASSERT_THAT(albums.GetItems(), testing::Contains(testing::Property(&SavedAlbum::GetAlbum,
                                                     testing::Property(&std::shared_ptr<Album>::operator*,
                                                     testing::Property(&Album::GetName, testing::StrEq("She's So Unusual"))))));
    ASSERT_TRUE(api.CheckSavedAlbums({"0sNOF9WDwhWunNAHPD3Baj"}));

    api.RemoveSavedAlbums({"0sNOF9WDwhWunNAHPD3Baj"});
    albums = api.GetMySavedAlbums();
    ASSERT_THAT(albums.GetItems(), testing::Not(testing::Contains(testing::Property(&SavedAlbum::GetAlbum,
                                                                  testing::Property(&std::shared_ptr<Album>::operator*,
                                                                  testing::Property(&Album::GetName, testing::StrEq("She's So Unusual")))))));
    ASSERT_FALSE(api.CheckSavedAlbums({"0sNOF9WDwhWunNAHPD3Baj"}));
}

TEST_F(TestEndpoints, MyTopArtistsTest)
{
    Pager<Artist> artists = api.GetMyTopArtists();
    ASSERT_EQ(artists.GetLimit(), 20);
}

TEST_F(TestEndpoints, MyTopTracksTest)
{
    Pager<Track> tracks = api.GetMyTopTracks();
    ASSERT_EQ(tracks.GetLimit(), 20);
}

TEST_F(TestEndpoints, RecommendationsTest)
{
    std::map<std::string, std::string> options;
    options["seed_artists"] = "4NHQUGzhtTLFvgF5SZesLK";
    options["seed_tracks"] = "0c6xIDDpzE81m2q797ordA";
    options["min_energy"] = "0.4";
    options["min_popularity"] = "50";
    options["market"] = "US";

    Recommendations recommendations = api.GetRecommendations(options);
    ASSERT_EQ(recommendations.GetTracks().size(), 20);
}

TEST_F(TestEndpoints, SearchAlbumsTest)
{
    Pager<AlbumSimple> albums = api.SearchAlbums("Adventure");

    ASSERT_THAT(albums.GetItems(), testing::Contains(testing::Property(&AlbumSimple::GetName, testing::StrEq("Adventure (Deluxe)"))));
}

TEST_F(TestEndpoints, SearchArtistsTest)
{
    Pager<Artist> artists = api.SearchArtists("Killers");

    ASSERT_THAT(artists.GetItems(), testing::Contains(testing::Property(&ArtistSimple::GetName, testing::StrEq("The Killers"))));
}

TEST_F(TestEndpoints, SearchPlaylistsTest)
{
    Pager<PlaylistSimple> playlists = api.SearchPlaylists("Today's");

    ASSERT_THAT(playlists.GetItems(), testing::Contains(testing::Property(&PlaylistSimple::GetName, testing::StrEq("Today's Top Hits"))));
}

TEST_F(TestEndpoints, SearchTracksTest)
{
    Pager<Track> tracks = api.SearchTracks("Brightside");

    ASSERT_THAT(tracks.GetItems(), testing::Contains(testing::Property(&TrackSimple::GetName, testing::StrEq("Mr. Brightside"))));
}

TEST_F(TestEndpoints, GetTrackTest)
{
    std::shared_ptr<Track> track = api.GetTrack("3n3Ppam7vgaVa1iaRUc9Lp");
    ASSERT_STREQ(track->GetName().c_str(), "Mr. Brightside");
}

TEST_F(TestEndpoints, GetTracksTest)
{
    std::vector<std::shared_ptr<Track>> tracks = api.GetTracks({"3n3Ppam7vgaVa1iaRUc9Lp", "3twNvmDtFQtAd5gMKedhLD"});
    ASSERT_THAT(tracks, testing::ElementsAre(testing::Property(&std::shared_ptr<Track>::operator*, testing::Property(&Track::GetName, testing::StrEq("Mr. Brightside"))),
                                             testing::Property(&std::shared_ptr<Track>::operator*, testing::Property(&Track::GetName, testing::StrEq("Somebody Told Me")))
    ));
}

TEST_F(TestEndpoints, GetUserTest)
{
    std::shared_ptr<UserPublic> user = api.GetUser("tuggareutangranser");
    ASSERT_STREQ(user->GetDisplayName().c_str(), "Lilla Namo");
}

TEST_F(TestEndpoints, EditPlaylistsTest)
{
    std::shared_ptr<User> me = api.GetMe();

    // Create a playlist and make sure the playlist is properly returned with the correct attributes
    std::shared_ptr<Playlist> playlist = api.CreatePlaylist(me->GetId(), "Test Playlist");
    ASSERT_STREQ(playlist->GetName().c_str(), "Test Playlist");

    // Make sure the playlist is followed on being created
    Pager<PlaylistSimple> myPlaylists = api.GetMyPlaylists();
    ASSERT_THAT(myPlaylists.GetItems(), testing::Contains(testing::Property(&PlaylistSimple::GetName, testing::StrEq("Test Playlist"))));

    // Add tracks and make sure they are in the list of playlist tracks
    api.AddTracksToPlaylist(me->GetId(), playlist->GetId(), {"spotify:track:3n3Ppam7vgaVa1iaRUc9Lp", "spotify:track:3twNvmDtFQtAd5gMKedhLD"});
    Pager<PlaylistTrack> tracks = api.GetPlaylistTracks(me->GetId(), playlist->GetId());
    ASSERT_THAT(tracks.GetItems(), testing::ElementsAre(testing::Property(&PlaylistTrack::GetTrack, testing::Property(&std::shared_ptr<Track>::operator*, testing::Property(&Track::GetName, testing::StrEq("Mr. Brightside")))),
                                                        testing::Property(&PlaylistTrack::GetTrack, testing::Property(&std::shared_ptr<Track>::operator*, testing::Property(&Track::GetName, testing::StrEq("Somebody Told Me"))))
    ));

    // Remove one of the tracks and make sure it is no longer in the playlist
    api.RemoveTracksFromPlaylist(me->GetId(), playlist->GetId(), {"spotify:track:3n3Ppam7vgaVa1iaRUc9Lp"});
    tracks = api.GetPlaylistTracks(me->GetId(), playlist->GetId());
    ASSERT_THAT(tracks.GetItems(), testing::ElementsAre(testing::Property(&PlaylistTrack::GetTrack, testing::Property(&std::shared_ptr<Track>::operator*, testing::Property(&Track::GetName, testing::StrEq("Somebody Told Me"))))));

    // Unfollow the playlist
    api.UnfollowPlaylist(me->GetId(), playlist->GetId());
    myPlaylists = api.GetMyPlaylists();
    ASSERT_THAT(myPlaylists.GetItems(), testing::Not(testing::Contains(testing::Property(&PlaylistSimple::GetName, testing::StrEq("Test Playlist")))));
}