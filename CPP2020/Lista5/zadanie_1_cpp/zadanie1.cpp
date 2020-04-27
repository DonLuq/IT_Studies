#include "stos.h"
#include <iostream>


int main()
{
    Stos A;
    A.push(1);
    A.push(2);
    A.push(3);
    A.push(4);
    A.push(5);
    std::cout << A.top() << std::endl;
    A.push(6);
    std::cout << A.top() << "\t"<< A.size() << std::endl;
    A.pop();
    std::cout << A.top() << "\t"<< A.size() << std::endl;


}