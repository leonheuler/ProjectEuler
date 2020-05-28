#include <iostream>
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

std::string prev_permutation(std::string s)
{
    std::prev_permutation(s.begin(), s.end());
    return s;
}

bool are_permutations(num_t n1, num_t n2, num_t n3)
{
    std::string n1_str = std::to_string(n1);
    std::string n2_str = std::to_string(n2);
    std::string n3_str = std::to_string(n3);

    std::string last_perm = prev_permutation(n1_str);
    bool match1 = false, match2 = false;
    while (n1_str != last_perm && !(match1 && match2))
    {
        std::next_permutation(n1_str.begin(), n1_str.end());
        if (n1_str == n2_str)
            match1 = true;
        if (n1_str == n3_str)
            match2 = true;
    }
    return match1 && match2;
}

int main()
{
    num_t n = 1000;
    for (; n <= 9999; ++n)
    {
        if (n != 1487)
            if (is_prime(n))
                if (is_prime(n + 3330))
                    if (is_prime(n + 6660))
                        if (are_permutations(n, n + 3330, n + 6660))
                            break;
    }
    std::cout << n << n + 3330 << n + 6660 << std::endl;
    return 0;
}