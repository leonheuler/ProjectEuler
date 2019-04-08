#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ofstream fileo("result.txt");

    typedef map<unsigned long long, vector<unsigned long long>> chains_t;
    chains_t chains;
    size_t maxterms = 1;
    unsigned long long ans;

    for (unsigned long long n = 1; n < 1000000; n++)
    {
        chains[n].push_back(n);
        unsigned long long m = n;
        while (m > 1)
        {
            m % 2 ? m = 3 *m + 1 : m /= 2;
            if (m < n)
            {
                copy(chains[m].begin(), chains[m].end(), back_inserter(chains[n]));
                break;
            }
            chains[n].push_back(m);
        }

        fileo << n << " " << chains[n].size() << endl;  


        if (maxterms < chains[n].size())
        {
            maxterms = chains[n].size();
            ans = n;
        }
    }

    fileo << ans << " " << maxterms;

    fileo.close();

    return 0;
}