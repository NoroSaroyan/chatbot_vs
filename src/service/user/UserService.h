#ifndef BMSTU_CHATBOT_2SEM_USERSERVICE_H
#define BMSTU_CHATBOT_2SEM_USERSERVICE_H

#include "../../Entity/user/User.h"
#include "../../helpers/utils/Utilities.h"
#include "../../helpers/mappers/user/UserMapper.h"
#include "../../auth/AuthManager.h"
#include "../BaseService.h"
#include <fstream>
#include <iostream>
#include <optional>

class UserService : public BaseService {
private:
    Utilities utils;
    UserMapper mapper;

public:
    UserService();

    void registerAccount(const std::string &username, const std::string &password);

    User login(const std::string &username, const std::string &password);
};

#endif // BMSTU_CHATBOT_2SEM_USERSERVICE_H
