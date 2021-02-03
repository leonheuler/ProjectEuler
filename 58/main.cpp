#include <iostream>
#include <cmath>

typedef uint64_t num_t;

using namespace std;

bool is_prime(num_t n)
{
    for (num_t i = 2; i <= sqrt(n); ++i)
        if (n % i == 0)
            return false;
    return n == 1 ? false : true;
}

int main()
{
    num_t primes = 0, all = 1;
    float ratio = 0.0;
    for (num_t side_length = 3; ; side_length += 2)
    {
        for (int i = 1; i <= 4; ++i)
        {
            num_t num = (side_length - 2)*(side_length - 2) + (side_length - 1) * i;
            if (is_prime(num))
                primes++;
            all++;
            ratio = (float)primes/all;
            
            if (ratio < 0.1)
            {
                cout << side_length;
                cin.get();
                return 0;
            }
        }
    }
    return 0;
}