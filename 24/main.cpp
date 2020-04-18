/** 24
 * abcdefghij -> ... -> jihgfedcba */

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;

#define LIMIT 5

unsigned long long fact(int n)
{
    unsigned long long ret = 1;
    for (int i = 2; i <= n; ++i)
        ret *= i;
    return ret;
}

int main()
{
    static const long size = fact(LIMIT);
    int **m;
    m = new int *[size];
    for (size_t i = 0; i < size; i++)
        m[i] = new int[LIMIT];

    for (size_t row = 0; row < size; row++)
        for (int col = 0; col < LIMIT; col++)
            m[row][col] = col;

    int n = 0;
    for (int col = 0; col < LIMIT - 3; col++)
    {
        const size_t lim_c = fact(LIMIT - col) / (LIMIT - col);
        size_t lim = lim_c;
        n = 0;
        for (size_t row = 0; row < size; row++)
        {
            m[row][col] = n;
            if (row == lim - 1)
            {
                n++;
                if (n == LIMIT-col+1)
                    n = 0;
                lim += lim_c;
            }
        }
    }
    ofstream fileo("mat");

    for (size_t row = 0; row < size; row++)
    {
        for (int col = 0; col < LIMIT; col++)
            fileo << m[row][col] << " ";
        fileo << endl;
    }
    return 0;
}
