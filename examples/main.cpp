#include <iostream>
#include <spotify/SpotifyAPI.h>
#include <fstream>

int main()
{
    std::ifstream file;
    file.open("../../auth_token.txt");
    std::stringstream stream;
    stream << file.rdbuf();

    std::string authToken = stream.str();

    SpotifyAPI service = SpotifyAPI();
    service.setAuthToken(authToken);

    std::shared_ptr<Artist> artist = service.GetArtist("0OdUWJ0sBjDrqHygGUXeCF");
    auto tracks = service.GetArtistTopTracks(artist->GetId(), "US");
    for (auto track : tracks)
    {
        std::cout << track->GetName() << std::endl;
    }

    std::shared_ptr<User> me = service.GetMe();
    std::cout << me->GetBirthdate() << std::endl;
    return 0;
}
