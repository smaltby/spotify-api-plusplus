#include "SavedAlbum.h"

SavedAlbum::SavedAlbum(nlohmann::json albumJson)
{
    addedAt = albumJson["added_at"];
    album = std::shared_ptr<Album>(new Album(albumJson["album"]));
}

std::string SavedAlbum::GetAddedAt()
{
    return addedAt;
}

std::shared_ptr<Album> SavedAlbum::GetAlbum()
{
    return album;
}


