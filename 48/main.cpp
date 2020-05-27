#include <iostream>
#include <string>

typedef unsigned long long num_t;

num_t count_digits(num_t n)
{
    return std::to_string(n).size();
}

num_t cut_number(num_t n)
{
    std::string n_str = std::to_string(n);
    return std::stoull(std::string(n_str.end() - 10, n_str.end()));
}

int main()
{
    num_t sum = 1;
    for (num_t n = 2; n <= 1000; ++n)
    {
        num_t pow = n;
        for (num_t d = 1; d < n; ++d)
        {
            pow *= n;
            if (count_digits(pow) > 10)
                pow = cut_number(pow);
        }
        sum += pow;
    }
    
    std::cout << sum << std::endl;
    return 0;
}