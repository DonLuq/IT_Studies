
#include "window.hpp"
#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include "Collision.hpp"
#include "Player.hpp"

void window::losujElementTekstury(int numberOfTable)
{
    int dx = 100;
    sf::RectangleShape box;
    box.setPosition(rand() % this->getSize().x + this->x, rand() % this->getSize().y - 150);
    box.setSize(sf::Vector2f(rand() % 100 + 150, 60));

    while (intersekcjaKwadratow(box))
    {
        box.setPosition(rand() % this->getSize().x + this->x, rand() % this->getSize().y - 150);
        box.setSize(sf::Vector2f(rand() % 100 + 150, 60));
    }

    // box.setTexture(&arrayOfTextures[rand() % arrayOfTextures.size()]);
    // box.setTexture(&arrayOfTextures[1]);
    // if (TEX.loadFromFile("Sources/wood_texture.jpg"))
    // {
    //     std::cout << "Zaladowana A!\n";
    // }
    // else
    // {
    //     std::cout << "BLAD LADOWANIA TEKSTURY!\n";
    // }
    // box.setTexture(&arrayOfTextures[rand() % arrayOfTextures.size()]);

    arrayOfBoxes[numberOfTable] = box;
};

bool window::intersekcjaKwadratow(sf::RectangleShape box)
{
    for (auto &table : arrayOfBoxes)
    {
        if (box.getGlobalBounds().intersects(table.getGlobalBounds()))
        {
            return true;
        }
        sf::RectangleShape temp;
        temp.setPosition(table.getPosition().x - doggyHigh, table.getPosition().y - doggyHigh);
        temp.setSize(sf::Vector2f(table.getSize().x + 2 * doggyHigh, table.getSize().y + 2 * doggyHigh));
        if (box.getGlobalBounds().intersects(temp.getGlobalBounds()))
        {
            return true;
        }
    }
    return false;
}

void window::rysujElemetyTekstury()
{
    for (int i = arrayOfBoxes.size() - 1; i >= 0; i--)
    {
        arrayOfBoxes[i].setTexture(&arrayOfTextures[0]);
        draw(arrayOfBoxes[i]);
    }
    for (int i = arrayOfFood.size() - 1; i >= 0; i--)
    {
        sf::Texture temp(arrayOfTextures[4]);
        // temp = arrayOfTextures[4];
        // temp.getMaximumSize();
        // temp.setTextureRect();
        // arrayOfFood[i].setTexture(&temp);
        arrayOfFood[i].setFillColor(sf::Color::Red);
        draw(arrayOfFood[i]);
    }
};

bool window::checkStatus(int x, int y)
{
    for (int i = arrayOfBoxes.size() - 1; i >= 0; i--)
    {
        if (arrayOfBoxes.at(i).getPosition().x + arrayOfBoxes.at(i).getSize().x < 0)
        {
            losujElementTekstury(i);
        }
    }

    for (int i = arrayOfFood.size() - 1; i >= 0; i--)
    {
        // sf::CircleShape tempCir(this->doggyHigh);

        if (intersekcjaFood(i, x, y))
        {
            losujFood(i);
        };

        if (arrayOfFood.at(i).getPosition().x + arrayOfFood.at(i).getGlobalBounds().width < 0)
        {
            losujFood(i);
        }
    }

    if (1)
    {
        przesunElementTekstury();
    }

    std::cout << "Koordynaty: " << x << "  " << y << "\n";

    if (y > 550)
    {
        return false;
    }
    else if (x == 0)
    {
        std::cout << "Na rogu mapy jest\n";
        sf::RectangleShape temp;
        temp.setPosition(x, y);
        temp.setSize(sf::Vector2f(this->doggyHigh, this->doggyHigh));
        if (intersekcjaKwadratow(temp))
        {
            std::cout << "JEST INTEAKCJA\n";
            return false;
        }
        return true;
    }
    else
    {
        return true;
    }
};

void window::przesunElementTekstury()
{
    for (sf::RectangleShape &eat : arrayOfBoxes)
    {
        eat.move(-3, 0);
    }

    for (sf::CircleShape &eat : arrayOfFood)
    {
        eat.move(-3, 0);
    }
}

bool window::czyZderzenie(float x, float y)
{
    for (auto &table : arrayOfBoxes)
    {
        if (x >= table.getPosition().x && x <= table.getPosition().x + table.getSize().x && y >= table.getPosition().y && y <= table.getPosition().y + table.getSize().y)
        {
            // std::cout << table.getPosition().x<<" <---"<<"\n";
            return true;
        }
    }
    return false;
};

void window::doggyHighSet(int X)
{
    this->doggyHigh = X;
};

bool window::ladowanieTekstur(std::string x)
{
    sf::Texture texture;
    if (texture.loadFromFile(x))
    {
        std::cout << "Tekstura wczytana!" << std::endl;
        this->arrayOfTextures[howManyTextures] = texture;
        howManyTextures++;
        return true;
    }
    else
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
        return false;
    }
};

void window::losujFood()
{
    sf::CircleShape Jedzenie(20);
    sf::Texture texture;
    if (texture.loadFromFile("Sources/background1.jpg"))
    {
        Jedzenie.setTexture(&texture);
    }

    for (auto &table : arrayOfBoxes)
    {
        if (howManyFoods < this->arrayOfFood.size())
        {
            Jedzenie.setPosition(table.getPosition().x + table.getGlobalBounds().width / 2, table.getPosition().y - Jedzenie.getGlobalBounds().height);

            if (table.getPosition().x > 1200 & !intersekcjaFood(Jedzenie))
            {
                this->arrayOfFood[this->howManyFoods] = Jedzenie;
                std::cout << "Karma ---> " << howManyFoods << std::endl;
                ++howManyFoods;
            }
        }
    }
};

void window::losujFood(int x) // x - index
{
    for (auto &table : arrayOfBoxes)
    {
        sf::CircleShape tempCircle(20);
        int tempx = table.getPosition().x + table.getGlobalBounds().width / 2;
        int tempy = table.getPosition().y - tempCircle.getGlobalBounds().height;
        int width = table.getGlobalBounds().width;
        int height = table.getGlobalBounds().height;
        tempCircle.setPosition(tempx, tempy);

        if (table.getPosition().x > 1200 & !intersekcjaFood(tempCircle)) // + zabezpieczenie przed nakladaniem sie cirle na cirle
        {
            this->arrayOfFood[x].setPosition(table.getPosition().x + table.getGlobalBounds().width / 2, table.getPosition().y - this->arrayOfFood[x].getGlobalBounds().height);
            // this->arrayOfFood[x].setPosition(table.getPosition().x + table.getGlobalBounds().width / 2, table.getPosition().y);
            if (table.getGlobalBounds().intersects(this->arrayOfFood[x].getGlobalBounds()))
            {
                this->arrayOfFood[x].move(0, -arrayOfFood[x].getGlobalBounds().height);
            }
            break;
        }
    }
};

bool window::intersekcjaFood(sf::CircleShape food)
{
    for (auto &table : arrayOfFood)
    {
        if (food.getGlobalBounds().intersects(table.getGlobalBounds()))
        {
            std::cout << "Nachodzi!\n";
            return true;
        }
    }
    return false;
};

bool window::intersekcjaFood(int index, int playerX, int playerY)
{
    sf::CircleShape tempCircle(this->doggyHigh/5);
    tempCircle.setPosition(playerX, playerY);
    if (arrayOfFood[index].getGlobalBounds().intersects(tempCircle.getGlobalBounds()))
    {
        ++PUNKTY;
        return true;
    };
    return false;
};

// bool window::czyZderzenie(float x,float y){
//     for(int i = arrayOfBoxes.size() - 1; i>=0; i--){
//         if(x >= arrayOfBoxes[i].getPosition().x && x <= arrayOfBoxes[i].getPosition().x + arrayOfBoxes[i].getSize().x && y >= arrayOfBoxes[i].getPosition().y && y <= arrayOfBoxes[i].getPosition().y + arrayOfBoxes[i].getSize().y ){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };