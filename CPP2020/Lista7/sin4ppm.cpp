#include <iostream>
#include <fstream>
#include <cmath>

class PPMimage
{
public:
    struct Kolor { unsigned char red,green,blue; };

    PPMimage(const char nazwa_pliku[]); //wczytanie obrazu z pliku
    ~PPMimage();
    void zapisz(const char nazwa_pliku[]); // zaoisanie obraz w pliku
    void znieksztalc(int param_x,int param_y); 
private:
    PPMimage(PPMimage const&){}
    void operator= (PPMimage const&){}

    int _szerokosc;
    int _wysokosc;
    int _glebia;
    Kolor** _tab;
};

PPMimage::PPMimage(const char nazwa_pliku[])
{
    std::ifstream F(nazwa_pliku, std::ios::binary);
    std:: string s;
    F >> s >> std::ws;
    while(F.peek()=='#')
    {
        F.ignore(100000,'\n');
    }
    F >> _szerokosc >> _wysokosc >> _glebia;
    F.ignore(100000,'\n');
    _tab = new Kolor*[_wysokosc];
    for(int i = 0;i< _wysokosc;++i)
    {
        _tab[i] = new Kolor [_szerokosc];
        char* adres = reinterpret_cast<char*>(_tab[i]);
        F.read(adres, sizeof(Kolor) * _szerokosc);
    }
}

void PPMimage::znieksztalc(int param_x,int param_y)
{
    Kolor * p = new Kolor [_szerokosc];
    for(int y = 0; y< _wysokosc; ++y)
    {
        int dx = int(0.5 + param_x/2.0 * sin(2*M_PI*y/param_y));
        for(int x = 0; x< _szerokosc; x++)
        {
            int index = (x + dx)%_szerokosc;
            if(index < 0)
                index += _szerokosc;
            p[x] = _tab[y][index];
        }
        std::swap(_tab[y],p);
    }
    delete [] p;
}

void PPMimage::zapisz(const char nazwa_pliku[])
{
    std::ofstream F(nazwa_pliku, std::ios::binary);
    F << "P6\n" << _szerokosc << " " << +_wysokosc << "\n" << _glebia << "\n";
    for (int i = 0; i < _wysokosc; ++i)
        F.write(reinterpret_cast<char*>(_tab[i]), 3* _szerokosc);
}

PPMimage::~PPMimage()
{
    for(int i = 0;i< _wysokosc; ++i)
        delete [] _tab[i];
    delete [] _tab;
}

int main()
{
    PPMimage image("west_2.ppm");
    image.znieksztalc(50,50);
    image.zapisz("nowy1.ppm");
}