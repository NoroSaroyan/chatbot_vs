#include "History.h"

History::History(const string &userId, const QA &qa) : userId(userId), qa(qa)
{
    setUserId(userId);
    setQA(qa);
}

string History::getUserId()
{
    return this->userId;
}

QA History::getQA()
{
    return this->qa;
}

void History::setUserId(string userId)
{
    this->userId = userId;
}

void History::setQA(QA qa)
{
    this->qa = qa;
}