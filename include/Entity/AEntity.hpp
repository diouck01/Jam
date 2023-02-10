/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** AEntity
*/

#pragma once

#include "IEntity.hpp"

class AEntity: public IEntity {
public:
    AEntity();
    ~AEntity();

    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f position);
    void setPosition(double x, double y);
    void setMove(sf::Vector2f position);
    void setMove(double x, double y);
    void move(sf::Vector2f position);
    void move(double x, double y);
    void move(void);

    double getVectorLength(sf::Vector2f vect) const;
    double getVectorDot(sf::Vector2f v1, sf::Vector2f v2) const;
    void setVectorNorm(sf::Vector2f &vect);
    void updateAngle(void);

protected:
    sf::Vector2f _position;
    sf::Vector2f _movement;
    double _angle = 0;
    double _speed = 5;
};
