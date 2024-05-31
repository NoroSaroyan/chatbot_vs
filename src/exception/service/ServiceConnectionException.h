#ifndef SERVICECONNECTIONEXCEPTION_H
#define SERVICECONNECTIONEXCEPTION_H

#include <stdexcept>
#include <string>

class ServiceConnectionException : public std::runtime_error {
public:
    explicit ServiceConnectionException(const std::string &message)
        : std::runtime_error("Service unavailable: " + message) {
    }
};

#endif // SERVICECONNECTIONEXCEPTION_H
