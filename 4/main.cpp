#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>

using std::endl;
using std::ofstream;
using std::string;
using std::to_string;
using std::max;
// 9009 | /1000 = 9 quot 9 rem
// 1*2*3*5
bool is_palindrome(const string &s)
{
    return equal(s.begin(), s.end(), s.rbegin());
}

int main()
{

    ofstream fileo("result.txt");


    int maxvalue = 0;

    for (int a = 999; a > 0; --a)
    {
        for (int b = 999; b > 0; --b)
        {
            int res = a * b;
            if (is_palindrome(to_string(res)))
            {
                maxvalue = max(maxvalue, res);
                fileo << to_string(res) << endl;
            }
        }
    }

    fileo << endl << maxvalue << endl;

    fileo.close();
    return 0;
}