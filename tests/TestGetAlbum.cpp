#include <SpotifyAPI.h>
#include <gtest/gtest.h>

TEST(TestGetAlbum, test1)
{
    SpotifyAPI spotify = SpotifyAPI();
    std::shared_ptr<Artist> artist = spotify.GetArtist("0OdUWJ0sBjDrqHygGUXeCF");
    ASSERT_STREQ(artist->GetName().c_str(), "Band of Horses");
}