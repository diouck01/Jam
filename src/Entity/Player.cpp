/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** Player
*/

#include "Player.hpp"

Player::Player()
{
    _name = "Ben Underwood";
    this->setPosition(0, 0);
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
    
    this->setMove(q - d, s - z);
    this->setVectorNorm(this->_movement);
    this->updateAngle();

    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (this->_echoStrength >= 30) {
            std::cout << "AH" << std::endl;
        } else if (this->_echoStrength < 30 && this->_echoStrength > 0) {
            std::cout << "ah" << std::endl;
        }
    } else
        ++this->_echoStrength;


}