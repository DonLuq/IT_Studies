#include <iostream>

using namespace std;

void funkcjaB(int & p){
    std::cout << p << endl;
    // std::cout << p << endl;
    };


int main(){
    // int Zmienna = 20;
    int *p;

    cout << p << endl;
    cout << *p << endl;
    cout << p++ << endl;
    cout << *p++ << endl;
    funkcjaB(*p);

}