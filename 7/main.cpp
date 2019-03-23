#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

bool is_simple(int n)
{
    for (int i = 2; i < n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    ofstream fileo("result.txt");
    
    vector<int> primes;

    int n = 2;
    while (primes.size() != 10001)
    {   
        if (is_simple(n))
            primes.push_back(n);
        
        ++n;
    }

    copy(primes.begin(), primes.end(), ostream_iterator<int>(fileo, "\n"));

    fileo << endl << primes.size();
    
    fileo.close();
    return 0;
}