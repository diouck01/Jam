/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** AMob
*/

#include "AMob.hpp"

AMob::AMob(Map &map) : AEntity(map)
{
}

void AMob::generatePath(void)
{
    
}

void AMob::MoveToPlayer(Player &p)
{
    sf::Vector2f pPos = p.getPosition();
    this->_movement = pPos - this->_position;

    this->setVectorNorm(this->_movement);
    this->_movement.x *= this->_speed;   
    this->_movement.y *= this->_speed;
    this->moveNoCollide(this->_movement);
}
