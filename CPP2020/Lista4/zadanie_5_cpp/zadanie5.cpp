#include <iostream>

//U mnie na systemie MacOS kod dziala prawidlowo bez poprawek

class Samochod
{
public:
    Samochod(int n)
    :_kola(n),_sruby(4*n)//Teoretyczny blad wystepuje w tym miejscu, polega na uzyciu jeszcze nie istniejacej zmiennej _kola(nie ma ona wlasciwej wartosci przypiasnej) w tworzeniu zmiennej _sruby 
    {
        std::cout << "Samochod ma "<< _kola << " kola i " << _sruby << "sruby"<< std::endl;
    }
private:
int _kola;
int _sruby;
};

int main()
{
    Samochod A(4);
    Samochod B(12);
}

//blad mozna usunac operujac bezposrednio na danych uzytych do inicjacji uzytej zmiennej