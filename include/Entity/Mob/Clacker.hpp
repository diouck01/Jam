/*
** EPITECH PROJECT, 2023
** Clacker
** File description:
** The header contains the Clacker class.
*/

#pragma once

#include "Map.hpp"
#include "AMob.hpp"

class Clacker : public AMob{
    public:
        Clacker(Map &map);
};
