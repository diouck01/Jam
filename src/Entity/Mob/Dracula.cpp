/*
** EPITECH PROJECT, 2023
** Dracula
** File description:
** The file contains all the methods of the header class.
*/

#include "Mob/Dracula.hpp"

Dracula::Dracula()
{
    sf::SoundBuffer buffer;
    sf::Sound sound;

    if (!buffer.loadFromFile("Vampire.ogg"))
        throw LoadingError("Cannot load the file \"Dracula.ogg\".");
    sound.setBuffer(buffer);
    _sound.push_back(sound);
}
