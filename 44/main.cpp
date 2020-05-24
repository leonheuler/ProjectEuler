#include <iostream>
#include <cmath>
#include <vector>

typedef unsigned long long num_t;

bool is_pentagonal(const num_t &n)
{
    double fraction, integer;
    if (modf(sqrt(1 + 24 * n), &integer) == 0)
        if ((1 + (num_t)integer) % 6 == 0)
            return true;
    return false;
}

int main()
{
    std::vector<num_t> pentagon_numbers;
    for (int n = 1; n < 100000000; ++n)
        if (is_pentagonal(n))
            pentagon_numbers.push_back(n);

    std::vector<std::pair<num_t, num_t>> pent_pairs;
    for (auto i = pentagon_numbers.begin(); i != pentagon_numbers.end() - 1; ++i)
        for (auto j = i + 1; j != pentagon_numbers.end(); ++j)
            if (is_pentagonal(*j - *i))
                if (is_pentagonal(*i + *j))
                    pent_pairs.push_back({*i, *j});

    for (auto i : pent_pairs)
        std::cout << i.first << " " << i.second << " " << i.second - i.first << std::endl;
    
    return 0;
}