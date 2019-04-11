#include <fstream>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

int main()
{

    ofstream fileo("result.txt");

    const int N = 1000;

    vector<int> digits = {1};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j != digits.size(); ++j)
        {
            digits[j] *= 2;
        }

        if (digits[digits.size() - 1] >= 10)
        {
            digits[digits.size() - 1] %= 10;
            digits.push_back(1);
        }

        for (vector<int>::iterator it = digits.begin(); it != digits.end(); ++it)
        {
            if (*it >= 10)
            {
                *it %= 10;
                *(it + 1) += 1;
            }
        }


    }

    copy(digits.rbegin(), digits.rend(), ostream_iterator<int>(fileo, ""));
    fileo << endl
          << accumulate(digits.begin(), digits.end(), 0);

    fileo.close();
    return 0;
}