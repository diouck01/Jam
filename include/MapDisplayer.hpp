/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** MapDisplayer
*/

#pragma once

#include "Map.hpp"
#include "Player.hpp"

class MapDisplayer {
public:
    MapDisplayer(Map &map, sf::RenderWindow &window, Player &player);
    ~MapDisplayer();

    void showMap(void);
protected:
    int _tileSize = 100;
    Map &_map;
    sf::RenderWindow &_window;
    Player &_player;

};
