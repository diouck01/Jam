/*
** EPITECH PROJECT, 2023
** AMob
** File description:
** The header contains all the abstract class AMob.
*/

#pragma once

#include "AEntity.hpp"
#include "Player.hpp"

class AMob: public AEntity {
    public:
        AMob(Map &map);

        sf::Sound getSound() const;
        void MoveToPlayer(Player &p);
        void generatePath(void);
        void moveToPath(void);
        void clearPath(void);
        void setSoundTrigger(int soundTrigger);
        void resetSoundTrigger(void);
        void incrementSoundTrigger(int soundTrigger);

        void setBufferSound(std::string son);
        void setSoundPos(sf::Vector2f pos) {_sound.setPosition(pos.x, pos.y, pos.y); _sound.setMinDistance(20.f);};
        sf::Sound *getSound() {return &_sound;};

    protected:
        sf::Vector2f _target;
        int _soundTriggerMax = 3;
        int _soundTrigger = 0;
        std::vector<sf::Vector2f> _path;
        
};
