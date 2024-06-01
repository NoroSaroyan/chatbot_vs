cmake_minimum_required(VERSION 3.26)
project(BMSTU_Chatbot_2sem)
set(CMAKE_CXX_STANDARD 17)

# set(Boost_ROOT "/usr/local/Cellar/boost")

# find_package(Boost 1.70.0 REQUIRED COMPONENTS system filesystem)

# Include Boost directories
# include_directories(${Boost_INCLUDE_DIRS})

add_executable(BMSTU_Chatbot_2sem
        src/main.cpp
        src/Menu/Menu.h
        src/Menu/MenuItem.h
        src/Menu/MenuItem.cpp
        src/Menu/Menu.cpp
        src/Entity/user/User.h
        src/Entity/user/User.cpp
        src/helpers/encoder/Encoder.cpp
        src/service/user/UserService.cpp
        src/service/user/UserService.h
        src/helpers/utils/Utilities.cpp
        src/helpers/mappers/user/UserMapper.cpp
        src/helpers/utils/Utilities.h
        src/helpers/mappers/user/UserMapper.h
        src/Entity/qa/QA.cpp
        src/Entity/qa/QA.h
        src/auth/AuthManager.cpp
        src/auth/AuthManager.h
        src/helpers/mappers/qa/QAMapper.cpp
        src/helpers/mappers/qa/QAMapper.h
        src/service/qa/QAService.cpp
        src/service/qa/QAService.h
        src/service/history/HistoryService.cpp
        src/service/history/HistoryService.h
        src/Entity/history/History.cpp
        src/Entity/history/History.h
        src/helpers/mappers/history/HistoryMapper.cpp
        src/helpers/mappers/history/HistoryMapper.h
        src/customized/MyGenericVector.h
        src/Entity/parent/Client.h
        src/service/BaseService.h
        src/exception/service/ServiceConnectionException.h
        src/exception/service/ServiceDataException.h
        src/exception/service/QANotFoundException.h
)

# target_link_libraries(BMSTU_Chatbot_2sem ${Boost_LIBRARIES})
