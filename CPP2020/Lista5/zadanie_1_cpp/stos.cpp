#include "stos.h"
#include <cassert>

inline Stos::Stos()
:_capacity(initial_capacity), _size(0),
    _tab(new int[initial_capacity])
{
    assert(initial_capacity > 0);
}

inline Stos::~Stos()
{
    delete [] _tab;
}

inline void Stos::push(int n)
{
    if(_size == _capacity)
    {
        _grow();
    }
    _tab[_size] = n;
    _size++;
}

inline void Stos::pop()
{
    assert(!empty());
    _size--;
    if(_size*4<_capacity)
    {
        _shrink();
    }
}

inline int Stos::top() const
{
    assert(!empty());
    return _tab[_size-1];
} 

inline int& Stos::top()
{
    assert(!empty());
    return _tab[_size-1];
}

inline bool Stos::empty() const
{
    return _size == 0;
}

inline size_t Stos::size() const
{
    return _size;
}

void Stos::_grow()
{
    assert(_size == _capacity);

    _capacity*=2;
    int *p = new int[_capacity];

    for(size_t i = 0; i < _size; i++)
    {
        p[i] =  _tab[i];
    }
    _tab = p;
    delete [] p;
}

Stos::Stos(Stos const& rhx)
:_capacity(rhx._capacity),_size(rhx._size),_tab(new int[_capacity])
{
    for(size_t i = 0; i < _size; i++)
    {
        _tab[i] = rhx._tab[i];
    }
}

Stos& Stos::operator=(Stos const& rhs)
{
    if(this == &rhs)
    {
        return *this;
    }
    if(_capacity < rhs._size)
    {
        delete [] _tab;
        _capacity = rhs._size;
        _tab = new int[_capacity];
    }
    for(size_t i = 0; i < _size; i++)
    {
        _tab[i] = rhs._tab[i];
    }
    return *this;
}

void Stos::_shrink()
{
    assert(_capacity>4);
    _capacity /= 2;
}