#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{

    ifstream filei("input.txt");
    string ins;
    filei >> ins;


    vector<string> res;
    size_t i = 0;
    size_t j = i + 13;
    while (j < ins.size())
    {
        string s;
        copy(s[i], s[j], back_inserter(s));
        string::size_type n = s.find('0');
        if (n == s.size())
        {
            res.push_back(s);
            i = i + 13;
        }
        else
        {
            res.push_back(s);
            i = i + n;
        }
        j = i + 13;
    }

    ofstream fileo("result.txt");
    copy(res.begin(), res.end(), ostream_iterator<string>(fileo, "\n"));

    filei.close();
    fileo.close();

    return 0;
}