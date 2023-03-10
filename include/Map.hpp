/*
** EPITECH PROJECT, 2023
** Map
** File description:
** The header contains the Map class.
*/

#pragma once
#include <vector>
#include <ostream>
#include "IEntity.hpp"
#include "AEntity.hpp"

class Player;

class Map {
    public:
        Map(unsigned int width, unsigned int height);
        ~Map();

        void generate_mobs(unsigned int zombies = 3, unsigned int clackers = 2, unsigned int draculas = 1);
        void replace_mobs();
        unsigned int random_empty_position();
        bool moveToPlayer(Player &player) const;
        std::vector<IEntity *> getMobs() const;
        unsigned int getWidth() const;
        unsigned int getHeight() const;
        unsigned int getSize() const;
        int &operator[](unsigned int i);
        int operator[](unsigned int i) const;
    private:
        std::vector <IEntity *> _mobs;
        unsigned int _width;
        unsigned int _height;
        int *_tiles;
};

std::ostream &operator<<(std::ostream &os, const Map map);
