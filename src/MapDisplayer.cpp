/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** MapDisplayer
*/

#include "MapDisplayer.hpp"

MapDisplayer::MapDisplayer(Map &map, sf::RenderWindow &window, Player &player)
: _map(map), _window(window), _player(player)
{
}

MapDisplayer::~MapDisplayer()
{
}

void MapDisplayer::showMap(void)
{
    sf::Vector2f offset;
    sf::Vector2f blockPos;
    sf::RectangleShape block(sf::Vector2f(this->_tileSize, this->_tileSize));
    block.setOutlineThickness(2);

    offset.x += this->_tileSize * this->_player.getPosition().x - 640;
    offset.y += this->_tileSize * this->_player.getPosition().y - 360;

    for (std::size_t i = 0; i < this->_map.getWidth() * this->_map.getHeight(); ++i) {
        blockPos.x = this->_tileSize * (i % this->_map.getWidth());
        blockPos.y = this->_tileSize * (i / this->_map.getWidth());
        block.setPosition(blockPos - offset);
        if (this->_map[i]) {
            block.setFillColor(sf::Color(255, 0, 0));
            this->_window.draw(block);
        }
        block.setOutlineColor(sf::Color(255, 255, 255, 64));
        block.setFillColor(sf::Color(0, 0, 0, 0));
        this->_window.draw(block);
    }
}
