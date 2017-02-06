#include "User.h"

User::User(nlohmann::json userJson) : UserPublic::UserPublic(userJson)
{
    birthdate = userJson["birthdate"];
    country = userJson["country"];
    email = userJson["email"];
    product = userJson["product"];
}

std::string User::GetBirthdate() const
{
    return birthdate;
}

std::string User::GetCountry() const
{
    return country;
}

std::string User::GetEmail() const
{
    return email;
}

std::string User::GetProduct() const
{
    return product;
}
