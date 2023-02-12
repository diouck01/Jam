/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** AMob
*/

#include "AMob.hpp"

<<<<<<< HEAD
<<<<<<< HEAD:src/Entity/Mob/AMob.cpp
AMob::AMob(Map &map) : AEntity(map)
=======
AMob::AMob(Map &map)
: AEntity::AEntity(map)
{
    this->_speed = 4;
}

AMob::~AMob()
>>>>>>> 32b6e43 ([ADD] Raycasting/echo system and collisions):src/Entity/AMob.cpp
=======
AMob::AMob(Map &map) : AEntity(map)
>>>>>>> 4b6dab9 ([Fix] Merge conflit fixed)
{
}

void AMob::generatePath(void)
{
    
}
