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
#include "ResourcePath.hpp"
#include <random>


sf::RectangleShape window::losujElementTekstury(){
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "cute_image.jpg")) {
        throw EXIT_FAILURE;
    };

    
//    std::random_device rd;
//    std::mt19937 mt(rd());
//    std::uniform_real_distribution<double> dist(1.0, 10.0);
    
    
    sf::RectangleShape box;
    box.setPosition(rand()%this->getSize().x, rand()%this->getSize().y);
    box.setSize(sf::Vector2f(100,60));
    box.setTexture(&texture);

    return box;
};
