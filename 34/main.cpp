#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>

typedef uint32_t num_t;

num_t factorial(num_t n)
{
    return n == 0 || n == 1 ? 1 : n * factorial(n - 1);
}

num_t digit_factorials_sum(num_t n)
{
    std::string num_str = std::to_string(n);
    std::vector<num_t> num_vec;
    std::transform(num_str.begin(), num_str.end(), std::back_inserter(num_vec), [](char n) { return factorial(n - 48); });
    return std::accumulate(num_vec.begin(), num_vec.end(), 0);
}

int main()
{
    num_t ans = 0;
    for (num_t n = 3; n < 2540160; ++n)
        if (n == digit_factorials_sum(n))
            ans += n;
    std::cout << ans << std::endl;
    return 0;
}