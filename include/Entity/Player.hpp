/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** Player
*/

#pragma once

#include <iostream>

#include "AEntity.hpp"

class Player: public AEntity {
public:
    Player(Map &map);
    ~Player();

    void getInput(void);
protected:
    int _echoStrength = 0;
private:
};
