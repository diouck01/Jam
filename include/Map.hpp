/*
** EPITECH PROJECT, 2023
** Map
** File description:
** The header contains the Map class.
*/

#pragma once
#include <vector>
#include <ostream>
#include <IEntity.hpp>

class Map {
    public:
        Map(unsigned int width, unsigned int height);
        ~Map();

        unsigned int random_empty_position();
        unsigned int getWidth() const;
        unsigned int getHeight() const;
        unsigned int getSize() const;
        int &operator[](unsigned int i);
        int operator[](unsigned int i) const;
    private:
        IEntity *_mobs;
        unsigned int _width;
        unsigned int _height;
        int *_tiles;
};

std::ostream &operator<<(std::ostream &os, const Map map);
