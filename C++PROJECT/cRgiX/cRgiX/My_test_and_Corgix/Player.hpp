#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include <iostream>
#include "Collision.hpp"

class Player{
public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
    ~Player();
    void Update(float deltaTime);
    void Draw(sf::RenderWindow& window);
    Collision getCollision(){
        return Collision(body);
    }
    void OnCollision(sf::Vector2f direction);
private:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;
};
#endif