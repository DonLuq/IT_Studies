#include <iostream>

using namespace std;


int main(){
    double tab[10];
    double x;
    cout << &x << "\t" << &tab[-1] << "\n"; // 0x7ffee88a79b0	0x7ffee88a79b8
    //Kompilator jest sprytny i rezerwuje pierwsze komorke pamieci dla pojedynczego double x niz tablicy.
    //Rezerwuje dla Tablicy 8 bitow dalej, ze wzgledu na to ze pomiedzy prawdopodobnie byly jakies inne dane zapisane badz parzysta liczba byla bardziej optymalna.
    //Latwiej dla kompilatora jest znalesc 8 bitow dla double x niz 10x8bitow dla tab[10];, poza tym bardziej optymalnie jest
    //umieszczenie x w miejscu gdzie tab[10] nie zmiescilby sie.
    return 0;
}