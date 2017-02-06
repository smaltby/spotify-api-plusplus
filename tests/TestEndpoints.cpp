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

TEST_F(TestEndpoints, MyFollowedTest)
{
    // Follow Band of Horses and check to make sure that MyFollowedArtists contains it
    api.FollowArtist("0OdUWJ0sBjDrqHygGUXeCF");
    std::vector<Artist> followed = api.GetMyFollowedArtists().GetItems();
    ASSERT_THAT(followed, testing::Contains(testing::Property(&Artist::GetName, testing::StrEq("Band of Horses"))));

    // Unfollow Band of Horses and check to make sure that MyFollowedArtists no longer contains it
    api.UnfollowArtist("0OdUWJ0sBjDrqHygGUXeCF");
    followed = api.GetMyFollowedArtists().GetItems();
    ASSERT_THAT(followed, testing::Not(testing::Contains(testing::Property(&Artist::GetName, testing::StrEq("Band of Horses")))));
}