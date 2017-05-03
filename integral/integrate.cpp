#include <thread>
#include <mutex>
#include <vector>
#include "integrate.hpp"

extern std::mutex mtx;

void thr_func (double (*f) (double x), double& summ,  double h, double left,
               const unsigned int my_nu, const unsigned int segment_nu, const unsigned int thread_nu)
{
    for (unsigned int i = my_nu; i < segment_nu; i += thread_nu)
    {
        mtx.lock ();
        summ += f (left + i * h);
        mtx.unlock ();
    }
}

double integrate (double (*f) (double x), const double left, const double right, const unsigned int thread_nu)
{
    const unsigned int segment_nu = 1000000;
    const double h = (right - left) / (double) segment_nu;
    double result = (f(left) + f(right)) / 2;
    std::vector <std::thread> threads;
    for (unsigned int i = 0; i < thread_nu; i++)
        threads.push_back (std::thread(thr_func, f, std::ref(result), h, left, i, segment_nu, thread_nu));
    for (auto& i : threads)
        i.join ();
    /*
    for (unsigned int i = 1; i < segment_nu; i++)
        result += f(left + i * h);
    */
    result *= h;
    return result;
}

