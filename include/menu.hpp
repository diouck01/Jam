/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <unistd.h>
#include <vector>
#include "Framerate.hpp"

const int WIDTH = 1280;
const int HEIGHT = 720;

void menuConstructor(std::vector<sf::Sprite> &spriteDraw, std::vector<sf::Text> &textDraw);
void mouse_activity(int &i, sf::Event event, sf::Sprite button, sf::Sprite button2, sf::Sound &sound);
void drawWindow(sf::RenderWindow &window, std::vector<sf::Sprite> spriteDraw, std::vector<sf::Text> textDraw);
void error(std::string str);
void set_music(sf::Music &music, std::string name, int volume);
void set_text(sf::Text &text, std::string str, sf::Color color, sf::Vector2f pos, int x);

#endif /* !MENU_HPP_ */
