#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
//#include "Animation.hpp"
#include "Collision.hpp"
#include "Platform.hpp"
#include "Player.hpp"

int main(){
    sf::RenderWindow window(sf::VideoMode(1200, 700), "MyTest_v26", sf::Style::Close | sf::Style::Resize);

    sf::Music music;
    music.openFromFile("Source/nice_music.ogg");
    music.setVolume(50);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("Sources/corgi2.png");
    
    Player player(&playerTexture, sf::Vector2u(3, 3), 0.3, 150.0, 300.0);

    std::vector<Platform> platforms;
    platforms.push_back(Platform(nullptr, sf::Vector2f(1000, 40), sf::Vector2f(1000, 650)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(250, 40), sf::Vector2f(250, 250)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(250, 40), sf::Vector2f(250, 450)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(250, 40), sf::Vector2f(450, 250)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(250, 40), sf::Vector2f(450, 250)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(250, 40), sf::Vector2f(650, 650)));

    float deltaTime = 0.0;
    sf::Clock clock;

    while (window.isOpen()){

        deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0/30.0){
            deltaTime = 1.0/30.0; //Setting FPS
        }//Not needed but usfull

        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
                window.close();
            }
        }

        player.Update(deltaTime);
        sf::Vector2f direction;
        for (Platform& platform: platforms){
            if(platform.getCollision().CheckCollision(player.getCollision(), direction, 1.0)){
                player.OnCollision(direction);
            }
        }

        window.clear();
        player.Draw(window);
        for (Platform& platform: platforms){
            platform.Draw(window);
        }
        window.display();
    }
    return 0;
}


/*//
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
#include <vector>
#include "player.hpp"
//#include "window.hpp"
#include <random>



bool START = false;
bool FINISHED = false;
bool ACTIVE = false;

int main(int, char const **)
{
    // Create the main window
    window window(sf::VideoMode(1200, 700), "cRgiX");
    //    sf::RenderWindow window(sf::VideoMode(800, 600), "cRgiX");
    window.setFramerateLimit(60);

    sf::Texture corgi;
    if (!corgi.loadFromFile("Sources/corgi2.png"))
    {
        return EXIT_FAILURE;
    }

    window.ladowanieTekstur("Sources/wood_texture.jpg");
    // Create player
    player A;
    A.setPosition(150, 530);
    // A.setFillColor(sf::Color::White);
    A.setSize(sf::Vector2f(100, 70));
    A.setTexture(&corgi, true);

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile("Sources/icon.png"))
    {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("Sources/background1.jpg"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    sf::Sprite menuSprite;
    menuSprite = sprite;
    menuSprite.setColor(sf::Color(50, 50, 50, 50));

    sf::Texture picFloor;
    if (!picFloor.loadFromFile("Sources/wood_texture.jpg"))
    {
        return EXIT_FAILURE;
    }
    picFloor.setSmooth(true);

    sf::RectangleShape floor;
    floor.setSize(sf::Vector2f(1200, 700));
    floor.setPosition(0, window.getSize().y - 100);
    floor.setFillColor(sf::Color::White);
    floor.setTexture(&picFloor);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("Sources/sansation.ttf"))
    {
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

    window.setKeyRepeatEnabled(true);

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        if (START == true and FINISHED == false)
        {
            while (window.pollEvent(event))
            {
                // Close window: exit
                if (event.type == sf::Event::Closed){
                    window.close();
                }

                // Escape pressed: exit
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space){
                    A.moveUp();
                    A.canJump = false;
                    //A.move(0, -10);
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right){
                    if (!window.czyZderzenie(A.getPosition().x, A.getPosition().y) == true)
                        A.moveRight(window.getSize().x - 100);
                    //A.move({A.speed, 0});
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left){
                    A.moveLeft();
                    //A.move({-A.speed, 0});
                }

                if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space){
                    A.checkJump(A.canJump);
                }
                
                if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right){
                    A.stopX();
                }

                if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left){
                    A.stopX();
                }

                if (event.type == sf::Event::LostFocus){
                    START = false;
                }
                // Clear screen
            // window.clear();

            // Draw the sprite
            window.draw(sprite);
            window.draw(floor);

            // Draw the string
            //        window.draw(text);

            // Draw the element
            window.draw(A);
            window.rysujElemetyTekstury();

            //player
            A.checkStatus(window.czyZderzenie(A.getPosition().x, A.getPosition().y));

            //window
            window.checkStatus(A.getPosition().x, A.getPosition().y);

            // if(window.czyZderzenie(A.getPosition().x,A.getPosition().y)){
            //     std::cout << "ZDERZENIE!" << std::endl; // do tej funkcji pozycja obeiktu musi byc z uwzglednieniem rozmiaru bo kolo np ma x,y w centrum i on jest
            // }
            // std::cout<< A.getPosition().x << "\n";
            }
        }
        else{
            while (window.pollEvent(event)){
                // Close window: exit
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                // Escape pressed: exit
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                {
                    START = true;
                }

                if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
                {
                    std::cout << "KONIEC\n";

                    if (0)//funkcja do sprawdzania co klikniete!
                    {
                        START = true;
                    }
                }
            }
            window.draw(menuSprite);
        }
            
        
        

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}*/