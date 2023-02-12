/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Game
*/

#include "Game.hpp"
#include "SceneManager.hpp"
#include "RayCasting.hpp"

Game::Game(sf::RenderWindow &window) : _window(window)
{
    _map = new Map(20, 20);
    _p = new Player(*_map);
    _mdisplayer = new MapDisplayer(*_map, window, *_p);
}

Game::~Game()
{
}

static void error(std::string str)
{
    std::cout << str << std::endl;
    exit(1);
}

static void set_text(sf::Text &text, std::string str, sf::Color color, sf::Vector2f pos, int x) 
{
    text.setString(str);
    text.setCharacterSize(60);
    text.setFillColor(color);
    pos.x += x;
    text.setPosition(pos);
}

void Game::loadScene(SceneManager *manager, void *data)
{
    (void)manager;
    (void)data;
    if (!this->_font.loadFromFile("sfx/menu/gunplay-3d.ttf"))
        error("Error loading font");
    sf::Vector2f pos_text(0, 0);
    _text.setFont(this->_font);
    set_text(_text, std::to_string(_time), sf::Color::Yellow, pos_text, 0);
}

void Game::unloadScene(SceneManager *manager, void *data)
{
    (void)manager;
    (void)data;
}

void Game::run(SceneManager *manager, void *data)
{
    (void)data;
    _frame++;
    if (_frame == 60) {
        _time--;
        _frame = 0;
        _replace++;
        if (_replace % 15 == 0)
            _map->replace_mobs();
    }
    if (_time == 0)
        manager->changeMenu("EndMenu");
    sf::Vector2f pos_text(0, 0);
    set_text(_text, std::to_string(_time), sf::Color::Yellow, pos_text, 0);
    this->_window.draw(_text);
    _p->getInput();
    _p->move();
    if (_map->moveToPlayer(*_p))
        this->_window.close();
    _p->setListener(_p->getPosition());
    _mdisplayer->drawEcho();
    _mdisplayer->showMob();
    sf::RectangleShape block(sf::Vector2f(5, 5));
    block.setPosition(638, 358);
    block.setFillColor(sf::Color(255, 255, 255));
    this->_window.draw(block);
}
