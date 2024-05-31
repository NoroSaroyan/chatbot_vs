

#ifndef BMSTU_CHATBOT_2SEM_USERMAPPER_H
#define BMSTU_CHATBOT_2SEM_USERMAPPER_H

#include "../../../Entity/user/User.h"

class UserMapper{
public:
    string mapToString(User user);
    User mapToObject(string line);
};

#endif //BMSTU_CHATBOT_2SEM_USERMAPPER_H
