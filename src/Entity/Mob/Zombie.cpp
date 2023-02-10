/*
** EPITECH PROJECT, 2023
** Zombie
** File description:
** The file contains all the methods of the header class.
*/

#include "Mob/Zombie.hpp"

Zombie::Zombie()
{
    sf::SoundBuffer buffer;
    sf::Sound sound;

    if (!buffer.loadFromFile("zombie_bruh.ogg"))
        throw LoadingError("Cannot load the file \"zombie_bruh.ogg\".");
    sound.setBuffer(buffer);
    _sound.push_back(sound);
}
