#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int smalest(vector<int> & N){
    if(N.size()==0){ 
       return INT_MIN;
    }
    int number = N[0];
    for(int i=0; i<N.size();i++){
        if(N[i] <= number){
            number = N[i];
        }
    }
    return number;
}

int main(){

    vector<int>  wektor{31,321,32,43,12,54,-10,1};
    vector<int>  vek{};
    int smallest_number =  smalest(wektor);
    cout<<"Najmniesza wartosc wektora to: "<<smallest_number<<endl;

    return 0;
}

//c++ zadanie1.cpp -std=c++0x