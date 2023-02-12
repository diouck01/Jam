/*
** EPITECH PROJECT, 2023
** IEntity
** File description:
** The header contains the IEntity class.
*/

#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <exception>
#include <string>
#include <list>
#include <cmath>

class IEntity {
    public:
        class LoadingError : std::exception {
            public:
                explicit LoadingError(const std::string &message);
                virtual ~LoadingError() noexcept;
                virtual const char *what() const noexcept;
            private:
                const std::string &_msg;
        };
        IEntity() = default;

        virtual sf::Vector2f getPosition() const = 0;
        virtual void setPosition(sf::Vector2f position) = 0;
        virtual void setPosition(double x, double y) = 0;
        virtual void move(sf::Vector2f position) = 0;
        virtual void move(double x, double y) = 0;
        virtual int distance(IEntity &entity) const = 0;
};
