/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Framerate
*/

#include "Framerate.hpp"

Framerate::Framerate()
{
}

Framerate::~Framerate()
{
}


void Framerate::capFramerate(void)
{
    this->_elapsedTime = this->_clock.getElapsedTime().asMicroseconds();
    if (this->_cappedTime > this->_elapsedTime) {
        usleep(this->_cappedTime - this->_elapsedTime);
    }
    this->_logElapsedTime = this->_logClock.getElapsedTime().asMicroseconds();
    this->_currentFps = static_cast<double>(this->_timeUnit) / static_cast<double>(this->_logElapsedTime);
    this->_clock.restart();
    this->_logClock.restart();
}

void Framerate::SetFramerateCap(std::size_t cappedFps)
{
    this->_cappedFps = cappedFps;
    this->updateCappedTime();
}

void Framerate::updateCappedTime(void)
{
    this->_cappedTime = this->_timeUnit / this->_cappedFps;
}

void Framerate::printLog(void)
{   
    double potentialFps;

    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "\r";
    std::cout << std::setfill('0') << std::setw(6);
    std::cout << this->_currentFps << " FPS | USAGE: ";
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << std::setfill('0') << std::setw(6);
    potentialFps = static_cast<double>(this->_timeUnit) / static_cast<double>(this->_elapsedTime);
    std::cout << (this->_currentFps / potentialFps) * 100 << "%" << std::flush;
    
}
