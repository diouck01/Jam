/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** Player
*/

#pragma once

#include <iostream>
#include <vector>

#include "AEntity.hpp"
#include "RayCasting.hpp"

class Player: public AEntity {
public:
    Player(Map &map);
    ~Player();

    void setListener(sf::Vector2f pos) {_listener.setPosition(pos.x, pos.y, pos.y);}
    void getInput(void);

    void echo(double range, double width);
    void normalEcho(void);
    void strongEcho(void);
    std::vector<t_RayResult> &getEchoes(void);

protected:
    int _echoStrength = 0;
    sf::Listener _listener;
    std::vector<t_RayResult> _echoes;
private:
};
