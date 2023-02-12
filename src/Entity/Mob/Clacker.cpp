/*
** EPITECH PROJECT, 2023
** Clacker
** File description:
** The file contains all the methods of the header class.
*/

#include "Mob/Clacker.hpp"

Clacker::Clacker(Map &map) : AMob(map)
{
    _name = "Clacker";

    if (!_buff_sound.loadFromFile("sfx/mob/spider1.ogg"))
        throw LoadingError("Cannot load the file \"Clacker.ogg\".");
    _sound.setBuffer(_buff_sound);
}
