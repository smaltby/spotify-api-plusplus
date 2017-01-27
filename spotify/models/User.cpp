#include "User.h"

User::User(nlohmann::json userJson) : UserPublic::UserPublic(userJson)
{
    birthdate = userJson["birthdate"];
    country = userJson["country"];
    email = userJson["email"];
    product = userJson["product"];
}

std::string User::GetBirthdate()
{
    return birthdate;
}

std::string User::GetCountry()
{
    return country;
}

std::string User::GetEmail()
{
    return email;
}

std::string User::GetProduct()
{
    return product;
}
