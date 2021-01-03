#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include <iostream>

Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight):
    animation(texture, imageCount, switchTime){
        this->speed = speed;
        this->jumpHeight = jumpHeight;
        row = 0;
        faceRight = true;
        body.setSize(sf::Vector2f(75, 50));
        body.setOrigin(body.getSize() / 2.0f);
        body.setPosition(700, 300);
        body.setTexture(texture);
    }

Player::~Player(){}

void Player::Update(float deltaTime){
    velocity.x *= 0.0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        velocity.x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        velocity.x += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&  canJump){
        canJump = false;
        velocity.y = -sqrtf(2.0 * 98.1 * jumpHeight);
    }
    velocity.y += 98.1 * deltaTime;
    if (velocity.x == 0.0){
        row = 0;
    }
    else{
        row = 1;
        if (velocity.x > 0.0){
            faceRight = true;
        }
        else{
            faceRight = false;
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
    if (direction.x < 0.0){
        velocity.x = 0.0; //z Lewej
    }
    else if (direction.x > 0.0){
        velocity.x = 0.0; //z Prawej
    }
    if (direction.y < 0.0){
        velocity.y = 0.0;
        canJump = true; //z dołu
    }
    else if (direction.y > 0.0){
        velocity.y = 0.0;
    }
}