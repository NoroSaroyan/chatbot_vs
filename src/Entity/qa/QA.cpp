
#include "QA.h"

QA::QA(const string &question, const string &answer)
{

    this->setId(to_string(rand() % 100 + 1));
    this->setQuestion(question);
    this->setAnswer(answer);
}

bool QA::operator<(const QA &rhs) const
{
    if (id < rhs.id)
        return true;
    if (rhs.id < id)
        return false;
    if (question < rhs.question)
        return true;
    if (rhs.question < question)
        return false;
    return answer < rhs.answer;
}

bool QA::operator>(const QA &rhs) const
{
    return rhs < *this;
}

bool QA::operator<=(const QA &rhs) const
{
    return !(rhs < *this);
}

bool QA::operator>=(const QA &rhs) const
{
    return !(*this < rhs);
}

ostream &operator<<(ostream &os, const QA &qa)
{
    os << "id: " << qa.id << " question: " << qa.question << " answer: " << qa.answer;
    return os;
}

istream &operator>>(istream &in, QA &qa)
{
    string question, answer;
    in >> question;
    in >> answer;
    QA result(question, answer);
    return in;
}