

#ifndef BMSTU_CHATBOT_2SEM_HISTORY_H
#define BMSTU_CHATBOT_2SEM_HISTORY_H

#include "string"
#include "../../../Headers.h"
#include "../qa/QA.h"

class History {
private:
    string userId;
    QA qa;
    time_t timestamp;
public:
    History(const string &userId, const QA &qa, time_t timestamp);

    string getUserId();

    QA getQA();

    time_t getTimestamp();

    void setUserId(string userId);

    void setQA(QA qa);

    void setTimestamp(time_t timestamp);
};


#endif //BMSTU_CHATBOT_2SEM_HISTORY_H
