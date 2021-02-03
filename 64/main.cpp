#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#include <fstream>
ofstream fout("output.txt");

bool is_square(int n)
{
    return sqrtl(n) - (int)sqrtl(n) == 0;
}

int period_length(int n)
{
    int a_0, a, b, c, b_0, c_0, result = 0;
    a_0 = sqrt(n * 1.0);
    b = b_0 = a_0;
    c = c_0 = n - a_0 * a_0;
    do
    {
        a = (a_0 + b) / c;
        b = a * c - b;
        c = (n - b * b) / c;
        result++;
    } while ((b != b_0) || (c != c_0));
    return result;
}

int main()
{

    int result = 0;
    for (int n = 2; n <= 10000; ++n)
        if (!is_square(n))
            if (period_length(n) % 2 == 1)
                result++;

    cout << result << endl;
    cin.get();
    return 0;
}