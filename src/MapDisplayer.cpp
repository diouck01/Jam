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

void MapDisplayer::drawEcho(void)
{
    std::vector<t_RayResult> &echoes = this->_player.getEchoes();
    t_RayResult result;
    sf::Vector2f offset;
    sf::Vector2f blockPos;
    sf::RectangleShape block(sf::Vector2f(this->_tileSize, this->_tileSize));

    offset.x += this->_tileSize * this->_player.getPosition().x - 640;
    offset.y += this->_tileSize * this->_player.getPosition().y - 360;

    block.setFillColor(sf::Color(255,255,255));
    while (echoes.size() > 0) {
        result = echoes.back();
        echoes.pop_back();

        blockPos.x = (static_cast<long>(result.coords.x) - (result.direction.x < 0 && result.side == HORI));
        blockPos.y = (static_cast<long>(result.coords.y) - (result.direction.y < 0 && result.side == VERT));
        blockPos.x *= this->_tileSize;
        blockPos.y *= this->_tileSize;
        block.setPosition(blockPos - offset);
        this->_window.draw(block);
    }
}
