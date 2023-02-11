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
    sf::SoundBuffer buffer;
    sf::Sound sound;

    if (!buffer.loadFromFile("sfx/mob/spider1.ogg"))
        throw LoadingError("Cannot load the file \"Clacker.ogg\".");
    sound.setBuffer(buffer);
    _sound.push_back(sound);
}
