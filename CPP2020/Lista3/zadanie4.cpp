#include <iostream>

using namespace std;


int main(){
    double tab[10];
    double x;
    cout << &x << "\t" << &tab[-1] << "\n"; // 0x7ffee88a79b0	0x7ffee88a79b8
    //Kompilator jest sprytny i rezerwuje pierwsze komorke pamieci dla pojedynczego double x niz tablicy.
    //Rezerwuje dla Tablicy 8 bitow dalej, ze wzgledu na to ze pomiedzy prawdopodobnie byly jakies inne dane zapisane badz parzysta liczba byla bardziej optymalna.

    return 0;
}