#include <iostream>
#include <string>
#include <algorithm>

typedef unsigned long num_t;

bool is_pandigital(std::string s)
{
    std::sort(s.begin(), s.end());
    return s.find('0') != std::string::npos ? false : std::unique(s.begin(), s.end()) == s.end();
}

num_t expand(num_t n)
{
    std::string s;
    for (int i = 1; s.size() < 9; ++i)
    {
        std::string next = std::to_string(n * i);
        s += next;
    }
    return s.size() == 9 ? std::stoul(s) : 0;
}

int main()
{
    num_t max = 0;
    for (num_t n = 1; n < 10000; ++n)
    {
        num_t pan_cand = expand(n);
        if (is_pandigital(std::to_string(pan_cand)))
            max = std::max(max, pan_cand);
    }
    std::cout << max << std::endl;
    return 0;
}