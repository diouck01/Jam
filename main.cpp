#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

const int WIDTH = 1280;
const int HEIGHT = 720;

sf::Sprite move(sf::Sprite player, sf::Clock &clock, sf::Listener listener)
{
    if (player.getPosition().x > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        player.move(-0.25f, 0.0f);
    if (player.getPosition().x < WIDTH - player.getTextureRect().width * player.getScale().x && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player.move(0.25f, 0.0f);
    if (player.getPosition().y > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        player.move(0.0f, -0.25f);
    if (player.getPosition().y < HEIGHT - player.getTextureRect().height * player.getScale().y && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player.move(0.0f, 0.25f);
    listener.setPosition(player.getPosition().x, player.getPosition().y, player.getPosition().y);
    return player;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "My SFML Platformer");
    sf::Clock clock;

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("player.png"))
    {
        std::cout << "Error loading player texture" << std::endl;
        return 1;
    }
    sf::Sprite player(playerTexture, sf::IntRect(5,40,20, 25));
    player.setScale(1, 1);
    sf::Vector2f vec_p;
    vec_p.x = WIDTH/2;
    vec_p.y = HEIGHT/2;
    player.setPosition(vec_p);

    sf::Texture ZombiTexture;
    if (!playerTexture.loadFromFile("square.png"))
    {
        std::cout << "Error loading player texture" << std::endl;
        return 1;
    }
    sf::Sprite zombi(ZombiTexture, sf::IntRect(5,40,20, 25));
    sf::Vector2f vec_z;
    vec_z.x = 0;
    vec_z.y = 0;
    zombi.setScale(1, 1);
    zombi.setPosition(vec_z);

    sf::Listener listener;
    listener.setPosition(vec_p.x, vec_p.y, vec_p.y);
    listener.setGlobalVolume(50.f);

    sf::SoundBuffer buff_sound;
    if (!buff_sound.loadFromFile("zombie.ogg"))
    {
        std::cout << "Error loading zombie" << std::endl;
        return 1;
    }
    sf::Sound sound;
    sound.setBuffer(buff_sound);
    sound.setPosition(vec_z.x, vec_z.y, vec_z.y);
    sound.setMinDistance(20.f);

    while (window.isOpen()) {
        player = move(player, clock, listener);
        vec_z = zombi.getPosition();
        zombi.setPosition(vec_z + ((player.getPosition() - vec_z) * 0.00005f));
        sound.setPosition(zombi.getPosition().x, zombi.getPosition().y, zombi.getPosition().y);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
            sound.play();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        
        window.clear();
        window.draw(player);
        window.draw(zombi);
        window.display();
    }

    return 0;
}