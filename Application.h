#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>



class Application{
    public:
    Application();
    bool IsRunnning() const;
    void ProcessEvents();
    void Update();
    void Render();

    private:
    sf::RenderWindow window_;
    void HandleEvent(const sf::Event::Closed&);
    void HandleEvent(const sf::Event::Resized& resized);
    void HandleEvent(const sf::Event::FocusLost&);
    void HandleEvent(const sf::Event::FocusGained&);
    void HandleEvent(const sf::Event::KeyPressed& key);
    void HandleEvent(const sf::Event::KeyReleased& key);
    void HandleEvent(const sf::Event::MouseButtonPressed& mouse);
    void HandleEvent(const sf::Event::MouseButtonReleased& mouse);
    void HandleEvent(const sf::Event::MouseWheelScrolled& scroll);
    void HandleEvent(const auto&){} // Default handler do nothing
};