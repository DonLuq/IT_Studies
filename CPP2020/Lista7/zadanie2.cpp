#include <iostream>
#include <fstream>
#include <cmath>

class PPMimage
{
public:
    struct Kolor
    {
        unsigned char red, green, blue;
    };

    PPMimage(const char nazwa_pliku[]); //wczytanie obrazu z pliku
    ~PPMimage();
    void zapisz(const char nazwa_pliku[]); // zaoisanie obraz w pliku
    void znieksztalc(int param_x, int param_y);
    void zmiekcz();
    void ppm2pgm();

private:
    PPMimage(PPMimage const &) {}
    void operator=(PPMimage const &) {}

    int _szerokosc;
    int _wysokosc;
    int _glebia;
    Kolor **_tab;
};

PPMimage::PPMimage(const char nazwa_pliku[])
{
    std::ifstream F(nazwa_pliku, std::ios::binary);
    std::string s;
    F >> s >> std::ws;
    while (F.peek() == '#')
    {
        F.ignore(100000, '\n');
    }
    F >> _szerokosc >> _wysokosc >> _glebia;
    F.ignore(100000, '\n');
    _tab = new Kolor *[_wysokosc];
    for (int i = 0; i < _wysokosc; ++i)
    {
        _tab[i] = new Kolor[_szerokosc];
        char *adres = reinterpret_cast<char *>(_tab[i]);
        F.read(adres, sizeof(Kolor) * _szerokosc);
    }
}

void PPMimage::znieksztalc(int param_x, int param_y)
{
    Kolor *p = new Kolor[_szerokosc];
    for (int y = 0; y < _wysokosc; ++y)
    {
        int dx = int(0.5 + param_x / 2.0 * sin(2 * M_PI * y / param_y));
        for (int x = 0; x < _szerokosc; x++)
        {
            int index = (x + dx) % _szerokosc;
            if (index < 0)
                index += _szerokosc;
            p[x] = _tab[y][index];
        }
        std::swap(_tab[y], p);
    }
    delete[] p;
}

void PPMimage::zapisz(const char nazwa_pliku[])
{
    std::ofstream F(nazwa_pliku, std::ios::binary);
    F << "P6\n"
      << _szerokosc << " " << +_wysokosc << "\n"
      << _glebia << "\n";
    for (int i = 0; i < _wysokosc; ++i)
        F.write(reinterpret_cast<char *>(_tab[i]), 3 * _szerokosc);
}

PPMimage::~PPMimage()
{
    for (int i = 0; i < _wysokosc; ++i)
        delete[] _tab[i];
    delete[] _tab;
}

void PPMimage::zmiekcz()
{
    Kolor *p = new Kolor[_szerokosc];
    for (int h = 0; h < _wysokosc; ++h)
    {
        for (int x = 0; x < _szerokosc; ++x)
        {
            unsigned char R, G, B;
            if (x == 0)
            {
                R = (_tab[h][x + 1].red + _tab[h][x].red) / 2;
                G = (_tab[h][x + 1].green + _tab[h][x].green) / 2;
                B = (_tab[h][x + 1].blue + _tab[h][x].blue) / 2;
            }
            else if (x == _szerokosc - 1)
            {
                R = (_tab[h][x].red + _tab[h][x - 1].red) / 2;
                G = (_tab[h][x].green + _tab[h][x - 1].green) / 2;
                B = (_tab[h][x].blue + _tab[h][x - 1].blue) / 2;
            }
            else
            {
                R = (_tab[h][x + 1].red + _tab[h][x - 1].red) / 2;
                G = (_tab[h][x + 1].green + _tab[h][x - 1].green) / 2;
                B = (_tab[h][x + 1].blue + _tab[h][x - 1].blue) / 2;
            }
            p[x].red = R;
            p[x].green = G;
            p[x].blue = B;
        }
        std::swap(_tab[h], p);
    }
    delete[] p;
}

void PPMimage::ppm2pgm()
{
    const char nazwa_pliku[] = "konwert.pgm";
    int *TAB[_wysokosc];
    int *p = new int[_szerokosc];
    for (int h = 0; h < _wysokosc; ++h)
    {
        for (int x = 0; x < _szerokosc; ++x)
        {
            p[x] = (_tab[h][x].red + _tab[h][x].green + _tab[h][x].blue) / 3;
        }
        std::swap(TAB[h], p);
    }
    delete[] p;

    std::ofstream F(nazwa_pliku, std::ios::binary);
    F << "P5\n"
      << _szerokosc << " " << +_wysokosc << "\n"
      << _glebia << "\n";
    for (int i = 0; i < _wysokosc; ++i)
    {
        F.write(reinterpret_cast<char *>(TAB[i]), 3 * _szerokosc);
    }
    F.close();
}

// class PGMimage
// :PPMimage
// {
// public:
//     struct Szarosc{int szarosc;};

//     PGMimage(const char nazwa_pliku[]);
//     ~PGMimage();
//     void zapisz(const char nazwa_pliku[]);

// private:
//     int _wysokosc;
//     int _szerokosc;
//     int _tab**;
// }

int main()
{
    PPMimage image("west_2.ppm");
    image.ppm2pgm();
}