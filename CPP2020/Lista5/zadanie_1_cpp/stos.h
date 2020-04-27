#include <iostream>
#include <climits>

class Stos
{
public:
    Stos(); //konstruktor domyslny
    Stos(Stos const&); // konstrukto kopiujacy
    ~Stos();

    void push(int i); //dodaj na stos
    void pop(); //zdejmij ze stosu
    int top() const; //udostepnia wartosc liczby na szczycie stosie
    int& top(); // udostepnia referencje do wartosci liczby na szczycie stosu
    bool empty() const; // czy stos jest pusty? , const zapobiega edycji
    size_t size() const; // metoda zwracajaca rozmiar stosu
    Stos& operator= (Stos const&);// operator przypisania

private:
    enum {initial_capacity = 1};
    void _grow(); // prywatna funkcja do rozszerzenia 

    void _shrink();  // zadanie 1

    size_t _capacity;
    size_t _size;
    int* _tab; // tablica z danymi
};