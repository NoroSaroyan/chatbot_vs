//
// Created by Norik Saroyan on 20.02.24.
//

#ifndef MENUITEM_H
#define MENUITEM_H
#include "../../Headers.h"
class MenuItem {
public:
    typedef int (*Func)();
    MenuItem(string, Func);
    Func func{};
    string item_name{};
    string getName() const;
    void print();
    int run();
};
#endif //MENUITEM_H
