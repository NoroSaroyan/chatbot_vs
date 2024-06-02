#include "Menu/Menu.h"
#include "Menu/MenuItem.h"
#include "service/user/UserService.h"
#include "service/qa/QAService.h"
#include "auth/AuthManager.h"
#include "customized/MyGenericVector.h"
#include "Entity/qa/QA.h"
#include "service/history/HistoryService.h"

using namespace std;

void authorizeUser(User user);

[[maybe_unused]]
void logoutUser();

#pragma region функции-заглушки

int request();

int loginFunction();

int registration();

int questions();

int dataStoringGuide();

int privacyPolicy();

void lab3Sort();

int main();

UserService service;

int request()
{
    AuthManager &authManager = AuthManager::getInstance();
    auto temp = authManager.getCurrentUser();
    cout << temp->getId();

    int result = 1;
    int number, power;
    cout << "Введите число" << endl;
    cin >> number;
    cout << "\n введите степень" << endl;
    cin >> power;
    for (int i = 0; i < power; i++)
    {
        result *= number;
    }
    cout << "\n"
         << result << endl;
    return 1;
}

int loginFunction()
{
    string username, password;

    cout << "Enter username" << endl;
    cin >> username;
    cout << endl;

    cout << "Enter password" << endl;
    cin >> password;
    cout << endl;

    if (auto user = service.login(username, password); true)
        authorizeUser(user);
    return 1;
}

int registration()
{
    cout << "REGISTRATION" << endl;
    string username, password;

    cout << "Enter username" << endl;
    cin >> username;
    cout << endl;

    cout << "Enter password" << endl;
    cin >> password;
    cout << endl;

    service.registerAccount(username, password);
    return 2;
}

int questions()
{
    QAService qaService;
    HistoryService historyService;
    MyGenericVector<QA> opt = qaService.getAll();
    MyGenericVector<QA> list = true ? opt : MyGenericVector<QA>();
    int idx = 1;
    for (auto qa : list)
    {
        cout << idx << ". " << qa.getQuestion() << endl;
        idx++;
    }
    cout << "Выберите вопрос: " << endl;
    int choice;
    cin >> choice;
    if (choice < list.getSize() && list.getSize() >= 0)
    {
        cout << "Ответ на вопрос: " + list[choice - 1].getAnswer() << endl;
        auto record = historyService.createRecord(AuthManager::getInstance().getCurrentUser().get()->getUsername(), list[choice - 1]);
        historyService.postRecord(AuthManager::getInstance().getCurrentUser().get()->getUsername(), record);
    }
    else
    {
        cout << "Вопроса с таким номером нет в каталоге" << endl;
    }
    return 3;
}

int dataStoringGuide()
{
    AuthManager &authManager = AuthManager::getInstance();
    auto temp = authManager.getCurrentUser();
    cout << temp->getId();

    cout << "We take your safety close to heart, "
            "\nso, we came up with the idea of multilayer encoding, "
            "\nto ensure your private information and "
            "\n4search history can't be read by anyone except you.\n\n";
    return 4;
}

int privacyPolicy()
{
    AuthManager &authManager = AuthManager::getInstance();
    auto temp = authManager.getCurrentUser();
    cout << temp->getId();

    cout << "Privacy policy is for telling you about basic rules and agreements between me and you."
            "\n we'll get to this in a bit. \n\n";
    return 5;
}
int userHistory()
{
    AuthManager &AuthManager = AuthManager::getInstance();
    auto temp = AuthManager.getCurrentUser().get();
}

void lab3Sort()
{
    UserMapper um;
    vector<string> strUsers{
        "3d24b878-9b7d-4ae8-886b-e75945405a8e noriksaroyan@gmail.com Noro$2004 USER",
        "7c145b0a-2e8b-48db-a105-556e2f73093b User1@gmail.com User1$pswrd USER",
        "50693932-99ed-4496-bb9f-9b57223e0125 user2@gmail.com User2$pswrd USER",
        "c84c49e8-2f02-43a0-90d5-bad89dddd174 user3@gmail.com User3$pswrd USER",
        "35577aec-a430-4e43-87a1-a5de3f398069 User4@gmail.com User4$Pswrd USER",
    };
    vector<User> users;
    for (const auto &strUser : strUsers)
    {
        users.push_back(um.mapToObject(strUser));
    }
    cout << "ORIGINAL" << endl;
    for (const auto &user : users)
    {
        cout << user << endl;
    }

    for (int i = 0; i < users.size() - 1; ++i)
    {
        if (users[i] > users[i + 1])
        {
            auto temp = users[i];
            users[i] = users[i + 1];
            users[i + 1] = temp;
        }
    }
    cout << "SORTED" << endl;
    for (const auto &user : users)
    {
        cout << user << endl;
    }
}

#pragma endregion

void authorizeUser(User user)
{
    AuthManager &AuthManager = AuthManager::getInstance();
    if (AuthManager.login(user.getUsername(), user.getPassword(), user.getAuthority()))
    {
        std::shared_ptr<User> user = AuthManager.getCurrentUser();
        std::cout << "Пользователь:" << user->getUsername() << std::endl;
    }
    else
    {
        std::cerr << "Login failed for user " << user.getUsername() << std::endl;
    }
}

void logoutUser()
{
    AuthManager &authManager = AuthManager::getInstance();
    authManager.logout();
    std::cout << "User has logged out." << std::endl;
}

const int ITEMS_NUMBER = 6;
string username, password;

int main()
{
    lab3Sort();

    std::shared_ptr<User> user = AuthManager::getInstance().getCurrentUser();
    if (user)
    {
        std::cout << "Current User: " << user->getUsername() << ", ID: " << user->getId() << std::endl;
    }

    MenuItem items[ITEMS_NUMBER]{
        MenuItem{"Request", request}, {"Login", loginFunction}, MenuItem{"Register", registration}, MenuItem{"Catalog", questions}, MenuItem{"How do we store data?", dataStoringGuide}, MenuItem{"Privacy policy", privacyPolicy}};
    Menu menu("My console menu", items, ITEMS_NUMBER);
    while (menu.runCommand())
    {
    };

    return 0;
}
