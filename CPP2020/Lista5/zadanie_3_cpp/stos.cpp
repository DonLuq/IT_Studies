#include "stos.h"

Stos::~Stos()
{
    while (!this->empty())
        this->pop();
}

std::ostream &operator<< (std::ostream &F, Stos & const stos)
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