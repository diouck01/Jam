/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Tuto
*/

#include "Tuto.hpp"
#include "SceneManager.hpp"

Tuto::Tuto(sf::RenderWindow &window) : _window(window)
{
}

Tuto::~Tuto()
{
}

static void error(std::string str)
{
    std::cout << str << std::endl;
    exit(1);
}

void Tuto::loadScene(SceneManager *manager, void *data)
{
    (void)manager;
    (void)data;
    
    if (!_backgroundTexture.loadFromFile("sfx/Tuto.png"))
        error("Error loading background texture");
    _background.setTexture(_backgroundTexture);
}

void Tuto::unloadScene(SceneManager *manager, void *data)
{
    (void)manager;
    (void)data;
}

void Tuto::run(SceneManager *manager, void *data)
{
    (void)data;
    _window.draw(_background);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        manager->changeMenu("EndMenu");
}