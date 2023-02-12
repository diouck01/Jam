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
    _map = new Map(20, 20);
    _p = new Player(*_map);
    _mdisplayer = new MapDisplayer(*_map, window, *_p);
}

Game::~Game()
{
}

void Game::loadScene(SceneManager *manager, void *data)
{
    (void)manager;
    (void)data;
    _map->random_empty_position();
}

void Game::unloadScene(SceneManager *manager, void *data)
{
    (void)manager;
    (void)data;
}

void Game::run(SceneManager *manager, void *data)
{
    (void)data;
    _p->getInput();
    _p->move();
    _mdisplayer->drawEcho();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        manager->changeMenu("EndMenu");
}