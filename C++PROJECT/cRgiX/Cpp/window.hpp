#ifndef window_hpp
#define window_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <array>
#include <iostream>

class window : public sf::RenderWindow
{
public:
    sf::Texture TEX;
    int howManyFoods = 0;
    int howManyBoxes = 0;
    int howManyTextures = 0;
    int doggyHigh = 80;
    int PUNKTY = 0;
    float x = this->getSize().x;
    float y = this->getSize().y;
    std::array<sf::RectangleShape, 10> arrayOfBoxes;
    std::array<sf::Texture, 20> arrayOfTextures;
    std::array<sf::CircleShape, 5> arrayOfFood;

    window(sf::VideoMode x, std::string y) : sf::RenderWindow(x, y)
    {
        int i = 0;
        if (TEX.loadFromFile("Sources/wood_texture.jpg"))
        {
            std::cout << "Zaladowana A!\n";
        }
        else
        {
            std::cout << "BLAD LADOWANIA TEKSTURY!\n";
        }

        while (i < arrayOfBoxes.size())
        {
            losujElementTekstury(i);
            ++i;
        }
        losujFood();
    };

    /// Losowanie teskstur przeszkod
    void losujElementTekstury(int numberOfTable);

    void losujElementTekstury();

    void rysujElemetyTekstury();

    bool intersekcjaKwadratow(sf::RectangleShape box);

    /// Zbieranie i czyszczenie po pozostalych funkcjach np. gdy tekstury sa juz poza mapa
    bool checkStatus(int x = -100, int y = -100);

    bool czyZderzenie(float x, float y);
    
    bool czyZderzenieLewa(float x, float y);

    bool czyZderzeniePrawa(float x, float y);

    bool czyZderzenieGora(float x, float y);

    bool czyZderzenieDol(float x, float y);

    void doggyHighSet(int X);

    bool ladowanieTekstur(std::string x);

    sf::Texture losujTesktureZArraya(int rand);

    void przesunElementTekstury();

    void losujFood();

    void losujFood(int x);

    bool intersekcjaFood(sf::CircleShape food);

    bool intersekcjaFood(int index, int playerX, int playerY);

    void graStop();
};

class food : public sf::CircleShape
{

    int number;
    bool trafienie = true;
    float x = this->getPosition().x;
    float y = this->getPosition().y;
    /* data */
    food() : sf::CircleShape(20)
    {
        sf::Texture texture;
        if (texture.loadFromFile("Sources/background1.jpg"))
        {
            this->setTexture(&texture);
        }
    }

    bool zjedzone(float x, float y);
};

#endif