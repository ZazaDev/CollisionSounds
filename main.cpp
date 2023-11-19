#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <ctime>

int main(int argc, char const *argv[]){
    // Window rendering
    sf::RenderWindow window(sf::VideoMode(800, 600), "Collision Test");
    window.setFramerateLimit(60);

    // Random seed gen
    srand(static_cast <unsigned> (time(0)));
    
    // Shape properties
    float deltaX = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/25);
    float deltaY = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/25);
    float circleRadius = 10.0;
    sf::CircleShape circle;
    circle.setRadius(circleRadius);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(400, 300);

    // Audio buffer
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("tick.wav"))
        return -1;

    sf::Sound sound;
    sound.setBuffer(buffer);

    // Main simulation loop
    while(window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        sf::Event e;
        while(window.pollEvent(e)){
            if(e.type == sf::Event::Closed)
                window.close();
        }
        // Crude border detection
        if(circle.getPosition().x > 775 || circle.getPosition().x < 0){
            deltaX = -deltaX * 1.05;
            circleRadius *= 1.05; 
            sound.play();
        }
        if(circle.getPosition().y > 575 || circle.getPosition().y < 0){
            deltaY = -deltaY * 1.05;
            circleRadius *= 1.05;
            sound.play();
        }

        circle.move(deltaX, deltaY);
        circle.setRadius(circleRadius);
        window.clear();
        window.draw(circle);
        window.display();
    }
    return 0;
}