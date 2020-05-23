#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

typedef unsigned long num_t;

bool is_prime(num_t n)
{
    for (num_t i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}

bool is_circular_prime(num_t num)
{
    const std::string num_str = std::to_string(num);
    std::string num_str_rot = num_str;
    do
    {
        std::rotate(num_str_rot.begin(), num_str_rot.begin() + 1, num_str_rot.end());
        if (!is_prime(std::stoi(num_str_rot)))
            return false;
    } while (num_str_rot != num_str);
    return true;
}

int main()
{
    num_t ans = 0;
    for (num_t n = 2; n < 1e6; ++n)
        if (is_prime(n))
            if (is_circular_prime(n))
                ++ans;

    std::cout << ans << std::endl;                

    return 0;
}