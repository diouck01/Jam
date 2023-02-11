/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Framerate
*/

#pragma once

#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Framerate {
public:
    Framerate();
    ~Framerate();

    void capFramerate(void);
    void SetFramerateCap(std::size_t cappedFps);
    void updateCappedTime(void);
    void printLog(void);

protected:
    sf::Clock _clock;
    sf::Clock _logClock;
    const std::size_t _timeUnit = 1000000; 
    std::size_t _cappedFps = 60;
    std::size_t _elapsedTime;
    std::size_t _logElapsedTime;
    std::size_t _cappedTime = _timeUnit / _cappedFps;
    double _currentFps = 0;
private:
};

