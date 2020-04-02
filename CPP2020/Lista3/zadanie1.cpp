#include <iostream>
#include <string>

void kopiuj(char* dokad,const char* skad){
    while(*dokad++ = *skad++)
        continue;
    //najwyzszy priorytet ma operator wyluskiwania * dzialający na wskazniki dokad i skad,
    //następnie dziala operator przypisania,
    //nastepnie dziala operator ++, przemieszczajac wskaznik o jeden w pamieci.

    //operator ++ zwraca wskaznik wskazujacy na o jedna dalej wartosc pamieci niz wczesniej.
    //operator * zwraca nam miejsce w pamieci dla objektu.
    //operator przypisania zwraca nowe przypisanie wskaznika dokad na skad
    
    //wyrazenie w petli while, jest interpretowane jako true dopuki jest realizowane, 
    //jezeli nie ma mozliwosci jego zrealizowania while przyjmuje false
}

int main(){
    char bufor[200];
    kopiuj(bufor,"Ala ma kota");
    std::cout << "Tekst" << bufor << " ma dlugosc "<< std::strlen(bufor) << std::endl;
}