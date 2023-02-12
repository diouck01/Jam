/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(Map &map)
: AEntity::AEntity(map)
{
    this->_speed = 0.05;
    _name = "Ben Underwood";
    _listener.setPosition(0, 0, 0);
    _listener.setGlobalVolume(50.f);

    std::srand (time(NULL));
    int tmp = std::rand()%101;

    if (tmp < 45 && !_buff_sound.loadFromFile("sfx/echo/tongue_click1.ogg"))
        throw LoadingError("Cannot load the file \"player heart.ogg\".");
    if (tmp > 45 && tmp < 90 && !_buff_sound.loadFromFile("sfx/echo/tongue_click2.ogg"))
        throw LoadingError("Cannot load the file \"player heart.ogg\".");
    if (tmp > 90 && tmp < 99 && !_buff_sound.loadFromFile("sfx/echo/villager.ogg"))
        throw LoadingError("Cannot load the file \"player heart.ogg\".");
    if (tmp == 100 && !_buff_sound.loadFromFile("sfx/echo/fart_reverb.ogg"))
        throw LoadingError("Cannot load the file \"player heart.ogg\".");
    sf::Sound sound;
    sound.setBuffer(_buff_sound);
    sound.setPosition(0, 0, 0);
    sound.setMinDistance(20.f);
    _sound = sound;
}

Player::~Player()
{
}

void Player::getInput(void)
{
    bool z = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
    bool s = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    bool q = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
    bool d = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    
    this->setMove(d - q, s - z);
    this->setVectorNorm(this->_movement);
    this->_movement.x *= this->_speed;
    this->_movement.y *= this->_speed;
    this->updateAngle();

    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (this->_echoStrength >= 20) {
            this->strongEcho();
        } else if (this->_echoStrength < 20 && this->_echoStrength > 0) {
            this->normalEcho();
        }
        this->_echoStrength = 0;
    } else
        ++this->_echoStrength;
}

void Player::echo(double range, double width)
{
    s_RayResult rayResult;
    double hAngle = width / 2;

    for (double i = -hAngle + this->_angle; i <= hAngle + this->_angle; i += M_PI / 30) {
        rayResult = this->_rayCaster->sendRay(this->_position, i, range);
        if (rayResult.wallFound)
            this->_echoes.push_back(rayResult);
    }
}

void Player::normalEcho(void)
{
    this->getSound()->play();
    this->echo(5, M_PI / 2);
}

void Player::strongEcho(void)
{
    this->getSound()->play();
    this->echo(8, M_PI * 2);
}

std::vector<t_RayResult> &Player::getEchoes(void)
{
    return (this->_echoes);
}
