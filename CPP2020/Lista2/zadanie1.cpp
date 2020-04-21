#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int smallest(vector<int> const & N){
    if(N.size()==0){ 
       return INT_MIN;
    }
    int number = N[0];
    for(int i=1; i<N.size();i++){
        if(N[i] <= number){
            number = N[i];
        }
    }
    return number;
    //petla wykonywana od i=1 poniewaz pierwsze przejscie dla petli zawsze bedzie spelnione bo porownanie N[0]==N[i=0]
}

int main(){

    vector<int>  wektor{31,321,32,43,12,54,-10,1};
    vector<int>  vek{};
    vector<int>  vekt{1,2};
    int smallest_number =  smallest(wektor);
    cout<<"Najmniesza wartosc wektora to: "<<smallest_number<<endl;

    return 0;
}

//c++ zadanie1.cpp -std=c++0x