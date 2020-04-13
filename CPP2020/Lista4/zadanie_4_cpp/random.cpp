#include "random.h"
#include <cassert>
#include <cmath>
#include <climits>


Random::Random(int  f1)
:_fn(f1)
{
assert(f1 > 0 && f1 < std::pow(2,31));
}

double Random::operator()()
{
long long wsp = _fn;
long long const_A = pow(2,31);  //structure error? compile it with "c++ zadanie3.cpp random.cpp" sentence.
wsp = (16807*wsp)%(const_A-1);
_fn = wsp;
return _fn/(pow(2,31)-2);

// long long wsp = this->_fn;
// wsp = (16807*wsp)%(INT_MAX);
// this->_fn = wsp;
// return wsp/(INT_MAX-1);
}

