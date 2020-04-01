#include <iostream>

using namespace std;

int nwd(int x, int y){


    if(x == 0 || y == 0) return -1;

    x = std::abs(x);
    y = std::abs(y);

    while (x != y)
    {
        if(x > y)
        {
            x -= y;
        }
        else
        {
            y -= x;
        }
    }
    return x;
}

int main()
{
    cout << nwd(12,24) << endl;
    return 0;
}