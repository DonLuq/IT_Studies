#include <iostream>
#include <cmath>
#include <iomanip>  

using namespace std;

double przybA(int i){
if(i==0){
    long double t = 1/pow(3,0.5);
    return t;
}
else{
    long double A = przybA(i-1);
    long double t = (pow(pow(A,2)+1,0.5)-1)/A;
    return t;
}


}

double przybB(int i){
if(i==0){
    long double t = 1/pow(3,0.5);
    return t;
}
else{
    long double B = przybB(i-1);
    long double t = B/(sqrt(pow(B,2)+1)+1);
    return t;
}


}


int main(){
long double WynikA;
long double WynikB;
cout << setprecision(9);
cout << fixed;
for(int K = 0 ; K<31; K++){
WynikA = 6 * pow(2,K)* przybA(K);
cout <<"A : Dla i = "<<K<<" Wynik = "<< WynikA << endl;


WynikB = 6 * pow(2,K)* przybB(K);
cout <<"B : Dla i = "<<K<<" Wynik = "<< WynikB << endl;
}

return 0;
}