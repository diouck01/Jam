#include "menu.hpp"
#include "Player.hpp"
#include "MainMenu.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "DardDesVilles");
    Framerate fps;
    sf::Event event;
    std::vector<sf::Sprite> spriteDraw;
    std::vector<sf::Text> textDraw;
    MainMenu menu(window);
    // menuConstructor(spriteDraw, textDraw);
     //Music
    sf::Music music;
    set_music(music, "sfx/menu/menu_drill.ogg", 10);
    music.play();

    //easter_egg
    Player ben;
    
    menu.loadScene(NULL, NULL);
    int i = 0;
    while (window.isOpen()) {
        window.pollEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
        if (i == 2 || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }
        mouse_activity(i, event, spriteDraw[1], spriteDraw[2], menu._easter_egg);

        window.clear();
        if (i != 0)
            music.stop();
        if (i == 0)
            menu.run(NULL, NULL);
        if (i == 1) {
            if (ben.getSound()->getStatus() == sf::SoundSource::Stopped && sf::Keyboard::isKeyPressed(sf::Keyboard::L))
                ben.getSound()->play();
        }
        window.display();

        // fps.capFramerate();
        // fps.printLog();
    }
    return 0;
}
