//
// Created by Norik Saroyan on 20.02.24.
//

#include "MenuItem.h"
#include "../../Headers.h"

MenuItem::MenuItem(string name, Func func) : func(func), item_name(name){}


 string MenuItem::getName() const
{
    return item_name;
}

void MenuItem::print()
{
    std::cout << item_name;
}

int MenuItem::run()
{
    return func();
}
