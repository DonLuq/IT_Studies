#include "stos.h"
#include <cassert>

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

Stos::~Stos()
{
    while (!this->empty())
    {
        this->pop();
    }
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
//ZADANIE 2

Stos::Stos(const Stos &A)
    : _size(A._size)
{
    Ogniwo *temp_oryginal = A._pSzczyt;
    Ogniwo *temp_kopia = _pSzczyt;
    temp_kopia->_dane = temp_oryginal->_dane;

    for (int i = _size - 1; i > 0; i--)
    {
        temp_kopia->_nastepny_p = new Ogniwo(0, NULL);
        temp_kopia = temp_kopia->_nastepny_p;

        temp_oryginal = temp_oryginal->_nastepny_p;

        temp_kopia->_dane = temp_oryginal->_dane;
    }
}

Stos &Stos::operator=(Stos const &A)
{
    if (this == &A)
    {
        return *this;
    }
    delete [] this -> _pSzczyt;
    this ->_size = A._size;

    _pSzczyt = new Ogniwo(0,NULL);

    Ogniwo* temp_oryginal = A._pSzczyt;
    Ogniwo* temp_kopia = _pSzczyt;
    temp_kopia -> _dane = temp_oryginal -> _dane;
    for(int i = _size-1; i>0; i--)
    {
        temp_oryginal = temp_oryginal ->_nastepny_p;
        temp_kopia -> _nastepny_p = new Ogniwo(temp_oryginal->_dane,NULL);
    }
    return *this; // dlaczego zwracamy wskaznik na typ Stos? a nie referencje?
}
