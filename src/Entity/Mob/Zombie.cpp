/*
** EPITECH PROJECT, 2023
** Zombie
** File description:
** The file contains all the methods of the header class.
*/

#include "Mob/Zombie.hpp"

Zombie::Zombie(Map &map) : AMob(map)
{
    _name = "Zombie";

    if (!_buff_sound.loadFromFile("sfx/mob/zombie_bruh.ogg"))
        throw LoadingError("Cannot load the file \"zombie_bruh.ogg\".");
    _sound.setBuffer(_buff_sound);
    _speed = 0.02;
}
