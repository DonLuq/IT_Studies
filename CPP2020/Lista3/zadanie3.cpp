#include <iostream>
#include <time.h>

using namespace std;

int main(){
    long long int A = 0;

    time_t Time;
    Time = clock();
    long long int N = 1130000;
    for(long long int n = 1; n <= N; ++n){
        int *p = new int[n];
        delete [] p;
    }

    time_t Timeoff = (clock() - Time)*1000/CLOCKS_PER_SEC;
    cout << Timeoff << " ms"<< endl; // 1001ms

    time_t Time2;
    Time2 = clock();
    for(long long int n=1;n<1000000;n++){
        A = A + 5;
    }
    time_t Timeoff2 = (clock() - Time2)*1000000/CLOCKS_PER_SEC;
    cout << Timeoff2 << " ns"<< endl; // 3000ns // Dla jednego dodania t= 3000/1000000 = 3e-3 ns

    return 0;

    // czas wykoniania pojedynczego dodawania wyznaczonaczam jako 1sec/1130000=> 0.885ns
    
}

