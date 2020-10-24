//
//  player.cpp
//  cRgiX
//
//  Created by LBs_MacOS on 10/24/20.
//  Copyright © 2020 LBs_MacOS. All rights reserved.
//

#include "player.hpp"
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <time.h>

void HelloWorld(){
    std::cout<< "HELLO WORLD!"<< std:: endl;
};

void player::moveRight(){
    if (this->velocityX < 6){
        this->velocityX += this->acceleration;
    }
};

void player::moveLeft(){
    if (this->velocityX < 6){
        this->velocityX -= this->acceleration;
    }
};

void player::moveDown(){
    this->move(0,10);
};

void player::moveUp(){
    if (this->velocityY == 0){
        this->velocityY -= this->jumpVelocity;
        this->timeY = clock();
        this->start_y = this->getPosition().y;
    }
};


void player::checkStatus(){
    if(this->velocityX < 0){
        this->velocityX+= 0.05;
    }
    else if(this->velocityX > 0){
        this->velocityX -=0.05;
    }
    
    if(this->timeY != 0){
        float dt = (clock()-this->timeY)/(float)CLOCKS_PER_SEC; // dt SEC.
        std::cout << "CZAS : " << dt << std::endl;
        if(dt >= 2*abs(this->jumpVelocity)/9.81 or this->getPosition().y >= this->start_y+0.00001){
            this->setPosition(this->getPosition().x, this->start_y);
            this->start_y = NULL;
            this->timeY = NULL;
            this->velocityY = 0;
            std::cout<< "CZAS STOP!"<<std::endl;
        }
        else{
            this->velocityY = this->jumpVelocity + 9.81*dt;
            std::cout<< "VY = "<< this->velocityY <<std::endl;
        }
        std::cout << "Wysokosc : " << this->getPosition().y << std::endl;
        
    }
    
    this->move(this->velocityX, this->velocityY);
};


