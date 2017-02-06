#include "Category.h"

Category::Category(nlohmann::json categoryJson)
{
    href = categoryJson["href"];
    for(nlohmann::json json : categoryJson["icons"])
        icons.push_back(std::shared_ptr<Image>(new Image(json)));
    id = categoryJson["id"];
    name = categoryJson["name"];
}

std::string Category::GetHref() const
{
    return href;
}

std::vector<std::shared_ptr<Image>> Category::GetIcons() const
{
    return icons;
}

std::string Category::GetId() const
{
    return id;
}

std::string Category::GetName() const
{
    return name;
}
