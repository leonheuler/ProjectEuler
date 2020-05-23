#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>

typedef unsigned long num_t;

bool is_palindrome(const std::string &s)
{
    return std::equal(s.begin(), s.end(), s.rbegin());
}

bool is_decimal_palindrome(const num_t& n)
{
    std::string num_str = std::to_string(n);
    return is_palindrome(num_str);
}

bool is_binary_palindrome(const num_t& n)
{
    std::bitset<32> num(n);
    std::string num_str = num.to_string();
    size_t pos = num_str.find_first_not_of('0');
    num_str.erase(num_str.begin(), num_str.begin() + pos);
    return is_palindrome(num_str);
}

int main()
{
    num_t ans = 0;
    for (num_t n = 1; n < 1e7; ++n)
        if (is_decimal_palindrome(n))
            if (is_binary_palindrome(n))
                ans += n;

    std::cout << ans << std::endl;
    return 0;
}