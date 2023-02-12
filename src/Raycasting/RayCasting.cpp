/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** RayCasting
*/

#include "RayCasting.hpp"

RayCasting::RayCasting(Map &map) : _map(map)
{
}

RayCasting::~RayCasting()
{
}

static void getNextIntersectPosibilities(sf::Vector2f *nextIntersect, sf::Vector2f intersectPos, sf::Vector2f rayDir)
{
    nextIntersect[HORI].x = (1 - GET_FLOATANT_PART(intersectPos.x)) - (rayDir.x < 0);
    if (IS_BETWEEN(nextIntersect[HORI].x, -0.000001, 0.000001))
        nextIntersect[HORI].x = IS_SIGN_COEF(rayDir.x);

    nextIntersect[HORI].y = rayDir.y * ABS(nextIntersect[HORI].x / rayDir.x);


    nextIntersect[VERT].y = (1 - GET_FLOATANT_PART(intersectPos.y)) - (rayDir.y < 0);
    if (IS_BETWEEN(nextIntersect[VERT].y, -0.000001, 0.000001))
        nextIntersect[VERT].y = IS_SIGN_COEF(rayDir.y);

    nextIntersect[VERT].x = rayDir.x * ABS(nextIntersect[VERT].y / rayDir.y);
}

static void getNextIntersectLength(sf::Vector2f *nextIntersect, double *nextIntersectLen)
{
    nextIntersectLen[HORI] = sqrt(nextIntersect[HORI].x * nextIntersect[HORI].x +
                               nextIntersect[HORI].y * nextIntersect[HORI].y);
    nextIntersectLen[VERT] = sqrt(nextIntersect[VERT].x * nextIntersect[VERT].x +
                               nextIntersect[VERT].y * nextIntersect[VERT].y);
}

void setFixedPos(sf::Vector2<long> &fixedPos, sf::Vector2<long> pos, sf::Vector2<long> off, sf::Vector2f intersectPos)
{
    fixedPos.x = pos.x - off.x * (GET_FLOATANT_PART(intersectPos.x) == 0);
    fixedPos.y = pos.y - off.y * (GET_FLOATANT_PART(intersectPos.y) == 0);
}

t_RayResult RayCasting::sendRay(sf::Vector2f pPos, double direction, double maxRange)
{
    t_RayResult result;
    double len = 0;
    double nextIntersectLen[2];
    sf::Vector2f rayDir(cos(direction), sin(direction));
    sf::Vector2f intersectPos(pPos);
    sf::Vector2f prevIntersectPos(pPos);
    sf::Vector2f nextIntersect[2];
    sf::Vector2<long> off((rayDir.x < 0), (rayDir.y < 0));
    sf::Vector2<long> pos(pPos);
    sf::Vector2<long> fixedPos;
    t_RayCollideSide side = SIDE_UNDEF;

    rayDir.x = (rayDir.x == 0) ? 0.000001 : rayDir.x;
    rayDir.y = (rayDir.y == 0) ? 0.000001 : rayDir.y;
    setFixedPos(fixedPos, pos, off, intersectPos);

    while (len < maxRange && 
    fixedPos.x >= 0 && fixedPos.x < this->_map.getWidth() && 
    fixedPos.y >= 0 && fixedPos.y < this->_map.getHeight() && 
    this->_map[fixedPos.y * this->_map.getWidth() + fixedPos.x] == 0) {
        getNextIntersectPosibilities(nextIntersect, intersectPos, rayDir);
        getNextIntersectLength(nextIntersect, nextIntersectLen);
        side = (nextIntersectLen[HORI] < nextIntersectLen[VERT]) ? HORI : VERT;
        prevIntersectPos = intersectPos;
        intersectPos += nextIntersect[side];
        len += ABS(nextIntersectLen[side]);
        pos.x = static_cast<long>(intersectPos.x);
        pos.y = static_cast<long>(intersectPos.y);
        setFixedPos(fixedPos, pos, off, intersectPos);
    }
    result.wallFound = len < maxRange;
    result.coords = intersectPos;
    result.direction.x = cos(direction);
    result.direction.y = sin(direction);
    result.side = side;
    return (result);
}
