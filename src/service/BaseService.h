#ifndef BASESERVICE_H
#define BASESERVICE_H

#include <string>
#include <fstream>
#include <iostream>
#include "string"
using namespace std;

class BaseService {
protected:
    string path;

    explicit BaseService(const string &filePath) : path(filePath) {
    }

    ifstream openInputFile() const {
        std::ifstream inFile(this->path);
        if (!inFile) {
            std::cerr << "Unable to open file for reading: " << path << std::endl;
        }
        return inFile;
    }

    ofstream openOutputFile(std::ios_base::openmode mode = std::ios_base::app) const {
        std::ofstream outFile(this->path, mode);
        if (!outFile) {
            std::cerr << "Unable to open file for writing: " << path << std::endl;
        }
        return outFile;
    }
};

#endif // BASESERVICE_H
