/*
** EPITECH PROJECT, 2023
** Map
** File description:
** The file contains all the methods of the map class.
*/

#include "Map.hpp"
#include <Zombie.hpp>
#include <Clacker.hpp>
#include <Dracula.hpp>
#include "AMob.hpp"

void fill_around(Map &map, unsigned int i, int value)
{
    unsigned int width = map.getWidth();

    if (i >= width)
        map[i - width] = value;
    if (i % width != 0)
        map[i - 1] = value;
    if (i >= width && i % width != 0)
        map[i - width - 1] = value;
}

Map::Map(unsigned int width, unsigned int height) : _width(width), _height(height), _tiles(new int[width * height])
{
    unsigned int i;

    for (i = 0; i != width * height; i++)
        _tiles[i] = 0;
    for (i = 0; i != (width + height); i++)
        _tiles[rand() % (_width * _height)] = 1;
    for (i = 0; i != width * height; i++)
        if (_tiles[i] == 1)
            fill_around(*this, i, 2);
    generate_mobs();
}

Map::~Map()
{
}

void Map::generate_mobs(unsigned int zombies, unsigned int clackers, unsigned int draculas)
{
    unsigned int i;
    for (i = 0; i != zombies; i++)
        _mobs.push_back(new Zombie(*this));
    for (i = 0; i != clackers; i++)
        _mobs.push_back(new Clacker(*this));
    for (i = 0; i != draculas; i++)
        _mobs.push_back(new Dracula(*this));
}

int &Map::operator[](unsigned int i)
{
    return (_tiles[i]);
}

int Map::operator[](unsigned int i) const
{
    return (_tiles[i]);
}

std::vector <IEntity *>Map::getMobs() const
{
    return (_mobs);
}

unsigned int Map::getWidth() const
{
    return (_width);
}

unsigned int Map::getHeight() const
{
    return (_height);
}

unsigned int Map::getSize() const
{
    return (_width * _height);
}

bool Map::moveToPlayer(Player &player) const
{
    unsigned int i;
    AMob *mobs;

    for (i = 0; i != _mobs.size(); i++){
        mobs = static_cast<AMob *> (_mobs[i]);
        mobs->MoveToPlayer(player);
        if (mobs->distance(player) < 0.1)
            return (true);
    }
    return (false);
}

unsigned int Map::random_empty_position()
{
    unsigned int i;

    do{
        i = rand() % (_width * _height);
    } while (_tiles[i] != 0);
    return (i);
}

std::ostream &operator<<(std::ostream &os, const Map map)
{
    unsigned int width = map.getWidth();
    unsigned int height = map.getHeight();
    unsigned int i;

    for (i = 0; i != width * height; i++){
        if (i % width == 0)
            os << '\n';
        else
            os << ' ';
        if (map[i] == 3)
            os << "\033[31mo\033[0m";
        else if (map[i] == 4)
            os << "\033[33mo\033[0m";
        else if (map[i] != 0 && map[i] != 3)
            os << "#";
        else
            os << "-";
       
    }
    return (os);
}
