#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <time.h>
#include "Player.hpp"
#include "Collision.hpp"
#include "window.hpp"
#include <random>
#include <string>
#include <array>
#include "Platform.hpp"

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

    sf::Music music;
    if (!music.openFromFile("Sources/nice_music.ogg")){
        return -1;
    }
    music.setVolume(50);
    music.setLoop(true);
    music.play();

    window.setFramerateLimit(60);

    sf::Texture playerTexture;
    playerTexture.loadFromFile("Sources/v1.png");
    window.ladowanieTekstur("Sources/wood_texture.jpg");
    window.ladowanieTekstur("Sources/cute_image.jpg");
    window.ladowanieTekstur("Sources/cute_image.jpg");
    window.ladowanieTekstur("Sources/cute_image.jpg");
    window.ladowanieTekstur("Sources/food.jpg");
    // Create player
    Player player(&playerTexture, sf::Vector2u(12, 8), 0.3f, 350.0f, 200.0f);

    /*std::vector<Platform> platforms;
    platforms.push_back(Platform(nullptr, sf::Vector2f(350.0f, 40.0f), sf::Vector2f(150.0f, 600.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(350.0f, 40.0f), sf::Vector2f(450.0f, 600.0f)));
    platforms.push_back(Platform(nullptr, sf::Vector2f(350.0f, 40.0f), sf::Vector2f(150.0f, 250.0f)));
    */
    // A.setFillColor(sf::Color::White);

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

    //TEST SPRITE
    // sf::RectangleShape box;
    // box.setPosition(100, 100);
    // box.setSize(sf::Vector2f(rand() % 100 + 100, 60));

    // sf::Texture TEX;
    // if (TEX.loadFromFile("Sources/cute_image.jpg"))
    // {
    //     std::cout << "Zaladowana TEKSTURA!\n";
    // }
    // else
    // {
    //     std::cout << "BLAD LADOWANIA TEKSTURY!\n";
    // }

    // sf::Sprite testsprite;
    // testsprite.setTexture(TEX);
    // testsprite.setTextureRect(sf::IntRect(200, 200, 320, 320));
    // testsprite.setTextureRect(sf::IntRect(10, 10, 32, 32));

    // Start the game loop
    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        if (deltaTime > 1.0/30.0){
            deltaTime = 1.0/30.0;
        }
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
        }
        else if (START == true and FINISHED == false)
        {
            window.clear();
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

            //take movement from player
            player.Update(deltaTime);
            sf::Vector2f direction;
            //collisions
            int i = 0;
            for (i; i < window.arrayOfBoxes.size(); i++){
                if(window.getCollision().CheckCollision(player.getCollision(), direction, 1.0)){
                    player.OnCollision(direction);
                }
            }
            //collision with window
            /*if (player.getPosition().y + player.getGlobalBounds().height > 560.0f){
                player.setPosition(player.getPosition().x, 700 - player.getGlobalBounds().height);
                std::cout << "you hit the ground" << std::endl;
            }*/
            /*if (player.getPosition().x < 0.0f){
                player.setPosition(0.0f, player.getPosition().y);
            }//collision with left side of the screen
            if (player.getPosition().x + player.getGlobalBounds().width > Window_width){
                player.setPosition(Window_width - player.getGlobalBounds().width, player.getPosition().y);
            }//collision with right edge of the screen
            if (player.getPosition().y < 0.0f){
                player.setPosition(player.getPosition().x, 0.0f);
            }//collision with top edge of the screen
            if (player.getPosition().y + player.getGlobalBounds().height > 700){
                player.setPosition(player.getPosition().x, 700 - player.getGlobalBounds().height);
            }//collision with bottom edge of the screen*/


            /*for (Platform& platform: platforms){
                if(platform.getCollision().CheckCollision(player.getCollision(), direction, 1.0)){
                    player.OnCollision(direction);
                }
            }*/

            // Clear screen
            // window.clear();

            //wyswietlanie punktow
            std::string punkt = "Punkty: ";
            std::string tempPkt = punkt + std::to_string(window.PUNKTY);
            sf::Text PKT(tempPkt, font, 40);

            PKT.setPosition(50, 50);
            // char pkt = "casdad" + "asdasd";
            // Draw the sprite
            window.draw(sprite);
            window.draw(floor);

            // Draw the string
            //        window.draw(text);

            // Draw the element
            player.Draw(window);
            /*for (Platform& platform: platforms){
                platform.Draw(window);
            }*/
            window.rysujElemetyTekstury();
            window.draw(PKT);


            // window.draw(testsprite);

            //window
            if (!window.checkStatus(player.getPosition().x, player.getPosition().y))
            {
                std::cout<<"KONIEC GRY!\n";
                FINISHED = true;
                player.setPosition(100, 100);
            };


            // if(window.czyZderzenie(A.getPosition().x,A.getPosition().y)){
            //     std::cout << "ZDERZENIE!" << std::endl; // do tej funkcji pozycja obeiktu musi byc z uwzglednieniem rozmiaru bo kolo np ma x,y w centrum i on jest
            // }
            // std::cout<< A.getPosition().x << "\n";
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