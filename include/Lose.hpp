/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** LOOSE
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <unistd.h>
#include <vector>

#include "IScene.hpp"

class Lose: public IScene {
public:
    Lose(sf::RenderWindow &window);
    ~Lose();

    void loadScene(SceneManager *manager, void *data);
    void unloadScene(SceneManager *manager, void *data);
    void run(SceneManager *manager, void *data);

    sf::Sound _easter_egg;
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
