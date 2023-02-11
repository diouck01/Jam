/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** EndMenu
*/

#include "EndMenu.hpp"

EndMenu::EndMenu(sf::RenderWindow &window) : _window(window)
{
}

EndMenu::~EndMenu()
{
}

static void set_music(sf::Music &music, std::string name, int volume)
{
    if (!music.openFromFile(name))
    {
        std::cout << "Error loading music" << std::endl;
        exit(1);
    }
    music.setVolume(volume);
}

static void error(std::string str)
{
    std::cout << str << std::endl;
    exit(1);
}

static void set_text(sf::Text &text, std::string str, sf::Color color, sf::Vector2f pos, int x) 
{
    text.setString(str);
    text.setCharacterSize(200);
    text.setFillColor(color);
    pos.x += x;
    text.setPosition(pos);
}

void EndMenu::loadScene(SceneManager *manager, void *data)
{
    (void)manager;
    (void)data;
    //Music
    set_music(this->_music, "sfx/end/end.ogg", 10);
    _music.play();

    if (!this->_font.loadFromFile("sfx/menu/gunplay-3d.ttf"))
        error("Error loading font");
    
    if (!_backgroundTexture.loadFromFile("sfx/end/end.jpeg"))
        error("Error loading background texture");
    _background.setTexture(_backgroundTexture);


    sf::Vector2f pos_text(200, 200);
    _text.setFont(this->_font);
    set_text(_text, "YOU WIN", sf::Color::Red, pos_text, 0);
}

void EndMenu::unloadScene(SceneManager *manager, void *data)
{
    (void)manager;
    (void)data;
    this->_music.stop();
    _window.close();
}

void EndMenu::run(SceneManager *manager, void *data)
{
    (void)manager;
    (void)data;
    _window.draw(_background);
    _window.draw(_text);
    if (_music.getStatus() == sf::SoundSource::Stopped)
        unloadScene(manager, data);
}