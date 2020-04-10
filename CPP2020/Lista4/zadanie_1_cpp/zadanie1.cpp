#include <iostream>
#include "wektor.h"
#include <cassert>


int main()
{
    Wektor wektorek(10);
    // assert(wektorek.size()!=10); //to run without checking assert state use : c++ -DNDEBUG NAME_FILE.cpp -o NAME_FILE.exe
    std::cout<< wektorek.size()<< std::endl;
    for(int i=0;i<wektorek.size();i++)
    {
        std::cout << wektorek[i] << std::endl;
    }
}