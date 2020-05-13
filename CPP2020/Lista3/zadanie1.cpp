#include <iostream>
#include <string>

void kopiuj(char* dokad,const char* skad){
    while(*dokad++ = *skad++)
        continue;
    //najwyzszy priorytet ma operator ikrementacji ++, a najnizszy operator przypisania =.

    //operator ++ zwraca wskaznik komorki pamieci, wskazujacy na o jedna dalej wartosc adresu niz wczesniej.
    //Czyli np dla char bedzie wzkazywal na kolejna wartosc w tablicy.
    //operator * zwraca nam bezposrednio obiekt odpowiadajacy adresowi z pamieci, jest to operator wyluskiwania.
    //operator przypisania zwraca referencje char* obiektu dokad, i przypisuje mu skad.
    
    //while bedzie wykonywany dopoki wartosc wyrazenia logicznego bedzie rozna od 0.
    
}

int main(){
    char bufor[200];
    kopiuj(bufor,"Ala ma kota");
    std::cout << "Tekst" << bufor << " ma dlugosc "<< strlen(bufor) << std::endl;
}