// /*
// ** EPITECH PROJECT, 2023
// ** Jam
// ** File description:
// ** main
// */

// #include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
// #include <iostream>
// #include <unistd.h>
// #include "Framerate.hpp"

// const int WIDTH = 1280;
// const int HEIGHT = 720;

// void set_music(sf::Music &music, std::string name, int volume)
// {
//     if (!music.openFromFile(name))
//     {
//         std::cout << "Error loading music" << std::endl;
//         exit(1);
//     }
//     music.setVolume(volume);
//     music.setLoop(true);
//     music.play();
// }

// void set_text(sf::Text &text, std::string str, sf::Color color, sf::Vector2f pos, int x) 
// {
//     text.setString(str);
//     text.setCharacterSize(80);
//     text.setFillColor(color);
//     pos.x += x;
//     text.setPosition(pos);
// }

// int main(void)
// {
//     sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "DardDesVilles");
//     Framerate fps;
//     sf::Event event;

//     //Music
//     sf::Music music;
//     set_music(music, "menu_drill.ogg", 10);
//     music.play();

//     //Img
//     sf::Texture bee;
//     if (!bee.loadFromFile("sfx/perso.png"))
//     {
//         std::cout << "Error loading bee" << std::endl;
//         exit(1);
//     }
//     sf::Sprite perso;
//     perso.setTexture(bee);
//     perso.scale(2, 2);
//     perso.setPosition(800, 50);

//     //Font
//     sf::Font font;
//     if (!font.loadFromFile("gunplay-3d.ttf"))
//     {
//         std::cout << "Error loading font" << std::endl;
//         return 1;
//     }
    
//     //Title
//     sf::Text text;
//     sf::Vector2f pos_text(50, 0);
//     text.setFont(font);
//     set_text(text, "Dard Des Villes", sf::Color::Yellow, pos_text, 0);

//     //Background
//     sf::Texture backgroundT;
//     if (!backgroundT.loadFromFile("background.jpg"))
//     {
//         std::cout << "Error loading background texture" << std::endl;
//         return 1;
//     }
//     sf::Sprite background(backgroundT);

//     //Button
//     sf::Texture button_texture;
//     if (!button_texture.loadFromFile("sfx/button1.png"))
//     {
//         std::cout << "Error loading button" << std::endl;
//         return 1;
//     }
//     sf::Sprite button(button_texture);
//     sf::Vector2f vec_button(200, 250);
//     sf::Text play;
//     play.setFont(font);
//     set_text(play, "PLAY", sf::Color::Red, vec_button, 50);
//     button.setPosition(vec_button);
//     sf::Sprite button2(button_texture);
//     sf::Vector2f vec_button2(200, 500);
//     sf::Text quit;
//     quit.setFont(font);
//     set_text(quit, "QUIT", sf::Color::Red, vec_button2, 50);
//     button2.setPosition(vec_button2);

//     //easter_egg
//     sf::SoundBuffer buff_sound;
//     if (!buff_sound.loadFromFile("easter_egg.ogg"))
//     {
//         std::cout << "Error loading zombie" << std::endl;
//         return 1;
//     }
//     sf::Sound sound;
//     sound.setBuffer(buff_sound);
//     sound.setVolume(30);
//     int i = 0;

//     while (window.isOpen()) {
//         window.pollEvent(event);
//         if (event.type == sf::Event::Closed)
//             window.close();
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//             window.close();
//         window.clear();
//         // All display thing must be here

//         if (i == 2 || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
//             music.stop();
//             window.close();
//         }
//         if (event.type == sf::Event::MouseButtonPressed)
//         {
//             if (event.mouseButton.x > button.getPosition().x && event.mouseButton.x < button.getPosition().x + button.getTexture()->getSize().x && 
//                 event.mouseButton.y > button.getPosition().y && event.mouseButton.y < button.getPosition().y + button.getTexture()->getSize().y &&
//                 event.mouseButton.button == sf::Mouse::Left)
//                 i = 1;
//             if (event.mouseButton.x > button2.getPosition().x && event.mouseButton.x < button2.getPosition().x + button2.getTexture()->getSize().x && 
//                 event.mouseButton.y > button2.getPosition().y && event.mouseButton.y < button2.getPosition().y + button2.getTexture()->getSize().y &&
//                 event.mouseButton.button == sf::Mouse::Left)
//                 i = 2;
//             if (event.mouseButton.x > 950 && event.mouseButton.x < 990 && 
//                 event.mouseButton.y > 580 && event.mouseButton.y < 590 &&
//                 event.mouseButton.button == sf::Mouse::Left)
//                 sound.play();
//         }
//         window.clear();
//         window.draw(background);
//         window.draw(perso);
//         window.draw(text);
//         window.draw(button);
//         window.draw(button2);
//         window.draw(play);
//         window.draw(quit);
//         window.display();

//         window.display();
//         fps.capFramerate();
//         fps.printLog();
//     }

//     return 0;
// }

// // sf::Sprite move(sf::Sprite player, sf::Clock &clock, sf::Listener listener)
// // {
// //     (void)clock;
// //     if (player.getPosition().x > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
// //         player.move(-0.25f, 0.0f);
// //     if (player.getPosition().x < WIDTH - player.getTextureRect().width * player.getScale().x && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
// //         player.move(0.25f, 0.0f);
// //     if (player.getPosition().y > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
// //         player.move(0.0f, -0.25f);
// //     if (player.getPosition().y < HEIGHT - player.getTextureRect().height * player.getScale().y && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
// //         player.move(0.0f, 0.25f);
// //     listener.setPosition(player.getPosition().x, player.getPosition().y, player.getPosition().y);
// //     return player;
// // }

// // int main()
// // {
// //     sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My SFML Platformer");
// //     sf::Clock clock;

// //     sf::Texture playerTexture;
// //     if (!playerTexture.loadFromFile("player.png"))
// //     {
// //         std::cout << "Error loading player texture" << std::endl;
// //         return 1;
// //     }
// //     sf::Sprite player(playerTexture, sf::IntRect(5,40,20, 25));
// //     player.setScale(1, 1);
// //     sf::Vector2f vec_p;
// //     vec_p.x = WIDTH/2;
// //     vec_p.y = HEIGHT/2;
// //     player.setPosition(vec_p);

// //     sf::Texture ZombiTexture;
// //     if (!playerTexture.loadFromFile("square.png"))
// //     {
// //         std::cout << "Error loading player texture" << std::endl;
// //         return 1;
// //     }
// //     sf::Sprite zombi(ZombiTexture, sf::IntRect(5,40,20, 25));
// //     sf::Vector2f vec_z;
// //     vec_z.x = 0;
// //     vec_z.y = 0;
// //     zombi.setScale(1, 1);
// //     zombi.setPosition(vec_z);

// //     sf::Listener listener;
// //     listener.setPosition(vec_p.x, vec_p.y, vec_p.y);
// //     listener.setGlobalVolume(50.f);

// //     sf::SoundBuffer buff_sound;
// //     if (!buff_sound.loadFromFile("zombie.ogg"))
// //     {
// //         std::cout << "Error loading zombie" << std::endl;
// //         return 1;
// //     }
// //     sf::Sound sound;
// //     sound.setBuffer(buff_sound);
// //     sound.setPosition(vec_z.x, vec_z.y, vec_z.y);
// //     sound.setMinDistance(20.f);

// //     while (window.isOpen()) {
// //         player = move(player, clock, listener);
// //         vec_z = zombi.getPosition();
// //         zombi.setPosition(vec_z + ((player.getPosition() - vec_z) * 0.00005f));
// //         sound.setPosition(zombi.getPosition().x, zombi.getPosition().y, zombi.getPosition().y);
// //         if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
// //             sound.play();
// //         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
// //             window.close();
        
// //         // window.clear();
// //         window.draw(player);
// //         window.draw(zombi);
// //         window.display();
// //     }

// //     return 0;
// // }

// #include "Map.hpp"
// #include <iostream>

// int main(void)
// {
//     srand(time(nullptr));
//     Map map(20, 20);
    

//     unsigned int pos = map.random_empty_position();
    
//     map[pos] = 3;
//     std::cout << map << std::endl;
//     return (0);
// }

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <unistd.h>

#include "Map.hpp"
#include "MapDisplayer.hpp"
#include "Framerate.hpp"
#include "Player.hpp"

int main(void) 
{
    srand(time(nullptr));

    sf::RenderWindow window(sf::VideoMode(1280, 720), "DardDesVilles");
    Framerate fps;
    sf::Event event;
    Map map(20, 20);
    Player p;
    MapDisplayer mdisplayer(map, window, p);
    

    map.random_empty_position();
    std::cout << map << std::endl;
    while (window.isOpen()) {
        window.pollEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        window.clear();

        // All display thing must be here

        p.getInput();
        p.move();
        mdisplayer.showMap();

        window.display();
        fps.capFramerate();
        fps.printLog();
    }

    return 0;
}
