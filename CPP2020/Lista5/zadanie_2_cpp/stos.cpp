#include "stos.h"
#include <cassert>

inline Stos::Stos()
: _pSzczyt(0), _size(0)
{}

inline bool Stos::empty() const 
{
    return _pSzczyt == 0;
}

inline void Stos::push (int n)
{
    _pSzczyt = new Ogniwo(n,_pSzczyt);
    _size++;
}

inline void Stos::pop()
{
    assert(!empty());
    Ogniwo* temp = _pSzczyt;
    _pSzczyt = _pSzczyt -> _nastepny_p;
    delete temp;
    _size--;
}

Stos::~Stos()
{
    while(!this -> empty())
    {
        this -> pop();
    }
}

inline int Stos::top() const
{
    assert(!empty());
    return _pSzczyt -> _dane;
}

inline int& Stos::top()
{
    assert(!empty());
    return _pSzczyt -> _dane;
}


//ZADANIE 2
Stos::Stos(const Stos & A)
:_size(A._size)
{
    _pSzczyt = new Ogniwo(A._pSzczyt->_dane,0);
    Ogniwo* poczatek = _pSzczyt;
    Ogniwo* temp = A._pSzczyt;
    
    for(int i = _size; i > 0; i--)
    {
        temp = temp -> _nastepny_p;
        _pSzczyt -> _nastepny_p = new Ogniwo(temp -> _dane,_pSzczyt -> _nastepny_p);  
        _pSzczyt = _pSzczyt->_nastepny_p;
    }
    _pSzczyt->_nastepny_p = 0;
    _pSzczyt = poczatek;
}

Stos& Stos::operator= (Stos const& A)
{
    if(this == &A)
    {
        return *this;
    }
    delete [] this -> _pSzczyt; 
    this -> _size = A._size;
    // this -> _pSzczyt = new Ogniwo(A._pSzczyt -> _dane,0);
    Ogniwo* Temp_A = A._pSzczyt;
    for(int i = _size; i > 0; i--)
    {
        _pSzczyt = new Ogniwo(Temp_A -> _dane,Temp_A); 
        Temp_A = Temp_A -> _nastepny_p;
        _pSzczyt = _pSzczyt -> _nastepny_p;
    }
    _pSzczyt -> _nastepny_p = 0;
    return *this;
}
//KONIEC ZADANIA 2