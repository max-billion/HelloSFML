#include "Application.h"

Application::Application() : window_(sf::VideoMode({800, 800}), "SFML works!"){
  window_.setFramerateLimit(60);
}

bool Application::IsRunnning() const
{
    return window_.isOpen();
}

void Application::ProcessEvents()
{
    window_.handleEvents([this](const auto &event) { this->HandleEvent(event); });
}

void Application::Update()
{
}

void Application::Render()
{
    window_.clear();
    window_.display();
}

void Application::HandleEvent(const sf::Event::Closed &)
{
    window_.close();
}

void Application::HandleEvent(const sf::Event::Resized &resized)
{
}

void Application::HandleEvent(const sf::Event::FocusLost &)
{
}

void Application::HandleEvent(const sf::Event::FocusGained &)
{
}

void Application::HandleEvent(const sf::Event::KeyPressed &key)
{
}

void Application::HandleEvent(const sf::Event::KeyReleased &key)
{
}

void Application::HandleEvent(const sf::Event::MouseButtonPressed &mouse)
{
    if(mouse.button == sf::Mouse::Button::Left){
        std::cout << "Left Click" << std::endl;
    }
}

void Application::HandleEvent(const sf::Event::MouseButtonReleased &mouse)
{
}

void Application::HandleEvent(const sf::Event::MouseWheelScrolled &scroll)
{
}
