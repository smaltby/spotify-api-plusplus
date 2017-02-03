#ifndef SPOTIFY_PLUSPLUS_CURSORPAGER_H
#define SPOTIFY_PLUSPLUS_CURSORPAGER_H

#include <string>
#include <vector>
#include "Cursor.h"
#include "utils/json.h"


template <class T> class CursorPager
{
public:
    CursorPager<T>();
    CursorPager<T>(nlohmann::json pagerJson);

    std::string GetHref();
    std::vector<T> GetItems();
    int GetLimit();
    std::string GetNext();
    std::shared_ptr<Cursor> GetCursors();
    int GetTotal();

private:
    std::string href;
    std::vector<T> items;
    int limit;
    std::string next;
    std::shared_ptr<Cursor> cursors;
    int total;
};

template <typename T> CursorPager<T>::CursorPager() = default;

template <typename T> CursorPager<T>::CursorPager(nlohmann::json pagerJson)
{
    href = pagerJson["href"];
    for(nlohmann::json json : pagerJson["items"])
        items.push_back(T(json));
    limit = pagerJson["limit"];
    next = pagerJson["next"];
    cursors = std::shared_ptr<Cursor>(new Cursor(pagerJson["cursors"]));
    total = pagerJson["total"];
}

template <typename T> std::string CursorPager<T>::GetHref()
{
    return href;
}

template <typename T> std::vector<T> CursorPager<T>::GetItems()
{
    return items;
}

template <typename T> int CursorPager<T>::GetLimit()
{
    return limit;
}

template <typename T> std::string CursorPager<T>::GetNext()
{
    return next;
}

template <typename T> std::shared_ptr<Cursor> CursorPager<T>::GetCursors()
{
    return cursors;
}

template <typename T> int CursorPager<T>::GetTotal()
{
    return total;
}


#endif
