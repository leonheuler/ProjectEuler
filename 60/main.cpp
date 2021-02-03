#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

typedef unsigned int num_t;

bool isSetOfPrimes(const vector<num_t>&);
vector<num_t> getPrimes(const num_t& sup);
bool isPrime(const num_t& n);

int main()
{
    unsigned int start_time = clock();

    vector<num_t> primes = getPrimes(10000);
    vector<num_t> prime_set;
    vector<num_t> least_prime_set;

    num_t prime_set_sum = 0;
    num_t least_prime_set_sum = 1000000;

    for (auto i = 0; i < primes.size() - 5; ++i)
    {
        for (auto j = i + 1; j < primes.size() - 4; ++j)
        {
            if (!isSetOfPrimes({primes[i], primes[j]}))
                continue;
            else
                prime_set = {primes[i], primes[j]};

            for (auto k = j + 1; k < primes.size() - 3; ++k)
            {
                if (!isSetOfPrimes({primes[i], primes[j], primes[k]}))
                    continue;
                else
                    prime_set.push_back(primes[k]);

                for (auto l = k + 1; l < primes.size() - 2; ++l)
                {
                    if (!isSetOfPrimes({primes[i], primes[j], primes[k], primes[l]}))
                        continue;
                    else
                        prime_set.push_back(primes[l]);

                    for (auto m = l + 1; m < primes.size() - 1; ++m)
                    {
                        if (!isSetOfPrimes({primes[i], primes[j], primes[k], primes[l], primes[m]}))
                            continue;
                        else
                        {
                            prime_set.push_back(primes[m]);

                            prime_set_sum = accumulate(prime_set.begin(), prime_set.end(), (num_t)0);

                            for (auto p : prime_set)
                                cout << p << " ";
                            cout << endl
                                 << prime_set_sum;

                            unsigned int end_time = clock();

                            cout << endl
                                 << (float)(end_time - start_time) / 1000 / 60 << " min." << endl;
                            cin.get();
                            return 0;
                        }
                    }
                }
            }
        }
    }
}

vector<num_t> getPrimes(const num_t& sup)
{
    vector<num_t> result;
    for (num_t n = 2; n <= sup; n++)
        if (isPrime(n))
            result.push_back(n);
    return result;
}

bool isPrime(const num_t& n)
{
    for (num_t d = 2; d <= sqrt(n); ++d)
        if (n % d == 0)
            return false;
    return true;
}

bool isSetOfPrimes(const vector<num_t>& vec)
{
    for (auto i = 0; i < vec.size() - 1; ++i)
        for (auto j = i + 1; j < vec.size(); ++j)
            if (!isPrime(stoi(to_string(vec[i]) + to_string(vec[j]))) ||
                !isPrime(stoi(to_string(vec[j]) + to_string(vec[i]))))
                return false;
    return true;
}