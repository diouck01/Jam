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
#include "Game.hpp"
#include "EndMenu.hpp"
#include "Lose.hpp"
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
    Game game(window);
    EndMenu endmenu(window);
    Lose lose(window);

    SceneManager scene;
    scene.addMenu("MainMenu", &mainmenu);
    scene.addMenu("Tuto", &tuto);
    scene.addMenu("Game", &game);
    scene.addMenu("EndMenu", &endmenu);
    scene.addMenu("Lose", &lose);

    while (window.isOpen()) {
        window.pollEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        window.clear();
        scene.display(NULL);
        window.display();
        fps.capFramerate();
        //fps.printLog();
    }

    return 0;
}
