#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <ios>
#include <iomanip>

using namespace std;

int main()
{

    ofstream fileo("result.txt");
    ifstream filei("input.txt");

    vector<string> number;
    string s;
    while (filei >> s)
        number.push_back(s);

    const int seqlen = 13;

    vector<string> sequences;

    for (vector<string>::const_iterator it = number.begin(); it != number.end(); ++it)
    {
        string::const_iterator i, j;
        i = it->begin();
        j = i + seqlen;
        while (j <= it->end())
        {
            string seq = string(i, j);
            string::size_type n = seq.find('0');

            if (n == string::npos)
            {
                sequences.push_back(seq);
                i = i + 1;
            }
            else
            {
                i = i + n + 1;
            }
            j = i + seqlen;
        }
    }

    unsigned long long maxprod = 1;
    for (vector<string>::const_iterator it = sequences.begin(); it != sequences.end(); ++it)
    {
        fileo << "seq: " << *it;

        vector<unsigned long long> digits;
        for (string::size_type i = 0; i < it->size(); ++i)
        {
            digits.push_back((*it)[i] - 48);
        }
        fileo << " digits: ";
        copy(digits.begin(), digits.end(), ostream_iterator<unsigned long long>(fileo, " "));

        unsigned long long prod = 1;
        for (vector<unsigned long long>::const_iterator it_d = digits.begin(); it_d != digits.end(); ++it_d)
        {
            prod *= *it_d;
        }


        fileo << "prod: " << setw(20) << prod << endl;
        
        maxprod = max(maxprod, prod);
    }

    fileo << maxprod;

    filei.close();
    fileo.close();

    return 0;
}