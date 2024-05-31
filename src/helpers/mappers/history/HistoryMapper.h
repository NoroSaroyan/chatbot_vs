//
// Created by Norik Saroyan on 15.05.24.
//

#ifndef BMSTU_CHATBOT_2SEM_HISTORYMAPPER_H
#define BMSTU_CHATBOT_2SEM_HISTORYMAPPER_H

#include "../../../Entity/history/History.h"
#include "../qa/QAMapper.h"

class HistoryMapper {
public:

    QAMapper qaMapper;

    string mapToString(History &history);

    History mapToObject(const string &line);
};


#endif //BMSTU_CHATBOT_2SEM_HISTORYMAPPER_H
