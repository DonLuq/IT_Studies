#include "wektor.h"

void Wektor::operator=(Wektor const & wek)
{
    if(this == &wek)
    {
        return;
    }

    delete [] _ptab;
    _rozmiar = wek._rozmiar;
    _ptab = new int [_rozmiar];
    for(int i=0;i<_rozmiar;i++)
    {
        _ptab[i] = wek._ptab[i];
    }
}