/*
** EPITECH PROJECT, 2023
** Dracula
** File description:
** The file contains all the methods of the header class.
*/

#include "Mob/Dracula.hpp"

<<<<<<< HEAD
Dracula::Dracula(Map &map) : AMob(map)
=======
Dracula::Dracula(Map &map)
: AMob::AMob(map)
>>>>>>> 32b6e43 ([ADD] Raycasting/echo system and collisions)
{
    _name = "Dracula";
    sf::SoundBuffer buffer;
    sf::Sound sound;

    if (!buffer.loadFromFile("sfx/mob/vampire1.ogg"))
        throw LoadingError("Cannot load the file \"Vampire.ogg\".");
    sound.setBuffer(buffer);
    _sound = sound;
}
