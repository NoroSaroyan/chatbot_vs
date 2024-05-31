#include "User.h"
#include <utility>
#include <sstream>

std::string User::getUsername() const
{
    return this->username;
}

std::string User::getPassword() const
{
    return this->password;
}

std::string User::getAuthority() const
{
    return this->authority;
}

void User::setUsername(const std::string &username)
{
    this->username = username;
}

void User::setPassword(const std::string &password)
{
    this->password = password;
}

void User::setAuthority(std::string authority)
{
    this->authority = std::move(authority);
}

User::User(const std::string &username, const std::string &password, const std::string &authority)
    : Client(), username(username), password(password), authority(authority)
{
}

User::User() : Client()
{
}

std::ostream &operator<<(std::ostream &os, const User &user)
{
    os << "username: " << user.username << " password: " << user.password << " authority: " << user.authority << " id: "
       << user.getId();
    return os;
}

std::istream &operator>>(std::istream &in, User &user)
{
    std::string name, password, authority;
    in >> name >> password >> authority;
    user.setUsername(name);
    user.setPassword(password);
    user.setAuthority(authority);
    return in;
}

// Comparison operators
bool User::operator<(const User &rhs) const
{
    if (username < rhs.username)
        return true;
    if (rhs.username < username)
        return false;
    if (password < rhs.password)
        return true;
    if (rhs.password < password)
        return false;
    if (authority < rhs.authority)
        return true;
    if (rhs.authority < authority)
        return false;
    return getId() < rhs.getId();
}

bool User::operator>(const User &rhs) const
{
    return rhs < *this;
}

bool User::operator<=(const User &rhs) const
{
    return !(rhs < *this);
}

bool User::operator>=(const User &rhs) const
{
    return !(*this < rhs);
}

std::string User::toString() const
{
    std::stringstream ss;
    ss << "username: " << username << " password: " << password << " authority: " << authority << " id: "
       << getId();
    return ss.str();
}

// std::size_t User::hash() const {
//     return std::hash<std::string>{}(toString());
// }
