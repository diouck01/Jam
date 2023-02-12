/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** RayCasting
*/

#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Map.hpp"

class Map;

#define ABS(nbr) (((nbr) < 0) ? -(nbr) : (nbr))
#define IS_NEG(nbr) ((nbr) < 0)
#define IS_SIGN_COEF(nbr) (((nbr) < 0) * -1 + 1 * ((nbr) >= 0))
#define IS_BETWEEN(nbr, nbrA, nbrB) ((nbr) > (nbrA) && (nbr) < (nbrB))
#define GET_FLOATANT_PART(nbr) ((nbr) - static_cast<long>(nbr))

typedef enum e_RayCollideSide {
    HORI,
    VERT,
    SIDE_UNDEF
} t_RayCollideSide;

typedef struct s_RayResult {
    bool wallFound;
    sf::Vector2f coords;
    sf::Vector2f direction;
    t_RayCollideSide side;
} t_RayResult;

class RayCasting {
public:
    RayCasting(Map &map);
    ~RayCasting();

    t_RayResult sendRay(sf::Vector2f pPos, double direction, double maxRange); 
protected:
    Map &_map;
private:
};
