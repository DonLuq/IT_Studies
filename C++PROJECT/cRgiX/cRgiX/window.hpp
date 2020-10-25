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


class window: public sf::RenderWindow{
public:
    float x;
    float y;
    sf::RectangleShape box1; // zamienic na tablice w pozniejszym etapie
    sf::RectangleShape box2;
    sf::RectangleShape box3;
    
    /// Losowanie teskstur przeszkod
    sf::RectangleShape losujElementTekstury();
    
    /// Zbieranie i czyszczenie po pozostalych funkcjach np. gdy tekstury sa juz poza mapa
    void checkStatus();
    
private:
};






#endif /* window_hpp */
