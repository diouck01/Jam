/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <unistd.h>

#include "Map.hpp"
#include "MapDisplayer.hpp"
#include "Framerate.hpp"
#include "Player.hpp"
#include "MainMenu.hpp"
#include "Tuto.hpp"
#include "EndMenu.hpp"
#include "SceneManager.hpp"
#include "RayCasting.hpp"

int main(void) 
{
    srand(time(nullptr));

    sf::RenderWindow window(sf::VideoMode(1280, 720), "DardDesVilles");
    Framerate fps;
    sf::Event event;
    MainMenu mainmenu(window, event);
    Tuto tuto(window);
    EndMenu endmenu(window);
    SceneManager scene;
    scene.addMenu("MainMenu", &mainmenu);
    scene.addMenu("Tuto", &tuto);
    scene.addMenu("EndMenu", &endmenu);
    while (window.isOpen()) {
        window.pollEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        window.clear();
        scene.display(NULL);
        window.display();

        // All display thing must be here

        p.getInput();
        p.move();
        mdisplayer.showMap();
        mdisplayer.drawEcho();
        // result = raycaster.sendRay(p.getAngle(), 5);
        // std::cout << result.coords.x << ", " << result.coords.y << std::endl;

        // for (double a = -M_PI; a < M_PI; a += M_PI / 20) {
        //     result = raycaster.sendRay(p.getPosition(), p.getAngle() + a, 100);
        //     line[1].position.x = (p.getPosition().x - result.coords.x) * -100 + 640;
        //     line[1].position.y = (p.getPosition().y - result.coords.y) * -100 + 360;
        //     window.draw(line, 2, sf::Lines);
        // }

        // line[1].position.x = 640 + cos(p.getAngle()) * 100;
        // line[1].position.y = 360 + sin(p.getAngle()) * 100;
        sf::RectangleShape block(sf::Vector2f(5, 5));
        block.setPosition(638, 358);
        block.setFillColor(sf::Color(255, 255, 255));
        window.draw(block);        

        window.display();
        fps.capFramerate();
        fps.printLog();
    }

    return 0;
}
