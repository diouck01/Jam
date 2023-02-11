#include "menu.hpp"
#include "Player.hpp"
#include "MainMenu.hpp"
#include "EndMenu.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "DardDesVilles");
    Framerate fps;
    sf::Event event;
    std::vector<sf::Sprite> spriteDraw;
    std::vector<sf::Text> textDraw;
    //MainMenu menu(window, event);
    EndMenu menu(window);
    
    menu.loadScene(NULL, NULL);
    while (window.isOpen()) {
        window.pollEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }
        
        window.clear();
        menu.run(NULL, NULL);
        window.display();

        // fps.capFramerate();
        // fps.printLog();
    }
    return 0;
}
