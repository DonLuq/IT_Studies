#ifndef MAIN_STOS_H
#define MAIN_STOS_H
#include <cstdlib>
#include <cassert>
#include <iostream>

struct Ogniwo
{
    Ogniwo(int n, Ogniwo *p)
    :_dane(n), _p_nastepny(p)
    {}

    int _dane;
    Ogniwo *_p_nastepny; //rekurenycjna struktura danych
};

class Stos
{
    friend std:: ostream& operator<< (std::ostream &, Stos &);
public:
    Stos (); //konstruktor domyślny
    Stos(Stos const&); //konstruktor kopiujący
    ~Stos(); //destruktor

    void push(int i); //dokłada liczbę na stos
    void pop(); //zdejmuje liczbę ze stosu
    void reverse(); //
    int top()const; //udostępnia wartość liczby na szczycie stosu
    int& top(); //udostępnia referencję do liczby na szczycie stosu
    bool empty() const; //czy stos jest pusty?
    size_t size() const; //bieżacy rozmiar logiczny stosu
    Stos& operator=(Stos const&); //operator przypisania
private:
    Ogniwo* _pSzczyt; //wskaznik na ogniwo leżące na szczycie stosu
    size_t _size; //rozmiar stosu
};

inline Stos::Stos()
:_pSzczyt(0), _size(0)
{}

inline bool Stos::empty() const {return _pSzczyt == 0;}

inline void Stos::push(int n)
{
    _pSzczyt = new Ogniwo(n, _pSzczyt);
    _size++;
}

inline void Stos::pop()
{
    assert(!empty());
    Ogniwo * temp = _pSzczyt;
    _pSzczyt = _pSzczyt->_p_nastepny;
    delete temp;
    _size--;
}

inline int Stos::top() const
{
    assert(!empty());
    return _pSzczyt->_dane;
}

inline int& Stos::top()
{
    assert(!empty());
    return _pSzczyt->_dane;
}

#endif //MAIN_STOS_H