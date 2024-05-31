#ifndef BMSTU_CHATBOT_2SEM_QASERVICE_H
#define BMSTU_CHATBOT_2SEM_QASERVICE_H

#include "../BaseService.h"
#include "../../helpers/mappers/qa/QAMapper.h"
#include "../../Entity/qa/QA.h"
#include <fstream>
#include <optional>
#include <vector>
#include "../../customized/MyGenericVector.h"

class QAService : public BaseService {
private:
    QAMapper mapper;

public:
    QAService() : BaseService("/Users/noriksaroyan/CLionProjects/BMSTU-Chatbot-2sem/static/Database/QA.txt") {
    }

    MyGenericVector<QA> getAll();

    QA getById(const std::string &id);
};

#endif // BMSTU_CHATBOT_2SEM_QASERVICE_H
