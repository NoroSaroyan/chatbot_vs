#include "HistoryMapper.h"
#include <sstream>

std::string HistoryMapper::mapToString(History &history)
{
    std::ostringstream oss;
    oss << history.getUserId() << "&" << qaMapper.mapToString(history.getQA()) << "&";
    return oss.str();
}

History HistoryMapper::mapToObject(const std::string &line)
{
    std::istringstream iss(line);
    std::string userId, qaString;

    std::getline(iss, userId, '&');
    std::getline(iss, qaString, '&');

    QA qa = qaMapper.mapToObject(qaString);
    return History(userId, qa);
}
