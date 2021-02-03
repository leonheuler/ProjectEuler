#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long num_t;

int main()
{
    int result  = 0;
    for (int n = 1; n < 10; ++n)
    {
        for (int p = 1;; ++p)
        {
            double powed = pow(n, p);
            string value = to_string(powed);
            int d = value.erase(value.find('.'), string::npos).length();
            if (d == p)
            {
                cout << n << " " << p << " " << powed << endl;
                result++;
            }
            else if (d < p)
                break;
        }
    }
    cout << result;
    cin.get();
    return 0;
}