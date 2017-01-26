#include "Error.h"

Error::Error(nlohmann::json pagerJson)
{
    status = pagerJson["status"];
    message = pagerJson["message"];
}

int Error::GetStatus()
{
    return status;
}

std::string Error::GetMessage()
{
    return message;
}
