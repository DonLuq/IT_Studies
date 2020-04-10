#include <cstdlib>

class Wektor
{
private:
    size_t _rozmiar;
    int * _ptab;

public:
    Wektor(size_t N);
    ~Wektor()
    {
        delete [] _ptab;
    }
    size_t size() const
    {
        return _rozmiar;
    } 
    int & operator[](int N)
    {
        return _ptab[N];
    }
    int operator[](int N) const
    {
        return _ptab[N];
    }
    void operator=(Wektor const & Wek);
};

inline Wektor::Wektor(size_t N)
:_rozmiar(N), _ptab(new int [N])
{
    for(int i=0;i<_rozmiar;i++)
    {
        _ptab[i] = 0;
    }
}