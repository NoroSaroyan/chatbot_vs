#ifndef USER_H
#define USER_H

#include "../../../Headers.h"
#include "../parent/Client.h"
// #include <boost/uuid/uuid.hpp>
// #include <boost/uuid/uuid_generators.hpp>
// #include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <ostream>
#include <utility>

class User : public Client {
public:
    User(const std::string &username, const std::string &password, const std::string &authority);

    User();

    std::string getUsername() const;

    std::string getPassword() const;

    std::string getAuthority() const;

    void setUsername(const std::string &username);

    void setPassword(const std::string &password);

    void setAuthority(std::string authority);

    bool operator<(const User &rhs) const;

    bool operator>(const User &rhs) const;

    bool operator<=(const User &rhs) const;

    bool operator>=(const User &rhs) const;

    friend std::istream &operator>>(std::istream &in, User &user);

    friend std::ostream &operator<<(std::ostream &os, const User &user);

    std::string toString() const override;

    // std::size_t hash() const override;

protected:
    std::string username;
    std::string password;
    std::string authority;
};

#endif // USER_H
