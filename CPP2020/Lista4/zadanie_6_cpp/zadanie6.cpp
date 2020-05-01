#include <iostream>

class X
{
    friend std::ostream & operator<<(std::ostream &,X const&); // program nie kompiluje sie bez friend
private:
    int _x;
public:
    X(int arg) : _x(arg){}
};

std::ostream& operator<<(std::ostream & F, X const& arg)
{
    // return F << arg;
    return F << arg._x; // bez friend nie ma mozliwosci uzycia tutaj zmiennej prywatnej
    //bez zaprzyjaznienia klasy X z std::ostreamem, operator strumieniowy << nie ma dostepu do zmiennej prywatnej _x obiektu arg.
    //Blad polagal na probie wypisania obiektu klasy X zamiast zmiennej prywatnej obiektu.
}

int main()
{
    X x(10);
    std::cout << x << std::endl;
}