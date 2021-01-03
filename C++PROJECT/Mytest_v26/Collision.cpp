#include <SFML/Graphics.hpp>
#include "Collision.hpp"
#include <iostream>

Collision::Collision(sf::RectangleShape& body):
    body(body){}

Collision::~Collision(){}

bool Collision::CheckCollision(Collision& other, sf::Vector2f& direction, float push){
    sf::Vector2f otherPosition = other.GetPosition();
    sf::Vector2f otherHalfSize = other.GetHalfSize();
    sf::Vector2f thisPosition = GetPosition();
    sf::Vector2f thisHalfSize = GetHalfSize();
    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;
    float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
    if (intersectX < 0.0 && intersectY < 0.0){
        push = std::min(std::max(push, 0.0f), 1.0f);
        if (intersectX > intersectY){
            if (deltaX > 0.0){
                Move(intersectX * (1.0 - push), 0.0);
                other.Move(-intersectX * push, 0.0);
                direction.x = 1.0; //z prawej
                direction.y = 0.0;
            }
            else{
                Move(-intersectX * (1.0 - push), 0.0);
                other.Move(intersectX * push, 0.0);
                direction.x = -1.0; //z lewej
                direction.y = 0.0;
            }
        }
        else{
           if (deltaY > 0.0){
                Move(0.0, intersectX * (1.0 - push));
                other.Move(0.0, -intersectX * push);
                direction.x = 0.0;
                direction.y = 1.0; //z dołu
            }
            else{
                Move(0.0, -intersectX * (1.0 - push));
                other.Move(0.0, intersectX * push);
                direction.x = 0.0;
                direction.y = -1.0; //z góry
            } 
        }
        return true;
    }
    return false;
}