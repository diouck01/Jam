/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** MainMenu
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <unistd.h>
#include <vector>

#include "IScene.hpp"

class Tuto: public IScene {
public:
    Tuto(sf::RenderWindow &window);
    ~Tuto();

    void loadScene(SceneManager *manager, void *data);
    void unloadScene(SceneManager *manager, void *data);
    void run(SceneManager *manager, void *data);
protected:
private:
    sf::RenderWindow &_window;
    sf::Texture _backgroundTexture;
    sf::Sprite _background;
};
