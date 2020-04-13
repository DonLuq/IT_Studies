#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>

using namespace std;

int fibo1(int n){
    if(n<2){
        return 1;
    }
    else{
        return fibo1(n-1)+fibo1(n-2);
    }
}

int fibo2(int n){
    return ceil(1.0/sqrt(5.0)*(pow(2.0/(sqrt(5.0)-1),n+1)-pow(-2.0/(sqrt(5.0)+1.0),n+1)));
    // return f;
}

int fibo3(int n){
    if(n==0){return 1;}
    if(n==1){return 1;}
    static bool RUN = true;
    static vector<int> wektor(n+1);
    if(RUN){
        RUN=false;
        wektor[0] = 1;
        wektor[1] = 1;
        for(int i = 0;i<wektor.size()-2;i++){
            wektor[i+2]=wektor[i]+wektor[i+1];
        }

    }
    return wektor[n];
}


int main(){
    int n = 30;
    double_t time;


    time = clock();
    cout << "Fib1 liczba dla n = "<<n<<" Wynosi: "<<fibo1(n)<<endl;
    cout << "Fib1 Czas wykonania : "<< (clock()-time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;

    time = clock();
    cout << "Fib2 liczba dla n = "<<n<<" Wynosi: "<<fibo2(n)<<endl;
    cout << "Fib2 Czas wykonania : "<< (clock()-time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;

    time = clock();
    cout << "Fib3 liczba dla n = "<<n<<" Wynosi: "<<fibo3(n)<<endl;
    cout << "Fib3 Czas wykonania : "<< (clock()-time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;

    cout <<fibo3(3) <<" "<<fibo3(7)<<"\n";

    return 0;
}