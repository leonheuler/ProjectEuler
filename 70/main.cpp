#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cmath>
#include <map>

using namespace std;

typedef unsigned long num_t;

ofstream fileo("result.txt");

bool is_prime(num_t n)
{
    for (num_t i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return true;
}

num_t totient(num_t n) 
{
    if (is_prime(n))
        return n - 1;   
    
    map<num_t, int> divs;
    for (num_t d = 2; n > 1; d++)
    {
        while (n % d == 0)
        {
            divs[d]++;
            n /= d;
        }
    }

    num_t result = 1;

    for_each(divs.begin(), divs.end(), [&result](auto e) { 
        result *= (e.first-1)*(num_t)pow(e.first, e.second-1);
    }); 

    return result;
}

bool is_permutation(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main()
{
    num_t answer = 1;
    double ratio = 2;
    clock_t start = clock();
    for (num_t n = 3; n < 1e7; n += 2)
    {
        num_t phi = totient(n);

        if ((double)n / phi < ratio)
        {
            if (is_permutation(to_string(n), to_string(phi)))
            {
                answer = n;
                ratio = (double)n / phi;
            }

        }

    }
    cout << answer << " " << ratio << " " << (clock() - start) / (double)CLOCKS_PER_SEC << " sec" << endl;
    system("pause");
    //8319823 1.00071 5197.53 sec
    return 0;
}

