#ifndef SPOTIFY_PLUSPLUS_PAGER_H
#define SPOTIFY_PLUSPLUS_PAGER_H

#include <string>
#include <vector>
#include "utils/json.h"

template <class T> class Pager
{
public:
    Pager<T>();
    Pager<T>(nlohmann::json pagerJson);

    std::string GetHref();
    std::vector<T> GetItems();
    int GetLimit();
    std::string GetNext();
    int GetOffset();
    std::string GetPrevious();
    int GetTotal();

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
    href = pagerJson["href"];
    for(nlohmann::json json : pagerJson["items"])
        items.push_back(T(json));
    limit = pagerJson["limit"];
    if (!pagerJson["next"].is_null())
        next = pagerJson["next"];
    offset = pagerJson["offset"];
    if (!pagerJson["previous"].is_null())
        previous = pagerJson["previous"];
    total = pagerJson["total"];
}

template <typename T> std::string Pager<T>::GetHref()
{
    return href;
}

template <typename T> std::vector<T> Pager<T>::GetItems()
{
    return items;
}

template <typename T> int Pager<T>::GetLimit()
{
    return limit;
}

template <typename T> std::string Pager<T>::GetNext()
{
    return next;
}

template <typename T> int Pager<T>::GetOffset()
{
    return offset;
}

template <typename T> std::string Pager<T>::GetPrevious()
{
    return previous;
}

template <typename T> int Pager<T>::GetTotal()
{
    return total;
}


#endif
