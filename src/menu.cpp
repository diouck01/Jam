#include "menu.hpp"


void error(std::string str)
{
    std::cout << str << std::endl;
    exit(1);
}

void drawWindow(sf::RenderWindow &window, std::vector<sf::Sprite> spriteDraw, std::vector<sf::Text> textDraw)
{
    for (auto element : spriteDraw) {
        window.draw(element);
    }
    for (auto element : textDraw) {
        window.draw(element);
    }
}

void mouse_activity(int &i, sf::Event event, sf::Sprite button, sf::Sprite button2, sf::Sound &sound)
{
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
            event.mouseButton.button == sf::Mouse::Left) {
            sound.play();
        }
    }
}

void set_music(sf::Music &music, std::string name, int volume)
{
    if (!music.openFromFile(name))
    {
        std::cout << "Error loading music" << std::endl;
        exit(1);
    }
    music.setVolume(volume);
    music.setLoop(true);
}

void set_text(sf::Text &text, std::string str, sf::Color color, sf::Vector2f pos, int x) 
{
    text.setString(str);
    text.setCharacterSize(80);
    text.setFillColor(color);
    pos.x += x;
    text.setPosition(pos);
}

void menuConstructor(std::vector<sf::Sprite> &spriteDraw, std::vector<sf::Text> &textDraw)
{
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

}