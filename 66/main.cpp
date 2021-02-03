#include <iostream>
#include <cmath>
#include <gmpxx.h>

using namespace std;


typedef unsigned long long num_t;

bool is_square(num_t n)
{
    return sqrtl(n) - (num_t)sqrtl(n) == 0;
}

int main()
{
    mpz_class h_max = 0, D = 0;
    for (int n = 2; n <= 1000; ++n)
    {
        if (!is_square(n))
        {   
            mpz_class a_0, a, b, c, b_0, c_0;
            a_0 = sqrt(n * 1.0);
            b = b_0 = a_0;
            c = c_0 = n - a_0 * a_0;

            mpz_class h_pr = 1,
                k_pr = 0,
                h_pr_pr = 0,
                k_pr_pr = 1;

            // ищем подходящие дроби которые являются решением
            mpz_class h_n = a_0*h_pr + h_pr_pr,
                k_n = a_0*k_pr + k_pr_pr;

            k_pr_pr = k_pr;
            h_pr_pr = h_pr;
            k_pr = k_n;
            h_pr = h_n;


            while (h_n * h_n - n * k_n * k_n != 1)
            {
                a = (a_0 + b) / c;
                b = a * c - b;
                c = (n - b * b) / c;

                h_n = a * h_pr + h_pr_pr;
                k_n = a * k_pr + k_pr_pr;

                h_pr_pr = h_pr;
                h_pr = h_n;

                k_pr_pr = k_pr;
                k_pr = k_n;
            }

            cout << h_n << "^2 - " << n << "*" << k_n << "^2 = 1" << endl;

            if (h_n > h_max)
            {
                h_max = h_n;
                D = n;
            }
        }
    }
    cout << D;
    cin.get();
    return 0;
}