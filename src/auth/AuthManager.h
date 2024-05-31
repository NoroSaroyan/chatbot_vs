
#ifndef BMSTU_CHATBOT_2SEM_AUTHMANAGER_H
#define BMSTU_CHATBOT_2SEM_AUTHMANAGER_H


#ifndef AUTH_MANAGER_H
#define AUTH_MANAGER_H

#include "../Entity/user/User.h"
#include <memory>
#include <mutex>

class AuthManager {
public:
    static AuthManager& getInstance() {
        static AuthManager instance;
        return instance;
    }

    AuthManager(const AuthManager&) = delete;
    AuthManager& operator=(const AuthManager&) = delete;

    bool login(const std::string &username, const std::string &password, const std::string &authority);
    void logout();
    std::shared_ptr<User> getCurrentUser() const;

private:
    AuthManager() = default;
    ~AuthManager() = default;

    mutable std::mutex mtx;
    std::shared_ptr<User> currentUser;
};

#endif // AUTH_MANAGER_H


#endif //BMSTU_CHATBOT_2SEM_AUTHMANAGER_H
