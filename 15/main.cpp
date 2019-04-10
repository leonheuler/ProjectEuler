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

    for (unsigned long long n = 1; n < N - 1; ++n)
    {

        for (unsigned long long i = 0; i < N; ++i)
        {
            // matrix[n][i] = accumulate(matrix[n - 1].begin(), matrix[n - 1].begin() + i, 0);

            unsigned long long sum = 0;
            for (unsigned long long j = 0; j <= i; j++)
            {
                sum += matrix[n - 1][j];
            }

            matrix[n][i] = sum;

            // fileo << matrix[n][i] << " ";
        }
    }

    unsigned long long sum = 0;
    for (unsigned long long i = 0; i < N - 1; i++)
    {
        for (unsigned long long j = 0; j < N; j++)
        {
            sum += matrix[i][j];
            fileo << matrix[i][j] << " ";
        }
        fileo << endl;
    }

    fileo << (sum + 1) * 2 << endl;

    return 0;
}