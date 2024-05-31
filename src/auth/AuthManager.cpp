
#include "AuthManager.h"

bool AuthManager::login(const std::string &username, const std::string &password, const std::string &authority) {
    std::lock_guard<std::mutex> lock(mtx);
    currentUser = std::make_shared<User>(username, password, authority);
    return true;
}

void AuthManager::logout() {
    std::lock_guard<std::mutex> lock(mtx);
    currentUser.reset();
}

std::shared_ptr<User> AuthManager::getCurrentUser() const {
    std::lock_guard<std::mutex> lock(mtx);
    return currentUser;
}
