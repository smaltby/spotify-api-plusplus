#include <SpotifyAPI.h>
#include <gtest/gtest.h>
#include <fstream>
#include <gmock/gmock.h>

class AClass {
public:
    AClass() : n_(0) {}

    // A getter that returns a non-reference.
    int n() const { return n_; }

    void set_n(int new_n) { n_ = new_n; }

    // A getter that returns a reference to const.
    const std::string& s() const { return s_; }

    void set_s(const std::string& new_s) { s_ = new_s; }

    // A getter that returns a reference to non-const.
    double& x() const { return x_; }
private:
    int n_;
    std::string s_;

    static double x_;
};

double AClass::x_ = 0.0;

SpotifyAPI GetAPI()
{
    SpotifyAPI api = SpotifyAPI();

    std::ifstream t("../auth_token.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();

    api.setAuthToken(buffer.str());

    return api;
}

TEST(TestEndpoints, GetAlbumTest)
{
    SpotifyAPI api = GetAPI();

    std::shared_ptr<Artist> artist = api.GetArtist("0OdUWJ0sBjDrqHygGUXeCF");
    ASSERT_STREQ(artist->GetName().c_str(), "Band of Horses");
}

TEST(TestEndpoints, MyFollowedTest)
{
    SpotifyAPI api = GetAPI();

    // Follow Band of Horses and check to make sure that MyFollowedArtists contains it
    api.FollowArtist("0OdUWJ0sBjDrqHygGUXeCF");
    std::vector<Artist> followed = api.GetMyFollowedArtists().GetItems();
    ASSERT_THAT(followed, testing::Contains(testing::Property(&Artist::GetName, testing::StrEq("Band of Horses"))));

    // Unfollow Band of Horses and check to make sure that MyFollowedArtists no longer contains it
    api.UnfollowArtist("0OdUWJ0sBjDrqHygGUXeCF");
    followed = api.GetMyFollowedArtists().GetItems();
    ASSERT_THAT(followed, testing::Not(testing::Contains(testing::Property(&Artist::GetName, testing::StrEq("Band of Horses")))));
}