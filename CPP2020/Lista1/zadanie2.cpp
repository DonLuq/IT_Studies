#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    long double wynikA = 0;
    long double wynikB = 1;
    long double wynikC = 0;
    long int n = 1000000;
    for (long int j = 1; j < n + 1; j++)
    {
        wynikA += pow(-1, j + 1) / (2 * j - 1);
        wynikB *= 4 * pow(j, 2) / (4 * pow(j, 2) - 1);
        wynikC += 1.0/((2*j-1)*(2*j-1)); 
        // wynikC += 1 / pow((2 * j - 1), 2);
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    cout << "A = " << 4 * wynikA << endl;
    cout << "B = " << 2 * wynikB << endl;
    cout << "C = " << pow(8 * wynikC, 0.5) << endl;
    cout << "pi =" << M_PI << endl;
    return 0;
}