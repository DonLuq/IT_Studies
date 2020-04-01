#include <iostream>
#include <vector>

using namespace std;

unsigned silnia(unsigned n){
    if(n==0){
        return 0;
    }
    else{
        return n = silnia(n-1);
    }
}

int main(){
    for(int i=0;i<5;++i){
        cout << i << "! = "<<silnia(i)<<endl;
    }
    cout << silnia(-1)<<endl;

    //Pojawia sie Segmentation fault: 11, swiadczacy o probie odczytu/zapisania poza pamiecia nadana danemu procesowie,
    //wynika to z faktu wybrania typu unsighned ktory moze przyjmowac wartosci wylacznie dodatnie i 0. 
    return 0;
}