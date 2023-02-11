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
#include "Player.hpp"

class MainMenu: public IScene {
public:
    MainMenu(sf::RenderWindow &window, sf::Event &event);
    ~MainMenu();

    void loadScene(SceneManager *manager, void *data);
    void unloadScene(SceneManager *manager, void *data);
    void run(SceneManager *manager, void *data);

    sf::Sound _easter_egg;
    Player ben;
protected:
private:
    sf::RenderWindow &_window;
    sf::Event &_event;
    sf::Music _music;
    sf::Font _font;
    std::vector<sf::Sprite> _spriteDraw; 
    std::vector<sf::Text> _textDraw;
    sf::Texture _button_texture;
    sf::Texture _backgroundTexture;
    sf::Texture _personnage;
    sf::SoundBuffer _buff_sound;
};
