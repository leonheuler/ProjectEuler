#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <iterator>

typedef unsigned long num_t;
typedef std::vector<num_t> vec_t;
typedef std::string dig_t;

bool is_desired(num_t n);
num_t pow_to_5(const char &d);

int main()
{
    vec_t v;
    for (num_t n = 1; n < 1e8; ++n)
        if (is_desired(n))
            v.push_back(n);
    std::cout << std::accumulate(v.begin(), v.end(), (num_t)0);
    return 0;
}


bool is_desired(num_t n)
{
    dig_t digs = std::to_string(n);
    vec_t pows;
    std::transform(digs.begin(), digs.end(), std::back_inserter(pows), pow_to_5);

    return n == std::accumulate(pows.begin(), pows.end(), (num_t)0);
}

num_t pow_to_5(const char &d)
{
    return pow((num_t)(d-'0'), 5);
}

