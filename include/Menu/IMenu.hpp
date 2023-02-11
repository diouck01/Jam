/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** IMenu
*/

#pragma once

class MenuManager;

class IMenu {
public:
    ~IMenu() = default;

    virtual void loadMenu(MenuManager &manager, void *data) = 0;
    virtual void unloadMenu(MenuManager &manager, void *data) = 0;
    virtual void run(MenuManager &manager, void *data) = 0;
};
