#include <iostream>
#include "random.h"
#include <fstream>
#include <fstream>

int main()
{
    Random liczb_losowa;

    std::ofstream Plik;
    Plik.open("data.txt");

    for (int i = 0; i < 1000; i++)
    {
        Plik << liczb_losowa() << std::endl;
    }
    Plik.close();
    //plik utworzony obrobiony zostal przy uzyciu pythona
}