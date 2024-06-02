
#include "HistoryService.h"

std::string HistoryService::createRecord(const std::string &username, const QA &qa)
{
    History temp(username, qa);
    auto result = historyMapper.mapToString(temp);
    return result;
}

void HistoryService::postRecord(const std::string &username, const std::string &record)
{
    std::ofstream out(path + username, std::ios::app);
    if (!out.is_open())
    {
        std::cerr << "Database error" << std::endl;
        return;
    }
    out << record << std::endl;
    out.close(); // Add this line to close the file after writing
}

MyGenericVector<QA> HistoryService::getHistory(string &username)
{
    std::ifstream in(path + username);
    if (!in.is_open())
    {
        std::cerr << "Database error" << std::endl;
        return MyGenericVector<QA>();
    }

    MyGenericVector<QA> history;
    std::string line;
    while (std::getline(in, line))
    {
        QA qa = historyMapper.mapToObject(line).getQA();
        history.push_back(qa);
    }

    in.close();
    return history;
}
