//
//  window.cpp
//  cRgiX
//
//  Created by LBs_MacOS on 10/24/20.
//  Copyright © 2020 LBs_MacOS. All rights reserved.
//

#include "window.hpp"
#include <iostream>
#include <string>
#include <random>
#include <algorithm>

void window::losujElementTekstury(int numberOfTable)
{
    int dx = 100;
    sf::RectangleShape box;
    box.setPosition(rand() % this->getSize().x + this->x, rand() % this->getSize().y - 150);
    box.setSize(sf::Vector2f(rand() % 100 + 100, 60));

    while (intersekcjaKwadratow(box))
    {
        box.setPosition(rand() % this->getSize().x + this->x, rand() % this->getSize().y - 150);
        box.setSize(sf::Vector2f(rand() % 100 + 100, 60));
    }

    box.setTexture(&arrayOfTextures[rand() % arrayOfTextures.size()]);

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
    for (auto &eat : arrayOfBoxes)
    {
        draw(eat);
    }
};

void window::checkStatus(int x, int y)
{
    for (int i = arrayOfBoxes.size() - 1; i >= 0; i--)
    {
        if (arrayOfBoxes.at(i).getPosition().x + arrayOfBoxes.at(i).getSize().x < 0)
        {
            losujElementTekstury(i);
        }
    }

    if (x >= this->getSize().x - 600)
    {
        przesunElementTekstury();
    }
};

void window::przesunElementTekstury()
{
    for (auto &eat : arrayOfBoxes)
    {
        eat.move(-5, 0);
    }
}

bool window::czyZderzenie(float x, float y)
{
    for (auto &table : arrayOfBoxes)
    {
        // std::cout<< table.getPosition().x<<'\n';
        // sf::RectangleShape X;
        // X.setPosition(table.getPosition().x,table.getPosition().y);
        // X.setSize(table.getSize());
        // draw(X);
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
        this->arrayOfTextures[howManyTextures];
        howManyTextures++;
        return true;
    }
    else
    {
        std::cout << "Blad wczytywania tekstury!" << std::endl;
        return false;
    }
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
