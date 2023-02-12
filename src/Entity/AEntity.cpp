/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** AEntity
*/

#include "AEntity.hpp"
#include <iostream>

AEntity::AEntity(Map &map) : _map(map)
{
    unsigned int i = map.random_empty_position();

    this->_position.y = i % map.getHeight();
    this->_position.y = i / map.getWidth();
    map[map.getWidth() * _position.y + _position.x] = 3;
    this->_movement.x = 0;
    this->_movement.y = 0;
    this->_rayCaster = new RayCasting(this->_map);
}

AEntity::~AEntity()
{
    delete this->_rayCaster;
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
    t_RayResult result = this->_rayCaster->sendRay(this->_position, this->_angle, 100);

    double angle = atan2(0, position.x);
    result = this->_rayCaster->sendRay(this->_position, angle, 100);
    if (ABS(this->_position.x - result.coords.x) > ABS(this->_movement.x)) {
        this->_position.x += position.x;
    }
    angle = atan2(position.y, 0);
    result = this->_rayCaster->sendRay(this->_position, angle, 100);
    if (ABS(this->_position.y - result.coords.y) > ABS(this->_movement.y)) {
        this->_position.y += position.y;
    }
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

int AEntity::distance(IEntity &entity) const
{
    sf::Vector2f epos = entity.getPosition();

    return (sqrt((epos.x - _position.x ) * (epos.x - _position.x) + (epos.y - _position.y) * (epos.y - _position.y)));
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

double AEntity::getAngle(void)
{
    return (this->_angle);
}

void AEntity::updateAngle(void)
{
    if (this->_movement.y != 0 || this->_movement.x != 0)
        this->_angle = atan2(this->_movement.y, this->_movement.x);
}

void AEntity::setBufferSound(std::string son)
{
    if (!_buff_sound.loadFromFile(son)){
        std::cout << "Error loading sond" << _name << std::endl;
        exit(1);
    }
}

// void AEntity::setBufferSound(std::string son)
// {
//     if (!_buff_sound.loadFromFile(son)){
//         std::cout << "Error loading sond" << _name << std::endl;
//         exit(1);
//     }
// }
