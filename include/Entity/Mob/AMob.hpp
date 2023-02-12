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
<<<<<<< HEAD
<<<<<<< HEAD
=======
        ~AMob();
=======
>>>>>>> 4b6dab9 ([Fix] Merge conflit fixed)

>>>>>>> 32b6e43 ([ADD] Raycasting/echo system and collisions)
        sf::Sound getSound() const;
        void moveToPath(void);
        void clearPath(void);
        void generatePath(void);
        void setSoundTrigger(int soundTrigger);
        void resetSoundTrigger(void);
        void incrementSoundTrigger(int soundTrigger);

    protected:
        sf::Vector2f _target;
        int _soundTriggerMax = 3;
        int _soundTrigger = 0;
        std::list<sf::Vector2f> _path;
        

};
