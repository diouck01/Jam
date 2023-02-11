/*
** EPITECH PROJECT, 2023
** Map
** File description:
** The header contains the Map class.
*/

#pragma once
#include <vector>
#include <IMob.hpp>

class Map {
    public:
        Map(int x, int y);
        ~Map();
    private:
        std::list<IMob*> _mobs;
        std::list<int> _tiles;
        sf::Vector2f _size;
};
