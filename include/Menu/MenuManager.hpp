/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** MenuManager
*/

#pragma once

#include <map>
#include <string>
#include <iostream>

#include "IMenu.hpp"

class MenuManager {
public:
    MenuManager();
    ~MenuManager();

    void addMenu(std::string MenuManager, IMenu menu);
    void display(void);
    void changeMenu(std::string MenuManager);

protected:
    std::string currentMenu = "None";
    std::string previousMenu = "None";
    std::map<std::string, IMenu> _menuList;

private:
};
