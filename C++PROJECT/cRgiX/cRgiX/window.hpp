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
    int howManyTextures = 0;
    int doggyHigh = 75;
    float x = this->getSize().x;
    float y = this->getSize().y;
    std::array<sf::RectangleShape, 30> arrayOfBoxes;
    std::array<sf::Texture, 20> arrayOfTextures;
    
    window(sf::VideoMode x,std::string y):sf::RenderWindow(x,y){
        int i = 0;
        while( i < arrayOfBoxes.size())
        {
            losujElementTekstury(i);
            ++i;
        }
    };
    
    /// Losowanie teskstur przeszkod
    void losujElementTekstury(int numberOfTable);

    void losujElementTekstury();

    void rysujElemetyTekstury();
    
    bool intersekcjaKwadratow(sf::RectangleShape box);

    /// Zbieranie i czyszczenie po pozostalych funkcjach np. gdy tekstury sa juz poza mapa
    void checkStatus(int x = -100, int y = -100);

    bool czyZderzenie(float x,float y);

    void doggyHighSet(int X);

    bool ladowanieTekstur(std::string x);
    
private:
    void przesunElementTekstury();
};






#endif /* window_hpp */
