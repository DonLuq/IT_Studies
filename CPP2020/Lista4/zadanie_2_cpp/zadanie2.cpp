#include <iostream>

class Zespolona{
public:
double R_part;
double I_part;

Zespolona(float const & R,float const & I)
:R_part(R),I_part(I)
{
    // if(I_part<0)
    // std::cout << "(" << R_part << I_part << "i)" << std::endl;
    // else
    // std::cout << "(" << R_part << "+" << I_part << "i)" << std::endl;
}

Zespolona(float const & R)
:R_part(R),I_part(0)
{
    // std::cout << "(" << R_part << "+" << I_part << "i)" << std::endl;
}

Zespolona()
:R_part(0),I_part(0)
{
}

Zespolona operator+(Zespolona & X)
{
    // return Zespolona(this.R_part+X.R_part,this.I_part+X.I_part) // a nie tak?
    return Zespolona(this->R_part+X.R_part,this->I_part+X.I_part); // Dlaczego tak?
}

Zespolona operator-(Zespolona & X)
{
    return Zespolona(this->R_part-X.R_part,this->I_part-X.I_part); 
}

Zespolona operator*(Zespolona & X)
{
    
    return Zespolona(this->R_part*X.R_part-this->I_part*X.I_part,this->R_part*X.I_part+this->I_part*X.R_part); 
}

Zespolona operator/(Zespolona & X)
{
    return Zespolona(this->R_part*X.R_part-X.I_part*this->I_part,this->I_part*X.R_part-this->R_part*X.I_part); 
}

};

std::ostream& operator<<(std::ostream &Exit, class Zespolona const& X)
{
    if(X.I_part<0)
    Exit << "(" << X.R_part << X.I_part << "i)" << std::endl;
    else
    Exit << "(" << X.R_part << "+" << X.I_part << "i)" << std::endl;
    return Exit;
}

std::istream& operator>>(std::istream& INPUT, Zespolona & X)
{
    std::cout<< "Real part: "; 
    INPUT >> X.R_part;
    std::cout<< "Image part: "; 
    INPUT >> X.I_part;
    return INPUT;
}


int main(){
    Zespolona K(2.5,3);
    Zespolona B(2,2);
    std::cout << K-B;
    std::cout << K+B;
    std::cout << K*B;
    std::cout << K/B;
}