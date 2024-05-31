#ifndef BMSTU_CHATBOT_2SEM_QAMAPPER_H
#define BMSTU_CHATBOT_2SEM_QAMAPPER_H

#include "../../../Entity/qa/QA.h"

#include <string>

class QAMapper {

public:
    QA mapToObject(const string &line);
    string mapToString(QA qa);
};


#endif //BMSTU_CHATBOT_2SEM_QAMAPPER_H
