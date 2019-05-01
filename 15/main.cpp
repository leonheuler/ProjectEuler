#include <fstream>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

#define N 20

int main()
{

    ofstream fileo("result.txt");

    vector<vector<unsigned long long>> matrix(N - 1, vector<unsigned long long>(N, 1));

    for (int n = 1; n < N - 1; ++n)
    {

        for (int i = 0; i < N; ++i) 
        {

            unsigned long long sum = 0;
            for (int j = 0; j <= i; j++)
            {
                sum += matrix[n - 1][j];
            }

            matrix[n][i] = sum;

        }
    }

    unsigned long long sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum += matrix[i][j];
            fileo << matrix[i][j] << " ";
        }
        fileo << endl;
    }

    fileo << (sum + 1) * 2 << endl;

    return 0;
}