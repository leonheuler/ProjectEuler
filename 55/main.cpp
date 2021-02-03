#include <algorithm>
#include <string>
#include <iostream>
    
using namespace std;

typedef uint64_t num_t;

bool is_palindrome(const std::string &s)
{
    return std::equal(s.begin(), s.end(), s.rbegin());
}

bool is_decimal_palindrome(const num_t& n)
{
    std::string num_str = std::to_string(n);
    return is_palindrome(num_str);
}

bool isLychrel(const num_t& n)
{
    num_t result = n;
    for (int i = 0; i < 30; ++i)
    {   
        string sn = to_string(result);
        sn = string(sn.rbegin(), sn.rend());
        result += stoull(sn);
        if (is_decimal_palindrome(result))
            return false;
    }
    return true;
}

int main() {


    int counter = 0;
    for (num_t n = 1; n < 10000; ++n)
    {
        if (isLychrel(n))
            counter++;
    }

    cout << counter;
    cin.get();
    return 0;
}