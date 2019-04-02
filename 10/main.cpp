#include <fstream>
#include <vector>
#include <numeric>
#include <ctime>
#include <iterator>
#include <cmath>

using namespace std;

int main()
{
    ofstream fileo("result2.txt");

    
    const int n = 2000000;

    vector<unsigned long long> primes = {2};

    clock_t start_time = clock();

    for (int i = 3; i <= n; i++)
    {
        bool isPrime = true;
        for (vector<unsigned long long>::const_iterator it = primes.begin(); it != primes.end(); ++it)
        {
            if ( (i % *it == 0)  )
            {
                isPrime = false;
                break;
            }
            if ( *it >= sqrt(i))
                break;
        }
        if (isPrime)
        {
            primes.push_back(i);
        } 
    }

    copy(primes.begin(), primes.end(), ostream_iterator<unsigned long long>(fileo, "\n"));

    unsigned long long sum = 0;
    
    for (vector<unsigned long long>::const_iterator it = primes.begin(); it != primes.end(); ++it)
    {
        sum += *it;
    }

    fileo << endl << sum << endl;
    fileo << (clock() - start_time) / 1000.0 << " sec" << endl;

    fileo.close();
    return 0;
}