  
#include "stos.h"
#include <iostream>

int main()
{
    Stos stos;
    for (int i = 1; i <= 5; i++)
    {
        stos.push(i);
    }
    std::cout << stos;
}