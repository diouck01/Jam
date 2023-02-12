/*
** EPITECH PROJECT, 2023
** Clacker
** File description:
** The file contains all the methods of the header class.
*/

#include "Mob/Clacker.hpp"

<<<<<<< HEAD
<<<<<<< HEAD
Clacker::Clacker(Map &map) : AMob(map)
=======
Clacker::Clacker(Map &map)
: AMob::AMob(map)
>>>>>>> 32b6e43 ([ADD] Raycasting/echo system and collisions)
=======
Clacker::Clacker(Map &map) : AMob(map)
>>>>>>> 4b6dab9 ([Fix] Merge conflit fixed)
{
    _name = "Clacker";
    sf::SoundBuffer buffer;
    sf::Sound sound;

<<<<<<< HEAD
    if (!buffer.loadFromFile("sfx/mob/spider1.ogg"))
=======
    if (!buffer.loadFromFile("sfx/mob/villager.ogg"))
>>>>>>> 750db46 ([Fix] merge conflit fixed)
        throw LoadingError("Cannot load the file \"Clacker.ogg\".");
    sound.setBuffer(buffer);
    _sound = sound;
}
