#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include <iostream>
#include <cmath>

Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight):
    animation(texture, imageCount, switchTime){
        sf::RectangleShape();
        this->speed = speed;
        this->jumpHeight = jumpHeight;
        row = 0;
        faceRight = true;
        canJump = true;
        this->setSize(sf::Vector2f(80, 80));
        this->setOrigin(this->getSize() / 2.0f);
        //this->setPosition(150.0f, 50.0f);
        this->setTexture(texture);
    }

Player::~Player(){}

void Player::Update(float deltaTime){
    velocity.x *= 0.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        velocity.x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        velocity.x += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&  canJump){
        canJump = false;
        velocity.y = -sqrtf(2.0f * 98.1f * jumpHeight);  
    }
    velocity.y += 98.1f * deltaTime;
    if (velocity.x == 0.0f){
        row = 0;
    }
    else{
        row = 2;
        if (velocity.x > 0.0f){
            faceRight = true;
        }
        else{
            faceRight = false;
        }
    }
    animation.Update(row, deltaTime, faceRight);
    this->setTextureRect(animation.uvRect);
    this->move(velocity * deltaTime);
}
