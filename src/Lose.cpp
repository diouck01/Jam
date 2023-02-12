/*
** EPITECH PROJECT, 2023
** Jam
** File description:
** Lose
*/

#include "Lose.hpp"

Lose::Lose(sf::RenderWindow &window) : _window(window)
{
}

Lose::~Lose()
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

void Lose::loadScene(SceneManager *manager, void *data)
{
    (void)manager;
    (void)data;

    if (!this->_font.loadFromFile("sfx/menu/gunplay-3d.ttf"))
        error("Error loading font");
    
    if (!_backgroundTexture.loadFromFile("sfx/end/end.jpeg"))
        error("Error loading background texture");
    _background.setTexture(_backgroundTexture);


    sf::Vector2f pos_text(200, 200);
    _text.setFont(this->_font);
    set_text(_text, "YOU WIN", sf::Color::Red, pos_text, 0);
}

void Lose::unloadScene(SceneManager *manager, void *data)
{
    (void)manager;
    (void)data;
    this->_music.stop();
    _window.close();
}

void Lose::run(SceneManager *manager, void *data)
{
    (void)manager;
    (void)data;
    static bool tmp = false;
    if (tmp == false) {
        std::srand (time(NULL));
        int tmp = std::rand()%4;
        if (tmp == 0)
            set_music(this->_music, "sfx/death/hoho_no.ogg", 10);
        if (tmp == 1)
            set_music(this->_music, "sfx/death/scream.ogg", 10);
        if (tmp == 2)
            set_music(this->_music, "sfx/death/mmmm.ogg", 10);
        if (tmp == 3)
            set_music(this->_music, "sfx/death/wah.ogg", 10);
        _music.play();
        tmp = true;
    }
    _window.draw(_background);
    _window.draw(_text);
    if (_music.getStatus() == sf::SoundSource::Stopped)
        unloadScene(manager, data);
}