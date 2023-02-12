/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** Game
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <unistd.h>
#include <vector>

#include "IScene.hpp"
#include "RayCasting.hpp"
#include "Player.hpp"
#include "MapDisplayer.hpp"

class Player;
class Game: public IScene {
public:
    Game(sf::RenderWindow &window);
    ~Game();

    void loadScene(SceneManager *manager, void *data);
    void unloadScene(SceneManager *manager, void *data);
    void run(SceneManager *manager, void *data);
protected:
private:
    sf::RenderWindow &_window;
    int _time = 120;
    int _frame = 0;
    int _replace = 0;
    sf::Font _font;
    sf::Text _text;
    Map *_map;
    Player *_p;
    MapDisplayer *_mdisplayer;
};
