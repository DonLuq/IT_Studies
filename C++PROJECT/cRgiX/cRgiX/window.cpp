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


void window::losujElementTekstury(){
    
    sf::RectangleShape box;
    box.setPosition(rand()%this->getSize().x + 500, rand()%this->getSize().y- 100);
    box.setSize(sf::Vector2f(rand()%100+100,rand()%50+20));
    // box.setFillColor(sf::Color::Magenta);
    sf::Texture klocek;
    if (!klocek.loadFromFile("Sources/wood2.jpg")) 
    {
        std::cout<< "NIE Zaladowano!!! ZDJECIE!"<<std::endl;
        box.setFillColor(sf::Color::Magenta);    
    }
    else
    {
        std::cout<< "Zaladowano!!! ZDJECIE!"<<std::endl;
        box.setTexture(&klocek);
        // box.setFillColor(sf::Color::Yellow);    
    }

    arrayOfBoxes[howManyBoxes] = box;
    ++howManyBoxes;
    if(howManyBoxes == static_cast<int>(arrayOfBoxes.size())){
        howManyBoxes = 0;
    }
};

void window::losujElementTekstury(int numberOfTable){

    sf::RectangleShape box;
    box.setPosition(this->getSize().x + 500, rand()%this->getSize().y - 100);
    box.setSize(sf::Vector2f(100,60));
    // box.setFillColor(sf::Color::Magenta);
    sf::Texture klocek;
    if (!klocek.loadFromFile("Sources/wood2.jpg")) 
    {
        std::cout<< "NIE Zaladowano!!! ZDJECIE!"<<std::endl;
        box.setFillColor(sf::Color::Magenta);    
    }
    else
    {
        std::cout<< "Zaladowano!!! ZDJECIE!"<<std::endl;
        box.setTexture(&klocek);
        // box.setFillColor(sf::Color::Yellow);    
    }

    arrayOfBoxes[numberOfTable] = box;
};

void window::rysujElemetyTekstury(){
    for(auto & eat:arrayOfBoxes){
        draw(eat);
    }
};

void window::checkStatus(int x, int y){
    for(int i = arrayOfBoxes.size() - 1; i>=0; i--){
        if(arrayOfBoxes.at(i).getPosition().x + arrayOfBoxes.at(i).getSize().x < 0){
            losujElementTekstury(i);
        }
    }

    if(x >= this->getSize().x-600){
        przesunElementTekstury();
    }
};

void window::przesunElementTekstury(){
    for(auto & eat:arrayOfBoxes){
        eat.move(-5,0);
    }
}

bool window::czyZderzenie(float x,float y){
    for(auto & table:arrayOfBoxes){
        // std::cout<< table.getPosition().x<<'\n';
        // sf::RectangleShape X;
        // X.setPosition(table.getPosition().x,table.getPosition().y);
        // X.setSize(table.getSize());
        // draw(X);
        if(x >= table.getPosition().x && x <= table.getPosition().x + table.getSize().x && y >= table.getPosition().y && y <= table.getPosition().y + table.getSize().y ){
            // std::cout << table.getPosition().x<<" <---"<<"\n";
            return true;
        }
    
    }
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
