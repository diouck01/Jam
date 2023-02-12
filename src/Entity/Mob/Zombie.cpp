/*
** EPITECH PROJECT, 2023
** Zombie
** File description:
** The file contains all the methods of the header class.
*/

#include "Mob/Zombie.hpp"

<<<<<<< HEAD
Zombie::Zombie(Map &map) : AMob(map)
=======
Zombie::Zombie(Map &map)
: AMob::AMob(map)
>>>>>>> 32b6e43 ([ADD] Raycasting/echo system and collisions)
{
    _name = "Zombie";
    sf::SoundBuffer buffer;
    sf::Sound sound;

    if (!buffer.loadFromFile("sfx/mob/zombie_bruh.ogg"))
        throw LoadingError("Cannot load the file \"zombie_bruh.ogg\".");
    sound.setBuffer(buffer);
    _sound = sound;
}
