#include <iostream>
#include <string>

struct Pracownik{
    std::string imie;
    std::string nazwisko;
    int rok_urodz;
};

std::ostream& operator<<(std::ostream& F,struct Pracownik const& pracownik){
    F << pracownik.imie << " " << pracownik.nazwisko << " (" << pracownik.rok_urodz <<")"<< std::endl;
    return F;
}

int main(){
    Pracownik president;
    president.imie = "Andrzej";
    president.nazwisko = "Duda";
    president.rok_urodz = 1973;

    std::cout << president << std::endl;

    Pracownik * prac = new Pracownik;
    (*prac).imie = "Adam";
    (*prac).nazwisko = "Kowalski";
    (*prac).rok_urodz = 1971;

    std::cout << *prac << std::endl;
    delete prac;
    return 0;
}