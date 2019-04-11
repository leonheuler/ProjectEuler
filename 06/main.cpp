#include <fstream>
#include <vector>
#include <numeric>

using std::accumulate;
using std::ofstream;
using std::vector;

int main()
{
    ofstream fileo("result.txt");

    const int N = 100;

    int natural[N];

    for (int i = 0; i < N; ++i)
        natural[i] = i + 1;

    vector<int> outer_sum;
    for (int i = 0; i < N; ++i)
    {
        vector<int> productions;
        for (int j = i + 1; j < N; ++j)
        {
            productions.push_back(natural[i]*natural[j]);
        }
        
        outer_sum.push_back(accumulate(productions.begin(), productions.end(), 0));

    }

    fileo << 2 * accumulate(outer_sum.begin(), outer_sum.end(), 0);

    
}