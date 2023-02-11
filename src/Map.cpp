/*
** EPITECH PROJECT, 2023
** Map
** File description:
** The file contains all the methods of the map class.
*/

#include "Map.hpp"

void fill_around(Map &map, unsigned int i, int value)
{
    unsigned int width = map.getWidth();
    unsigned int height = map.getHeight();

    if (i >= width)
        map[i - width] = value;
    if (i % width != 0)
        map[i - 1] = value;
    if ((i + 1) % width != 0)
        map[i + 1] = value;
    if (i < width * height - width)
        map[i + width] = value;
    if (i >= width + 1 && (i + 1) % width != 0)
        map[i - width + 1] = value;
    if (i >= width && i % width != 0)
        map[i - width - 1] = value;
    if (i < width * height - width - 1 && i % width != 0)
        map[i + width - 1] = value;
    if (i < width * height - width && (i + 1) % width != 0)
        map[i + width + 1] = value;
}

Map::Map(unsigned int width, unsigned int height) : _width(width), _height(height), _tiles(new int[width * height])
{
    unsigned int i;

    for (i = 0; i != width * height; i++)
        _tiles[i] = 0;
    for (i = 0; i != (width + height) / 2; i++)
        _tiles[rand() % (_width * _height)] = 1;
    for (i = 0; i != width * height; i++){
        if (_tiles[i] == 1){
            fill_around(*this, i, 2);
    }
    }
}

Map::~Map()
{
}

int &Map::operator[](unsigned int i)
{
    return (_tiles[i]);
}

int Map::operator[](unsigned int i) const
{
    return (_tiles[i]);
}

unsigned int Map::getWidth() const
{
    return (_width);
}

unsigned int Map::getHeight() const
{
    return (_height);
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
        else if (map[i] != 0 && map[i] != 3)
            os << "#";
        else
            os << "-";
       
    }
    return (os);
}