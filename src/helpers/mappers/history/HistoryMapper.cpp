#include "HistoryMapper.h"
#include <sstream>

std::string HistoryMapper::mapToString(History &history) {
    std::ostringstream oss;
    oss << history.getUserId() << "&" << qaMapper.mapToString(history.getQA()) << "&" << history.getTimestamp();
    return oss.str();
}

History HistoryMapper::mapToObject(const std::string &line) {
    std::istringstream iss(line);
    std::string userId, qaString;
    std::time_t timestamp;

    std::getline(iss, userId, '&');
    std::getline(iss, qaString, '&');
    iss >> timestamp;

    QA qa = qaMapper.mapToObject(qaString);
    return History(userId, qa, timestamp);
}
