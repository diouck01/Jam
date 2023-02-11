#include "menu.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "DardDesVilles");
    Framerate fps;
    sf::Event event;
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
    
    int i = 0;

    while (window.isOpen()) {
        window.pollEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
        if (i == 2 || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }
        mouse_activity(i, event, spriteDraw[1], spriteDraw[2], sound);

        window.clear();
        if (i == 0)
            drawWindow(window, spriteDraw, textDraw);
        window.display();

        fps.capFramerate();
        fps.printLog();
    }
    return 0;
}
