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
    _listener.setGlobalVolume(50.f);
    sf::SoundBuffer buffer;
    sf::Sound sound;

    if (!buffer.loadFromFile("sfx/death/mc_ougth.ogg"))
        throw LoadingError("Cannot load the file \"player heart.ogg\".");
    sound.setBuffer(buffer);
    _sound.push_back(sound);
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