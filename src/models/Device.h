#ifndef SPOTIFY_API_PLUSPLUS_DEVICE_H
#define SPOTIFY_API_PLUSPLUS_DEVICE_H

#include "../utils/json.h"

class Device
{
public:
    Device(nlohmann::json deviceJson);

    std::string GetId() const;
    bool IsActive() const;
    bool IsRestricted() const;
    std::string GetName() const;
    std::string GetType() const;
    int GetVolumePercent() const;

private:
    std::string id;
    bool isActive;
    bool isRestricted;
    std::string name;
    std::string type;
    int volumePercent;
};


#endif
