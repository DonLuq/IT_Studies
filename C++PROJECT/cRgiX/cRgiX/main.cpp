
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <time.h>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

class player: public sf::CircleShape{
public:
    float velocityX = NULL;
    float velocityY = NULL;
    int HP = NULL;
    int MANA = NULL;
    float acceleration = 1;
    clock_t timeY;
    
//public:
//    void move(float x, float y){
//        if (x>0) {
//
//        }
//        else if (y>0){
//
//        }
//        else if (x<0){
//
//        }
//        else if (y<0){
//
//        }
//    };
    
//private:
//    void SmothMove(float x, float y){
//        this->velocity;
//    }
};

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "cRgiX");
    window.setFramerateLimit(60);
    
    // Create player
    player A;
    A.setPosition(100, 200);
    A.setFillColor(sf::Color::Black);
    A.setRadius(20);
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setFillColor(sf::Color::Black);

//     Load a music to play
//    sf::Music music;
//    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
//        return EXIT_FAILURE;
//    }

//     Play the music
//    music.play();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code ==
                sf::Keyboard::Up) {
                if (A.velocityY == 0){
                    A.velocityY -= 2;
                    A.timeY = clock();
                }
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code ==
                sf::Keyboard::Down) {
                A.move(0,10);
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code ==
                sf::Keyboard::Right) {
                if (A.velocityX < 6){
                    A.velocityX += A.acceleration;
                }
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code ==
                sf::Keyboard::Left) {
                if (A.velocityX < 6){
                    A.velocityX -= A.acceleration;
                }
            }
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Draw the string
//        window.draw(text);

        // Draw the element
        window.draw(A);
        
        // Update the window
        window.display();
        
        // Move
        A.move(A.velocityX, A.velocityY);
        if(A.velocityX <= 0){
            A.velocityX += 0.05;
        }
        else if(A.velocityX > 0){
            A.velocityX -= 0.05;
        }
        else if(A.velocityY < 0){
            A.velocityY = 2 +9.81*0.001*(clock()-A.timeY);
        }
        else if(A.velocityY > 0){
            A.velocityY = 0;
        }
    }

    return EXIT_SUCCESS;
}
