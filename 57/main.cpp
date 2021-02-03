#include <iostream>
#include <gmpxx.h>

/**
 * 1/2
 * 1/(1+1/2)
 * 1/(1+1/(1+1/2))
*/
using namespace std;

int main()
{
    int result = 0;

    for (int n = 1; n <= 1000; ++n)
    {
        mpq_class q(1, 2);
        for (int i = 0; i < n - 1; i++)
        {
            q += 2;
            q = 1 / q;
        }
        q += 1;

        if (q.get_num().get_str().size() > q.get_den().get_str().size())
            result++;
    }
    cout << result;
    cin.get();
}