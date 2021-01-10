#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <time.h>
#include "Player.hpp"
#include "window.hpp"
#include "Animation.hpp"
#include <random>
#include <string>
#include <cmath>

bool START = false;
bool FINISHED = false;
bool ACTIVE = false;
bool MAINMENU = true;
int OPTION = 0;

int main(int, char const **)
{
    // Create the main window
    window window(sf::VideoMode(1200, 700), "cRgiX");
    //    sf::RenderWindow window(sf::VideoMode(800, 600), "cRgiX");
    window.setFramerateLimit(60);

    sf::Music music;
    if (!music.openFromFile("Sources/nice_music.ogg"))
    {
        return -1;
    }
    music.setVolume(50);
    music.setLoop(true);
    music.play();

    sf::Texture corgi;
    corgi.loadFromFile("Sources/v1.png");

    window.ladowanieTekstur("Sources/wood_texture.jpg");
    window.ladowanieTekstur("Sources/cute_image.jpg");
    window.ladowanieTekstur("Sources/cute_image.jpg");
    window.ladowanieTekstur("Sources/cute_image.jpg");
    window.ladowanieTekstur("Sources/food.jpg");
    // Create player
    Player A(&corgi, sf::Vector2u(12, 8), 0.3f, 110.0f, 150.0f);
    A.setPosition(150, 150);
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
    menuSprite.setColor(sf::Color(115, 106, 98));

    sf::Texture picFloor;
    if (!picFloor.loadFromFile("Sources/wood_texture.jpg"))
    {
        return EXIT_FAILURE;
    }
    picFloor.setSmooth(true);
    picFloor.setRepeated(true);

    sf::RectangleShape floor;
    floor.setSize(sf::Vector2f(1200, 700));
    floor.setPosition(0, window.getSize().y - 100);
    floor.setFillColor(sf::Color::Red);
    floor.setTexture(&picFloor);

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("Sources/sansation.ttf"))
    {
        return EXIT_FAILURE;
    }
    sf::Text text("Hello SFML", font, 50);
    text.setFillColor(sf::Color::Black);

    float deltaTime = 0.0f;
    sf::Clock clock;
    

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        if (FINISHED == true)
        {
            window.clear();
            window.draw(menuSprite);
            if (window.PUNKTY >= 3)
            {
                std::string tempPkt = "Zobyles " + std::to_string(window.PUNKTY) + " Punktow!";
                sf::Text PKT(tempPkt, font, 40);
                sf::Text Win1("Wygrales!", font, 50);
                sf::Text Win2("Gratulacje Corgi juz nigdy nie bedzie glodny <3", font, 50);
                sf::Text back("Wcisnij ESC aby wrocic do Menu...", font, 20);
                Win1.setPosition(sf::Vector2f(window.x / 2 - Win1.getGlobalBounds().width / 2, window.y / 5));
                Win2.setPosition(sf::Vector2f(window.x / 2 - Win2.getGlobalBounds().width / 2, window.y / 5 + 100));
                back.setPosition(window.x / 2 - back.getGlobalBounds().width / 2, Win1.getPosition().y + 400);
                PKT.setPosition(window.x / 2 - PKT.getGlobalBounds().width / 2, Win1.getPosition().y + 200);
                Win1.setStyle(sf::Text::Bold);
                window.draw(Win1);
                window.draw(Win2);
                window.draw(back);
                window.draw(PKT);
                 A.setPosition(150, 150);;
            }
            else if (window.PUNKTY < 3)
            {
                std::string tempPkt = "Zobyles " + std::to_string(window.PUNKTY) + " Punktow!";
                sf::Text PKT(tempPkt, font, 40);
                sf::Text Win1("Zginales!", font, 50);
                sf::Text Win2("Corgi juz zawsze bedzie glodny </3", font, 50);
                sf::Text back("Wcisnij ESC aby wrocic do Menu...", font, 20);
                Win1.setPosition(sf::Vector2f(window.x / 2 - Win1.getGlobalBounds().width / 2, window.y / 5));
                Win2.setPosition(sf::Vector2f(window.x / 2 - Win2.getGlobalBounds().width / 2, window.y / 5 + 100));
                back.setPosition(window.x / 2 - back.getGlobalBounds().width / 2, Win1.getPosition().y + 400);
                PKT.setPosition(window.x / 2 - PKT.getGlobalBounds().width / 2, Win1.getPosition().y + 200);
                Win1.setStyle(sf::Text::Bold);
                window.draw(Win1);
                window.draw(Win2);
                window.draw(back);
                window.draw(PKT);
                A.setPosition(150, 150);
            }
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                {
                    START = false;
                    FINISHED = false;
                    window.PUNKTY = 0;
                }
            }
            window.draw(A);
        }
        else if (START == true and FINISHED == false)
        {
            
            deltaTime = clock.restart().asSeconds();
            while (window.pollEvent(event))
            {
                // Close window: exit
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                // Escape pressed: exit
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                {
                    START = false;
                }

                if (event.type == sf::Event::LostFocus)
                {
                    START = false;
                }
            }

            //A.Update(deltaTime);

            //Collision
            int playerOX = A.getPosition().x + 40;
            int playerOY = A.getPosition().y + 40;

            if (window.czyZderzenieLewa(playerOX + 40, playerOY)){
                A.velocity.x *= -1.0f;
                A.move(-5, 0);
                std::cout << "collision on left side of the block" << std::endl;
            }
            else if (window.czyZderzeniePrawa(playerOX - 40, playerOY)){
                A.velocity.x *= -1.0f;
                A.move(5, 0);
                std::cout << "collision on right side of the block" << std::endl;
            }
            if (window.czyZderzenieGora(playerOX, playerOY + 40)){
                A.velocity.y *= 0.0f;
                A.canJump = true;
                A.move(-3, 0);
                std::cout << "collision on top of the block" << std::endl;
            }
            else if (window.czyZderzenieDol(playerOX, playerOY - 40)){
                A.velocity.y *= -1.0f;
                A.move(-1, -1);
                std::cout << "collision on bottom of the block" << std::endl;
            }
            //player movement actualisation
            A.Update(deltaTime);

            //wyswietlanie punktow
            std::string punkt = "Punkty: ";
            std::string tempPkt = punkt + std::to_string(window.PUNKTY);
            sf::Text PKT(tempPkt, font, 40);

            PKT.setPosition(50, 50);

            // Draw the sprite
            window.clear();
            window.draw(sprite);
            window.draw(floor);

            // Draw the element
            window.rysujElemetyTekstury();
            window.draw(A);
            window.draw(PKT);

            //window
            if (!window.checkStatus(A.getPosition().x, A.getPosition().y))
            {
                std::cout<<"KONIEC GRY!\n";
                FINISHED = true;
                if (FINISHED == true){
                    A.setPosition(150, 150);
                }
            };
            
        }
        else
        {
            window.clear();
            //OBSLUGA MENU
            sf::Text strzalkalewa("---->", font, 50);

            sf::Text strzalkaprawa("<----", font, 50);

            sf::Text start("START", font, 50);
            start.setPosition(window.x / 2 - start.getGlobalBounds().width / 2, window.y / 7);
            if (OPTION == 0)
            {
                strzalkalewa.setPosition(start.getPosition().x - strzalkalewa.getGlobalBounds().width * 1.2, start.getPosition().y);
                strzalkaprawa.setPosition(start.getPosition().x + start.getGlobalBounds().width + strzalkaprawa.getGlobalBounds().width * 0.1, start.getPosition().y);
            }

            sf::Text records("RECORDS", font, 50);
            records.setPosition(window.x / 2 - records.getGlobalBounds().width / 2, window.y / 7 * 2);
            if (OPTION == 1)
            {
                strzalkalewa.setPosition(records.getPosition().x - strzalkalewa.getGlobalBounds().width * 1.2, records.getPosition().y);
                strzalkaprawa.setPosition(records.getPosition().x + records.getGlobalBounds().width + strzalkaprawa.getGlobalBounds().width * 0.1, records.getPosition().y);
            }

            sf::Text madeby("Created by...", font, 50);
            madeby.setPosition(window.x / 2 - madeby.getGlobalBounds().width / 2, window.y / 7 * 3);
            if (OPTION == 2)
            {
                strzalkalewa.setPosition(madeby.getPosition().x - strzalkalewa.getGlobalBounds().width * 1.2, madeby.getPosition().y);
                strzalkaprawa.setPosition(madeby.getPosition().x + madeby.getGlobalBounds().width + strzalkaprawa.getGlobalBounds().width * 0.1, madeby.getPosition().y);
            }

            sf::Text exit("EXIT", font, 50);
            exit.setPosition(window.x / 2 - exit.getGlobalBounds().width / 2, window.y / 7 * 4);
            if (OPTION == 3)
            {
                strzalkalewa.setPosition(exit.getPosition().x - strzalkalewa.getGlobalBounds().width * 1.2, exit.getPosition().y);
                strzalkaprawa.setPosition(exit.getPosition().x + exit.getGlobalBounds().width + strzalkaprawa.getGlobalBounds().width * 0.1, exit.getPosition().y);
            }

            while (window.pollEvent(event))
            {
                // Close window: exit
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                }

                // Escape pressed: exit
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                {
                    if (MAINMENU == false)
                    {
                        MAINMENU = true;
                    }
                    else if (OPTION == 3)
                    {
                        window.close();
                    }
                    else
                    {
                        OPTION = 3;
                    }
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
                {
                    if (MAINMENU == true)
                    {
                        if (OPTION == 0)
                        {
                            OPTION = 3;
                        }
                        else
                        {
                            --OPTION;
                        }
                    }
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
                {
                    if (MAINMENU == true)
                    {
                        if (OPTION == 3)
                        {
                            OPTION = 0;
                        }
                        else
                        {
                            ++OPTION;
                        }
                    }
                }

                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
                {
                    if (OPTION == 0)
                    {
                        START = true;
                    }
                    else if (OPTION == 1)
                    {
                        MAINMENU = false;
                    }
                    else if (OPTION == 2)
                    {
                        MAINMENU = false;
                    }
                    else if (OPTION == 3)
                    {
                        window.close();
                    }
                }

                if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
                {
                    std::cout << "KONIEC\n";

                    if (0) //funkcja do sprawdzania co klikniete!
                    {
                        START = true;
                    }
                }
            }
            // window.draw(sprite);
            window.draw(menuSprite);
            if (MAINMENU == true)
            {
                window.draw(start);
                window.draw(records);
                window.draw(madeby);
                window.draw(exit);
                window.draw(strzalkalewa);
                window.draw(strzalkaprawa);
            }
            else
            {
                if (OPTION == 1)
                {
                    sf::Text tekst2("TUTAJ Wczytywac z pliku wyniki pkt graczy", font, 50);
                    tekst2.setPosition(window.x / 2 - tekst2.getGlobalBounds().width / 2, window.y / 7);
                    window.draw(tekst2);
                }
                else if (OPTION == 2)
                {
                    sf::Text createdby("Created by Lukasz Bajsarowicz & Jakub Grzedowskihehe", font, 30);
                    createdby.setPosition(window.x / 2 - createdby.getGlobalBounds().width / 2, window.y / 7 * 5);

                    sf::Texture goodbye;
                    if (!goodbye.loadFromFile("Sources/goodbye.jpg"))
                    {
                        std::cout << "Not Goodbye !\n";
                    }
                    sf::CircleShape corg(200);
                    corg.setTexture(&goodbye);
                    corg.setPosition(window.x / 2 - corg.getGlobalBounds().width / 2, 50);

                    window.draw(createdby);
                    window.draw(corg);
                }
            }
        }

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}