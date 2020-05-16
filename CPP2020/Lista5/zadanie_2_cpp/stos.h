#ifndef MAIN_STOS_H
#define MAIN_STOS_H
#include <iostream>
#include <climits>
#include <cassert>


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


inline Stos::Stos()
    : _pSzczyt(0), _size(0)
{
}

inline bool Stos::empty() const
{
    return _pSzczyt == 0;
}

inline void Stos::push(int n)
{
    _pSzczyt = new Ogniwo(n, _pSzczyt);
    _size++;
}

inline void Stos::pop()
{
    assert(!empty());
    Ogniwo *temp = _pSzczyt;
    _pSzczyt = _pSzczyt->_nastepny_p;
    delete temp;
    _size--;
}

inline int Stos::top() const
{
    assert(!empty());
    return _pSzczyt->_dane;
}

inline int &Stos::top()
{
    assert(!empty());
    return _pSzczyt->_dane;
}
#endif //MAIN_STOS_H