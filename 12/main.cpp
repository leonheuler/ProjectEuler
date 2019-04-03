#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<unsigned long> find_dividers(unsigned long n)
{
    vector<unsigned long> ret = {1};
    for (unsigned long i = 2; i < n; ++i)
    {
        if (n % i == 0)
            ret.push_back(i);
    }
    ret.push_back(n);
    return ret;
}

unsigned long number_of_dividers(unsigned long n)
{
    unsigned long ret = 2;
    for (unsigned long i = 2; i < n; ++i)
    {
        if (n % i == 0)
            ret++;
    }
    return ret;
}

int main() 
{
    ofstream fileo("result.txt");

    unsigned long n = 0;
    unsigned long lim = 10000;

    unsigned long maxdivnum = 1;

    for (unsigned long i = 1; i < lim; ++i)
    {
        n = n + i;
        unsigned long divnum = number_of_dividers(n);
        fileo << n << " " << divnum << endl;

        maxdivnum = max(maxdivnum, divnum);

        if (maxdivnum > 500)   
            break;

    }

    fileo << endl << maxdivnum;

    fileo.close();
    return 0;
}