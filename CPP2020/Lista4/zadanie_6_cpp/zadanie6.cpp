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
    // return F << arg._x;
    return F << arg._x; // bez friend nie ma mozliwosci uzycia tutaj zmiennej prywatnej
}

int main()
{
    X x(10);
    std::cout << x << std::endl;
}