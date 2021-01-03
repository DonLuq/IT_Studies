#ifndef Platform_hpp
#define Platform_hpp

#include <SFML/Graphics.hpp>
#include "Collision.hpp"

class Platform{
public:
    Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
    ~Platform();
    void Draw(sf::RenderWindow& window);
    Collision getCollision(){
        return Collision(body);
    }
private:
    sf::RectangleShape body;
};
#endif