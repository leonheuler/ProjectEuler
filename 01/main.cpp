#include <fstream>
#include <iostream>

using namespace std;

int main()
{

    ofstream fileo("result.txt");

    const int N = 1000;
    int sum = 0;

    for (int i = 1; i < N; i++)
    {
        if ( i % 3 == 0 || i % 5 == 0)
            sum += i;
    }

    fileo << sum << endl;

    fileo.close();

    return 0;
}