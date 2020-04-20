#include <iostream>
#include <string>

void kopiuj(char* dokad,const char* skad){
    while(*dokad++ = *skad++)
        continue;
    //najwyzszy priorytet ma operator ikrementacji ++, a najnizszy operator przypisania =.

    //operator ++ zwraca wskaznik komorki pamieci, wskazujacy na o jedna dalej wartosc adresu niz wczesniej.
    //operator * zwraca nam miejsce w pamieci dla objektu, jest to operator wyluskiwania.
    //operator przypisania zwraca nowe przypisanie wskaznika dokad na skad
    
    //while bedzie wykonywany dopoki wartosc wyrazenia logicznego bedzie rozna od 0.
    
}

int main(){
    char bufor[200];
    kopiuj(bufor,"Ala ma kota");
    std::cout << "Tekst" << bufor << " ma dlugosc "<< std::strlen(bufor) << std::endl;
}