#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include <iostream>

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime){
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    totalTime = 0.0;
    currentImage.x = 0;
    uvRect.width = texture->getSize().x/float(imageCount.x);
    uvRect.height = texture->getSize().y/float(imageCount.y);
}

Animation::~Animation(){}

void Animation::Update(int row, float deltaTime, bool faceRight){
    currentImage.y = row;
    totalTime += deltaTime;
    if (totalTime >= switchTime){
        totalTime -= switchTime;
        currentImage.x++;
        if (currentImage.x >= 2){
            currentImage.x = 0;
        }
    }
    uvRect.top = currentImage.y * uvRect.height;
    if (faceRight){
        uvRect.left = currentImage.x * uvRect.width;
        uvRect.width = abs(uvRect.width);
    }
    else{
        uvRect.left = (currentImage.x + 1) *abs(uvRect.width);
        uvRect.width = -abs(uvRect.width);
    }
}