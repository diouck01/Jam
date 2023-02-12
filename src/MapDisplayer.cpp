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
    this->_echoLayer1.create(1280, 720);
    this->_echoLayer2.create(1280, 720);
    this->_echoLayer3.create(1280, 720);
    this->_offset.x = 0;
    this->_offset.y = 0;
    this->_prevOffset.x = 0;
    this->_prevOffset.y = 0;
    if (!this->_shader.loadFromFile("./shaders/fading.frag", sf::Shader::Fragment))
        std::cerr << "Failed to load shader." << std::endl;
}

MapDisplayer::~MapDisplayer()
{
}

void MapDisplayer::updateOffset(void)
{
    this->_prevOffset = this->_offset;
    this->_offset.x = this->_tileSize * this->_player.getPosition().x - 640;
    this->_offset.y = this->_tileSize * this->_player.getPosition().y - 360;

}

void MapDisplayer::showMap(void)
{
    sf::Vector2f offset;
    sf::Vector2f blockPos;
    sf::RectangleShape block(sf::Vector2f(this->_tileSize, this->_tileSize));
    block.setOutlineThickness(2);

    offset.x = this->_tileSize * this->_player.getPosition().x - 640;
    offset.y = this->_tileSize * this->_player.getPosition().y - 360;

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
    sf::Vector2f blockPos;
    sf::RectangleShape block(sf::Vector2f(this->_tileSize, this->_tileSize));
    sf::Sprite tmp;
    block.setFillColor(sf::Color(255,255,255));

    this->updateOffset();

    this->_echoLayer1.clear(sf::Color(0, 0, 0, 0));
    this->_echoLayer2.clear(sf::Color(0, 0, 0, 0));
    tmp.setTexture(this->_echoLayer3.getTexture());
    tmp.setPosition(0, 0);
    this->_echoLayer2.draw(tmp);
    this->_echoLayer3.clear(sf::Color(0, 0, 0, 0));
    while (echoes.size() > 0) {
        result = echoes.back();
        echoes.pop_back();

        blockPos.x = (static_cast<long>(result.coords.x) - (result.direction.x < 0 && result.side == HORI));
        blockPos.y = (static_cast<long>(result.coords.y) - (result.direction.y < 0 && result.side == VERT));
        blockPos.x *= this->_tileSize;
        blockPos.y *= this->_tileSize;
        block.setPosition(blockPos - this->_offset);
        this->_echoLayer1.draw(block);
    }
    tmp.setTexture(this->_echoLayer2.getTexture());
    tmp.setPosition(this->_prevOffset.x - this->_offset.x, this->_offset.y - this->_prevOffset.y);
    if (this->_prevOffset != this->_offset)
        this->_echoLayer3.draw(tmp, &this->_shader);
    else
        this->_echoLayer3.draw(tmp);
    tmp.setTexture(this->_echoLayer1.getTexture());
    tmp.setPosition(0, 0);
    this->_echoLayer3.draw(tmp);
    tmp.setTexture(this->_echoLayer3.getTexture());
    tmp.setPosition(0, 0);
    this->_window.draw(tmp);
}
