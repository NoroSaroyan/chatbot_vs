
#include "HistoryService.h"

std::string HistoryService::createRecord(const std::string &userId, const QA &qa, time_t time) {
    History temp(userId, qa, time);
    auto result = historyMapper.mapToString(temp);
    postRecord(userId, result);
    return result;
}

void HistoryService::postRecord(const std::string &userId, const std::string &record) {
    std::ofstream out(path + userId);
    if (!out.is_open()) {
        std::cerr << "Database error" << std::endl;
    }
    out << record << std::endl;
}
