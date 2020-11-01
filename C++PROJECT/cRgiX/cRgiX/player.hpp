//
//  player.hpp
//  cRgiX
//
//  Created by LBs_MacOS on 10/24/20.
//  Copyright © 2020 LBs_MacOS. All rights reserved.
//
// Klasa odpowiedzialna za dzialanie gracze:
// - funkcje poruszania się
// - funkcje interakcji z otoczeniem

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <time.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>



void HelloWorld();

class player: public sf::CircleShape{
public:
    float velocityX = NULL;
    float velocityY = NULL;
    float jumpVelocity = -1;
    int HP = NULL;
    int MANA = NULL;
    float acceleration = 1;
    clock_t timeY = NULL;
    float start_y;
    
    


    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    
    void checkStatus();// checkStatus - funkcja domykajaca dzialanie wszystkich pozostalych, aktualnie posiada dzialanie wspierajace funkcje moveRight(), moveLeft() w postaci redukcji predkosci X

private:
};

#endif /* player_hpp */
