/*
** EPITECH PROJECT, 2023
** Zombie
** File description:
** The file contains all the methods of the header class.
*/

#include "Mob/Zombie.hpp"

Zombie::Zombie(Map &map)
: AMob::AMob(map)
{
    _name = "Zombie";
    sf::SoundBuffer buffer;
    sf::Sound sound;

    if (!buffer.loadFromFile("sfx/mob/zombie_bruh.ogg"))
        throw LoadingError("Cannot load the file \"zombie_bruh.ogg\".");
    sound.setBuffer(buffer);
    _sound = sound;
}
