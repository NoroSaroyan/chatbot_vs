#include "QAMapper.h"
#include <sstream>
#include <vector>
#include <iostream>

std::string QAMapper::mapToString(QA qa) {
    return qa.getId() + "&" + qa.getQuestion() + "&" + qa.getAnswer();
}

QA QAMapper::mapToObject(const std::string& line) {
    std::vector<std::string> values;
    std::string data;
    std::istringstream stream(line);

    while (std::getline(stream, data, '&')) {
        values.push_back(data);
    }

    QA temp("", "");
    if (values.size() == 3) {
        temp.setId(values[0]);
        temp.setQuestion(values[1]);
        temp.setAnswer(values[2]);
    } else {
        std::cerr << "Line format is incorrect: " << line << std::endl;
    }

    return temp;
}
