#include <iostream>
#include <string>
#include <vector>

class Wektor
{
public: 
    size_t const m_rozmiar;
    int * const m_ptab;

    Wektor(size_t n)
    :m_rozmiar(n),m_ptab(new int[n])
    {}

    ~Wektor()
    {
        delete [] m_ptab;
    }

    size_t size() const
    {
        return m_rozmiar;
    }

    int & at(int n)
    {
        return m_ptab[n];
    } 

    int at(int n) const
    {
        return m_ptab[n];
    } 

    Wektor(Wektor const& w)
    :m_rozmiar(w.m_rozmiar),m_ptab(new int[w.m_rozmiar])
    {
        for(size_t i = 0;i < m_rozmiar;i++)
        {
            m_ptab[i]=w.m_ptab[i];
        }
    }
    
    // void f(Wektor w)
    // {
    //     w[1]=100;
    // }
};




int main(){
    Wektor v(10);
    v.at(5) = 1;
    std::cout<<"Rozmiar wektor v = "<< v.size()<<", wartosc elementu 6 = "<< v.at(5) << std::endl;
    Wektor u(10);
    // u[1] = 1;
    // std::cout << "Przed v[1] = "<<u[1]<<std::endl;
    // Wektor::f(u);
    // std::cout << "Po v[1] = "<<u[1]<<std::endl;

}