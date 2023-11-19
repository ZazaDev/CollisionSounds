#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>

class Shapes{
    public:
        std::shared_ptr<sf::RenderWindow> window;
        float deltaX, deltaY, radius;
        sf::CircleShape circle;
        
        void update(sf::Sound &sound);

        Shapes();
        void run();
};