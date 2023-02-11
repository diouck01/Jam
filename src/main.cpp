#include "menu.hpp"
#include "Player.hpp"
#include "MainMenu.hpp"
#include "EndMenu.hpp"
#include "SceneManager.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "DardDesVilles");
    Framerate fps;
    sf::Event event;
    MainMenu mainmenu(window, event);
    //mainmenu.loadScene(NULL, NULL);
    EndMenu endmenu(window);
    //endmenu.loadScene(NULL, NULL);
    SceneManager scene;
    scene.addMenu("MainMenu", &mainmenu);
    scene.addMenu("EndMenu", &endmenu);

    while (window.isOpen()) {
        window.pollEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }
        
        window.clear();
        scene.display(NULL);
        window.display();

        // fps.capFramerate();
        // fps.printLog();
    }
    return 0;
}
