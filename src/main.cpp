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
>>>>>>> 26217ff ([add]son perso)

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
    //menuConstructor(spriteDraw, textDraw);
     //Music
    sf::Music music;
    set_music(music, "sfx/menu/menu_drill.ogg", 10);
    music.play();

    //Font
    sf::Font font;
    if (!font.loadFromFile("sfx/menu/gunplay-3d.ttf"))
        error("Error loading font");
    
    //Title
    sf::Text text;
    sf::Vector2f pos_text(50, 0);
    text.setFont(font);
    set_text(text, "Dard Des Villes", sf::Color::Yellow, pos_text, 0);
    textDraw.push_back(text);

    //Background
    sf::Texture backgroundT;
    if (!backgroundT.loadFromFile("sfx/menu/background.jpg"))
        error("Error loading background texture");
    sf::Sprite background(backgroundT);
    spriteDraw.push_back(background);

    //PLAY
    sf::Texture button_texture;
    if (!button_texture.loadFromFile("sfx/menu/button1.png"))
        error("Error loading button");
    sf::Sprite button(button_texture);
    sf::Vector2f vec_button(200, 250);
    sf::Text play;
    play.setFont(font);
    set_text(play, "PLAY", sf::Color::Red, vec_button, 50);
    button.setPosition(vec_button);
    spriteDraw.push_back(button);
    textDraw.push_back(play);

    //QUIT
    sf::Sprite button2(button_texture);
    sf::Vector2f vec_button2(200, 500);
    sf::Text quit;
    quit.setFont(font);
    set_text(quit, "QUIT", sf::Color::Red, vec_button2, 50);
    button2.setPosition(vec_button2);
    spriteDraw.push_back(button2);
    textDraw.push_back(quit);

    //Img
    sf::Texture bee;
    if (!bee.loadFromFile("sfx/menu/perso.png"))
        error("Error loading bee");
    sf::Sprite perso;
    perso.setTexture(bee);
    perso.scale(2, 2);
    perso.setPosition(800, 50);
    spriteDraw.push_back(perso);

    //easter_egg
    sf::SoundBuffer buff_sound;
    if (!buff_sound.loadFromFile("sfx/menu/easter_egg.ogg"))
        error("Error loading easter_egg");
    sf::Sound sound;
    sound.setBuffer(buff_sound);
    sound.setVolume(30);
    Player ben;
    
    int i = 1;
>>>>>>> 26217ff ([add]son perso)

    map.random_empty_position();
    std::cout << map << std::endl;
    while (window.isOpen()) {
        window.pollEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
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
            drawWindow(window, spriteDraw, textDraw);
        if (i == 1) {
            if (ben.getSound()->getStatus() == sf::SoundSource::Stopped && sf::Keyboard::isKeyPressed(sf::Keyboard::L))
                ben.getSound()->play();
        }
        window.display();

        // fps.capFramerate();
        // fps.printLog();
>>>>>>> 26217ff ([add]son perso)
    }

    return 0;
}
