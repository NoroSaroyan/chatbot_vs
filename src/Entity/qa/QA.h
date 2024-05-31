//
// Created by Norik Saroyan on 14.05.24.
//

#ifndef BMSTU_CHATBOT_2SEM_QA_H
#define BMSTU_CHATBOT_2SEM_QA_H

#include "../../../Headers.h"
// #include <boost/uuid/uuid.hpp>
// #include <boost/uuid/uuid_generators.hpp>
// #include <boost/uuid/uuid_io.hpp>
#include <ostream>

class QA {
protected:
    string id;
    string question;
    string answer;

public:
    QA(const string &question, const string &answer);

    QA() : id(""), question(""), answer("") {
    }

    void setId(string id) {
        this->id = id;
    }

    void setQuestion(string question) {
        this->question = question;
    }

    void setAnswer(string answer) {
        this->answer = answer;
    }

    string getId() {
        return this->id;
    }

    string getQuestion() {
        return this->question;
    }

    string getAnswer() {
        return this->answer;
    }

    friend istream &operator>>(istream &in, const QA &qa);

    friend ostream &operator<<(ostream &os, const QA &qa);

    bool operator<(const QA &rhs) const;

    bool operator>(const QA &rhs) const;

    bool operator<=(const QA &rhs) const;

    bool operator>=(const QA &rhs) const;
};

#endif //BMSTU_CHATBOT_2SEM_QA_H
