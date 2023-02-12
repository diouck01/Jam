/*
** EPITECH PROJECT, 2023
** Dracula
** File description:
** The file contains all the methods of the header class.
*/

#include "Mob/Dracula.hpp"

Dracula::Dracula(Map &map) : AMob(map)
{
    _name = "Dracula";

    if (!_buff_sound.loadFromFile("sfx/mob/vampire1.ogg"))
        throw LoadingError("Cannot load the file \"vampire.ogg\".");
    _sound.setBuffer(_buff_sound);
    _speed = 0.04;
}
