#include "stos.h"

Stos::~Stos()
{
    while (!this->empty())
        this->pop();
}

Stos::Stos(Stos const& rhs)
        :_pSzczyt(rhs._pSzczyt), _size(rhs._size)
{
    for (size_t i = 0; i < _size; i++)
        _pSzczyt[i]._dane = rhs._pSzczyt[i]._dane;
}

Stos & Stos:: operator=(const Stos &rhs)
{
    if (this == &rhs)
        return *this;
    if (_size < rhs._size)
    {
        delete _pSzczyt;
        _size = rhs._size;
        _pSzczyt = new Ogniwo(rhs._pSzczyt->_dane, rhs._pSzczyt);
    }
    _size = rhs._size;
    for (size_t i = 0; i < _size; i++)
        _pSzczyt[i]._dane = rhs._pSzczyt[i]._dane;
    return *this;
}

std::ostream &operator<< (std::ostream &F, Stos & stos)
{
    F << "(";
    F << stos.top();
    stos.pop();
    while (!stos.empty())
    {
        F << ", " << stos.top();
        stos.pop();
    }
    F << ")";
    return F;
}