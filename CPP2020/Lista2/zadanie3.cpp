#include <iostream>
#include <vector>
#include <climits>

using namespace std;

double operator*(vector<double> &u,vector<double> &v){
    if(u.size()==v.size()){
        return 0;
    }
    double Iloczyn = 0;
    for(int y=0;y<u.size();y++){
        Iloczyn += u[y]*v[y];
    }
    return Iloczyn;
}

int main(){
    vector<double> u{3.3,2.3};
    vector<double> v{2.1,2.1};
    cout<<"Iloczyn u * v = "<< u*v << endl;
    
    return 0;
}