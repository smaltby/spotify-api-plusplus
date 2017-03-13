#ifndef SPOTIFY_API_PLUSPLUS_CURLEXCEPTION_H
#define SPOTIFY_API_PLUSPLUS_CURLEXCEPTION_H

#include <exception>
#include <sstream>

class CurlException : public std::exception
{
public:
    CurlException(int errorCode) : errorCode(errorCode)
    {}

    virtual const char* what() const throw()
    {
        std::stringstream errorStream;
        errorStream << "cURL error: " << errorCode;
        std::string message = errorStream.str();

        char* what = (char *) calloc(message.length(), sizeof(char));
        strcpy(what, message.c_str());
        return what;
    }

private:
    int errorCode;
};
#endif
