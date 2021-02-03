#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <gmpxx.h>

using namespace std;

typedef unsigned long long num_t;

int main()
{
    mpz_class h_prev_prev,
        h_prev, a2k, a_n, h_n;

    h_prev_prev = 0,
    h_prev = 1;

    a2k = 4;

    for (num_t n = 0; n < 100; ++n)
    {
        if (n == 0)
            a_n = 2;
        else if (n == 1)
            a_n = 1;
        else if (n == 2)
            a_n = 2;
        else if (n % 3 == 0)
            a_n = 1;
        else if ((n - 1) % 3 == 0)
            a_n = 1;
        else
        {
            a_n = a2k;
            a2k += 2;
        }

        h_n = a_n * h_prev + h_prev_prev;

        h_prev_prev = h_prev;
        h_prev = h_n;

        cout << n + 1 << " " << h_n << endl;
    }

    cout << endl;
    string ans = h_n.get_str();
    cout << accumulate(ans.begin(), ans.end(), 0) - 48 * ans.size();

    cin.get();
    return 0;
}