#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

typedef unsigned long num_t;

bool is_prime(num_t n)
{
    for (num_t i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return n == 1 ? false : true;
}

// 1,4 -> "0001"; 2,4 -> "0010"
std::string to_binary(int n, int dig)
{
    std::string ret;
    while (n > 0)
    {
        ret.push_back(n % 2 == 0 ? '0' : '1');
        n /= 2;
    }
    if (ret.size() < dig)
    {
        std::string zeros(dig - ret.size(), '0');
        ret += zeros;
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}

// 4 -> {"0001,0010,0011,0100,0101,..."}
std::vector<std::string> gen_masks(num_t digits)
{
    std::vector<std::string> ret;
    for (int i = 1; i < pow(2, digits) - 1; ++i)
        ret.push_back(to_binary(i, digits));
    return ret;
}

// 1234 -> {*234, 1*34, 12*4, 123*, **34, ...}
std::vector<std::string> prepare_combinations(const num_t &n)
{
    std::vector<std::string> ret;
    std::string num = std::to_string(n);
    const size_t digits = num.size();
    std::vector<std::string> masks = gen_masks(digits);
    for (auto m : masks)
    {
        std::string next_num = num;
        for (std::string::size_type pos = 0; pos != next_num.size(); ++pos)
            if (m[pos] == '1')
                next_num[pos] = '*';
        ret.push_back(next_num);
    }
    return ret;
}

std::vector<num_t> replace_digits(std::string n)
{
    std::vector<num_t> ret;
    for (char d = '0'; d <= '9'; ++d)
    {
        std::string num = n;
        std::replace(num.begin(), num.end(), '*', d);
        if (num[0] == '0')
            continue;
        else
            ret.push_back(std::stoul(num));
    }
    return ret;
}

int main()
{
    for (num_t n = 11; ; ++n)
    {
        if (is_prime(n))
        {
            std::vector<std::string> pc = prepare_combinations(n);

            for (auto i : pc)
            {
                std::vector<num_t> prime_candidates = replace_digits(i);
                if (prime_candidates.size() < 8)
                    continue;
                
                std::vector<num_t> primes;
                std::copy_if(prime_candidates.begin(), prime_candidates.end(), std::back_inserter(primes), is_prime);

                if (primes.size() == 8)
                {
                    for (auto j : primes)
                        std::cout << j << std::endl;

                    std::cout << "Press any key to continue..." << std::endl;
                    std::cin.get();
                    return 0;
                }
            }
        }
    }
}