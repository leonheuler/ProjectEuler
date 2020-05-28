#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>

#define LIMIT 1e6

typedef unsigned long long num_t;

bool is_prime(num_t n)
{
    for (num_t i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return n == 1 ? false : true;
}

int main()
{
    std::vector<num_t> primes;
    for (num_t n = 2; n < LIMIT / 2; ++n)
        if (is_prime(n))
        {
            primes.push_back(n);
            if (std::accumulate(primes.begin(), primes.end(), 0) > LIMIT)
                break;
        }

    num_t ans = 0;
    num_t maxlen = 0;
    for (auto it = primes.begin(); it != primes.end() - 1; ++it)
    {
        std::vector<num_t> ps;
        std::partial_sum(it, primes.end(), std::back_inserter(ps));
        for (auto jt = ps.begin(); jt != ps.end() && *jt < LIMIT; ++jt)
        {
            if (is_prime(*jt))
            {
                ptrdiff_t len = std::distance(ps.begin(), jt);
                if (len > maxlen)
                {
                    maxlen = len;
                    ans = *jt;
                    std::cout << ans << " " << maxlen << std::endl;
                }
            }
        }
    }

    return 0;
}