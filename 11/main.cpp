#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int n = 20;
const int len = 4;

int main()
{
    ofstream fileo("result.txt");
    ifstream filei("input.txt");

    vector<vector<int>> M(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            filei >> M[i][j];
        }
    }

    unsigned long maxprod = 1;
    for (int i = 0; i < n - len + 1; ++i)
    {
        for (int j = 0; j < n - len + 1; ++j)
        {
            unsigned long prod_diag = M[i][j] * M[i + 1][j + 1] * M[i + 2][j + 2] * M[i + 3][j + 3];
            unsigned long prod_right = M[i][j] * M[i][j+1] * M[i][j+2] * M[i][j+3];
            unsigned long prod_down = M[i][j] * M[i+1][j] * M[i+2][j] * M[i+3][j];
            unsigned long prod_diag2 = M[i][j+(len-1)] * M[i+1][j+(len-1)-1] * M[i+2][j+(len-1)-2] * M[i+3][j+(len-1)-3];
            maxprod = max(maxprod, max(prod_down, max(prod_diag, prod_right)));

            fileo << prod_diag << " " << prod_right << " " << prod_down << endl;;

        }
        fileo << endl;
    }


    fileo << maxprod << endl;

    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         fileo << M[i][j] << " ";
    //     }

    //     fileo << endl;
    // }

    filei.close();
    fileo.close();
    return 0;
}