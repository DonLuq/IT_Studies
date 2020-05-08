#include "stos.h"
#include <iostream>

int main(){

Stos A = Stos();
for(int i=0;i<5;i++)
{
    A.push(i);
}

Stos B = Stos(A);

while(!A.empty())
{
    std::cout<< A.top() << "\t";
    A.pop();
};
std::cout << "\n";
while(!B.empty())
{
    std::cout<< B.top() << "\t";
    B.pop();
};

}