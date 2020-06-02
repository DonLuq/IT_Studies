#include "stos.h"
//ZADANIE 2
Stos::~Stos()
{
    while (!this->empty())
    {
        this->pop();
    }
}

Stos::Stos(Stos const& rhs)
        :_pSzczyt(rhs._pSzczyt), _size(rhs._size)
{
    if(rhs.empty())
    {
        _pSzczyt = nullptr;
        _size = 0;
        return;
    }
    _pSzczyt = new Ogniwo(rhs._pSzczyt->_dane,nullptr);
    Ogniwo* start = _pSzczyt;
    Ogniwo* temp = rhs._pSzczyt;
    while(temp->_nastepny_p != nullptr)
    {
        temp = temp -> _nastepny_p;
        _pSzczyt->_nastepny_p = new Ogniwo(temp->_dane,nullptr);
        _pSzczyt = _pSzczyt->_nastepny_p;
    }
    _pSzczyt = start;
}

Stos & Stos:: operator=(const Stos &rhs)
{
    if (this == &rhs)
        return *this;
    delete _pSzczyt;
    if(rhs.empty())
    {
        _pSzczyt = nullptr;
        _size = 0;
    }
    else
    {
        _pSzczyt = new Ogniwo(rhs._pSzczyt->_dane,nullptr);
        Ogniwo* start = _pSzczyt;
        Ogniwo* temp = rhs._pSzczyt;
        while(temp->_nastepny_p != nullptr)
        {
                temp = temp ->_nastepny_p;
                _pSzczyt->_nastepny_p = new Ogniwo(temp->_dane,nullptr);
                _pSzczyt = _pSzczyt ->_nastepny_p;
        }
        _pSzczyt = start;
    }
    


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
