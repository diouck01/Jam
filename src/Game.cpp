/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Game
*/

#include "Game.hpp"
#include "SceneManager.hpp"

Game::Game(sf::RenderWindow &window) : _window(window)
{
}

Game::~Game()
{
}

void Game::loadScene(SceneManager *manager, void *data)
{
    (void)manager;
    (void)data;
}

void Game::unloadScene(SceneManager *manager, void *data)
{
    (void)manager;
    (void)data;
}

void Game::run(SceneManager *manager, void *data)
{
    (void)data;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        manager->changeMenu("EndMenu");
}