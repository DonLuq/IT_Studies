#include <iostream>
#include <math.h>

class Zespolona{
public:
double R_part;
double I_part;

Zespolona(double const & R,double const & I)
:R_part(R),I_part(I)
{   
}

Zespolona(double const & R)
:R_part(R),I_part(0)
{
}

Zespolona()
:R_part(0),I_part(0)
{
}

Zespolona operator+(Zespolona const & X)
{
    return Zespolona(this->R_part+X.R_part,this->I_part+X.I_part); // Dlaczego tak?
}

Zespolona operator-(Zespolona const & X)
{
    return Zespolona(this->R_part-X.R_part,this->I_part-X.I_part); 
}

Zespolona operator*(Zespolona const & X)
{  
    return Zespolona(this->R_part*X.R_part-this->I_part*X.I_part,this->R_part*X.I_part+this->I_part*X.R_part); 
}

Zespolona operator/(Zespolona const & X)
{
    return Zespolona((this->R_part*X.R_part+this->I_part*X.I_part)/(X.R_part*X.R_part+X.I_part*X.I_part),(this->I_part*X.R_part-this->R_part*X.I_part)/(X.R_part*X.R_part+X.I_part*X.I_part));
}

};

std::ostream& operator<<(std::ostream & Exit, class Zespolona const & X)
{
    if(X.I_part<0)
    Exit << "(" << X.R_part << X.I_part << "i)" << std::endl;
    else
    Exit << "(" << X.R_part << "+" << X.I_part << "i)" << std::endl;
    return Exit;
}

std::istream& operator>>(std::istream& INPUT, Zespolona const & X)
{
    std::cout<< "Real part: "; 
    INPUT >> X.R_part;
    std::cout<< "Image part: "; 
    INPUT >> X.I_part;
    return INPUT;
}


int main(){
    Zespolona K(1,1);
    Zespolona B(1,1);
    std::cout << K-B;
    std::cout << K+B;
    std::cout << K*B;
    std::cout << K/B;
}