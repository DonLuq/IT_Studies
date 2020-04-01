#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<double> zeruj(vector<double> & N){
for(int i=0;i<N.size();i++){
    N[i] = 0;
}
return N;
}

int main(){
    vector<double> N{1,2,3,434,54,6,132,432,54};
    for(int j=0;j<N.size();j++){
        cout << N[j] <<" ";
    }
    cout<<"\n";
    zeruj(N);
    for(int j=0;j<N.size();j++){
        cout << N[j] <<" ";
    }
    cout<<"\n";

    return 0;
}