using namespace std;
#include "random"
#include "Utilities.h"
#include "ctime"
#include "cstdlib"
#include "string"

bool Utilities::checkEmail(const std::string &email)
{
    return regex_match(email, regex(this->getEmailRegex()));
}

bool Utilities::checkPassword(const std::string &password)
{
    return regex_match(password, regex(this->getPasswordRegex()));
}

const string Utilities::getEmailRegex() const
{
    return emailRegex;
}

const string Utilities::getPasswordRegex() const
{
    return passwordRegex;
}
const string Utilities::generateNumericID() const
{
    std::string id;

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < 8; ++i)
    {
        id += std::to_string(std::rand() % 10); // Generates a random digit between 0 and 9
    }

    return id;
}