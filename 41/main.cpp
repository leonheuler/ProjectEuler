#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

typedef unsigned long num_t;

bool is_pandigital(const num_t &n)
{   
    std::string s = std::to_string(n);
    const char max_digit = s[0];
    std::sort(s.begin(), s.end());
    return s.find('0') != std::string::npos || s[s.size()-1] > max_digit ? false : std::unique(s.begin(), s.end()) == s.end();
}

bool is_prime(num_t n)
{
    for (num_t i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    num_t n = 7654321;
    while (n >= 1)
    {
        if (is_pandigital(n))
            if (is_prime(n))
                break;
        --n;
    }

    std::cout << n << std::endl;
    return 0;
}