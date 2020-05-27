#include <iostream>
#include <map>
#include <cmath>

typedef unsigned long num_t;

std::map<int, int> factorization(num_t n)
{
    std::map<int, int> ret;
    num_t d = 2;
    while (d <= sqrt(n))
    {
        if (n % d == 0)
        {
            ++ret[d];
            n /= d;
            d = 2;
        }
        else
            ++d;
    }
    ++ret[n];
    return ret;
}

int main()
{
    num_t n = 2;
    while (n++)
        if (factorization(n).size() == 4 && factorization(n + 1).size() == 4 && factorization(n + 2).size() == 4 && factorization(n + 3).size() == 4)
            break;

    std::cout << n << std::endl;
    return 0;
}