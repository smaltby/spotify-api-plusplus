#include <iostream>
#include <spotify/SpotifyService.h>
#include <spotify/models/Track.h>

int main()
{
    SpotifyService service = SpotifyService();
    std::shared_ptr<Album> album = service.GetAlbum("test");
    std::cout << album->GetTracks().GetItems()[0].GetName() << std::endl;

    return 0;
}
