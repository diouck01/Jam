/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** AEntity
*/

#include "AEntity.hpp"
#include <iostream>

AEntity::AEntity()
{
    this->_position.x = 0;
    this->_position.y = 0;
    this->_movement.x = 0;
    this->_movement.y = 0;
}

AEntity::~AEntity()
{
}

sf::Vector2f AEntity::getPosition() const
{
    return (this->_position);
}

void AEntity::setPosition(sf::Vector2f position)
{
    this->_position = position;
}

void AEntity::setPosition(double x, double y)
{
    sf::Vector2f position(x, y);
    
    this->setPosition(position);   
}

void AEntity::setMove(sf::Vector2f position)
{
    this->_movement = position;
}

void AEntity::setMove(double x, double y)
{
    sf::Vector2f position(x, y);
    
    this->setMove(position);   
}

void AEntity::move(sf::Vector2f position)
{
    this->_position += position;
}

void AEntity::move(double x, double y)
{
    sf::Vector2f position(x, y);
    
    this->move(position);   
}

void AEntity::move(void)
{
    this->move(this->_movement);   
}

double AEntity::getVectorLength(sf::Vector2f vect) const
{
    return (sqrt(pow(vect.x, 2) + pow(vect.y, 2)));
}

double AEntity::getVectorDot(sf::Vector2f v1, sf::Vector2f v2) const
{
    return (v1.x * v2.x + v1.y * v2.y);
}

void AEntity::setVectorNorm(sf::Vector2f &vect)
{
    double len = this->getVectorLength(vect);

    if (len != 0) {
        vect.x /= len;
        vect.y /= len;
    }
}

void AEntity::updateAngle(void)
{
    sf::Vector2f refAngle(0, -1);
    double len = this->getVectorLength(this->_movement);

    if (len == 0)
        return;
    this->_angle = acos(this->getVectorDot(this->_movement, refAngle) / len);
}
