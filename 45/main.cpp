#include <iostream>
#include <cmath>

typedef unsigned long long num_t;

bool is_pentagonal(const num_t &n)
{
    double fraction, integer;
    if (modf(sqrt(1 + 24 * n), &integer) == 0)
        if ((1 + (num_t)integer) % 6 == 0)
            return true;
    return false;
}

bool is_hexagonal(const num_t &n)
{
    double fraction, integer;
    if (modf(sqrt(1 + 8 * n), &integer) == 0)
        if ((1 + (num_t)integer) % 4 == 0)
            return true;
    return false;
}

int main()
{
    num_t n = 286;
    while (1)
    {
        num_t tri = 0.5 * n * (n + 1);
        if (is_pentagonal(tri))
            if (is_hexagonal(tri))
                break;
        ++n;
    }

    std::cout << "n: " << n << "\ttri: " << n * (n + 1) / 2 << std::endl;
    return 0;
}