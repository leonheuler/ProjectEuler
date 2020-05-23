#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

using std::string;
using std::to_string;

int digits(int n)
{
    int dig = 1;
    while (n / 10 > 0)
    {
        ++dig;
        n /= 10;
    }
    return dig;
}

bool is_pandigital(int a, int b, int c)
{
    string s = to_string(a) + to_string(b) + to_string(c);
    
    if (std::find(s.begin(), s.end(), '0') != s.end())
        return false;

    std::sort(s.begin(), s.end());
    if (std::unique(s.begin(), s.end()) == s.end())
        return true;
    return false;
}

int main()
{
    std::vector<int> pand_v;
    int a = 2;
    while (digits(a) <= 7)
    {
        int b = 2;
        while (digits(b) <= 8 - digits(a))
        {
            int c = a * b;

            if (digits(c) == 9 - (digits(a) + digits(b)))
                if (is_pandigital(a, b, c))
                    pand_v.push_back(c);

            if (digits(c) > 9 - (digits(a) + digits(b)))
                break;

            b++;
        }
        a++;
    }
    std::sort(pand_v.begin(), pand_v.end());
    auto last = std::unique(pand_v.begin(), pand_v.end());
    pand_v.erase(last, pand_v.end());
    std::cout << std::accumulate(pand_v.begin(), pand_v.end(), 0);
    return 0;
}