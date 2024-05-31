//
// Created by Norik Saroyan on 17.03.24.
//

#ifndef BMSTU_CHATBOT_2SEM_UTILITIES_H
#define BMSTU_CHATBOT_2SEM_UTILITIES_H

#include "../../../Headers.h"
#include "regex"

class Utilities {
private:
    const string emailRegex = "^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$";
    const string passwordRegex = "^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[^a-zA-Z\\d]).{8,}$";

public:
    bool checkEmail(const string &email);
    bool checkPassword(const string &password);

    const string getEmailRegex() const;

    const string getPasswordRegex() const;

    const string generateNumericID() const;

};

#endif //BMSTU_CHATBOT_2SEM_UTILITIES_H