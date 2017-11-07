#ifndef SPOTIFY_API_PLUSPLUS_SPOTIFYEXCEPTION_H
#define SPOTIFY_API_PLUSPLUS_SPOTIFYEXCEPTION_H

#include <exception>
#include <sstream>
#include "../models/Error.h"

class SpotifyException : public std::exception
{
public:
    SpotifyException(Error error) : error(error)
    {}

    virtual const char* what() const throw()
    {
        char* what = (char *) calloc(error.GetMessage().length(), sizeof(char));
        strcpy(what, error.GetMessage().c_str());
        return what;
    }

private:
    Error error;
};

#endif
