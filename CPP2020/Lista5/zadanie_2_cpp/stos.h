#include <iostream>
#include <climits>

struct Ogniwo
{
    Ogniwo(int n, Ogniwo* p)
    :_dane(n),_nastepny_p(p)
    {}

    int _dane;
    Ogniwo* _nastepny_p; 
};

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
    Ogniwo* _pSzczyt; // wskaznik na wartosc lezaca na stosie
    size_t _size;
};