#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    ifstream filei("input.txt");
    ofstream fileo("result.txt");

    vector<vector<int>> vv;

    int v;
    while (filei >> v)
        fileo << v;

    filei.close();
    filei.close();
    system("pause");
    return 0;
}