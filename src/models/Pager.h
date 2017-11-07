#ifndef SPOTIFY_PLUSPLUS_PAGER_H
#define SPOTIFY_PLUSPLUS_PAGER_H

#include <string>
#include <vector>
#include "../utils/json.h"

template <class T> class Pager
{
public:
    Pager<T>();
    Pager<T>(nlohmann::json pagerJson);

    std::string GetHref() const;
    std::vector<T> GetItems() const;
    int GetLimit() const;
    std::string GetNext() const;
    int GetOffset() const;
    std::string GetPrevious() const;
    int GetTotal() const;

private:
    std::string href;
    std::vector<T> items;
    int limit;
    std::string next;
    int offset;
    std::string previous;
    int total;
};

template <typename T> Pager<T>::Pager() = default;

template <typename T> Pager<T>::Pager(nlohmann::json pagerJson)
{
    if (!pagerJson["href"].is_null())
        href = pagerJson["href"];
    for(nlohmann::json json : pagerJson["items"])
        items.push_back(T(json));
    if(!pagerJson["limit"].is_null())
        limit = pagerJson["limit"];
    if (!pagerJson["next"].is_null())
        next = pagerJson["next"];
    if (!pagerJson["offset"].is_null())
        offset = pagerJson["offset"];
    if (!pagerJson["previous"].is_null())
        previous = pagerJson["previous"];
    total = pagerJson["total"];
}

template <typename T> std::string Pager<T>::GetHref() const
{
    return href;
}

template <typename T> std::vector<T> Pager<T>::GetItems() const
{
    return items;
}

template <typename T> int Pager<T>::GetLimit() const
{
    return limit;
}

template <typename T> std::string Pager<T>::GetNext() const
{
    return next;
}

template <typename T> int Pager<T>::GetOffset() const
{
    return offset;
}

template <typename T> std::string Pager<T>::GetPrevious() const
{
    return previous;
}

template <typename T> int Pager<T>::GetTotal() const
{
    return total;
}


#endif
