#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

int main()
{
    ifstream filei("p067_triangle.txt");

    const int n = 100;

    vector<vector<int>> vv;

    for (int i = 0; i < n; i++)
    {
        vector<int> v;

        for (int j = 0; j <= i; j++)
        {
            int n_i_j;
            filei >> n_i_j;
            v.push_back(n_i_j);
        }
        vv.push_back(v);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            vv[i][j] += max(vv[i+1][j],vv[i+1][j+1]);
        }
    }

    for (vector<vector<int>>::const_iterator it = vv.begin(); it != vv.end(); ++it)
    {
        copy(it->begin(), it->end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    filei.close();

    system("pause");

    return 0;
}