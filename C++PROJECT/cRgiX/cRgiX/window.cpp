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
// #include "ResourcePath.hpp"
#include <random>
#include <algorithm>


void window::losujElementTekstury(){
    sf::Texture texture;
    if (!texture.loadFromFile("Trashes/cute_image.jpg")) {
        throw EXIT_FAILURE;
    };
    
    sf::RectangleShape box;
    box.setPosition(rand()%this->getSize().x, rand()%this->getSize().y);
    box.setSize(sf::Vector2f(100,60));
    box.setFillColor(sf::Color::Magenta);

    arrayOfBoxes[howManyBoxes] = box;
    ++howManyBoxes;
    if(howManyBoxes == static_cast<int>(arrayOfBoxes.size())){
        howManyBoxes = 0;
    }
};

void window::losujElementTekstury(int numberOfTable){
    sf::Texture texture;
    if (!texture.loadFromFile("Trashes/cute_image.jpg")) {
        throw EXIT_FAILURE;
    };
    
    sf::RectangleShape box;
    box.setPosition(this->getSize().x, rand()%this->getSize().y);
    box.setSize(sf::Vector2f(100,60));
    box.setFillColor(sf::Color::Magenta);

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

    if(x >= this->getSize().x-100){
        przesunElementTekstury();
    }
};

void window::przesunElementTekstury(){
    for(auto & eat:arrayOfBoxes){
        eat.move(-1,0);
    }
}