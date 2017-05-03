#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <math.h>
#include "integrate.hpp"

std::mutex mtx;

double f1 (double x)
{
    return x * sin (x);   
}

double f2 (double x)
{
    return exp (-x) * x - cos(x);
}
int main ()
{
    const unsigned int thr_nu = 4;
    const double l = 0.0;
    const double r = 100*M_PI;
    double s = integrate (f1, l, r, thr_nu);
    std::cout<<"integral f1 from "<<l<<" to "<<r<<" is "<<s<<std::endl<<"Should be "<<-r<<std::endl;
    s = integrate (f2, l, r, thr_nu);
    std::cout<<"integral f2 from "<<l<<" to "<<r<<" is "<<s<<std::endl<<"Should be 1"<<std::endl;
    return 0;
}
