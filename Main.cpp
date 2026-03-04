#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <iostream>

#include "isa.c"

int main()
{
    std::cout << "SFML Version: " 
              << SFML_VERSION_MAJOR << "." 
              << SFML_VERSION_MINOR << "." 
              << SFML_VERSION_PATCH << std::endl;
    sf::RenderWindow window(sf::VideoMode({800, 800}), "SFML works!");
    sf::Texture texture;
    if(!texture.loadFromMemory(
        isa_jpg,isa_jpg_len)){
            std::cerr <<"What the fuck the image won't load!" << std::endl;
        return -1;
    } 
    
    sf::Sprite sprite(texture);
    sf::Clock clock;
    float radians_per_second = 0.9;
    sf::FloatRect bounds = sprite.getLocalBounds();

    // 2. Set the origin to the center (half width, half height)
    sprite.setOrigin(bounds.getCenter());
    sprite.move({400, 400});

    int speed = 200;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        sf::Time elapsed = clock.restart();
        const auto dt = elapsed.asSeconds();

        sprite.rotate(sf::radians(radians_per_second * dt));

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            sprite.move({0, -speed*dt});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            sprite.move({0, speed*dt});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
           sprite.move({-speed*dt, 0});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            sprite.move({speed*dt, 0}); 
        }
       

        window.clear();
        window.draw(sprite);
        window.display();
    }
}