#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{

    ifstream filei("input.txt");
    ofstream fileo("result.txt");

    const int N = 50;

    string s;
    vector<int> vec(N, 0);
    while (filei >> s)
    {
        for (int i = 0; i < N; ++i)
        {
            vec[i] += s[i] - '0';
        }
    }

    for (int i = N - 1; i > 0; i--)
    {
        vec[i - 1] += vec[i] / 10;
        vec[i] %= 10;
    }

    copy(vec.begin(), vec.end(), ostream_iterator<int>(fileo));

    fileo.close();
    return 0;
}