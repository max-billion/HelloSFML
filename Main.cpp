#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <iostream>

#include "Application.h"

int main()
{
    std::cout << "SFML Version: " 
              << SFML_VERSION_MAJOR << "." 
              << SFML_VERSION_MINOR << "." 
              << SFML_VERSION_PATCH << std::endl;
    Application app;
    while(app.IsRunnning()){
        app.ProcessEvents();
        app.Update();
        app.Render();
    }
}