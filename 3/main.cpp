#include <fstream>
#include <numeric>
#include <vector>
#include <iterator>
#include <cstdlib>

//  projecteuler.net/problem=3

using namespace std;

typedef long long long_int;

unsigned int gcd(unsigned int n1, unsigned int n2)
{
    return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}

bool is_simple(long_int n)
{
    for (long_int i = 2; i < n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{

    ofstream fileo1("result.txt");
    ofstream fileo2("primes.txt");

    long_int N = 600851475143;

    for (long_int n = 1; n < 10000; ++n)
    {
        if (is_simple(n))
        {
            lldiv_t res = lldiv(N, n);

            if (res.rem == 0)
            {
                fileo1 << N << " div " << n << " = " << res.quot << endl;

                N = res.quot;
            }
            if (N == 1)
                break;
        }
    }

    // int* natural = new int[size];

    fileo1.close();
    fileo2.close();
    return 0;
}