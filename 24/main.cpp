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

#define print_vec(v)                                            \
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); \
    cout << endl

#define len 5

#define print_mat(m)                          \
    for (size_t r = 0; r < fact(len); r++)     \
    {                                         \
        for (size_t c = 0; c < fact(len); c++) \
            cout << m[r][c];                  \
        cout << endl;                         \
    }

unsigned long long fact(int n)
{
    unsigned long long ret = 1;
    for (int i = 2; i <= n; i++)
        ret *= i;
    return ret;
}

int main()
{
    // const int n = 5;
    const long fact_len = fact(len);
    int **m;
    m = new int *[fact_len]; // n! строк
    for (size_t i = 0; i < len; i++)
        m[i] = new int[len];

    vector<int> v;
    for (int i = 0; i < len; i++)
        v.push_back(i);
    print_vec(v);

    for (size_t col = 0; col < len - 2; col++)
    {
        for (size_t row = 0; row < fact_len; row++)
        {
            m[row][col] = 1;
        }
    }
    print_mat(m);

    /*
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
    */
    ofstream fileo("mat");

    // for (size_t row = 0; row < size; row++)
    // {
    //     for (int col = 0; col < LIMIT; col++)
    //         fileo << m[row][col] << " ";
    //     fileo << endl;
    // }

    return 0;
}
