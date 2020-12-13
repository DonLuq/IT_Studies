// // else
// //         {
// //             while (window.pollEvent(event))
// //             {
// //                 // Close window: exit
// //                 if (event.type == sf::Event::Closed)
// //                 {
// //                     window.close();
// //                 }

// //                 // Escape pressed: exit
// //                 if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
// //                 {
// //                     window.close();
// //                 }

// //                 if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
// //                 {
// //                     START = true;
// //                 }

// //                 // if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
// //                 // {
// //                 //     std::cout << "KONIEC\n";

// //                 //     if (0)
// //                 //     {
// //                 //         START = true;
// //                 //     }
// //                 // }
// //             }
// //             window.draw(menuSprite);
// //         }
// //         // Update the window
// //         window.display();
// //     }



// //  sf::Sprite menuSprite;
// //     menuSprite = sprite;
// //     menuSprite.setColor(sf::);


// //
// // Disclaimer:
// // ----------
// //
// // This code will work only if you selected window, graphics and audio.
// //
// // Note that the "Run Script" build phase will copy the required frameworks
// // or dylibs to your application bundle so you can execute it on any OS X
// // computer.
// //
// // Your resource files (images, sounds, fonts, ...) are also copied to your
// // application bundle. To get the path to these resources, use the helper
// // function `resourcePath()` from ResourcePath.hpp
// //
// #include <iostream>
// #include <SFML/Audio.hpp>
// #include <SFML/Graphics.hpp>
// #include <string>
// #include <time.h>
// #include "player.hpp"
// #include "window.hpp"
// #include <random>

// bool START = false;
// bool FINISHED = false;
// bool ACTIVE = false;

// int main(int, char const **)
// {
//     // Create the main window
//     window window(sf::VideoMode(1200, 700), "cRgiX");
//     //    sf::RenderWindow window(sf::VideoMode(800, 600), "cRgiX");
//     window.setFramerateLimit(60);

//     sf::Texture corgi;
//     if (!corgi.loadFromFile("Sources/corgi2.png"))
//     {
//         return EXIT_FAILURE;
//     }

//     window.ladowanieTekstur("Sources/wood_texture.jpg");
//     // Create player
//     player A;
//     A.setPosition(100, 200);
//     // A.setFillColor(sf::Color::White);
//     A.setRadius(50);
//     A.setTexture(&corgi, true);

//     // Set the Icon
//     sf::Image icon;
//     if (!icon.loadFromFile("Sources/icon.png"))
//     {
//         return EXIT_FAILURE;
//     }
//     window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

//     // Load a sprite to display
//     sf::Texture texture;
//     if (!texture.loadFromFile("Sources/background1.jpg"))
//     {
//         return EXIT_FAILURE;
//     }
//     sf::Sprite sprite(texture);

    

//     sf::Texture picFloor;
//     if (!picFloor.loadFromFile("Sources/wood_texture.jpg"))
//     {
//         return EXIT_FAILURE;
//     }
//     picFloor.setSmooth(true);

//     sf::RectangleShape floor;
//     floor.setSize(sf::Vector2f(1200, 700));
//     floor.setPosition(0, window.getSize().y - 100);
//     floor.setFillColor(sf::Color::White);
//     floor.setTexture(&picFloor);

//     // Create a graphical text to display
//     sf::Font font;
//     if (!font.loadFromFile("Sources/sansation.ttf"))
//     {
//         return EXIT_FAILURE;
//     }
//     sf::Text text("Hello SFML", font, 50);
//     text.setFillColor(sf::Color::Black);

    //     Load a music to play
    //    sf::Music music;
    //    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
    //        return EXIT_FAILURE;
    //    }

    //     Play the music
    //    music.play();

    // Start the game loop
//     while (window.isOpen())
//     {
//         sf::Event event;

//         if (START == true and FINISHED == false)
//         {
//             // Process events
//             while (window.pollEvent(event))
//             {
//                 // Close window: exit
//                 if (event.type == sf::Event::Closed)
//                 {
//                     window.close();
//                 }

//                 // Escape pressed: exit
//                 if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
//                 {
//                     window.close();
//                 }

//                 if (event.type == sf::Event::KeyPressed && event.key.code ==
//                                                                sf::Keyboard::Up)
//                 {
//                     // A.moveUp();
//                     A.move(0, -10);
//                 }

//                 if (event.type == sf::Event::KeyPressed && event.key.code ==
//                                                                sf::Keyboard::Down)
//                 {
//                     A.moveDown();
//                 }

//                 if (event.type == sf::Event::KeyPressed && event.key.code ==
//                                                                sf::Keyboard::Right)
//                 {
//                     if (!window.czyZderzenie(A.getPosition().x, A.getPosition().y) == true)
//                     {
//                         A.moveRight(window.getSize().x - 100);
//                     }
//                 }

//                 if (event.type == sf::Event::KeyPressed && event.key.code ==
//                                                                sf::Keyboard::Left)
//                 {
//                     A.moveLeft();
//                 }

//                 if (event.type == sf::Event::Resized)
//                 {
//                     // window.setSize(sf::Vector2f(event.size.width,event.size.height));
//                 }

//                 if (event.type == sf::Event::LostFocus)
//                     START = false;

//                 if (event.type == sf::Event::GainedFocus)
//                     START = true;
//             }

//             // Clear screen
//             // window.clear();

//             // Draw the sprite
//             window.draw(sprite);
//             window.draw(floor);

//             // Draw the string
//             //        window.draw(text);

//             // Draw the element
//             window.draw(A);
//             window.rysujElemetyTekstury();

//             //player
//             A.checkStatus(window.czyZderzenie(A.getPosition().x, A.getPosition().y));

//             //window
//             window.checkStatus(A.getPosition().x, A.getPosition().y);

//             // if(window.czyZderzenie(A.getPosition().x,A.getPosition().y)){
//             //     std::cout << "ZDERZENIE!" << std::endl; // do tej funkcji pozycja obeiktu musi byc z uwzglednieniem rozmiaru bo kolo np ma x,y w centrum i on jest
//             // }
//             // std::cout<< A.getPosition().x << "\n";
//             window.draw(sprite);
//         }
//         else
//         {
//             while (window.pollEvent(event))
//             {
//                 // Close window: exit
//                 if (event.type == sf::Event::Closed)
//                 {
//                     window.close();
//                 }

//                 // Escape pressed: exit
//                 if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
//                 {
//                     window.close();
//                 }

//                 if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
//                 {
//                     START = true;
//                 }
//             }
//             std::cout << "KONIEC\n";
//         }
//         // Update the window
//         window.display();
//     }

//     return EXIT_SUCCESS;
// }
