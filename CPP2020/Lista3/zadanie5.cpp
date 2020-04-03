#include <iostream>

using namespace std;

int main(){
    char haslo[8];
    strcpy(haslo,"Taj.nE!");
    for(;;){
        cout << "Podaj haslo: ";
        char tmp[8];
        cin >> tmp;
        if(strcmp(tmp,haslo)==0)
            break;
        cout << "Bledne haslo!!!\n";
    }
    cout<<"Witaj w systemie!\n";
    //wpisywane hasla jezeli maja powyzej 8 znakow to zaczynaja byc zapisywane w komorkach pamieci przyznanych zmiennej haslo,
    //i tak wpisanie hasla 16 znakowego powoduje nadpisanie hasla i utworzenie nowego z 9-16 liter kolejno, co nastepnie po wprowadzeniu ich
    //pozwala na zlamanie zabezpieczenia.
    return 0;
}