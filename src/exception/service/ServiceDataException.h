#ifndef SERVICEDATAEXCEPTION_H
#define SERVICEDATAEXCEPTION_H

#include <stdexcept>
#include <string>

class ServiceDataException : public std::runtime_error {
public:
    explicit ServiceDataException(const std::string& message)
        : std::runtime_error("Failed to retrieve data from service: " + message) {}
};

#endif // SERVICEDATAEXCEPTION_H
