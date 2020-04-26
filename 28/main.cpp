#include <iostream>

#define N 1001

int main()
{
    long sum = 1, pr = 1;
    for (long i = 1; i <= (N - 1) / 2; ++i)
    {
        long k = 2 * i;
        for (long j = 0; j < 4; ++j)
        {
            sum += pr + k;
            pr += k;
        }
    }
    std::cout << sum;
    return 0;
}