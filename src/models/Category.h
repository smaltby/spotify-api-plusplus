#ifndef SPOTIFY_PLUSPLUS_CATEGORY_H
#define SPOTIFY_PLUSPLUS_CATEGORY_H

#include <string>
#include <memory>
#include <vector>
#include "Image.h"
#include "utils/json.h"

class Category
{
public:
    Category(nlohmann::json copyrightJson);
    
    std::string GetHref();
    std::vector<std::shared_ptr<Image>> GetIcons();
    std::string GetId();
    std::string GetName();

private:
    std::string href;
    std::vector<std::shared_ptr<Image>> icons;
    std::string id;
    std::string name;
};


#endif
