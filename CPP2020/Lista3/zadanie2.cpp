#include <iostream>
#include <vector>


int main(){

    double (*Tablica_A)[100]; //wskaznik na tablice 100 liczb typu double
    
    char * Tablica_B[5][5]; //dwuwymiarowa tablica 5x5 wskaznikow na char

    char * Tablica_C[]; // tablica o nieokreslonej wielkosci wskaznikow na char

    std::vector<void*> Wskaznik_na_Wektor; // standardowy vetor wskaznikow na void

    std::vector<double> Tablica_D[4]; // czteroelementowa tablica vectorow typu double

    double funkcjaB(double Tablica[] ,int liczba){return Tablica[];};
    double (*funkcjaB)(double*,int); // wskaznik na funkcja zwracajaca typ double i przyjmujaca tablice double oraz  liczbe int

    int * p;
    void (*funkcjaB)(int* & p); // funkcja przyjmujaca przez referencje wskaznik na int , nie rozumiem tego przykladu do konca.
}