#ifndef CLIENT_H
#define CLIENT_H

#include <string>
// #include <boost/uuid/uuid.hpp>
// #include <boost/uuid/u0uid_generators.hpp>
// #include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <sstream>

class Client
{
public:
    Client()
    {
        // boost::uuids::random_generator generator;
        // boost::uuids::uuid uuid = generator();
        // this->id = boost::uuids::to_string(uuid);
        this->id = rand() % 100 + 1;
    }

    explicit Client(const std::string &id) : id(id) {}

    virtual ~Client() = default;

    std::string getId() const
    {
        return id;
    }

    void setId(const std::string &id)
    {
        this->id = id;
    }

    virtual std::string toString() const
    {
        return "Client ID: " + id;
    }

    // virtual std::size_t hash() const {
    //     return std::hash<std::string>{}(id);
    // }

protected:
    std::string id;
};

#endif // CLIENT_H
