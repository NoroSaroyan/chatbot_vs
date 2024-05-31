#include "QAService.h"
#include "../../exception/service/QANotFoundException.h"
#include "../../customized/MyGenericVector.h"

MyGenericVector<QA> QAService::getAll()
{
    MyGenericVector<QA> readQuestions;
    std::ifstream inFile = openInputFile();
    if (!inFile)
    {
        return MyGenericVector<QA>();
    }
    std::string line;
    while (std::getline(inFile, line))
    {
        QA qa = mapper.mapToObject(line);
        readQuestions.push_back(qa);
    }

    inFile.close();
    return readQuestions;
}

QA QAService::getById(const std::string &id)
{
    std::ifstream inFile = openInputFile();
    if (inFile)
    {
        std::string line;
        while (std::getline(inFile, line))
        {
            QA qa = mapper.mapToObject(line);
            if (qa.getId() == id)
            {
                return qa;
            }
        }
    }

    throw QANotFoundException(id);
}
