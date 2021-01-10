#ifndef Player_hpp
#define Player_hpp

#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include <iostream>

class Player: public sf::RectangleShape{
public:
    Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
    ~Player();
    void Update(float deltaTime);
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
    sf::Vector2f velocity;
    bool canJump;
    float jumpHeight;  
};
#endif
