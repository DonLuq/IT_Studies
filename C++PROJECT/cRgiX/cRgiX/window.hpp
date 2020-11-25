//
//  window.hpp
//  cRgiX
//
//  Created by LBs_MacOS on 10/24/20.
//  Copyright © 2020 LBs_MacOS. All rights reserved.
//

#ifndef window_hpp
#define window_hpp
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <array>


class window: public sf::RenderWindow{
public:
    int howManyBoxes = 0;
    float x = this->getPosition().x;
    float y = this->getPosition().y;
    std::array<sf::RectangleShape, 5> arrayOfBoxes;
    
    window(sf::VideoMode x,std::string y):sf::RenderWindow(x,y){
        losujElementTekstury();
        losujElementTekstury();
        losujElementTekstury();
        losujElementTekstury();
        losujElementTekstury();
    };
    
    /// Losowanie teskstur przeszkod
    void losujElementTekstury(int numberOfTable);
    void losujElementTekstury();

    void rysujElemetyTekstury();
    

    /// Zbieranie i czyszczenie po pozostalych funkcjach np. gdy tekstury sa juz poza mapa
    void checkStatus(int x = -100, int y = -100);

    bool czyZderzenie(float x,float y);
    
private:
    void przesunElementTekstury();
};






#endif /* window_hpp */
