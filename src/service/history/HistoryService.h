#ifndef BMSTU_CHATBOT_2SEM_HISTORYSERVICE_H
#define BMSTU_CHATBOT_2SEM_HISTORYSERVICE_H

#include "../BaseService.h"
#include "../qa/QAService.h"
#include "../user/UserService.h"
#include "../../helpers/mappers/history/HistoryMapper.h"
#include <fstream>
#include <ctime>
#include <string>

class HistoryService : public BaseService {
private:
    HistoryMapper historyMapper;

public:
    HistoryService() : BaseService("/Users/noriksaroyan/CLionProjects/BMSTU-Chatbot-2sem/static/Database/history") {
    }

    std::string createRecord(const std::string &userId, const QA &qa, time_t time);

    void postRecord(const std::string &userId, const std::string &record);
};

#endif // BMSTU_CHATBOT_2SEM_HISTORYSERVICE_H
