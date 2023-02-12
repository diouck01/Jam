/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** AMob
*/

#include "AMob.hpp"

AMob::AMob(Map &map)
: AEntity::AEntity(map)
{
    this->_speed = 4;
}

AMob::~AMob()
{
}

void AMob::generatePath(void)
{
    
}
