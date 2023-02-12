/*
** EPITECH PROJECT, 2023
** AMob
** File description:
** The header contains all the abstract class AMob.
*/

#pragma once

#include "AEntity.hpp"

class AMob: public AEntity {
    public:
        AMob(Map &map);

        sf::Sound getSound() const;
        void generatePath(void);
        void moveToPath(void);
        void clearPath(void);
        void setSoundTrigger(int soundTrigger);
        void resetSoundTrigger(void);
        void incrementSoundTrigger(int soundTrigger);

    protected:
        sf::Vector2f _target;
        int _soundTriggerMax = 3;
        int _soundTrigger = 0;
        std::vector<sf::Vector2f> _path;
        
};
