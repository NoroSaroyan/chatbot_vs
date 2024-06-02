#ifndef BMSTU_CHATBOT_2SEM_HISTORYSERVICE_H
#define BMSTU_CHATBOT_2SEM_HISTORYSERVICE_H

#include "../BaseService.h"
#include "../qa/QAService.h"
#include "../user/UserService.h"
#include "../../helpers/mappers/history/HistoryMapper.h"
#include <fstream>
#include <ctime>
#include <string>

class HistoryService : public BaseService
{
private:
    HistoryMapper historyMapper;

public:
    HistoryService() : BaseService("static/Database/history/")
    {
    }

    string createRecord(const std::string &username, const QA &qa);

    void postRecord(const string &username, const string &record);

    MyGenericVector<QA> getHistory(string &username);
};

#endif // BMSTU_CHATBOT_2SEM_HISTORYSERVICE_H
