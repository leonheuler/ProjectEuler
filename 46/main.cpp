#include <iostream>
#include <cmath>

typedef unsigned long num_t;

bool is_prime(num_t n)
{
    for (num_t i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}

bool is_odd(num_t n)
{
    return n % 2 != 0;
}

int main()
{
    num_t n = 9;
    while (1)
    {
        if (is_odd(n))
        {
            if (!is_prime(n))
            {
                bool found = false;
                for (num_t p = 3; p <= n - 2; ++p)
                {
                    if (is_prime(p))
                    {
                        double fraction, integer;
                        if (modf(sqrt((n - p) / 2), &integer) == 0)
                            found = true;
                    }
                }
                if (!found)
                    break;
            }
        }
        ++n;
    }
    std::cout << n << std::endl;
    return 0;
}