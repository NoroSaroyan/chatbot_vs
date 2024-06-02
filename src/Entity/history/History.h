

#ifndef BMSTU_CHATBOT_2SEM_HISTORY_H
#define BMSTU_CHATBOT_2SEM_HISTORY_H

#include "string"
#include "../../../Headers.h"
#include "../qa/QA.h"

class History
{
private:
    string userId;
    QA qa;

public:
    History(const string &userId, const QA &qa);

    string getUserId();

    QA getQA();

    void setUserId(string userId);

    void setQA(QA qa);
};

#endif // BMSTU_CHATBOT_2SEM_HISTORY_H
