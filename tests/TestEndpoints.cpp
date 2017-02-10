#include <SpotifyAPI.h>
#include <gtest/gtest.h>
#include <fstream>
#include <gmock/gmock.h>

SpotifyAPI GetAPI()
{
    SpotifyAPI api = SpotifyAPI();

    std::ifstream t("../auth_token.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();

    api.setAuthToken(buffer.str());

    return api;
}

class TestEndpoints : public ::testing::Test
{
protected:
    SpotifyAPI api;
    virtual void SetUp()
    {
        api = SpotifyAPI();

        std::ifstream t("../auth_token.txt");
        std::stringstream buffer;
        buffer << t.rdbuf();

        api.setAuthToken(buffer.str());

        t.close();
    }
};

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
    //ASSERT_EQ(playlists.GetTotal(), 20);
}

TEST_F(TestEndpoints, GetNewReleasesTest)
{
    Pager<AlbumSimple> albums = api.GetNewReleases();
    //ASSERT_EQ(albums.GetTotal(), 20);
}

TEST_F(TestEndpoints, GetCategoriesTest)
{
    Pager<Category> categories = api.GetCategories();
    //ASSERT_EQ(categories.GetTotal(), 20);
}

TEST_F(TestEndpoints, GetCategoryTest)
{
    std::shared_ptr<Category> category = api.GetCategory("party");
    ASSERT_STREQ(category->GetName().c_str(), "Party");
}

TEST_F(TestEndpoints, GetCategoryPlaylistsTest)
{
    Pager<PlaylistSimple> playlists = api.GetCategoryPlaylists("party");
    //ASSERT_EQ(playlists.GetTotal(), 20);
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