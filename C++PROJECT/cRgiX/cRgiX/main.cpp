
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
#include "player.hpp"
#include "window.hpp"
// #include "ResourcePath.hpp"
#include <random>


int main(int, char const**)
{
    // Create the main window
    window window(sf::VideoMode(1200,700), "cRgiX");
//    sf::RenderWindow window(sf::VideoMode(800, 600), "cRgiX");
    window.setFramerateLimit(60);
    
    // Create player
    player A;
    A.setPosition(100, 200);
    A.setFillColor(sf::Color::White);
    A.setRadius(20);
    
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile("Trashes/icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("Trashes/cute_image.jpg")) {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);
    
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("Trashes/sansation.ttf")) {
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
    
    
    //TEST
    sf::RectangleShape box;
    sf::RectangleShape box1;
    sf::RectangleShape box2;
    sf::RectangleShape box3;
    box = window.losujElementTekstury();
    box1 = window.losujElementTekstury();
    box2 = window.losujElementTekstury();
    box3 = window.losujElementTekstury();
    //TEST
    
    
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
                A.moveUp();
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code ==
                sf::Keyboard::Down) {
                A.moveDown();
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code ==
                sf::Keyboard::Right) {
                A.moveRight();
            }
            
            if (event.type == sf::Event::KeyPressed && event.key.code ==
                sf::Keyboard::Left) {
                A.moveLeft();
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
        
        //TEST
        window.draw(box);
        window.draw(box1);
        window.draw(box2);
        window.draw(box3);
        //TEST
        
        //player
        A.checkStatus();

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
