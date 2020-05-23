#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <math.h>

typedef unsigned long num_t;

bool is_prime(num_t n)
{
    for (num_t i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return n == 1 ? false : true;
}

bool is_truncable_prime(num_t num)
{
    std::string num_str_left = std::to_string(num);
    std::string num_str_right = num_str_left;

    do
    {
        if (!is_prime(std::stoul(num_str_left)) || !is_prime(std::stoul(num_str_right)))
            return false;

        num_str_left.erase(num_str_left.begin());
        num_str_right.erase(num_str_right.end() - 1);

    } while (num_str_left.size() > 0);
    return true;
}

int main()
{
    std::vector<num_t> trunc_primes;
    num_t num = 11;
    while (trunc_primes.size() != 11)
    {
        if (is_truncable_prime(num))
            trunc_primes.push_back(num);
        ++num;
    }

    std::cout << std::accumulate(trunc_primes.begin(), trunc_primes.end(), 0) << std::endl;
    return 0;
}