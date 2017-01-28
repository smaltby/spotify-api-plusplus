#include <iostream>
#include <spotify/SpotifyAPI.h>
#include <spotify/models/Track.h>

int main()
{
    SpotifyAPI service = SpotifyAPI();
    std::shared_ptr<Album> album = service.GetAlbum("test");
    std::cout << album->GetTracks().GetItems()[0].GetName() << std::endl;

    return 0;
}
