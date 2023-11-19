#include "shapes.hpp"

Shapes::Shapes(){
    deltaX = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/25);
    deltaY = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/25);
    radius = 20.0;
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(400, 300);
    window = std::make_shared<sf::RenderWindow>(
        sf::VideoMode(800, 600),
        "Collision Test",
        sf::Style::Titlebar | sf::Style::Close
    );
    window->setFramerateLimit(60);
    window->setPosition(sf::Vector2i(0,0));
}

void Shapes::update(sf::Sound &sound){
    // Border detection
    if(circle.getPosition().x + (2.0 * radius) > window->getSize().x || circle.getPosition().x < 0){
        deltaX = -deltaX * 1.1;
        // Changing the radius of the circle causes some problems lol
        //radius *= 1.05; 
        sound.play();
        printf("Radius: %f\ncircle.getPosition().x: %f\n\n", radius, circle.getPosition().x);
    }
    if(circle.getPosition().y + (2.0 * radius) > window->getSize().y || circle.getPosition().y < 0){
        deltaY = -deltaY * 1.1;
        //radius *= 1.05;
        sound.play();
        printf("Radius: %f\ncircle.getPosition().y: %f\n\n", radius, circle.getPosition().y);
    }

    circle.move(deltaX, deltaY);
    circle.setRadius(radius);
}

void Shapes::run(){
    // Setting audio buffer and error handling
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("tick.wav"))
        exit(EXIT_FAILURE);

    sf::Sound sound;
    sound.setBuffer(buffer);

    // Main simulation loop
    while(window->isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        sf::Event e;
        while(window->pollEvent(e)){
            if(e.type == sf::Event::Closed)
                window->close();
        }
        update(sound);
        window->clear();
        window->draw(circle);
        window->display();
    }
}