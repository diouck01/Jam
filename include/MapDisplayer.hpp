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

    void updateOffset(void);
    void showMap(void);
    void drawEcho(void);
    void showMob(void);
protected:
    int _tileSize = 100;
    Map &_map;
    sf::RenderWindow &_window;
    Player &_player;
    sf::RenderTexture _echoLayer1;
    sf::RenderTexture _echoLayer2;
    sf::RenderTexture _echoLayer3;
    sf::Vector2f _offset;
    sf::Vector2f _prevOffset;
    sf::Shader _shader;
};
