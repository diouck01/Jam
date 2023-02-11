<<<<<<< HEAD
/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** main
*/
=======
#include "menu.hpp"
#include "Player.hpp"
<<<<<<< HEAD
>>>>>>> 26217ff ([add]son perso)
=======
#include "MainMenu.hpp"
<<<<<<< HEAD
>>>>>>> 2785aa3 ([add]menumanager)
=======
#include "EndMenu.hpp"
<<<<<<< HEAD
>>>>>>> 8d864be ([add]End menu)
=======
#include "SceneManager.hpp"
>>>>>>> 3eee9ce ([add]scenemanager + bug display)

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <unistd.h>

#include "Map.hpp"
#include "MapDisplayer.hpp"
#include "Framerate.hpp"
#include "Player.hpp"
// #include "RayCasting.hpp"

int main(void) 
{
    srand(time(nullptr));

    sf::RenderWindow window(sf::VideoMode(1280, 720), "DardDesVilles");
    Framerate fps;
    sf::Event event;
<<<<<<< HEAD
<<<<<<< HEAD
    Map map(20, 20);
    Player p(map);
    MapDisplayer mdisplayer(map, window, p);
    RayCasting raycaster(map);
    t_RayResult result;
    // sf::Vertex line[] =
    // {
    //     sf::Vertex(sf::Vector2f(640, 360)),
    //     sf::Vertex(sf::Vector2f(640, 360))
    // };
=======
    std::vector<sf::Sprite> spriteDraw;
    std::vector<sf::Text> textDraw;
    //MainMenu menu(window, event);
    EndMenu menu(window);
    
<<<<<<< HEAD
<<<<<<< HEAD
    int i = 1;
>>>>>>> 26217ff ([add]son perso)
=======
=======
    menu.loadScene(NULL, NULL);
<<<<<<< HEAD
>>>>>>> 2785aa3 ([add]menumanager)
    int i = 0;
>>>>>>> c333893 ([add]menumanager)

    map.random_empty_position();
    std::cout << map << std::endl;
=======
>>>>>>> c6ef58e ([EDIT] Fix up a memory crash caused by mouse_activity)
=======
    MainMenu mainmenu(window, event);
    //mainmenu.loadScene(NULL, NULL);
    EndMenu endmenu(window);
    //endmenu.loadScene(NULL, NULL);
    SceneManager scene;
    scene.addMenu("MainMenu", &mainmenu);
    scene.addMenu("EndMenu", &endmenu);

>>>>>>> 3eee9ce ([add]scenemanager + bug display)
    while (window.isOpen()) {
        window.pollEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
<<<<<<< HEAD
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
=======
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
>>>>>>> c6ef58e ([EDIT] Fix up a memory crash caused by mouse_activity)
            window.close();
<<<<<<< HEAD
=======
        }
<<<<<<< HEAD
        mouse_activity(i, event, spriteDraw[1], spriteDraw[2], menu._easter_egg);

>>>>>>> 2785aa3 ([add]menumanager)
        window.clear();
<<<<<<< HEAD

        // All display thing must be here

        p.getInput();
        p.move();
        mdisplayer.showMap();
        // mdisplayer.drawEcho();

        sf::RectangleShape block(sf::Vector2f(5, 5));
        block.setPosition(638, 358);
        block.setFillColor(sf::Color(255, 255, 255));
        window.draw(block);        

        window.display();
        fps.capFramerate();
        fps.printLog();
=======
        if (i != 0)
            music.stop();
        if (i == 0)
            menu.run(NULL, NULL);
        if (i == 1) {
            if (ben.getSound()->getStatus() == sf::SoundSource::Stopped && sf::Keyboard::isKeyPressed(sf::Keyboard::L))
                ben.getSound()->play();
        }
=======
        
        window.clear();
<<<<<<< HEAD
        menu.run(NULL, NULL);
>>>>>>> c6ef58e ([EDIT] Fix up a memory crash caused by mouse_activity)
=======
        scene.display(NULL);
>>>>>>> 3eee9ce ([add]scenemanager + bug display)
        window.display();

        // fps.capFramerate();
        // fps.printLog();
>>>>>>> 26217ff ([add]son perso)
    }

    return 0;
}
