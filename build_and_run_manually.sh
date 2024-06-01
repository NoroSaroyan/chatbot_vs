#!/bin/bash

g++ -std=c++17 -Wall -c src/main.cpp -o src/main.o

g++ -std=c++17 -Wall -c src/Menu/MenuItem.cpp -o src/Menu/MenuItem.o

g++ -std=c++17 -Wall -c src/Menu/Menu.cpp -o src/Menu/Menu.o

g++ -std=c++17 -Wall -c src/Entity/user/User.cpp -o src/Entity/user/User.o

g++ -std=c++17 -Wall -c src/helpers/encoder/Encoder.cpp -o src/helpers/encoder/Encoder.o

g++ -std=c++17 -Wall -c src/service/user/UserService.cpp -o src/service/user/UserService.o

g++ -std=c++17 -Wall -c src/helpers/utils/Utilities.cpp -o src/helpers/utils/Utilities.o

g++ -std=c++17 -Wall -c src/helpers/mappers/user/UserMapper.cpp -o src/helpers/mappers/user/UserMapper.o

g++ -std=c++17 -Wall -c src/Entity/qa/QA.cpp -o src/Entity/qa/QA.o

g++ -std=c++17 -Wall -c src/auth/AuthManager.cpp -o src/auth/AuthManager.o

g++ -std=c++17 -Wall -c src/helpers/mappers/qa/QAMapper.cpp -o src/helpers/mappers/qa/QAMapper.o

g++ -std=c++17 -Wall -c src/service/qa/QAService.cpp -o src/service/qa/QAService.o

g++ -std=c++17 -Wall -c src/service/history/HistoryService.cpp -o src/service/history/HistoryService.o

g++ -std=c++17 -Wall -c src/Entity/history/History.cpp -o src/Entity/history/History.o

g++ -std=c++17 -Wall -c src/helpers/mappers/history/HistoryMapper.cpp -o src/helpers/mappers/history/HistoryMapper.o

g++ -std=c++17 -Wall -o BMSTU_Chatbot_2sem src/main.o src/Menu/MenuItem.o src/Menu/Menu.o src/Entity/user/User.o src/helpers/encoder/Encoder.o src/service/user/UserService.o src/helpers/utils/Utilities.o src/helpers/mappers/user/UserMapper.o src/Entity/qa/QA.o src/auth/AuthManager.o src/helpers/mappers/qa/QAMapper.o src/service/qa/QAService.o src/service/history/HistoryService.o src/Entity/history/History.o src/helpers/mappers/history/HistoryMapper.o