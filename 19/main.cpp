#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    typedef vector<vector<int>> mat_t;

    mat_t mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (mat_t::const_iterator ii = mat.begin();
         ii != mat.end(); ++ii)
    {
        for (vector<int>::const_iterator jj = ii->begin();
             jj != ii->end(); ++jj)
        {
            cout << *jj;
        }
        cout << endl;
    }
    return 0;
}