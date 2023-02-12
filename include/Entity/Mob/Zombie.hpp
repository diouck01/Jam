/*
** EPITECH PROJECT, 2023
** Zombie
** File description:
** The header contains the Zombie class.
*/

#pragma once

#include "AMob.hpp"

class Player;

class Zombie : public AMob{
    public:
        Zombie(Map &map);
};
