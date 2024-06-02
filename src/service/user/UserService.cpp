#include "UserService.h"
#include "../../exception/service/ServiceConnectionException.h"

// UserService::UserService() : BaseService("/Users/noriksaroyan/CLionProjects/BMSTU-Chatbot-2sem/static/Database/users.txt") {}
UserService::UserService() : BaseService("static/Database/users.txt") {}

void UserService::registerAccount(const std::string &username, const std::string &password)
{
    User temp;
    std::string validUsername = username;
    std::string validPassword = password;

    while (!utils.checkEmail(validUsername))
    {
        std::cout << "Email is invalid, try again: ";
        std::cin >> validUsername;
        std::cout << std::endl;
    }
    temp.setUsername(validUsername);

    std::cout << "Enter password" << std::endl;
    std::cin >> validPassword;
    std::cout << std::endl;
    while (!utils.checkPassword(validPassword))
    {
        std::cout << "Password is too weak, try again: ";
        std::cin >> validPassword;
        std::cout << std::endl;
    }

    temp.setPassword(validPassword);
    temp.setAuthority("USER");

    temp.setId("1");

    try
    {
        std::ofstream out = openOutputFile();
        if (out.is_open())
        {
            out << mapper.mapToString(temp) << "\n";
        }
        else
        {
            throw ServiceConnectionException("Unable to access database for writing");
        }
    }
    catch (const ServiceConnectionException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

User UserService::login(const std::string &username, const std::string &password)
{
    User currentUser;

    try
    {
        std::ifstream file = openInputFile();
        if (!file.is_open())
        {
            throw ServiceConnectionException("Unable to access database for reading");
        }

        std::string current;

        while (std::getline(file, current))
        {
            currentUser = mapper.mapToObject(current);
            if (currentUser.getUsername() == username && currentUser.getPassword() == password)
            {
                AuthManager::getInstance().login(username, password, currentUser.getAuthority());
                return currentUser;
            }
        }
        file.close();
        std::cout << "User not found, try again" << std::endl;
        return User();
    }
    catch (const ServiceConnectionException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return User();
    }
}
