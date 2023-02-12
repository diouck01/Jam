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

class EndMenu: public IScene {
public:
    EndMenu(sf::RenderWindow &window);
    ~EndMenu();

    void loadScene(SceneManager *manager, void *data);
    void unloadScene(SceneManager *manager, void *data);
    void run(SceneManager *manager, void *data);
protected:
private:
    sf::RenderWindow &_window;
    sf::Music _music;
    sf::Font _font;
    sf::Texture _backgroundTexture;
    sf::Sprite _background;
    sf::SoundBuffer _buff_sound;
    sf::Text _text;
};
