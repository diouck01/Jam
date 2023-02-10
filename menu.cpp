#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

const int WIDTH = 1280;
const int HEIGHT = 720;

void set_music(sf::Music &music, std::string name, int volume)
{
    if (!music.openFromFile(name))
    {
        std::cout << "Error loading music" << std::endl;
        exit(1);
    }
    music.setVolume(volume);
    music.setLoop(true);
    music.play();
}

void set_text(sf::Text &text, std::string str, sf::Color color, sf::Vector2f pos, int x) 
{
    text.setString(str);
    text.setCharacterSize(80);
    text.setFillColor(color);
    pos.x += x;
    text.setPosition(pos);
}

int main()
{
    //WIndow
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My SFML Platformer");
    sf::Clock clock;

    //Music
    sf::Music music;
    set_music(music, "menu_drill.ogg", 10);
    music.play();

    //Img
    sf::Texture bee;
    if (!bee.loadFromFile("sfx/perso.png"))
    {
        std::cout << "Error loading bee" << std::endl;
        exit(1);
    }
    sf::Sprite perso;
    perso.setTexture(bee);
    perso.scale(2, 2);
    perso.setPosition(800, 50);

    //Font
    sf::Font font;
    if (!font.loadFromFile("gunplay-3d.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
        return 1;
    }
    
    //Title
    sf::Text text;
    sf::Vector2f pos_text(50, 0);
    text.setFont(font);
    set_text(text, "Dard Des Villes", sf::Color::Yellow, pos_text, 0);

    //Background
    sf::Texture backgroundT;
    if (!backgroundT.loadFromFile("background.jpg"))
    {
        std::cout << "Error loading background texture" << std::endl;
        return 1;
    }
    sf::Sprite background(backgroundT);

    //Button
    sf::Texture button_texture;
    if (!button_texture.loadFromFile("sfx/button1.png"))
    {
        std::cout << "Error loading button" << std::endl;
        return 1;
    }
    sf::Sprite button(button_texture);
    sf::Vector2f vec_button(200, 250);
    sf::Text play;
    play.setFont(font);
    set_text(play, "PLAY", sf::Color::Red, vec_button, 50);
    button.setPosition(vec_button);
    sf::Sprite button2(button_texture);
    sf::Vector2f vec_button2(200, 500);
    sf::Text quit;
    quit.setFont(font);
    set_text(quit, "QUIT", sf::Color::Red, vec_button2, 50);
    button2.setPosition(vec_button2);

    //easter_egg
    sf::SoundBuffer buff_sound;
    if (!buff_sound.loadFromFile("easter_egg.ogg"))
    {
        std::cout << "Error loading zombie" << std::endl;
        return 1;
    }
    sf::Sound sound;
    sound.setBuffer(buff_sound);
    sound.setVolume(30);


    sf::Event event;
    int i = 0;
    while (window.isOpen()) {
        window.pollEvent(event);
        if (i == 2 || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            music.stop();
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.x > button.getPosition().x && event.mouseButton.x < button.getPosition().x + button.getTexture()->getSize().x && 
                event.mouseButton.y > button.getPosition().y && event.mouseButton.y < button.getPosition().y + button.getTexture()->getSize().y &&
                event.mouseButton.button == sf::Mouse::Left)
                i = 1;
            if (event.mouseButton.x > button2.getPosition().x && event.mouseButton.x < button2.getPosition().x + button2.getTexture()->getSize().x && 
                event.mouseButton.y > button2.getPosition().y && event.mouseButton.y < button2.getPosition().y + button2.getTexture()->getSize().y &&
                event.mouseButton.button == sf::Mouse::Left)
                i = 2;
            if (event.mouseButton.x > 950 && event.mouseButton.x < 990 && 
                event.mouseButton.y > 580 && event.mouseButton.y < 590 &&
                event.mouseButton.button == sf::Mouse::Left)
                sound.play();
        }
        window.clear();
        window.draw(background);
        window.draw(perso);
        window.draw(text);
        window.draw(button);
        window.draw(button2);
        window.draw(play);
        window.draw(quit);
        window.display();
    }

    return 0;
}