/** 
 * sum of integers that cannot be written as sum of 2 abundunt numbers is 
 * a difference between sum of all integers and sum of integers that can be written 
 * as a sum of 2 abundunt numbers
 * how a number can be written as sum of 2 abundunt numbers? 
 * 1. discover abundunt numbers
 * 2. generate numbers which can be written as sum of two abundunt, find sum of them
 * 3. substract that sum from sum of integers from 1 to 28123
 * */

#include <iostream>
#include <fstream>

#include <vector>
#include <map>

#include <numeric>
#include <algorithm>

#include <iterator>

#define print_vec(v, ostream)                                      \
    ostream << endl;                                               \
    copy(v.begin(), v.end(), ostream_iterator<int>(ostream, " ")); \
    ostream << endl

#define UPPER_LIMIT 28123

bool is_abundunt(int n);
bool more_then_upper_limit(int n) { return n >= UPPER_LIMIT; };

using namespace std;

int main()
{

    // 1. find abundunt numbers
    vector<int> ab_n;
    for (int n = 1; n <= UPPER_LIMIT; n++)
        if (is_abundunt(n))
            ab_n.push_back(n);

    // 2. generate sums
    map<int, int> ab_s;
    for (vector<int>::const_iterator i = ab_n.begin(); i != ab_n.end(); i++)
    {
        for (vector<int>::const_iterator j = i; j != ab_n.end(); j++)
        {
            int sum = *i + *j;
            if (sum > UPPER_LIMIT)
                break;
            else
                ab_s[sum];
        }
    }

    // сложить все числа в отрезке [1, UPPER_LIMIT], 
    // которые можно представить в виде суммы двух избыточных
    long s_ab_s = 0; 
    for (map<int, int>::const_iterator i = ab_s.begin(); i != ab_s.end(); i++)
        s_ab_s += i->first;

    // сложить все числа в отрезке [1, n]
    long s_n = UPPER_LIMIT * (UPPER_LIMIT + 1) / 2;
    
    long ans = s_n - s_ab_s;
    cout << ans << endl;

    return 0;
}

vector<int> get_proper_divisors(int);
bool is_abundunt(int n)
{
    vector<int> proper_divisors = get_proper_divisors(n);
    int sum_of_proper_divisors = accumulate(proper_divisors.begin(),
                                            proper_divisors.end(), 0);

    // if (sum_of_proper_divisors > n)
    // {
    //     cout << "n = " << n << "; sum = " << sum_of_proper_divisors << "; divisors = ";
    //     print_vec(proper_divisors,cout);
    // }

    return sum_of_proper_divisors > n;
}

vector<int> get_proper_divisors(int n)
{
    vector<int> ret;
    for (int d = 1; d <= n / 2; d++)
        if (n % d == 0)
            ret.push_back(d);
    return ret;
}