#include <fstream>
#include <iostream>

using namespace std;

int main()
{

    ofstream fileo("result.txt");

    const int N = 46;
    unsigned long long a[N] = {1, 2};
    unsigned long long sum = 2;
 
    for (int i = 2; i < N; i++)
    {
        a[i] = a[i - 2] + a[i - 1];
        if (a[i] <= 4000000 && (a[i] % 2) == 0)
        {
            sum += a[i];
            fileo << a[i] << endl;
        }
    }

    fileo << endl << sum << endl;

    fileo.close();

    return 0;
}