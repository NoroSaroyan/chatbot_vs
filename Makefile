# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall


# Project name and sources
TARGET = BMSTU_Chatbot_2sem
SRCS = src/main.cpp \
       src/Menu/MenuItem.cpp \
       src/Menu/Menu.cpp \
       src/Entity/user/User.cpp \
       src/helpers/encoder/Encoder.cpp \
       src/service/user/UserService.cpp \
       src/helpers/utils/Utilities.cpp \
       src/helpers/mappers/user/UserMapper.cpp \
       src/Entity/qa/QA.cpp \
       src/auth/AuthManager.cpp \
       src/helpers/mappers/qa/QAMapper.cpp \
       src/service/qa/QAService.cpp \
       src/service/history/HistoryService.cpp \
       src/Entity/history/History.cpp \
       src/helpers/mappers/history/HistoryMapper.cpp


# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: build 

# Link the target
build: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	set -v
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean


real: 
	g++ -std=c++17 -Wall -o BMSTU_Chatbot_2sem src/main.o src/Menu/MenuItem.o src/Menu/Menu.o src/Entity/user/User.o src/helpers/encoder/Encoder.o src/service/user/UserService.o src/helpers/utils/Utilities.o src/helpers/mappers/user/UserMapper.o src/Entity/qa/QA.o src/auth/AuthManager.o src/helpers/mappers/qa/QAMapper.o src/service/qa/QAService.o src/service/history/HistoryService.o src/Entity/history/History.o src/helpers/mappers/history/HistoryMapper.o
#g++ -std=c++17 -Wall -c src/Menu/MenuItem.cpp -o src/Menu/MenuItem.o


