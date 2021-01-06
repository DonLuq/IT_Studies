#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include <iostream>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight):
    animation(texture, imageCount, switchTime){
        this->speed = speed;
        this->jumpHeight = jumpHeight;
        row = 0;
        faceRight = true;
        canJump = true;
        body.setSize(sf::Vector2f(100, 50));
        body.setOrigin(body.getSize() / 2.0f);
        body.setPosition(150.0f, 600.0f);
        body.setTexture(texture);
    }

Player::~Player(){}

void Player::Update(float deltaTime){
    velocity.x *= 0.15f;
    //velocity.y += 5.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        velocity.x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        velocity.x += speed;
    }
    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        velocity.y -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        velocity.y += speed;
    }*/
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&  canJump){
        canJump = false;
        velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);  
    }
    if (!canJump){
        velocity.y += 981.0f * deltaTime;
    }
    if (velocity.x == 0.0f){
        row = 0;
    }
    else{
        row = 1;
        if (velocity.x > 0.0f){
            faceRight = true;
        }
        else{
            faceRight = false;
        }
        if (velocity.y != 0.0f){
        row = 2;
        }
    }
    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow& window){
    window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction){
    if (direction.x < 0.0f){
        velocity.x *= 0.0f; //z Lewej
    }
    else if (direction.x > 0.0f){
        velocity.x *= 0.0f; //z Prawej
    }
    if (direction.y < 0.0f){
        velocity.y *= 0.0f;
        canJump = true; //z Dolu
    }
    else if (direction.y > 0.0f){
        velocity.y *= 0.0f;//z Gory
    }
}
