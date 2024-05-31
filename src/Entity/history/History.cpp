#include "History.h"

History::History(const string &userId, const QA &qa, time_t timestamp) : userId(userId), qa(qa), timestamp(timestamp) {
    setUserId(userId);
    setQA(qa);
    setTimestamp(timestamp);
}

string History::getUserId() {
    return this->userId;
}

QA History::getQA() {
    return this->qa;
}

time_t History::getTimestamp() {
    return this->timestamp;
}

void History::setUserId(string userId) {
    this->userId = userId;
}

void History::setQA(QA qa) {
    this->qa = qa;
}

void History::setTimestamp(time_t timestamp) {
    this->timestamp = timestamp;
}
